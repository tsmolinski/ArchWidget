// Fill out your copyright notice in the Description page of Project Settings.


#include "ArchBaseUI.h"
#include "Widgets/CommonActivatableWidgetContainer.h"

void UArchBaseUI::RegisterLayer(FGameplayTag LayerTag, UCommonActivatableWidgetContainerBase* Widget)
{
	Layers.Add(LayerTag, Widget);

	for (auto& layer : Layers)
	{
		UE_LOG(LogTemp, Log, TEXT("Tag: %s"), *layer.Key.ToString());
	}
}