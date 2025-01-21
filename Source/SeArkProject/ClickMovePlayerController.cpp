// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickMovePlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "../../../../Plugins/FX/Niagara/Source/Niagara/Public/NiagaraFunctionLibrary.h"


AClickMovePlayerController::AClickMovePlayerController()
{
	bShowMouseCursor = true; //마우스 보이게 하기

	ConstructorHelpers::FObjectFinder<UNiagaraSystem> TempNiagaraSystem(TEXT("NiagaraSystem'/Game/LHW/TrackMarker/Niagara/NotLooping/TrackMarker/NS_Icon_TrackMarker.NS_Icon_TrackMarker'"));

	if (TempNiagaraSystem.Succeeded())
	{
		NiagaraSystem = TempNiagaraSystem.Object;
	}
}

void AClickMovePlayerController::BeginPlay()
{
	Super::BeginPlay();
}


void AClickMovePlayerController::InputRightMouseButtonPressed()
{
	bClickRightMouse = true;

}

void AClickMovePlayerController::InputRightMouseButtonReleased()
{
	bClickRightMouse = false;

}



void AClickMovePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAction("RightClick", IE_Pressed, this, &AClickMovePlayerController::InputRightMouseButtonPressed);
	InputComponent->BindAction("RightClick", IE_Pressed, this, &AClickMovePlayerController::SpawnNiagara);
	InputComponent->BindAction("RightClick", IE_Released, this, &AClickMovePlayerController::InputRightMouseButtonReleased);
}
void AClickMovePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (bClickRightMouse) {
		MoveToMouseCursor();
	}

}

void AClickMovePlayerController::SetNewDestination(const FVector Destination)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn) {
		float const Distance = FVector::Dist(Destination, MyPawn->GetNavAgentLocation());
		if (Distance > 120.0f) {
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Destination);
		}
	}
}
void AClickMovePlayerController::SpawnNiagara()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit) {
		NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			GetWorld(), NiagaraSystem, Hit.ImpactPoint, FRotator::ZeroRotator, FVector(1.0f), true, true);
	}

}

void AClickMovePlayerController::MoveToMouseCursor()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit) {
		SetNewDestination(Hit.ImpactPoint);
	}

}
