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
	virtual bool Initialize() override;
	virtual void NativeConstruct() override;
	void SetItem_Index(int32 index, FMyItemInfo info);

	UPROPERTY(Editanywhere,BlueprintReadWrite,meta = (BindWidget))
	class UUniformGridPanel* Grid; //에디터와 이름이 일치해야함
	UPROPERTY(Editanywhere, BlueprintReadWrite, meta = (BindWidget))
	class UButton* Drop;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TArray<class UImage*> _slotImages;
	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TArray<class UButton*> _slotButtons;
	UPROPERTY()
	UTexture2D* _potionTexture;
	UTexture2D* _defaultTexture;

	int32 _curIndex = -1;
private:

};
/*
버튼을 클릭하면 void void 함수포인터 불러와야함

버튼의 인덱스를 아는방법 
각버튼의 인덱스 = 배열의 인덱스

*/
