// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "ArchBaseUI.generated.h"

/**
 *	This is the basic UI layout. It contains layers and functionalities such as adding and removing widgets from layers.
 */

class UCommonActivatableWidgetContainerBase;

UCLASS()
class ARCHWIDGET_API UArchBaseUI : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void RegisterLayer(FGameplayTag LayerTag, UCommonActivatableWidgetContainerBase* Widget);

private:
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UCommonActivatableWidgetContainerBase>> Layers;
	
};
