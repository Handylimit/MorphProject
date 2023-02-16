// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataManager.generated.h"

class ACameraActor;
UCLASS()
class MORPHPROJECT_API ADataManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADataManager();

	UFUNCTION(BlueprintCallable)
	void Initialization(const TArray<ACameraActor*>& transform);

	//void ReterieveVehicleData(int VehicleID);
	UFUNCTION(BlueprintCallable)
	void SetUpCameraTransform(bool Navigation);

	//distinguish between BP function and event
	//UFUNCTION(BlueprintCallable,BlueprintImplementableEvent)
	
	UFUNCTION(BlueprintCallable)
	void SetCameraByIndex(int32 Index);

protected:
		//UPROPERTY(EditAnywhere)
		//ACameraActor* m_Camera;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TArray<ACameraActor*> m_CameraArr;
	int32 m_CameraIndex = -1;
	float m_BlendTime = 0.75f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
