// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"


UCLASS()
class ARENABATTLE_API AFountain : public AActor
{
	GENERATED_BODY() // Ŭ������ �𸮾� �������� �� �� �ֵ��� ȯ���� �����ִ� �Լ�
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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
};