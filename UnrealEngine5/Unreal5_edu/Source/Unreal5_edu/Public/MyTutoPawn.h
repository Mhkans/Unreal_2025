// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTutoPawn.generated.h"

class UInputAction;
struct FInputActionValue;
UCLASS()
class UNREAL5_EDU_API AMyTutoPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTutoPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//c++클래스는 객체가 아니라 클래스
	//언리얼의 고유 클래스들은 UObject를 상속받아서 만들어진다.
	//모든 블루프린트는 C++클래스를 상속받아서 만들어진다.

	//함수에도 리플렉션 
	UFUNCTION(BlueprintCallable)
	void Temp();

	void Move(const FInputActionValue& value);
private:
	UPROPERTY(VisibleAnyWhere,Category ="Mesh") //매쉬 정보는 변경할수있는데 없애는건 불가능
	UStaticMeshComponent* _mesh;

	UPROPERTY(EditAnywhere,Category = "Speed")
	float _moveSpeed = 10.0f;
	UPROPERTY(EditAnywhere, Category = "Speed")
	float _rotationSpeed = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowprivateAccess = "true"))
	UInputAction* _moveAction;
};
