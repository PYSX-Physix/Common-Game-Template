// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonGameViewportClient.h"
#include "CGT_ViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class COMMONGAMETEMPLATE_API UCGT_ViewportClient : public UCommonGameViewportClient
{
	GENERATED_BODY()
	
public:
	UCGT_ViewportClient();
	virtual void Init(struct FWorldContext& WorldContext, UGameInstance* OwningGameInstance, bool bCreateNewAudioDevice = true) override;
};
