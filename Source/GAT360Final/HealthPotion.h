// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthPotion.generated.h"

UCLASS()
class GAT360FINAL_API AHealthPotion : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthPotion();

	UFUNCTION(BlueprintCallable, Category = "Potion")
	bool ConsumePotion(AActor* Consumer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Potion")
	float HealthRestoreAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Potion")
	UStaticMeshComponent* PotionMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
