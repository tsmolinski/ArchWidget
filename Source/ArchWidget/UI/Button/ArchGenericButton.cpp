// Fill out your copyright notice in the Description page of Project Settings.


#include "ArchGenericButton.h"
#include "CommonTextBlock.h"
#include "Internationalization/Text.h"

void UArchGenericButton::SetButtonText(FText InText)
{
	DisplayedText->SetText(InText);
}

void UArchGenericButton::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (DisplayedText)
	{
		DisplayedText->SetText(ButtonText);
	}
	
}
