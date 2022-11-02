// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MPBoardUnitActor.generated.h"


//class UCameraComponent;

UCLASS()
class MORPHPROJECT_API AMPBoardUnitActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMPBoardUnitActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//UCameraComponent* CamComp;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
