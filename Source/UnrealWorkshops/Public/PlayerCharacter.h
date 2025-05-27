// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class UNREALWORKSHOPS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, Category = "Health");
	float HP{};

	UFUNCTION(BlueprintCallable)
	void PrintHealth();

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent *CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent *FollowCamera;

	void Move(const FInputActionValue &Value);
	void Look(const FInputActionValue &Value);

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext *DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction *MovementAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction *LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction *JumpAction;
};
