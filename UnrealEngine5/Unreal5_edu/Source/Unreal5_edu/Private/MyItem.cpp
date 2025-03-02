// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItem.h"
#include "Components/CapsuleComponent.h"
#include "MyCharacter.h"
#include "MyStatComponent.h"
#include "MyPlayerController.h"
#include "MyPlayer.h"
// Sets default values
AMyItem::AMyItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	_collider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	_mesh->SetupAttachment(_collider);
	RootComponent = _collider;
}

void AMyItem::PostInitializeComponents() //생성이 다 끝난 후
{
	Super::PostInitializeComponents();
	_collider->OnComponentBeginOverlap.AddDynamic(this, &AMyItem::OnMyCharacterOverlap);

}

// Called when the game starts or when spawned
void AMyItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMyItem::OnMyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto character = Cast<AMyPlayer>(OtherActor);
	auto player = Cast<AMyPlayerController>(character->GetController());
	if (character != nullptr &&player != nullptr ) {
		character->AddHp(_healValue);
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
	}
}

