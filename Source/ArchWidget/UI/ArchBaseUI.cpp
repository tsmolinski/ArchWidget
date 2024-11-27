// Fill out your copyright notice in the Description page of Project Settings.


#include "ArchBaseUI.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "CommonActivatableWidget.h"

UCommonActivatableWidget* UArchBaseUI::PushWidgetToLayer(FGameplayTag LayerTag, UClass* ActivatableWidgetClass)
{
	if (UCommonActivatableWidgetContainerBase* Layer = GetLayerWidget(LayerTag))
	{
		return Layer->AddWidget<UCommonActivatableWidget>(ActivatableWidgetClass);
	}

	return nullptr;
}

UCommonActivatableWidgetContainerBase* UArchBaseUI::GetLayerWidget(FGameplayTag LayerTag)
{
	return Layers.FindRef(LayerTag);
}

void UArchBaseUI::RegisterLayer(FGameplayTag LayerTag, UCommonActivatableWidgetContainerBase* Widget)
{
	Layers.Add(LayerTag, Widget);

	for (auto& layer : Layers)
	{
		UE_LOG(LogTemp, Log, TEXT("Tag: %s"), *layer.Key.ToString());
	}
}
