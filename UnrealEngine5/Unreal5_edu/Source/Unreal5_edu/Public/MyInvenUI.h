// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyItem.h"
#include "MyInvenComponent.h"
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
	void SetItem_Default(int32 index);

	int32 GetArraySize();
	void AddItem(AMyItem* item) { return _myInvenComponent->AddItem(item); }
	AMyItem* DropItem();
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

	void SetComponenet(UMyInvenComponent* component) { _myInvenComponent = component; }
	UMyInvenComponent* GetComponent() { return _myInvenComponent; }
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta = (AllowprivateAccess = "true"))
	class UMyInvenComponent* _myInvenComponent;

};

