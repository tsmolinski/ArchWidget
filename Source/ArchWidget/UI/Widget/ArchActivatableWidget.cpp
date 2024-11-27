// Fill out your copyright notice in the Description page of Project Settings.


#include "ArchActivatableWidget.h"

TOptional<FUIInputConfig> UArchActivatableWidget::GetDesiredInputConfig() const
{
	switch (InputConfig)
	{
	case EArchWidgetInputMode::All:
		return FUIInputConfig(ECommonInputMode::All, GameMouseCaptureMode);
	case EArchWidgetInputMode::Game:
		return FUIInputConfig(ECommonInputMode::Game, GameMouseCaptureMode);
	case EArchWidgetInputMode::Menu:
		return FUIInputConfig(ECommonInputMode::Menu, EMouseCaptureMode::NoCapture);
	case EArchWidgetInputMode::Default:
	default:
		return TOptional<FUIInputConfig>();
	}
}
