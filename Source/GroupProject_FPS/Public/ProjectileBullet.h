// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBullet.generated.h"


UCLASS()
class GROUPPROJECT_FPS_API AProjectileBullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectileBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Function called when the Bullet hits something.
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	//Bullet collision component.
	UPROPERTY(VisibleDefaultsOnly, Category = "Bullet Projectile")
	USphereComponent* CollisionComponent;

	//Bullet fbx
	UPROPERTY(VisibleDefaultsOnly, Category = "Bullet Projectile")
	UStaticMeshComponent* ProjectileMeshComponent;

	//Bullet movement component.
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	UProjectileMovementComponent* ProjectileMovementComponent;

	//Bullet material
	UPROPERTY(VisibleDefaultsOnly, Category = "Movement")
	UMaterialInstanceDynamic* ProjectileMaterialInstance;

	//Function initializes Bullet's velocity in shot direction
	void FireInDirection(const FVector& ShootDirection);
};
