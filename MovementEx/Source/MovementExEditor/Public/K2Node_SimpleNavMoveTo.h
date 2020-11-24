// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "K2Node_BaseAsyncTask.h"
#include "K2Node_SimpleNavMoveTo.generated.h"

/**
 * 
 */
UCLASS()
class MOVEMENTEXEDITOR_API UK2Node_SimpleNavMoveTo : public UK2Node_BaseAsyncTask
{
	GENERATED_UCLASS_BODY()
	

public:
	virtual FText GetTooltipText() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;//�ڵ������
	virtual FText GetMenuCategory() const override;//����
};
