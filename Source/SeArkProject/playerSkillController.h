// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "playerSkillController.generated.h"

/**
 * 
 */
UCLASS()
class SEARKPROJECT_API AplayerSkillController : public APlayerController
{
	GENERATED_BODY()

public:
	AplayerSkillController();

protected:

    // �Է� ó�� �Լ���
    void OnQPressed();
    void OnWPressed();
    void OnEPressed();
    void OnRPressed();
    void OnAPressed();
    void OnSPressed();
    void OnDPressed();
    void OnFPressed();
    void OnVPressed();

    void OnQReleased();
    void OnWReleased();
    void OnEReleased();
    void OnRReleased();
    void OnAReleased();
    void OnSReleased();
    void OnDReleased();
    void OnFReleased();
    void OnVReleased();

    // ��ų �ߵ� �Լ�
    void UseSkill(int32 SkillID);
    void StopSkill(int32 SkillID);

    virtual void SetupInputComponent() override;

protected:
    virtual void BeginPlay() override;

private:
    // �Է¿� ���� ��ų �ߵ� �� ����
    void OnSkillPressed(int32 SkillID);
    void OnSkillReleased(int32 SkillID);

};
