// Fill out your copyright notice in the Description page of Project Settings.


#include "Yang/DataManager.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetArrayLibrary.h"

// Sets default values
ADataManager::ADataManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//m_Camera = CreateDefaultSubobject<ACameraActor>("Camera");
	//CameraComp->SetWorldTransform((0,0,0),(0,0,0),(0,0,0)));

}

void ADataManager::Initialization(const TArray<ACameraActor*>& transform)
{
	this->m_CameraArr = transform;
	//m_Camera->GetCameraComponent()->SetWorldTransform(m_CameraPosArr[0]);
	this->m_CameraIndex = 0;

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTargetWithBlend(m_CameraArr[m_CameraIndex]);

	
}


void ADataManager::SetUpCameraTransform(bool Navigation)
{
	int32 nextIndex = m_CameraIndex;

	//update temp index
	if (Navigation) nextIndex += 1;
	else nextIndex -= 1;

	//check vaildality of the index
	if (m_CameraArr.IsValidIndex(nextIndex)) this->m_CameraIndex = nextIndex;
	else {

		if (nextIndex < 0) {
			int32 size =m_CameraArr.Num();
			this->m_CameraIndex = size - 1;
		}
		
		if (nextIndex >= m_CameraArr.Num()) this->m_CameraIndex = 0;
	}

	//update camera position
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTargetWithBlend(m_CameraArr[m_CameraIndex], m_BlendTime);

}

void ADataManager::SetCameraByIndex(int32 Index)
{
	if (m_CameraArr.IsValidIndex(m_CameraIndex))
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTargetWithBlend(m_CameraArr[m_CameraIndex], m_BlendTime);
}

// Called when the game starts or when spawned
void ADataManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADataManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

