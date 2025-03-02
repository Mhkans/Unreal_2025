// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal5_edu/Public/MyCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
UNREAL5_EDU_API UClass* Z_Construct_UClass_AMyCharacter();
UNREAL5_EDU_API UClass* Z_Construct_UClass_AMyCharacter_NoRegister();
UNREAL5_EDU_API UClass* Z_Construct_UClass_UMyAnimInstance_NoRegister();
UNREAL5_EDU_API UClass* Z_Construct_UClass_UMyStatComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Unreal5_edu();
// End Cross Module References

// Begin Class AMyCharacter
void AMyCharacter::StaticRegisterNativesAMyCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyCharacter);
UClass* Z_Construct_UClass_AMyCharacter_NoRegister()
{
	return AMyCharacter::StaticClass();
}
struct Z_Construct_UClass_AMyCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyCharacter.h" },
		{ "ModuleRelativePath", "Public/MyCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__isAttack_MetaData[] = {
		{ "AllowprivateAccess", "true" },
		{ "Category", "Animation" },
		{ "ModuleRelativePath", "Public/MyCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__animInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/MyCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__statComponent_MetaData[] = {
		{ "AllowprivateAccess", "true" },
		{ "Category", "Stat" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__HPWidget_MetaData[] = {
		{ "AllowprivateAccess", "true" },
		{ "Category", "UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MyCharacter.h" },
	};
#endif // WITH_METADATA
	static void NewProp__isAttack_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp__isAttack;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__animInstance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__statComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__HPWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_AMyCharacter_Statics::NewProp__isAttack_SetBit(void* Obj)
{
	((AMyCharacter*)Obj)->_isAttack = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp__isAttack = { "_isAttack", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMyCharacter), &Z_Construct_UClass_AMyCharacter_Statics::NewProp__isAttack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__isAttack_MetaData), NewProp__isAttack_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp__animInstance = { "_animInstance", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, _animInstance), Z_Construct_UClass_UMyAnimInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__animInstance_MetaData), NewProp__animInstance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp__statComponent = { "_statComponent", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, _statComponent), Z_Construct_UClass_UMyStatComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__statComponent_MetaData), NewProp__statComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyCharacter_Statics::NewProp__HPWidget = { "_HPWidget", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyCharacter, _HPWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__HPWidget_MetaData), NewProp__HPWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp__isAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp__animInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp__statComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacter_Statics::NewProp__HPWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Unreal5_edu,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyCharacter_Statics::ClassParams = {
	&AMyCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMyCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyCharacter()
{
	if (!Z_Registration_Info_UClass_AMyCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyCharacter.OuterSingleton, Z_Construct_UClass_AMyCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyCharacter.OuterSingleton;
}
template<> UNREAL5_EDU_API UClass* StaticClass<AMyCharacter>()
{
	return AMyCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyCharacter);
AMyCharacter::~AMyCharacter() {}
// End Class AMyCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_GitHub_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyCharacter, AMyCharacter::StaticClass, TEXT("AMyCharacter"), &Z_Registration_Info_UClass_AMyCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyCharacter), 2338486354U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_GitHub_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyCharacter_h_1965556287(TEXT("/Script/Unreal5_edu"),
	Z_CompiledInDeferFile_FID_GitHub_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_GitHub_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
