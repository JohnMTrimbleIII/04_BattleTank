// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/UObjectGlobals.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
    void AimAt(FVector HitLocation);

    UFUNCTION(BlueprintCallable)
    void Fire();
    
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    UPROPERTY(BlueprintReadOnly)
    UTankAimingComponent *TankAimingComponent = nullptr;
    
    UPROPERTY(BlueprintReadOnly)
    UTankMovementComponent *TankMovementComponent = nullptr;

    
private:
    // Sets default values for this pawn's properties
    ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float LaunchSpeed = 10000.0f;
    
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float ReloadTimeInSeconds = 3.0f;
    
    float LastFireTime = 0.0f;
    
    
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint;
    
    UTankBarrel* Barrel = nullptr;
    


};
