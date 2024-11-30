// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "ArchUIMessagingSubsystem.generated.h"

DECLARE_DELEGATE(FGenericPromptOnConfirmedDelegate);
DECLARE_DELEGATE(FGenericPromptOnDeclinedDelegate);

/**
 * 
 */
UCLASS()
class ARCHWIDGET_API UArchUIMessagingSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
};
