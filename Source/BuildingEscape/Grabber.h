// Copyright Jeff Polasz 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	float Reach = 100.0f; // How far the player can reach in cm
	UPhysicsHandleComponent* PhysicsHandle = nullptr; // Points to memory address 0
	UInputComponent* InputComponent = nullptr;

	// Raycast and grab what is in reach
	void Grab();

	// Called when grab is released
	void Release();

	// Find assumed attached Physics Handle
	void FindPhysicsHandleComponent();

	// Setup assumed attached Input Component
	void SetupInputComponent();

	// Return hit for first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;

	// Returns start of reach line
	FVector GetReachLineStart() const;

	// Returns end of reach line
	FVector GetReachLineEnd() const;
};
