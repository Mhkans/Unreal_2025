// Fill out your copyright notice in the Description page of Project Settings.


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
		if (item.itemId != -1 && item.type != MyItemType::NONE) {
			count++;
		}
	}
	return count;
	
}



void UMyInvenComponent::AddItem(int32 itemID, MyItemType type)
{
	FMyItemInfo Addinfo;
	Addinfo.itemId = itemID;
	Addinfo.type = type;

	auto target = _items.FindByPredicate([](FMyItemInfo info) {
		return info.itemId == -1 && info.type == MyItemType::NONE;
	});
	if (target == nullptr) {
		return;
	}

	*target = Addinfo;
	int64 targetIndex = 0;

	int64 temp1 = (int64)target;
	int64 temp2 = (int64)(& _items[0]);
	targetIndex = (temp1 - temp2) / sizeof(int64);
	itemAddEvent.Broadcast(targetIndex,*target);
}

FMyItemInfo UMyInvenComponent::DropItem()
{
	int32 arrayIndex = GetArraySize()-1;
	auto temp = _items[arrayIndex];
	FMyItemInfo defaultInfo;
	_items[arrayIndex] = defaultInfo;
	itemDropEvent.Broadcast(arrayIndex, defaultInfo);
	return temp;
}

FMyItemInfo UMyInvenComponent::DropItem(int32 index)
{
	auto temp = _items[index];	
	FMyItemInfo defaultInfo;
	_items[index] = defaultInfo;
	itemDropEvent.Broadcast(index, defaultInfo);
	return temp;
}

