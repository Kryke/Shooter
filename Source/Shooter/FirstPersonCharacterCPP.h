// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FirstPersonCharacterCPP.generated.h"

UCLASS()
class SHOOTER_API AFirstPersonCharacterCPP : public ACharacter
{
	GENERATED_BODY()

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MyCharacter, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* SkeletalMesh;

	
	
public:
	// Sets default values for this character's properties
	AFirstPersonCharacterCPP();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RateOfFire = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UParticleSystem* MuzzleParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UParticleSystem* ImpactParticles;

	FTimerHandle TimerHandle_HandleRefire;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void StartFire();

	void StopFire();

	void FireShot();

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
