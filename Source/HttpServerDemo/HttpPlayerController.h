// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpServer.h"
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
	
private:
	UPROPERTY(EditAnywhere)
	UHttpServer* HttpInputReceiver { nullptr };
};
