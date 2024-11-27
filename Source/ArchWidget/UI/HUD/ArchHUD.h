// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ArchHUD.generated.h"

class UArchBaseUI;
class UCommonActivatableWidget;

/**
 * This is a UI manager class. 
 */
UCLASS()
class ARCHWIDGET_API AArchHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void ShowGameLayoutWidget();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Base") 
	TSubclassOf<UArchBaseUI> ArchBaseUIWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Base")
	TSubclassOf<UCommonActivatableWidget> GameLayoutWidgetClass;

private:
	TObjectPtr<UArchBaseUI> ArchBaseUIWidget;

	TObjectPtr<UCommonActivatableWidget> GameLayoutWidget;
};
