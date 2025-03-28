// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProjectile.h"
#include "Components/MeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "MyEnemy.h"
#include "MyCharacter.h"
#include "MyPlayer.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/DamageEvents.h"
// Sets default values
AMyProjectile::AMyProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	_collider = CreateDefaultSubobject<UCapsuleComponent>("ColliderComponent");
	_movementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");

	RootComponent = _collider;

	_mesh->SetupAttachment(_collider);
}

// Called when the game starts or when spawned
void AMyProjectile::BeginPlay()
{
	Super::BeginPlay();
	_collider->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnOverlap);
}

// Called every frame
void AMyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator curRot = GetActorRotation();

	curRot.Pitch += DeltaTime * 200.0f;
	
	SetActorRotation(curRot);
}

void AMyProjectile::FireDirection(const FVector& direction)
{
	_movementComponent->Velocity = direction * _movementComponent->InitialSpeed;
}

void AMyProjectile::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (_owner == nullptr) {
		return;
	}
	if (OtherActor->GetName() == _owner->GetName())
		return;

	auto victim = Cast<AMyCharacter>(OtherActor);
	if (victim)
	{
		FDamageEvent dEvent;
		victim->TakeDamage(50, dEvent, _owner->GetController(), _owner);

		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
	}
}


void AMyProjectile::SetOwner(AMyCharacter* owner)
{
	if (owner == nullptr)
	{
		_owner = nullptr;
		return;
	}

	_owner = owner;
}


