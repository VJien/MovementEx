// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Proxy/MoveProxy.h"
#include "Proxy/ActorMoveProxy.h"
#include "Proxy/PathMoveProxy.h"


#include "MovementExBPLibrary.generated.h"







UCLASS()
class UFlibMovementEx : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()


	/*
	* AI MoveTo 函数版, 回调事件通过动态代理返回
	* * Target优先于Des
	*/
	UFUNCTION(BlueprintCallable, Category = "Tomb | MovementEx", meta = (AdvancedDisplay = 5))
		static bool V_AIMoveToDelegate(APawn* Pawn, FVector Des, AActor* Target, const FMoveSimpleDelegate& MoveEndEvent, float AcceptanceRadius = 5.0, bool StopOnOverlap = false);
	/*
	* AI MoveTo 函数版, 回调事件通过绑定返回的Obj手动绑定
	* * Target优先于Des
	*/
	UFUNCTION(BlueprintCallable, Category = "Tomb | MovementEx", meta = (AdvancedDisplay = 5))
		static UMoveProxy* V_AIMoveTo(APawn* Pawn, FVector Des, AActor* Target, float AcceptanceRadius = 5.0, bool StopOnOverlap = false);

	/*
	* 路径版本AI MoveTo, 回调事件通过动态代理返回
	* * Target优先于Des
	*/
	UFUNCTION(BlueprintCallable, Category = "Tomb | MovementEx", meta = (AdvancedDisplay = 5))
		static bool V_AIPathMoveToDelegate(APawn* Pawn, TArray<FVector> DesPath, const FPathMoveDelegate& MoveEndEvent, const FPathMoveDelegate2& MoveOneStepEvent, float AcceptanceRadius = 5.0, bool StopOnOverlap = false);

	/*
	* 路径点集 MoveTo, 回调事件通过动态代理返回
	* Target优先于Des
	*/
	UFUNCTION(BlueprintCallable, Category = "Tomb | MovementEx")
		static UPathMoveProxy* V_AIPathMoveTo(APawn* Pawn, TArray<FVector> DesPath, float AcceptanceRadius = 5.0, bool StopOnOverlap = false);

	
	/*
	* Actor版本的 MoveTo, 回调事件通过绑定返回的Obj手动绑定
	* Target优先于Des
	* TurnSpeed: 转身速度,<=0 意味着不会转身
	*/
	UFUNCTION(BlueprintCallable, Category = "Tomb | MovementEx", meta = (AdvancedDisplay = 5))
		static	UActorMoveProxy* V_ActorSimpleMoveTo(AActor* MoveActor, FVector Des, AActor* Target, float LinearSpeed = 300, float TurnSpeed = 90, float AcceptanceRadius = 5.0, bool bTurnPitch = true, bool bTurnYaw = true, bool bTurnRoll = true);

	/*
	* Actor版本的 MoveTo, 回调事件通过动态代理返回
	* Target优先于Des
	* TurnSpeed: 转身速度,<=0 意味着不会转身
	*/
	UFUNCTION(BlueprintCallable, Category = "Tomb | MovementEx", meta = (AdvancedDisplay = 6))
		static	bool V_ActorSimpleMoveToDelegate(AActor* MoveActor, FVector Des, AActor* Target, const FActorSimpleMoveDlg& MoveEvent, float LinearSpeed = 300, float TurnSpeed = 90, float AcceptanceRadius = 5.0, bool bTurnPitch = true, bool bTurnYaw = true, bool bTurnRoll = true);

	/*
	* Actor版本的 MoveTo, 回调事件通过绑定返回的Obj手动绑定
	* Target优先于Des
	* 如果传入有效的Target类,那么DynamicTargetDetectInterval参数将生效
	* DynamicTargetDetectInterval:动态检测间隔
	* TurnSpeed: 转身速度,<=0 意味着不会转身
	*/
	UFUNCTION(BlueprintCallable, Category = "Tomb | MovementEx", meta = (AdvancedDisplay = 5))
		static	UActorMoveProxy* V_ActorNavMoveTo(AActor* MoveActor, FVector Des, AActor* Target, float LinearSpeed = 300, float TurnSpeed = 90, float AcceptanceRadius = 5.0, float DynamicTargetDetectInterval = 2.0f, bool bDebug = false, bool bTurnPitch = true, bool bTurnYaw = true, bool bTurnRoll = true);

};
