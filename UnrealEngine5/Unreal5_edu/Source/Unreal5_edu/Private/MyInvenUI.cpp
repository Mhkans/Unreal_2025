// Fill out your copyright notice in the Description page of Project Settings.


#include "MyInvenUI.h"
#include "MyButton.h"
#include "MyInvenComponent.h"
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
		button->_curIndex = index;
		button->widget = this;
		index++;
		_slotButtons.Add(button);
		if (button) {
			auto image = Cast<UImage>(button->GetChildAt(0));
			if (image) {
				_slotImages.Add(image);
			}
			button->OnClicked.AddDynamic(button, &UMyButton::SetCurIndex);
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
	if (info.itemId == 1 && info.type == MyItemType::POTION) {
		_slotImages[index]->SetBrushFromTexture(_potionTexture);
	}
}

void UMyInvenUI::SetItem_Default(int32 index)
{
	_slotImages[index]->SetBrushFromTexture(_defaultTexture);
}

int32 UMyInvenUI::GetArraySize()
{
	return _myInvenComponent->GetArraySize();
}

AMyItem* UMyInvenUI::DropItem()
{
	if (_curIndex != -1) {
		//특정 인덱스를 누른 경우
		int32 temp = _curIndex;
		_curIndex = -1;
		return _myInvenComponent->DropItem(temp);		
	}
	else {
		return _myInvenComponent->DropItem();
	}
	
}

