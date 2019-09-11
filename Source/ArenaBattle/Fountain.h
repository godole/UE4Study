// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Actor.h"
#include "GameFrameWork/RotatingMovementComponent.h"
#include "Fountain.generated.h"


UCLASS()
class ARENABATTLE_API AFountain : public AActor
{
	GENERATED_BODY() // 클래스를 언리얼 엔진에서 쓸 수 있도록 환경을 갖춰주는 함수
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		UStaticMeshComponent* Body;

	UPROPERTY()
		UStaticMeshComponent* Water;

	UPROPERTY()
		UStaticMeshComponent* Light;

	UPROPERTY()
		UParticleSystemComponent* Splash;
private:
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	float RotateSpeed;

	UPROPERTY(VisibleAnywhere)
	URotatingMovementComponent* Movement;
};