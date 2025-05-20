// Fill out your copyright notice in the Description page of Project Settings.


#include "Charcters/SCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"

namespace ASCharacterHelpers
{
	const FName MoveForward		= FName("MoveForward");
	const FName MoveRight		= FName("MoveRight");
	const FName Turn			= FName("Turn");
	const FName LookUp			= FName("LookUp");
}

ASCharacter::ASCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SprintArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SprintArmComp->bUsePawnControlRotation = true;
	SprintArmComp->SetupAttachment(GetRootComponent());
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SprintArmComp);

	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
}

void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASCharacter::MoveForward(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.f;
	ControlRot.Roll = 0.f;
	
	AddMovementInput(ControlRot.Vector(), Value);
}

void ASCharacter::MoveRight(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.f;
	ControlRot.Roll = 0.f;
	
	AddMovementInput(UKismetMathLibrary::GetRightVector(ControlRot), Value);
}

void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(ASCharacterHelpers::MoveForward, this, &ThisClass::MoveForward);
	PlayerInputComponent->BindAxis(ASCharacterHelpers::MoveRight, this, &ThisClass::MoveRight);
	
	PlayerInputComponent->BindAxis(ASCharacterHelpers::Turn, this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(ASCharacterHelpers::LookUp, this, &APawn::AddControllerPitchInput);
}

