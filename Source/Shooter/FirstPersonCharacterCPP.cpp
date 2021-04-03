// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacterCPP.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFirstPersonCharacterCPP::AFirstPersonCharacterCPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(GetCapsuleComponent());


	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(SkeletalMesh);
	

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(SkeletalMesh);	
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
	FirstPersonCameraComponent->bLockToHmd = false;
	FirstPersonCameraComponent->SetFieldOfView(103.0f);
	//FirstPersonCameraComponent->SetRelativeLocation(FVector(-10f, 1.75f, 64.f)); 
	//FirstPersonCameraComponent->SetRelativeRotation(FRotator(90.0f, 0.0f, -90.0f));

	
}

// Called when the game starts or when spawned
void AFirstPersonCharacterCPP::BeginPlay()
{
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	Weapon->AttachToComponent(SkeletalMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("hand_rSocket"));
	FirstPersonCameraComponent->AttachToComponent(SkeletalMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("head"));
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.0f, 20.0f, 0));
}

void AFirstPersonCharacterCPP::StartFire()
{
	FireShot();

	GetWorldTimerManager().SetTimer(TimerHandle_HandleRefire, this, &AFirstPersonCharacterCPP::FireShot, RateOfFire, true);
}

void AFirstPersonCharacterCPP::StopFire()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_HandleRefire);
}

void AFirstPersonCharacterCPP::FireShot()
{
	FHitResult Hit;

	const float FiringRange = 8000.0f;
	const FVector StartTrace = FirstPersonCameraComponent->GetComponentLocation();
	const FVector EndTrace = FirstPersonCameraComponent->GetForwardVector() * FiringRange + StartTrace;

	FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WeaponTrace), false, this);

	if (GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams))
	{
		if (ImpactParticles)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, FTransform(Hit.ImpactNormal.Rotation(), Hit.ImpactPoint));
		}
	}

	if (MuzzleParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleParticles, Weapon->GetSocketTransform(FName("Muzzle")));
	}
}


// Called to bind functionality to input
void AFirstPersonCharacterCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFirstPersonCharacterCPP::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AFirstPersonCharacterCPP::StopFire);

}

