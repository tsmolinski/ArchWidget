// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "ArchBaseUI.generated.h"

class UCommonActivatableWidgetContainerBase;
class UCommonActivatableWidget;

/**
 *	This is the basic UI layout. It contains layers and functionalities such as adding and removing widgets from layers.
 */

UCLASS()
class ARCHWIDGET_API UArchBaseUI : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UCommonActivatableWidget* PushWidgetToLayer(FGameplayTag LayerTag, UClass* ActivatableWidgetClass);

	UCommonActivatableWidgetContainerBase* GetLayerWidget(FGameplayTag LayerTag);

protected:
	UFUNCTION(BlueprintCallable)
	void RegisterLayer(UPARAM(meta = (Categories = "UI.Layer")) FGameplayTag LayerTag, UCommonActivatableWidgetContainerBase* Widget);

private:
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UCommonActivatableWidgetContainerBase>> Layers;
	
};
