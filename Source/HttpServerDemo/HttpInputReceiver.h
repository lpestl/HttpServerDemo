// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpServer.h"
#include "HttpInputReceiver.generated.h"

/**
 * 
 */
UCLASS()
class HTTPSERVERDEMO_API UHttpInputReceiver : public UHttpServer
{
	GENERATED_BODY()

public:
	virtual bool HandleRequest(const FHttpServerRequest& Request, const FHttpResultCallback& OnComplete, FEndpointData EndpointData) override;
};
