// Fill out your copyright notice in the Description page of Project Settings.


#include "K2Node_AIPathMoveTo.h"
#include "MovementExBPLibrary.h"
#include "Proxy/PathMoveProxy.h"
UK2Node_AIPathMoveTo::UK2Node_AIPathMoveTo(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ProxyFactoryFunctionName = GET_FUNCTION_NAME_CHECKED(UFlibMovementEx, V_AIPathMoveTo);
	ProxyFactoryClass = UFlibMovementEx::StaticClass();
	ProxyClass = UPathMoveProxy::StaticClass();
}


FText UK2Node_AIPathMoveTo::GetTooltipText() const
{
	return NSLOCTEXT("UK2Node_AIPathMoveTo", "AIPathMoveTo", "AIPathMoveTo");
}
