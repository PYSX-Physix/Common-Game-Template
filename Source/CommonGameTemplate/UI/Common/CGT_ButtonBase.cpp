// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Common/CGT_ButtonBase.h"
#include "CommonActionWidget.h"

void UCGT_ButtonBase::SetButtonText(const FText& InText)
{
	bOverride_ButtonText = InText.IsEmpty();
	ButtonText = InText;
	RefreshButtonText();
}

void UCGT_ButtonBase::NativePreConstruct()
{
	Super::NativePreConstruct();

	RefreshButtonText();
}

void UCGT_ButtonBase::UpdateInputActionWidget()
{
	Super::UpdateInputActionWidget();

	RefreshButtonText();
}

void UCGT_ButtonBase::OnInputMethodChanged(ECommonInputType CurrentInputType)
{
	Super::OnInputMethodChanged(CurrentInputType);
}

void UCGT_ButtonBase::RefreshButtonText()
{
	if (bOverride_ButtonText || ButtonText.IsEmpty())
	{
		if (InputActionWidget)
		{
			const FText ActionDisplayText = InputActionWidget->GetDisplayText();
			if (!ActionDisplayText.IsEmpty())
			{
				UpdateButtonText(ActionDisplayText);
				return;
			}
		}
	}
	UpdateButtonText(ButtonText);
}
