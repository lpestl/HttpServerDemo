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
		if (EndpointData.Endpoint.Contains(TEXT("/up/pressed")))
		{
			GetCharacter()->Jump();
		}
		else if (EndpointData.Endpoint.Contains(TEXT("/up/released")))
		{
			GetCharacter()->StopJumping();
		}
		else if (EndpointData.Endpoint.Contains(TEXT("/down/pressed"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/down/released"))){}
		else if (EndpointData.Endpoint.Contains(TEXT("/left/pressed")))
		{
			bMovePressed = true;
			MoveScale = 1.f;
		}
		else if (EndpointData.Endpoint.Contains(TEXT("/left/released")))
		{
			bMovePressed = false;
			MoveScale = 0.f;
		}
		else if (EndpointData.Endpoint.Contains(TEXT("/right/pressed")))
		{
			bMovePressed = true;
			MoveScale = -1.f;
		}
		else if (EndpointData.Endpoint.Contains(TEXT("/right/released")))
		{
			bMovePressed = false;
			MoveScale = 0.f;
		}
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

void AHttpPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bMovePressed && IsValid(GetCharacter()))
	{
		GetCharacter()->AddMovementInput(FVector(0.0f, 1.0f, 0.0f), MoveScale);
	}
}
