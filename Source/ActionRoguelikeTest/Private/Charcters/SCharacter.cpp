// Fill out your copyright notice in the Description page of Project Settings.


#include "Charcters/SCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

namespace ASCharacterHelpers
{
	const FName MoveForward = FName("MoveForward");
	const FName Turn = FName("Turn");
}

ASCharacter::ASCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SprintArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SprintArmComp->SetupAttachment(GetRootComponent());
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SprintArmComp);
}

void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(ASCharacterHelpers::MoveForward, this, &ThisClass::MoveForward);
	PlayerInputComponent->BindAxis(ASCharacterHelpers::Turn, this, &APawn::AddControllerYawInput);
}

