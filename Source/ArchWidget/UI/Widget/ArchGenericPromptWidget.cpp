// Fill out your copyright notice in the Description page of Project Settings.


#include "ArchGenericPromptWidget.h"
#include "CommonTextBlock.h"
#include "Internationalization/Text.h"
#include "ArchWidget/UI/Button/ArchGenericButton.h"

void UArchGenericPromptWidget::SetupPrompt(const FText& Message, FGenericPromptOnConfirmedDelegate Confirmed, FGenericPromptOnConfirmedDelegate Declined)
{
	PromptText->SetText(Message);

	OnConfirmedDelegate = Confirmed;
	OnDeclinedDelegate = Declined;
}

void UArchGenericPromptWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	GenericYesBtn->OnClicked().AddUObject(this, &ThisClass::OnYesBtnClicked);
	GenericNoBtn->OnClicked().AddUObject(this, &ThisClass::OnNoBtnClicked);
}

void UArchGenericPromptWidget::OnYesBtnClicked()
{
	DeactivateWidget();
	OnConfirmedDelegate.ExecuteIfBound();
}

void UArchGenericPromptWidget::OnNoBtnClicked()
{
	DeactivateWidget();
	OnDeclinedDelegate.ExecuteIfBound();
}
