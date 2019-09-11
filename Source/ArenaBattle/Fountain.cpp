// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"

// Sets default values
AFountain::AFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));
	Light = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LIGHT"));
	Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SPLASH"));

	//StaticMesh'/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01'
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01"));

	if(SM_Body.Succeeded())
		Body->SetStaticMesh(SM_Body.Object);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Water(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Meshes/Env/SM_Plains_Fountain_02"));

	if (SM_Water.Succeeded())
		Water->SetStaticMesh(SM_Water.Object);

	//ParticleSystem'/Game/InfinityBladeGrassLands/Effects/FX_Ambient/Water/P_Water_Fountain_Splash_Base_01.P_Water_Fountain_Splash_Base_01'

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PS_Splash(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Ambient/Water/P_Water_Fountain_Splash_Base_01.P_Water_Fountain_Splash_Base_01"));

	if (PS_Splash.Succeeded())
		Splash->SetTemplate(PS_Splash.Object);

	RootComponent = Body;
	Water->SetupAttachment(Body);
	Light->SetupAttachment(Body);
	Splash->SetupAttachment(Body);

	Water->SetRelativeLocation(FVector(0.0f, 0.0f, 135.0f));
	Light->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));
	Splash->SetRelativeLocation(FVector(0.0f, 0.0f, 195.0f));


}

// Called when the game starts or when spawned
void AFountain::BeginPlay() //유니티 start
{
	Super::BeginPlay();

	UE_LOG(ArenaBattle, Warning, TEXT("Actor Name : %s"), *GetName());
}

// Called every frame
void AFountain::Tick(float DeltaTime) // 유니티 update
{
	Super::Tick(DeltaTime);

}

