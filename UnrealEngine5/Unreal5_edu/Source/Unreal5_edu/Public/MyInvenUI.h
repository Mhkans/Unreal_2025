// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyItem.h"
#include "MyInvenUI.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL5_EDU_API UMyInvenUI : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	void SetItem_Index(int32 index, FMyItemInfo info);
	UPROPERTY(Editanywhere,BlueprintReadWrite,meta = (BindWidget))
	class UUniformGridPanel* Grid; //에디터와 이름이 일치해야함
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TArray<class UImage*> _slotImages;

	UPROPERTY()
	UTexture2D* _potionTexture;
	UTexture2D* _defaultTexture;
private:

};
