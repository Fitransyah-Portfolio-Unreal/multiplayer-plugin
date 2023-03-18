// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API UMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")), FString LobbyPath = FString(TEXT("/Game/Lobby")));

	protected:

	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	// 
	// Callback for the custom delegates on the MultiplayerSessionSubsystem
	//
	UFUNCTION()
	void OnCreateSession (bool bWasSuccesful);
	void OnFindSession(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccesful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccesful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccesful);




private:
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	// The subsystem designed to handle all online session functionality
	class UMultiplayerSessionSubsystem* MultiplayerSessionSubsystem;

	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	void MenuTearDown();

	int32 NumPublicConnections {4};
	FString MatchType {FString(TEXT("FreeForAll"))};
	FString PathToLobby {TEXT("")};
};
