// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "CPP_PlayerCharacter.generated.h"


UCLASS()
class TESTPROJECT_API ACPP_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_PlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class USkeletalMeshComponent* FPSBody;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)		
		class UCameraComponent* FPSCam;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)		
		class USkeletalMeshComponent* FPSArms;


	// Movement
	void MoveForward(float Value);
	void MoveRight(float Value);

	//Look
	void LookX(float Value);
	void LookY(float Value);

	//Toggle Crouching

	void ToggleCrouch();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
