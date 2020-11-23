// Fill out your copyright notice in the Description page of Project Settings.


#include "K2Node_SimpleMoveTo.h"
#include "MovementEx/Public/MovementExBPLibrary.h"
#include "Proxy/ActorMoveProxy.h"


UK2Node_SimpleMoveTo::UK2Node_SimpleMoveTo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UFlibMovementEx, V_ActorSimpleMoveTo);
	ProxyFactoryClass = UFlibMovementEx::StaticClass();
	ProxyClass = UActorMoveProxy::StaticClass();
}


FText UK2Node_SimpleMoveTo::GetTooltipText() const
{
	return NSLOCTEXT("UK2Node_SimpleMoveTo", "SimpleMoveTo", "SimpleMoveTo");
}

FText UK2Node_SimpleMoveTo::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return NSLOCTEXT("UK2Node_SimpleMoveTo", "SimpleMoveTo", "SimpleMoveTo");
}

FText UK2Node_SimpleMoveTo::GetMenuCategory() const
{
	return NSLOCTEXT("UK2Node_SimpleMoveTo", "MovementEx", "MovementEx");
}
