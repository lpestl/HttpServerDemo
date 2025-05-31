// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpPlayerController.h"

#include "HttpModule.h"
#include "GameFramework/Character.h"

AHttpPlayerController::AHttpPlayerController()
{
	HttpInputReceiver = CreateDefaultSubobject<UHttpInputReceiver>("HttpInputReceiver");
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
	if (IsValid(GetCharacter()))
	{
		if (EndpointData.Endpoint.Contains(TEXT("/up/pressed"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/up/released"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/down/pressed"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/down/released"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/left/pressed"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/left/released"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/right/pressed"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/right/released"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/a-button/pressed")))
		{
			GetCharacter()->Jump();
		}
		else if (EndpointData.Endpoint.Contains(TEXT("/a-button/released")))
		{
			GetCharacter()->StopJumping();
		}
		else if (EndpointData.Endpoint.Contains(TEXT("/b-button/pressed"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/b-button/released"))){}
	}
}
