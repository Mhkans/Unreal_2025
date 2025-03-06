// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInvenUI.h"
#include "Components/UniformGridPanel.h"
#include "Components/Image.h"
void UMyInvenUI::NativeConstruct()
{
	Super::NativeConstruct();

	auto array = Grid->GetAllChildren();
	for (auto widget : array) {
		auto image = Cast<UImage>(widget);
		if (image) {
			_slotImages.Add(image);
		}
	}

	UE_LOG(LogTemp, Error, TEXT("Imgae Size : %d"), _slotImages.Num());

	_potionTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Graphics/UI/Items/Tex_seeds_06_b.Tex_seeds_06_b'"));
	_defaultTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Graphics/UI/Items/Tex_Default.Tex_Default'"));

	for (auto slot : _slotImages) {
		slot->SetBrushFromTexture(_defaultTexture);
	}
}

void UMyInvenUI::SetItem_Index(int32 index, FMyItemInfo info)
{
	if (info.itemId == -1 && info.type == MyItemType::NONE) {
		_slotImages[index]->SetBrushFromTexture(_defaultTexture);
	}
	if (info.itemId == 1 && info.type == MyItemType::POTION) {
		_slotImages[index]->SetBrushFromTexture(_potionTexture);
	}
}


