// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "test/testGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodetestGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
TEST_API UClass* Z_Construct_UClass_AtestGameMode();
TEST_API UClass* Z_Construct_UClass_AtestGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_test();
// End Cross Module References

// Begin Class AtestGameMode
void AtestGameMode::StaticRegisterNativesAtestGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AtestGameMode);
UClass* Z_Construct_UClass_AtestGameMode_NoRegister()
{
	return AtestGameMode::StaticClass();
}
struct Z_Construct_UClass_AtestGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "testGameMode.h" },
		{ "ModuleRelativePath", "testGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AtestGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AtestGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_test,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AtestGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AtestGameMode_Statics::ClassParams = {
	&AtestGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AtestGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AtestGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AtestGameMode()
{
	if (!Z_Registration_Info_UClass_AtestGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AtestGameMode.OuterSingleton, Z_Construct_UClass_AtestGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AtestGameMode.OuterSingleton;
}
template<> TEST_API UClass* StaticClass<AtestGameMode>()
{
	return AtestGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AtestGameMode);
AtestGameMode::~AtestGameMode() {}
// End Class AtestGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AtestGameMode, AtestGameMode::StaticClass, TEXT("AtestGameMode"), &Z_Registration_Info_UClass_AtestGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AtestGameMode), 23077044U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h_2526459960(TEXT("/Script/test"),
	Z_CompiledInDeferFile_FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
