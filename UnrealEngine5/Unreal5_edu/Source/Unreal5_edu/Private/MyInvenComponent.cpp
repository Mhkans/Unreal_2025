// Fill out your copyright notice in the Description page of Project Settings.

#include "MyItem.h"
#include "MyInvenComponent.h"

// Sets default values for this component's properties
UMyInvenComponent::UMyInvenComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	_items.SetNum(9); //resize()
}


// Called when the game starts
void UMyInvenComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyInvenComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int32 UMyInvenComponent::GetArraySize()
{
	int32 count = 0;
	for (auto item : _items) {
		if (item != nullptr) {
			count++;
		}
	}
	return count;
	
}

int32 UMyInvenComponent::EmptyIndex()
{
	int32 index = 0;
	for (auto item : _items) {
		if (item == nullptr) {
			break;
		}
		index++;
	}
	return index;
}



void UMyInvenComponent::AddItem(AMyItem* item)
{
	auto target = _items.FindByPredicate([](AMyItem* here) {
		return here == nullptr;
	});
	if (target == nullptr) {
		return;
	}
	int32 index = EmptyIndex();
	_items[index] = item;
	itemAddEvent.Broadcast(index, item->GetInfo());
}

AMyItem* UMyInvenComponent::DropItem()
{
	int32 plus = 0;
	for (int i = 0; i < GetArraySize(); i++) {
		if (_items[i] == nullptr) {
			plus++;
		}
	}
	int32 arrayIndex = GetArraySize() + plus -1;
	AMyItem* dropItem = _items[arrayIndex];
	_items[arrayIndex] = nullptr;
	itemDropEvent.Broadcast(arrayIndex);
	return dropItem;
}

AMyItem* UMyInvenComponent::DropItem(int32 index)
{
	AMyItem* dropItem = _items[index];
	_items[index] = nullptr;
	itemDropEvent.Broadcast(index);
	return dropItem;
}

