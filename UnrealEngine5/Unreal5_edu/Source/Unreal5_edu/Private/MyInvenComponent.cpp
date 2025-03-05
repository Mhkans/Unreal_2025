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

void UMyInvenComponent::AddItem(int32 itemID, MyItemType type)
{
	FMyItemInfo Addinfo;
	Addinfo.itemId = itemID;
	Addinfo.type = type;

	FMyItemInfo temp;
	auto target = _items.FindByPredicate([temp](FMyItemInfo info) {
		return temp.itemId == info.itemId && temp.type == info.type;
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
	return FMyItemInfo();
}

FMyItemInfo UMyInvenComponent::DropItem(int32 index)
{
	return FMyItemInfo();
}

