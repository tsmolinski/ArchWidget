// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "ArchShowGenericPromptAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGenericPromptDelegate);

/**
 * 
 */
UCLASS()
class ARCHWIDGET_API UArchShowGenericPromptAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public: 
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta = (BlueprintInternalUseOnly = "true", WorldContext = "InWorldContextObject"))
	static UArchShowGenericPromptAsyncAction* ShowGenericPromptAsyncAction(UObject* InWorldContextObject, FText Message);

	virtual void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FGenericPromptDelegate OnConfirmed;

	UPROPERTY(BlueprintAssignable)
	FGenericPromptDelegate OnDeclined;

private:
	void OnConfirmedActionHandle();

	void OnDeclinedActionHandle();

	UPROPERTY(Transient)
	TObjectPtr<UObject> WorldContextObject;

	UPROPERTY(Transient)
	FText MessageText;
};
