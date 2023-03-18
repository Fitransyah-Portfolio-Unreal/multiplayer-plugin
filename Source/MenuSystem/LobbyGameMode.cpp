// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStatebase.h"
#include "GameFramework/PlayerState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	// Local variable of game mode
	if (GameState)
	{
		
		APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
		if (PlayerState)
		{
			FString PlayerName = PlayerState->GetPlayerName();

			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(
					1,
					60.f,
					FColor::Red,
					FString::Printf(TEXT("%s has joined the game!"), *PlayerName)
				);
			}
		}

		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				2,
				60.f,
				FColor::Yellow,
				FString::Printf(TEXT("Players in game : %d"), NumberOfPlayers)
			);
		}

	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	APlayerState* PlayerState = Exiting->GetPlayerState<APlayerState>();
	if (PlayerState)
	{
		int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				1,
				60.f,
				FColor::Yellow,
				FString::Printf(TEXT("Players in game : %d"), NumberOfPlayers -1)
			);
		}

		
		FString PlayerName = PlayerState->GetPlayerName();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				2,
				60.f,
				FColor::Red,
				FString::Printf(TEXT("%s has jexiting the game!"), *PlayerName)
			);
		}
	}
}
