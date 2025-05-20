// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputComponent;

UCLASS()
class ACTIONROGUELIKETEST_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SprintArmComp = nullptr;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComp = nullptr;
	
public:
	
	ASCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
};
