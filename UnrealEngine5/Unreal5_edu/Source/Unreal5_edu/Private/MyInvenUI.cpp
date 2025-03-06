// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInvenUI.h"
#include "MyButton.h"
#include "Components/UniformGridPanel.h"
#include "Components/Button.h"
#include "Components/Image.h"
bool UMyInvenUI::Initialize()
{
	Super::Initialize();

	_potionTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Graphics/UI/Items/Tex_seeds_06.Tex_seeds_06'"));
	_defaultTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Script/Engine.Texture2D'/Game/Graphics/UI/Items/Tex_Default.Tex_Default'"));

	int32 index = 0;
	auto array = Grid->GetAllChildren();
	for (auto widget : array) {
		auto button = Cast<UMyButton>(widget);
		/*button->widget = this;
		button->_curIndex = index;
		index++;*/
		if (button) {
			auto image = Cast<UImage>(button->GetChildAt(0));
			if (image) {
				_slotImages.Add(image);
			}
		}
	}

	if (_slotImages.Num() <= 0) {
		return false;
	}
	return true;
}
void UMyInvenUI::NativeConstruct()
{
	Super::NativeConstruct();

	
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

