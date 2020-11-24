// Fill out your copyright notice in the Description page of Project Settings.


#include "Proxy/RotateProxy.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"

void URotateProxy::Tick(float DeltaTime)
{
	if (m_RotateActor && bIsInit)
	{
		//UE_LOG(LogTemp, Log, TEXT("Rotation %s"), *currRot.ToString());
		//UE_LOG(LogTemp, Log, TEXT("Rotation %s"), *tarRot.ToString());
		currRot = UKismetMathLibrary::RInterpTo_Constant(currRot, tarRot, DeltaTime, fSpeed);
		m_RotateActor->SetActorRotation(currRot);
		
		if (UKismetMathLibrary::EqualEqual_RotatorRotator(currRot,tarRot,0.1))
		{
			OnRotateEnd.ExecuteIfBound();
			OnSuccess.Broadcast();
			Uninit();
			UE_LOG(LogTemp, Log, TEXT("Rotation FinishedFinished"));
			
		}
		
	}
}

bool URotateProxy::ProxyActorRotation(AActor* RotateActor, FRotator Rotation, float Speed /*= 90*/, bool bIsAdditive)
{
	if (Init() && RotateActor && Speed > 0)
	{
		m_RotateActor = RotateActor;
		currRot = m_RotateActor->GetActorRotation();
		fSpeed = Speed;	
		if (bIsAdditive)
		{
			tarRot.Roll = Rotation.Roll + currRot.Roll;
			tarRot.Pitch = Rotation.Pitch + currRot.Pitch;
			tarRot.Yaw = Rotation.Yaw + currRot.Yaw;
		}
		else
		{
			tarRot.Roll = Rotation.Roll;
			tarRot.Pitch = Rotation.Pitch;
			tarRot.Yaw = Rotation.Yaw;
		}
		return true;
	}
	return false;
}

bool URotateProxy::ProxyActorRotationDelegate(AActor* RotateActor, FRotator Rotation, const FActorSimpleRotateDlg& RotationEndEvent, float Speed /*= 90*/, bool bIsAdditive)
{
	if (Init() && RotateActor && Speed > 0)
	{
		m_RotateActor = RotateActor;
		currRot = m_RotateActor->GetActorRotation();
		OnRotateEnd = RotationEndEvent;
		fSpeed = Speed;
		if (bIsAdditive)
		{
			tarRot.Roll = Rotation.Roll + currRot.Roll;
			tarRot.Pitch = Rotation.Pitch + currRot.Pitch;
			tarRot.Yaw = Rotation.Yaw + currRot.Yaw;
		}
		else
		{
			tarRot.Roll = Rotation.Roll;
			tarRot.Pitch = Rotation.Pitch;
			tarRot.Yaw = Rotation.Yaw;
		}
		return true;
	}
	return false;
}

bool URotateProxy::Init()
{
	if (!bIsInit)
	{
		bIsInit = true;
		return true;
	}
	return false;
}

void URotateProxy::Uninit()
{
	bIsInit = false;
}
