// Fill out your copyright notice in the Description page of Project Settings.


#include "ArchShowGenericPromptAsyncAction.h"
#include "Kismet/GameplayStatics.h"
#include "ArchWidget/UI/HUD/ArchHUD.h"
#include "ArchWidget/UI/Subsystem/ArchUIMessagingSubsystem.h"

UArchShowGenericPromptAsyncAction* UArchShowGenericPromptAsyncAction::ShowGenericPromptAsyncAction(UObject* InWorldContextObject, FText Message)
{
	UArchShowGenericPromptAsyncAction* Action = NewObject<UArchShowGenericPromptAsyncAction>();
	Action->WorldContextObject = InWorldContextObject;
	Action->MessageText = Message;
	Action->RegisterWithGameInstance(InWorldContextObject);

	return Action;
}

void UArchShowGenericPromptAsyncAction::Activate()
{
	if (UWorld* World = WorldContextObject->GetWorld())
	{
			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
			if (PlayerController)
			{
				AArchHUD* ArchHUD = Cast<AArchHUD>(PlayerController->GetHUD());

				if (ArchHUD)
				{
					FGenericPromptOnConfirmedDelegate Confirmed = FGenericPromptOnConfirmedDelegate::CreateUObject(this, &UArchShowGenericPromptAsyncAction::OnConfirmedActionHandle);
					FGenericPromptOnDeclinedDelegate Declined = FGenericPromptOnDeclinedDelegate::CreateUObject(this, &UArchShowGenericPromptAsyncAction::OnDeclinedActionHandle);

					ArchHUD->ShowGenericPromptWidget(MessageText, Confirmed, Declined);
				}
			}
	}
}

void UArchShowGenericPromptAsyncAction::OnConfirmedActionHandle()
{
	OnConfirmed.Broadcast();
	SetReadyToDestroy();
}

void UArchShowGenericPromptAsyncAction::OnDeclinedActionHandle()
{
	OnDeclined.Broadcast();
	SetReadyToDestroy();
}
