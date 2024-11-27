// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "ArchActivatableWidget.generated.h"

UENUM(BlueprintType)
enum class EArchWidgetInputMode : uint8
{
	All,
	Game,
	Menu,
	Default
};

/**
 * 
 */
UCLASS()
class ARCHWIDGET_API UArchActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
public:
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = Input)
	EArchWidgetInputMode InputConfig = EArchWidgetInputMode::Default;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	EMouseCaptureMode GameMouseCaptureMode = EMouseCaptureMode::CapturePermanently;
};
