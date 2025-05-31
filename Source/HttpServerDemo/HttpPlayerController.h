// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpInputReceiver.h"
#include "GameFramework/PlayerController.h"
#include "HttpPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HTTPSERVERDEMO_API AHttpPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AHttpPlayerController();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void OnRecevedHttpInput(const FString& RequestBody, FEndpointData EndpointData);
	
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere)
	UHttpInputReceiver* HttpInputReceiver { nullptr };
	
	bool bMovePressed { false };
	float MoveScale { 0.f };
};
