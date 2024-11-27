// Fill out your copyright notice in the Description page of Project Settings.


#include "ArchHUD.h"
#include "../ArchBaseUI.h"
#include "Kismet/GameplayStatics.h"
#include "ArchWidget/ArchGameplayTags/ArchGameplayTags.h"
#include "CommonActivatableWidget.h"

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
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		/*if (GameLayoutWidgetClass)
		{
			GameLayoutWidget = CreateWidget<UCommonActivatableWidget>(PlayerController, GameLayoutWidgetClass);
		}*/

		ArchBaseUIWidget->PushWidgetToLayer(TAG_UI_Layer_GameStack, GameLayoutWidgetClass);
	}
}