// Copyright Varomic Games 2025

#include "CGTEdEngine.h"

#include "Engine/GameInstance.h"
#include "GameMode/ModularWorldSettings.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Settings/ContentBrowserSettings.h"
#include "Settings/LevelEditorPlaySettings.h"
#include "Widgets/Notifications/SNotificationList.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CGTEdEngine)

class IEngineLoop;

#define LOCTEXT_NAMESPACE "CGTEditor"

UCGTEdEngine::UCGTEdEngine(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UCGTEdEngine::Init(IEngineLoop* InEngineLoop)
{
	Super::Init(InEngineLoop);
}

void UCGTEdEngine::Start()
{
	Super::Start();
}

void UCGTEdEngine::Tick(float DeltaSeconds, bool bIdleMode)
{
	Super::Tick(DeltaSeconds, bIdleMode);
	FirstTickSetup();
}

FGameInstancePIEResult UCGTEdEngine::PreCreatePIEInstances(const bool bAnyBlueprintErrors, const bool bStartInSpectatorMode, const float PIEStartTime, const bool bSupportsOnlinePIE, int32& InNumOnlinePIEInstances)
{
	if (const AModularWorldSettings* ModularWorldSettings = Cast<AModularWorldSettings>(EditorWorld->GetWorldSettings()))
	{
		if (ModularWorldSettings->ForceStandaloneNetMode)
		{
			EPlayNetMode OutPlayNetMode;
			PlaySessionRequest->EditorPlaySettings->GetPlayNetMode(OutPlayNetMode);
			if (OutPlayNetMode != PIE_Standalone)
			{
				PlaySessionRequest->EditorPlaySettings->SetPlayNetMode(PIE_Standalone);

				FNotificationInfo Info(LOCTEXT("ForcingStandaloneForFrontend", "Forcing NetMode: Standalone for the Frontend"));
				Info.ExpireDuration = 2.0f;
				FSlateNotificationManager::Get().AddNotification(Info);
			}
		}
	}

	FGameInstancePIEResult Result = Super::PreCreatePIEServerInstance(bAnyBlueprintErrors, bStartInSpectatorMode, PIEStartTime, bSupportsOnlinePIE, InNumOnlinePIEInstances);

	return Result;
}

void UCGTEdEngine::FirstTickSetup()
{
	if (bFirstTickSetup)
	{
		return;
	}

	bFirstTickSetup = true;

	// Force show plugin content on load.
	GetMutableDefault<UContentBrowserSettings>()->SetDisplayPluginFolders(true);
}

#undef LOCTEXT_NAMESPACE

