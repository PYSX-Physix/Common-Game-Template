// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CGT_PlayerController.h"

#include "PrimaryGameLayout.h"
#include "CGT_LocalPlayer.h"

ACGT_PlayerController::ACGT_PlayerController() : Super()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true; //Required for Enhanced Input to function
}

void ACGT_PlayerController::BeginPlay()
{
	Super::BeginPlay();

#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
	const UCommonLocalPlayer* LocalPlayer = Cast<UCommonLocalPlayer>(GetLocalPlayer());
	ensureAlwaysMsgf(IsValid(LocalPlayer), TEXT("LocalPlayer must derive from UCommonLocalPlayer; fix project settings and restart project."), *GetName());

	const UPrimaryGameLayout* RootLayout = LocalPlayer->GetRootUILayout();
	ensureAlwaysMsgf(IsValid(RootLayout), TEXT("RootLayout must be valid; fix INI and restart."), *GetName());
#endif // UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
}

void ACGT_PlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
