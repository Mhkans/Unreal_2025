// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal5_edu/Public/MyItem.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyItem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
UNREAL5_EDU_API UClass* Z_Construct_UClass_AMyItem();
UNREAL5_EDU_API UClass* Z_Construct_UClass_AMyItem_NoRegister();
UNREAL5_EDU_API UEnum* Z_Construct_UEnum_Unreal5_edu_MyItemType();
UNREAL5_EDU_API UScriptStruct* Z_Construct_UScriptStruct_FMyItemInfo();
UPackage* Z_Construct_UPackage__Script_Unreal5_edu();
// End Cross Module References

// Begin Enum MyItemType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_MyItemType;
static UEnum* MyItemType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_MyItemType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_MyItemType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Unreal5_edu_MyItemType, (UObject*)Z_Construct_UPackage__Script_Unreal5_edu(), TEXT("MyItemType"));
	}
	return Z_Registration_Info_UEnum_MyItemType.OuterSingleton;
}
template<> UNREAL5_EDU_API UEnum* StaticEnum<MyItemType>()
{
	return MyItemType_StaticEnum();
}
struct Z_Construct_UEnum_Unreal5_edu_MyItemType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyItem.h" },
		{ "NONE.Name", "MyItemType::NONE" },
		{ "POTION.Name", "MyItemType::POTION" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "MyItemType::NONE", (int64)MyItemType::NONE },
		{ "MyItemType::POTION", (int64)MyItemType::POTION },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Unreal5_edu_MyItemType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Unreal5_edu,
	nullptr,
	"MyItemType",
	"MyItemType",
	Z_Construct_UEnum_Unreal5_edu_MyItemType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Unreal5_edu_MyItemType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Unreal5_edu_MyItemType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Unreal5_edu_MyItemType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Unreal5_edu_MyItemType()
{
	if (!Z_Registration_Info_UEnum_MyItemType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_MyItemType.InnerSingleton, Z_Construct_UEnum_Unreal5_edu_MyItemType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_MyItemType.InnerSingleton;
}
// End Enum MyItemType

// Begin ScriptStruct FMyItemInfo
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MyItemInfo;
class UScriptStruct* FMyItemInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MyItemInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MyItemInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMyItemInfo, (UObject*)Z_Construct_UPackage__Script_Unreal5_edu(), TEXT("MyItemInfo"));
	}
	return Z_Registration_Info_UScriptStruct_MyItemInfo.OuterSingleton;
}
template<> UNREAL5_EDU_API UScriptStruct* StaticStruct<FMyItemInfo>()
{
	return FMyItemInfo::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMyItemInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MyItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_itemId_MetaData[] = {
		{ "Category", "MyItemInfo" },
		{ "ModuleRelativePath", "Public/MyItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_type_MetaData[] = {
		{ "Category", "MyItemInfo" },
		{ "ModuleRelativePath", "Public/MyItem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_itemId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_type;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMyItemInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyItemInfo_Statics::NewProp_itemId = { "itemId", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyItemInfo, itemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_itemId_MetaData), NewProp_itemId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyItemInfo_Statics::NewProp_type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMyItemInfo_Statics::NewProp_type = { "type", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyItemInfo, type), Z_Construct_UEnum_Unreal5_edu_MyItemType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_type_MetaData), NewProp_type_MetaData) }; // 1520939960
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMyItemInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyItemInfo_Statics::NewProp_itemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyItemInfo_Statics::NewProp_type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyItemInfo_Statics::NewProp_type,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyItemInfo_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMyItemInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Unreal5_edu,
	nullptr,
	&NewStructOps,
	"MyItemInfo",
	Z_Construct_UScriptStruct_FMyItemInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyItemInfo_Statics::PropPointers),
	sizeof(FMyItemInfo),
	alignof(FMyItemInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyItemInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMyItemInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMyItemInfo()
{
	if (!Z_Registration_Info_UScriptStruct_MyItemInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MyItemInfo.InnerSingleton, Z_Construct_UScriptStruct_FMyItemInfo_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MyItemInfo.InnerSingleton;
}
// End ScriptStruct FMyItemInfo

// Begin Class AMyItem Function OnOverlap
struct Z_Construct_UFunction_AMyItem_OnOverlap_Statics
{
	struct MyItem_eventOnOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MyItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyItem_eventOnOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyItem_eventOnOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyItem_eventOnOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyItem_eventOnOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((MyItem_eventOnOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MyItem_eventOnOverlap_Parms), &Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyItem_eventOnOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyItem_OnOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyItem_OnOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyItem_OnOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyItem_OnOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyItem, nullptr, "OnOverlap", nullptr, nullptr, Z_Construct_UFunction_AMyItem_OnOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyItem_OnOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMyItem_OnOverlap_Statics::MyItem_eventOnOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyItem_OnOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyItem_OnOverlap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMyItem_OnOverlap_Statics::MyItem_eventOnOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyItem_OnOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyItem_OnOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyItem::execOnOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// End Class AMyItem Function OnOverlap

// Begin Class AMyItem
void AMyItem::StaticRegisterNativesAMyItem()
{
	UClass* Class = AMyItem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnOverlap", &AMyItem::execOnOverlap },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyItem);
UClass* Z_Construct_UClass_AMyItem_NoRegister()
{
	return AMyItem::StaticClass();
}
struct Z_Construct_UClass_AMyItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MyItem.h" },
		{ "ModuleRelativePath", "Public/MyItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__healValue_MetaData[] = {
		{ "AllowprivateAccess", "true" },
		{ "Category", "Item" },
		{ "ModuleRelativePath", "Public/MyItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__collider_MetaData[] = {
		{ "Category", "Collider" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__mesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyItem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__info_MetaData[] = {
		{ "Category", "ItemInfo" },
		{ "ModuleRelativePath", "Public/MyItem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp__healValue;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__collider;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__mesh;
	static const UECodeGen_Private::FStructPropertyParams NewProp__info;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyItem_OnOverlap, "OnOverlap" }, // 71712459
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyItem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMyItem_Statics::NewProp__healValue = { "_healValue", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyItem, _healValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__healValue_MetaData), NewProp__healValue_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyItem_Statics::NewProp__collider = { "_collider", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyItem, _collider), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__collider_MetaData), NewProp__collider_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyItem_Statics::NewProp__mesh = { "_mesh", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyItem, _mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__mesh_MetaData), NewProp__mesh_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyItem_Statics::NewProp__info = { "_info", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyItem, _info), Z_Construct_UScriptStruct_FMyItemInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__info_MetaData), NewProp__info_MetaData) }; // 3965938458
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyItem_Statics::NewProp__healValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyItem_Statics::NewProp__collider,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyItem_Statics::NewProp__mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyItem_Statics::NewProp__info,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyItem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyItem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Unreal5_edu,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyItem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyItem_Statics::ClassParams = {
	&AMyItem::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMyItem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyItem_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyItem_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyItem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyItem()
{
	if (!Z_Registration_Info_UClass_AMyItem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyItem.OuterSingleton, Z_Construct_UClass_AMyItem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyItem.OuterSingleton;
}
template<> UNREAL5_EDU_API UClass* StaticClass<AMyItem>()
{
	return AMyItem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyItem);
AMyItem::~AMyItem() {}
// End Class AMyItem

// Begin Registration
struct Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyItem_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ MyItemType_StaticEnum, TEXT("MyItemType"), &Z_Registration_Info_UEnum_MyItemType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1520939960U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMyItemInfo::StaticStruct, Z_Construct_UScriptStruct_FMyItemInfo_Statics::NewStructOps, TEXT("MyItemInfo"), &Z_Registration_Info_UScriptStruct_MyItemInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMyItemInfo), 3965938458U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyItem, AMyItem::StaticClass, TEXT("AMyItem"), &Z_Registration_Info_UClass_AMyItem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyItem), 484340604U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyItem_h_882534258(TEXT("/Script/Unreal5_edu"),
	Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyItem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyItem_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyItem_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyItem_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyItem_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyItem_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
