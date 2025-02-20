// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTutoPawn.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
AMyTutoPawn::AMyTutoPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = _mesh;
	//생성자에서 해당 경로의 메쉬 오브젝트를 갖고오는 방법
	static ConstructorHelpers::FObjectFinder<UStaticMesh> sm(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Chair.SM_Chair'"));
	if (sm.Succeeded()) {
		_mesh->SetStaticMesh(sm.Object);
	}
	UE_LOG(LogTemp, Warning, TEXT("CONSTRUCTOR"));
}

// Called when the game starts or when spawned
void AMyTutoPawn::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("BEGIN"));

}

// Called every frame
void AMyTutoPawn::Tick(float DeltaTime) //deltaTime : 1번 업데이트에 걸리는 시간
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Error, TEXT("DeltaTime : %f"), DeltaTime);

	//DeltaTime = 1번 업데이트하는데 걸리는 시간
	if (GetAttachParentActor() == nullptr) {
		FVector curLocation = GetActorLocation(); //현재위치 받기
		FVector destLocation = curLocation + FVector(_moveSpeed, 0, 0) * DeltaTime;
		SetActorLocation(destLocation);

		FRotator rot = FRotator(0, 1, 0);
		AddActorLocalRotation(rot * _rotationSpeed * DeltaTime);
	}
	else {
		FVector parentV = GetAttachParentActor()->GetActorLocation();
		FVector myV = GetActorLocation();//월드 로케이션

		FRotator rot = UKismetMathLibrary::FindLookAtRotation(myV, parentV);
		SetActorRotation(rot);
	}
	
	
}

// Called to bind functionality to input
void AMyTutoPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

