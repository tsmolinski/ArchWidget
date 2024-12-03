// Fill out your copyright notice in the Description page of Project Settings.


#include "ArchHUD.h"
#include "ArchWidget/UI/ArchBaseUI.h"
#include "Kismet/GameplayStatics.h"
#include "ArchWidget/ArchGameplayTags/ArchGameplayTags.h"
#include "ArchWidget/UI/Widget/ArchActivatableWidget.h"
#include "ArchWidget/UI/Widget/ArchGenericPromptWidget.h"
#include "Internationalization/Text.h"

void AArchHUD::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		if (ArchBaseUIWidgetClass)
		{
			ArchBaseUIWidget = CreateWidget<UArchBaseUI>(PlayerController, ArchBaseUIWidgetClass);

			ArchBaseUIWidget->AddToViewport();
		}
	}

	ShowGameLayoutWidget();
}

void AArchHUD::ShowGameLayoutWidget()
{
	if (ArchBaseUIWidget)
	{
		if (GameLayoutWidgetClass)
		{
			GameLayoutWidget = ArchBaseUIWidget->PushWidgetToLayer<UArchActivatableWidget>(TAG_UI_Layer_GameStack, GameLayoutWidgetClass);
		}
	}
}

void AArchHUD::ShowGenericPromptWidget(const FText& MessageText, FGenericPromptOnConfirmedDelegate Confirmed, FGenericPromptOnConfirmedDelegate Declined)
{
	if (ArchBaseUIWidget)
	{
		if (GenericPromptWidgetClass)
		{
			GenericPromptWidget = ArchBaseUIWidget->PushWidgetToLayer<UArchGenericPromptWidget>(TAG_UI_Layer_PopupStack, GenericPromptWidgetClass, [
				MessageText, Confirmed, Declined](
					UArchGenericPromptWidget& Prompt) {
						Prompt.SetupPrompt(MessageText, Confirmed, Declined); 
				}
			);
		}
	}
}

void AArchHUD::ShowInGameMenuWidget()
{
	if (ArchBaseUIWidget)
	{
		if (InGameMenuWidgetClass)
		{
			InGameMenuWidget = ArchBaseUIWidget->PushWidgetToLayer<UArchActivatableWidget>(TAG_UI_Layer_GameMenuStack, InGameMenuWidgetClass);
		}
	}
}
