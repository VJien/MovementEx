// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "K2Node_BaseAsyncTask.h"
#include "K2Node_AIPathMoveTo.generated.h"

/**
 * 
 */
UCLASS()
class MOVEMENTEXEDITOR_API UK2Node_AIPathMoveTo : public UK2Node_BaseAsyncTask
{
	GENERATED_UCLASS_BODY()
	

public:
	virtual FText GetTooltipText() const override;
};