// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UIDataManager.generated.h"

UCLASS()
class MORPHPROJECT_API AUIDataManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIDataManager();

	void SpawnNewVehicle(int VehicleType);

	void EditColor(int Index);
	void EditDescription(int Index);
	void EditPrice(int Index);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
