// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpInputReceiver.h"

bool UHttpInputReceiver::HandleRequest(const FHttpServerRequest& Request, const FHttpResultCallback& OnComplete,
	FEndpointData EndpointData)
{
	if (EndpointData.Verbs == EHttpServerWrapperRequestVerbs::VERB_GET && EndpointData.Endpoint.Contains(TEXT("version")))
	{
		return ProcessResponse(OnComplete, TEXT("version"), TEXT("1.0.0"), EHttpServerResponseCodes::Accepted);
	}
	return Super::HandleRequest(Request, OnComplete, EndpointData);
}
