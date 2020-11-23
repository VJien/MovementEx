// Copyright Epic Games, Inc. All Rights Reserved.

#include "MovementExBPLibrary.h"
#include "MovementEx.h"

UFlibMovementEx::UFlibMovementEx(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}




bool UFlibMovementEx::V_AIMoveToDelegate(APawn* Pawn, FVector Des, AActor* Target, const FMoveSimpleDelegate& MoveEndEvent, float AcceptanceRadius /*= 5.0*/, bool StopOnOverlap /*= false*/)
{
	if (!Pawn) { return nullptr; };
	UMoveProxy* p = NewObject<UMoveProxy>(Pawn);
	p->Proxy_AIMoveToDelegate(Pawn, Des, Target, MoveEndEvent, AcceptanceRadius, StopOnOverlap);

	return true;
}

UMoveProxy* UFlibMovementEx::V_AIMoveTo(APawn* Pawn, FVector Des, AActor* Target, float AcceptanceRadius /*= 5.0*/, bool StopOnOverlap /*= false*/)
{
	if (!Pawn) { return nullptr; };
	UMoveProxy* p = NewObject<UMoveProxy>(Pawn);
	 p->Proxy_AIMoveTo(Pawn, Des, Target, AcceptanceRadius, StopOnOverlap);
	 return p;
}

bool UFlibMovementEx::V_AIPathMoveToDelegate(APawn* Pawn, TArray<FVector> DesPath, const FPathMoveDelegate& MoveEndEvent, const FPathMoveDelegate2& MoveOneStepEvent, float AcceptanceRadius /*= 5.0*/, bool StopOnOverlap /*= false*/)
{
	if (!Pawn || DesPath.Num()<=0) { return nullptr; };
	UPathMoveProxy* p = NewObject<UPathMoveProxy>(Pawn);
	return p->Proxy_AIPathMoveToDelegate(Pawn, DesPath, MoveEndEvent, MoveOneStepEvent, AcceptanceRadius, StopOnOverlap);
}

UPathMoveProxy* UFlibMovementEx::V_AIPathMoveTo(APawn* Pawn, TArray<FVector> DesPath, float AcceptanceRadius /*= 5.0*/, bool StopOnOverlap /*= false*/)
{
	if (!Pawn || DesPath.Num() <= 0) { return nullptr; };
	UPathMoveProxy* p = NewObject<UPathMoveProxy>(Pawn);
	p->Proxy_AIPathMoveTo(Pawn, DesPath, AcceptanceRadius, StopOnOverlap);
	return p;
}

UActorMoveProxy* UFlibMovementEx::V_ActorSimpleMoveTo(AActor* MoveActor, FVector Des, AActor* Target, float LinearSpeed, float TurnSpeed, float AcceptanceRadius /*= 5.0*/, bool bTurnPitch, bool bTurnYaw, bool bTurnRoll)
{
	if (!MoveActor ) { return nullptr; };
	UActorMoveProxy* p = NewObject<UActorMoveProxy>(MoveActor);
	p->ProxyActorMoveTo(MoveActor,Des,Target,LinearSpeed,TurnSpeed,AcceptanceRadius,bTurnPitch,bTurnYaw,bTurnRoll);
	return p;
}

bool UFlibMovementEx::V_ActorSimpleMoveToDelegate(AActor* MoveActor, FVector Des, AActor* Target, const FActorSimpleMoveDlg& MoveEvent, float LinearSpeed, float TurnSpeed, float AcceptanceRadius /*= 5.0*/, bool bTurnPitch, bool bTurnYaw, bool bTurnRoll)
{
	if (!MoveActor) { return false; };
	UActorMoveProxy* p = NewObject<UActorMoveProxy>(MoveActor);
	p->ProxyActorMoveToDelegate(MoveActor, Des, Target, MoveEvent,LinearSpeed, TurnSpeed, AcceptanceRadius, bTurnPitch, bTurnYaw, bTurnRoll);
	return true;
}


UActorMoveProxy* UFlibMovementEx::V_ActorNavMoveTo(AActor* MoveActor, FVector Des, AActor* Target, float LinearSpeed, float TurnSpeed, float AcceptanceRadius /*= 5.0*/, float DynamicTargetDetectInterval /*= 2.0f*/, bool bDebug /*= false*/, bool bTurnPitch, bool bTurnYaw, bool bTurnRoll, bool bKeepLanded)
{
	if (!MoveActor) { return nullptr; };
	UActorMoveProxy* p = NewObject<UActorMoveProxy>(MoveActor);
	p->ProxyActorNavMoveTo(MoveActor, Des, Target, LinearSpeed, TurnSpeed, AcceptanceRadius, bDebug, bTurnPitch, bTurnYaw, bTurnRoll,bKeepLanded);
	return p;
}

