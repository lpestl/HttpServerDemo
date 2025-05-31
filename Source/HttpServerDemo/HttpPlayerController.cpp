// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpPlayerController.h"

AHttpPlayerController::AHttpPlayerController()
{
	HttpInputReceiver = CreateDefaultSubobject<UHttpServer>("HttpInputReceiver");
}

void AHttpPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Run Http server
	if (IsValid(HttpInputReceiver))
	{
		HttpInputReceiver->OnReceivedRequest().AddDynamic(this, &AHttpPlayerController::OnRecevedHttpInput);
		HttpInputReceiver->StartApiServer();
	}
}

void AHttpPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Stop Http server
	if (IsValid(HttpInputReceiver))
	{
		HttpInputReceiver->OnReceivedRequest().RemoveDynamic(this, &AHttpPlayerController::OnRecevedHttpInput);
		HttpInputReceiver->StartApiServer();
	}
	
	Super::EndPlay(EndPlayReason);
}

void AHttpPlayerController::OnRecevedHttpInput(const FString& RequestBody, FEndpointData EndpointData)
{
	
}
