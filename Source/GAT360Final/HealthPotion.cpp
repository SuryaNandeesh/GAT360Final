// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPotion.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DamageEvents.h"
#include "PlayerCharacter.h"

// Sets default values
AHealthPotion::AHealthPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PotionMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PotionMesh"));
	RootComponent = PotionMesh;

	HealthRestoreAmount = 20.0f;
}

// Called when the game starts or when spawned
void AHealthPotion::BeginPlay()
{
	Super::BeginPlay();	
}

bool AHealthPotion::ConsumePotion(AActor* Consumer)
{
    if (Consumer)
    {
        APlayerCharacter* Character = Cast<APlayerCharacter>(Consumer);

        if (Character->Health >= Character->MaxHealth)
        {
            // Only consume the potion if it will actually restore health
            //Character->SetHealth(Character->Health + HealthRestoreAmount);
            return true;
        }
    }
    return false;
}

// Called every frame
void AHealthPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}