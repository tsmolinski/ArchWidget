// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ArchWidget/UI/Subsystem/ArchUIMessagingSubsystem.h"
#include "ArchHUD.generated.h"

class UArchBaseUI;
class UArchActivatableWidget;
class FText;
class UArchGenericPromptWidget;
class UArchGenericButton;

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
	void ShowGameLayoutWidget();

	void ShowGenericPromptWidget(const FText& MessageText, FGenericPromptOnConfirmedDelegate Confirmed, FGenericPromptOnConfirmedDelegate Declined);

	UFUNCTION(BlueprintCallable)
	void ShowInGameMenuWidget();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Base") 
	TSubclassOf<UArchBaseUI> ArchBaseUIWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UArchActivatableWidget> GameLayoutWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UArchGenericPromptWidget> GenericPromptWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UArchActivatableWidget> InGameMenuWidgetClass;

private:
	TObjectPtr<UArchBaseUI> ArchBaseUIWidget;

	TObjectPtr<UArchActivatableWidget> GameLayoutWidget;

	TObjectPtr<UArchGenericPromptWidget> GenericPromptWidget;

	TObjectPtr<UArchActivatableWidget> InGameMenuWidget;
};
