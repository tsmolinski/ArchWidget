// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchActivatableWidget.h"
#include "ArchWidget/UI/Subsystem/ArchUIMessagingSubsystem.h"
#include "ArchGenericPromptWidget.generated.h"

class UCommonTextBlock;
class FText;
class UArchGenericButton;

/**
 * 
 */
UCLASS()
class ARCHWIDGET_API UArchGenericPromptWidget : public UArchActivatableWidget
{
	GENERATED_BODY()

public:
	void SetupPrompt(const FText& Message, FGenericPromptOnConfirmedDelegate Confirmed, FGenericPromptOnConfirmedDelegate Declined);

protected:
	void NativeOnInitialized() override;

	void OnYesBtnClicked();

	void OnNoBtnClicked();

	FGenericPromptOnConfirmedDelegate OnConfirmedDelegate;

	FGenericPromptOnDeclinedDelegate OnDeclinedDelegate;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UArchGenericButton> GenericYesBtn;

	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UArchGenericButton> GenericNoBtn;

private:
	UPROPERTY(Meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> PromptText;
};
