// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_Base_CPP.h"

// Sets default values
AWeapon_Base_CPP::AWeapon_Base_CPP()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	RedDot = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RedDot"));
	RedDot->AttachToComponent(Weapon, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("ScopePlacement"));
}

// Called when the game starts or when spawned
void AWeapon_Base_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}


