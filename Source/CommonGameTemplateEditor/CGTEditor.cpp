#include "CGTEditor.h"

#include "AbilitySystemGlobals.h"
#include "Editor/UnrealEdEngine.h"
#include "Engine/GameInstance.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "GameMode/ModularExperienceManager.h"
#include "GameplayAbilitiesEditorModule.h"
#include "GameplayCueInterface.h"
#include "GameplayCueNotify_Burst.h"
#include "GameplayCueNotify_BurstLatent.h"
#include "GameplayCueNotify_Looping.h"
#include "ToolMenu.h"
#include "ToolMenus.h"
#include "UObject/UObjectIterator.h"
#include "UnrealEdGlobals.h"

class SWidget;

#define LOCTEXT_NAMESPACE "CGTEditor"

DEFINE_LOG_CATEGORY(LogCGTEditor);

class FCGTEditorModule : public FDefaultGameModuleImpl
{
	typedef FCGTEditorModule ThisClass;
	virtual void StartupModule() override
	{
		if (!IsRunningGame())
		{
			FEditorDelegates::BeginPIE.AddRaw(this, &ThisClass::OnBeginPIE);
			FEditorDelegates::EndPIE.AddRaw(this, &ThisClass::OnEndPIE);
		}
	}
	void OnBeginPIE(bool bIsSimulating)
	{
		UModularExperienceManager* ExperienceManager = GEngine->GetEngineSubsystem<UModularExperienceManager>();
		check(ExperienceManager);
		ExperienceManager->OnPlayInEditorBegun();
	}
	void OnEndPIE(bool bIsSimulating)
	{
	}

	virtual void ShutdownModule() override
	{
		FEditorDelegates::BeginPIE.RemoveAll(this);
		FEditorDelegates::EndPIE.RemoveAll(this);
	}
};
IMPLEMENT_MODULE(FCGTEditorModule, CommonGameTemplateEditor);

#undef LOCTEXT_NAMESPACE