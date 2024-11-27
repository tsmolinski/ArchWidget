// Fill out your copyright notice in the Description page of Project Settings.


#include "ArchHUD.h"
#include "ArchWidget/UI/ArchBaseUI.h"
#include "Kismet/GameplayStatics.h"
#include "ArchWidget/ArchGameplayTags/ArchGameplayTags.h"
#include "ArchWidget/UI/Widget/ArchActivatableWidget.h"

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
	if (GameLayoutWidgetClass)
	{
		ArchBaseUIWidget->PushWidgetToLayer(TAG_UI_Layer_GameStack, GameLayoutWidgetClass);
	}
}