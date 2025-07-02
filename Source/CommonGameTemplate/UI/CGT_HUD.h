// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CGT_HUD.generated.h"

/**
 * 
 */
UCLASS()
class COMMONGAMETEMPLATE_API ACGT_HUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ACGT_HUD();
protected:
	//~UObject interface
	virtual void PreInitializeComponents() override;
	//~End of UObject interface

	//~AActor interface
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~End of AActor interface

};
