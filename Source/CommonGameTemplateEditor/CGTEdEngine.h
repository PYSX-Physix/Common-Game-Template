// Copyright Varomic Games 2025

#pragma once

#include "Editor/UnrealEdEngine.h"
#include "CGTEdEngine.generated.h"


class IEngineLoop;
class UObject;
/**
 * 
 */
UCLASS()
class UCGTEdEngine : public UUnrealEdEngine
{
	GENERATED_BODY()
	
public:
	UCGTEdEngine(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	virtual void Init(IEngineLoop* InEngineLoop) override;
	virtual void Start() override;
	virtual void Tick(float DeltaSeconds, bool bIdleMode) override;

	virtual FGameInstancePIEResult PreCreatePIEInstances(const bool bAnyBlueprintErrors, const bool bStartInSpectatorMode, const float PIEStartTime, const bool bSupportsOnlinePIE, int32& InNumOnlinePIEInstances) override;

private:
	void FirstTickSetup();

	bool bFirstTickSetup = false;
	
	
};
