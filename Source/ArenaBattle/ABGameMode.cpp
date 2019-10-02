// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "ABPlayerController.h"
#include "ABPawn.h"
#include "ABCharacter.h"

AABGameMode::AABGameMode()
{
	DefaultPawnClass = AABCharacter::StaticClass();
	PlayerControllerClass = AABPlayerController::StaticClass();
}

void AABGameMode::PostLogin(APlayerController* NewPlayer)
{
	ABLOG(Warning, TEXT("Post Login Start"));
	Super::PostLogin(NewPlayer);
	ABLOG(Warning, TEXT("Post Login End"));
}