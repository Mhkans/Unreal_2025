// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

UENUM()
enum class MyItemType {

	NONE,POTION
};
USTRUCT(BlueprintType)
struct FMyItemInfo {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 itemId = -1;
	UPROPERTY(EditAnywhere)
	MyItemType type = MyItemType::NONE;
	
};

UCLASS()
class UNREAL5_EDU_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();

protected:
	// Called when the game starts or when spawned
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);
	const FMyItemInfo& GetInfo() { return _info; }
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowprivateAccess = "true"))
	int32 _healValue = 15;

	UPROPERTY(EditAnywhere, Category = "Collider")
	class UCapsuleComponent* _collider;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	class UStaticMeshComponent* _mesh;

	UPROPERTY(EditAnywhere, Category = "ItemInfo")
	FMyItemInfo _info;
};
