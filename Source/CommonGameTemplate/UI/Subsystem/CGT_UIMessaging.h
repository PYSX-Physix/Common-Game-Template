// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Messaging/CommonMessagingSubsystem.h"
#include "Templates/SubclassOf.h"
#include "UObject/SoftObjectPtr.h"

#include "CGT_UIMessaging.generated.h"

class FSubsystemCollectionBase;
class UCommonGameDialog;
class UCommonGameDialogDescriptor;
class UObject;


UCLASS()
class COMMONGAMETEMPLATE_API UCGT_UIMessaging : public UCommonMessagingSubsystem
{
	GENERATED_BODY()
	
public:
	UCGT_UIMessaging() {}
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void ShowConfirmation(UCommonGameDialogDescriptor* DialogDescriptor, FCommonMessagingResultDelegate ResultCallback = FCommonMessagingResultDelegate()) override;
	virtual void ShowError(UCommonGameDialogDescriptor* DialogDescriptor, FCommonMessagingResultDelegate ResultCallback = FCommonMessagingResultDelegate()) override;

private:
	UPROPERTY()
	TSubclassOf<UCommonGameDialog> ConfirmationDialogClassPtr;
	UPROPERTY()
	TSubclassOf<UCommonGameDialog> ErrorDialogClassPtr;
	UPROPERTY(config)
	TSoftClassPtr<UCommonGameDialog> ConfirmationDialogClass;
	UPROPERTY(config)
	TSoftClassPtr<UCommonGameDialog> ErrorDialogClass;
};
