// Fill out your copyright notice in the Description page of Project Settings.


#include "playerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
AplayerCharacter::AplayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true; // ��� ��ŸƮ ���� ����ǰ� ��

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f); //ĳ���� Ŭ������ �ִ� �⺻ �ݶ��̴��� �����ͼ� ĸ���ݶ��̴� �Լ��� ũ�⸦ ���Ѵ�.

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false; //ĳ���Ͱ� ī�޶��� ȸ���� ������ �ʰ� false�� ���� true�� ĳ���Ͱ� ī�޶� ����
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f); //ĳ���Ͱ� �ٶ󺸴� ����� �̵������� �ٸ��� �ش� �������� ĳ���Ͱ� ȸ���ϰ� �� ȸ�� �ӵ��� ������
	GetCharacterMovement()->bConstrainToPlane = true; //ĳ������ �̵��� ������� ��ȯ
	GetCharacterMovement()->bSnapToPlaneAtStart = true; //ĳ���ͻ����� ��ġ�� ����� ����� �ֺ� ��鿡�� ����

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm")); //�������� ���� �ʱ�ȭ
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetUsingAbsoluteRotation(true); //������ ���� ȸ���� ��Ʈ ������Ʈ�� ���� ������Ʈ�� ȸ���� ������ �ʰ� ���� ��ǥ���� ȸ���� ������ ��
	SpringArmComponent->TargetArmLength = 800.0f; //ī�޶�� ĳ������ �Ÿ� 
	SpringArmComponent->SetRelativeRotation(FRotator(-100.0f, 0.0f, 0.0f)); //������ ���� ȸ������ ĳ���͸� ������ ������
	SpringArmComponent->bDoCollisionTest = false; //ī�޶� ���� ������ �浹 ����� ���� ī�޶�� ĳ������ �Ÿ��� ������ �Լ� ž�ٿ��� �ش� x�̹Ƿ� false

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera")); //ī�޶� ������Ʈ ����
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName); //ī�޶� ������Ʈ�� ������ �� ������Ʈ�� ���̱�
	CameraComponent->bUsePawnControlRotation = false; //ī�޶��� ȸ���� ���� ȸ���� ������ ���� �ʰ���
}

// Called when the game starts or when spawned
void AplayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	FVector StartLocation(-1432.0f, 447.0f, 143.0f);
	//(X = -1432.285866, Y = 447.066897, Z = 143.396009)
	SetActorLocation(StartLocation);

}

// Called every frame
void AplayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AplayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AplayerCharacter::setCameraArmLength(float length)
{
	SpringArmComponent->TargetArmLength = length;
			
}
