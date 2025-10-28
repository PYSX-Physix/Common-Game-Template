// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularPlayerController.h"
#include "CGT_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class COMMONGAMETEMPLATE_API ACGT_PlayerController : public AModularPlayerController
{
	GENERATED_BODY()
	
public:
	ACGT_PlayerController();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
