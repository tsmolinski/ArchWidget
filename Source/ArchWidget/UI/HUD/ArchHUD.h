// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ArchHUD.generated.h"

class UArchBaseUI;

/**
 * This is a UI manager class. 
 */
UCLASS()
class ARCHWIDGET_API AArchHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Base") 
	TSubclassOf<UArchBaseUI> ArchBaseUIWidgetClass;
	
private:
	TObjectPtr<UArchBaseUI> ArchBaseUIWidget;
};
