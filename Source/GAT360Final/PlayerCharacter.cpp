// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100.0f;
	MaxHealth = Health;
}

float APlayerCharacter::GetHealth() const
{
	return Health;
}

void APlayerCharacter::ApplyDamage(float DamageAmount)
{
	Health -= DamageAmount;
	Health = FMath::Clamp(Health, 0.0f, 100.0f);
	if (Health <= 0.0f)
	{
		Health = 0.0f;
		// Handle character death
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::ClampHealth()
{
	Health = FMath::Clamp(Health, 0.0f, 100.0f);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

