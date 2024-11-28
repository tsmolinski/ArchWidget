// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "ArchActivatableWidget.generated.h"

struct FUIInputConfig;

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
	UArchActivatableWidget(const FObjectInitializer& ObjectInitializer);

	void NativeOnInitialized() override;

	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = Input)
	EArchWidgetInputMode InputConfig = EArchWidgetInputMode::Default;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	EMouseCaptureMode GameMouseCaptureMode = EMouseCaptureMode::CapturePermanently;
};
