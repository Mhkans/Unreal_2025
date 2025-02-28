// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyStatComponent.generated.h"

USTRUCT() //블루프린트에서 쓸수있는 구조체
struct FMyStatData : public FTableRowBase {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 hp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 atk;

};

DECLARE_MULTICAST_DELEGATE_OneParam (FHpChanged,float);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL5_EDU_API UMyStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	int32 GetCurHp(){ return _curHp; }
	int32 GetAtk() { return _atk; }
	float GetSpeed() { return _moveSpeed; }

	int32 AddCurHp(float amount);

	bool IsDead() { return _curHp <= 0; }

	FHpChanged _hpChanged;
private:
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowprivateAccess = "true"))
	int32 _level = 1;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowprivateAccess = "true"))
	int32 _curHp = 100;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowprivateAccess = "true"))
	int32 _maxHp = 100;
	UPROPERTY(VisibleAnywhere, Category = "Stat", meta = (AllowprivateAccess = "true"))
	int32 _atk = 10;
	UPROPERTY(EditAnywhere, Category = "Stat", meta = (AllowprivateAccess = "true"))
	float _moveSpeed = 10.0f;

};
