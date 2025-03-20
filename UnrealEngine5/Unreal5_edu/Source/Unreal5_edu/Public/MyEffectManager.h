// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyEffect.h"

#include "MyEffectManager.generated.h"

USTRUCT()
struct FEffects {
	GENERATED_BODY()

	UPROPERTY()
	TArray<class AMyEffect*> _effects;
};

UCLASS()
class UNREAL5_EDU_API AMyEffectManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyEffectManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void PlayEffect(FString key, FVector pos);

 private:
	void CreateEffect(FString key, FString path);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TMap < FString, class UFXSystemAsset* > _particleTable; //UFXSystemAsset ->파티클시스템과 나이아가라 모두 사용가능하게
	UPROPERTY()
	TMap<FString, FEffects> _effectTable;
};
