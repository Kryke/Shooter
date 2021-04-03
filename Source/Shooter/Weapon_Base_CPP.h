// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Sound/SoundWave.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon_Base_CPP.generated.h"


UCLASS()
class SHOOTER_API AWeapon_Base_CPP : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scope", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* RedDot;
	
	
public:	
	// Sets default values for this actor's properties
	AWeapon_Base_CPP();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RateOfFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BaseDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float NonScopeRecoilMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 MagazineSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 AmmoDiff;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 MaxAmmoCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class USoundWave*	Gunshotsound;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
