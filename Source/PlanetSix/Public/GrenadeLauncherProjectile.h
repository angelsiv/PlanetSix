// This work is the sole property of 2Pow6 Games.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrenadeLauncherProjectile.generated.h"

UCLASS()
class PLANETSIX_API AGrenadeLauncherProjectile : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	class USphereComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "FX")
	class UParticleSystem* ExplosionParticles;

	UPROPERTY(EditAnywhere, Category = "FX")
	class USoundCue* ExplosionSound;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	float Radius = 500.f;
	
public:	
	AGrenadeLauncherProjectile();

	UFUNCTION()
	void OnDetonate();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }
	
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
