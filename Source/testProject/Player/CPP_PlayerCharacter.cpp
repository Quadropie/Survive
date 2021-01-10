// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerCharacter.h"

// Sets default values
ACPP_PlayerCharacter::ACPP_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    UCapsuleComponent* Cap = GetCapsuleComponent();
 
    FPSBody = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPSBody"));
    FPSCam = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCam"));
    FPSArms = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPSArms"));

    FPSBody->SetupAttachment(Cap);
    FPSCam->SetupAttachment(Cap);
    FPSArms->SetupAttachment(FPSCam);
  
    GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
  

}

// Called when the game starts or when spawned
void ACPP_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void ACPP_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPP_PlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ACPP_PlayerCharacter::MoveRight);

    PlayerInputComponent->BindAxis("LookUp", this, &ACPP_PlayerCharacter::LookY);
    PlayerInputComponent->BindAxis("Turn", this, &ACPP_PlayerCharacter::LookX);

    PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &ACPP_PlayerCharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACPP_PlayerCharacter::StopJumping);

    PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &ACPP_PlayerCharacter::ToggleCrouch);




}


void ACPP_PlayerCharacter::MoveForward(float Value)
{

    if ((Controller != NULL) && (Value != 0.0f))
    {
        // Get the Actor Rotation
        FRotator Rotation = GetActorRotation();

        // Add Movement to Forward/Backward X Axis
        const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void ACPP_PlayerCharacter::MoveRight(float Value)
{

    if ((Controller != NULL) && (Value != 0.0f))
    {
        // Get the Actor Rotation
        FRotator Rotation = GetActorRotation();

        // Add Movement to Right/Left Y Axis
        const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void ACPP_PlayerCharacter::LookX(float Value)
{

    if ((Controller != NULL) && (Value != 0.0f))
    {

        AddControllerYawInput(Value);

    }
}

void ACPP_PlayerCharacter::LookY(float Value)
{

    if ((Controller != NULL) && (Value != 0.0f))
    {

        AddControllerPitchInput(Value);

    }

}

void ACPP_PlayerCharacter::ToggleCrouch()
{
  
    if (bIsCrouched == false)
    {
        ACPP_PlayerCharacter::Crouch();
        FPSBody->GetAnimInstance();

    }

    if (bIsCrouched == true)
    {
        ACPP_PlayerCharacter::UnCrouch();
    }
    

}



/*

void ACPP_PlayerCharacter::Jump()
{

    if ((Controller != NULL)
    {
        // find out which way is forward
        FRotator Rotation = Controller->GetControlRotation();

        // add movement in that direction
        const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}
*/
