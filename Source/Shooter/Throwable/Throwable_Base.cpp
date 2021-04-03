// Fill out your copyright notice in the Description page of Project Settings.


#include "Throwable_Base.h"
//#include "Throwable/Throwable_Base.h"

// Sets default values
AThrowable_Base::AThrowable_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	NetUpdateFrequency = 10.0f;
	ThrowableMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = ThrowableMesh;
}

// Called when the game starts or when spawned
void AThrowable_Base::BeginPlay()
{
	Super::BeginPlay();
	
}



