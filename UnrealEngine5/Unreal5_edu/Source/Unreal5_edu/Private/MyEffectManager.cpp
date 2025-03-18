// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEffect.h"
#include "MyEffectManager.h"
#include "NiagaraSystem.h"
#include "Particles/ParticleSystem.h"
// Sets default values
AMyEffectManager::AMyEffectManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	CreateEffect(TEXT("BigFire"), TEXT("/Script/Niagara.NiagaraSystem'/Game/Graphics/Effect/Vefects/Free_Fire/Shared/Particles/NS_Fire_Big_Simple.NS_Fire_Big_Simple'"));
	CreateEffect(TEXT("MeleeAttack"), TEXT("/ Script / Engine.ParticleSystem'/Game/ParagonSparrow/FX/Particles/Sparrow/Effects/P_Arrow_Poster_CPU.P_Arrow_Poster_CPU'"));
}

// Called when the game starts or when spawned
void AMyEffectManager::BeginPlay()
{
	Super::BeginPlay();
	for (auto particle : _particleTable) {
		FString name = particle.Key;
		_effectTable.Add(name);

		for (int i = 0; i < 5; i++) {

			auto effect = GetWorld()->SpawnActor<AMyEffect>(FVector::ZeroVector, FRotator::ZeroRotator);
			effect->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
			auto niagara = Cast<UNiagaraSystem>(_particleTable[name]);
			if (niagara) {

				effect->SetParticle(niagara);


			}
			else {
				effect->SetParticle(Cast<UParticleSystem>(_particleTable[name]));
			}
			effect->Stop();

			_effectTable[name]._effects.Add(effect);
		}
	}
}

// Called every frame
void AMyEffectManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyEffectManager::CreateEffect(FString key, FString path)
{
	ConstructorHelpers::FObjectFinder<UFXSystemAsset>particle(*path);
	if (particle.Succeeded()) {
		//_particleTable.Add(TEXT("BigFire")); //언리얼에서는 키값을 한번 넣어줘야한다
		//_particleTable[TEXT("BigFire")] = particle.Object;

		_particleTable.Add(key, particle.Object); //한번에 하는방법
	}
}

void AMyEffectManager::PlayEffect(FString key, FVector pos)
{
	auto effects = _effectTable.Find(key);
	if (effects == nullptr) {
		return;
	}
	auto Iter = effects->_effects.FindByPredicate([](AMyEffect* effect){

		return !effect->IsActive();
	});
	if (Iter) {
		(*Iter)->Play(pos);
	}
}

