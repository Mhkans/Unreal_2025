// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Unreal5_edu/Public/MyTutoActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyTutoActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
UNREAL5_EDU_API UClass* Z_Construct_UClass_AMyTutoActor();
UNREAL5_EDU_API UClass* Z_Construct_UClass_AMyTutoActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_Unreal5_edu();
// End Cross Module References

// Begin Class AMyTutoActor
void AMyTutoActor::StaticRegisterNativesAMyTutoActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyTutoActor);
UClass* Z_Construct_UClass_AMyTutoActor_NoRegister()
{
	return AMyTutoActor::StaticClass();
}
struct Z_Construct_UClass_AMyTutoActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MyTutoActor.h" },
		{ "ModuleRelativePath", "Public/MyTutoActor.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyTutoActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMyTutoActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Unreal5_edu,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyTutoActor_Statics::ClassParams = {
	&AMyTutoActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyTutoActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyTutoActor()
{
	if (!Z_Registration_Info_UClass_AMyTutoActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyTutoActor.OuterSingleton, Z_Construct_UClass_AMyTutoActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyTutoActor.OuterSingleton;
}
template<> UNREAL5_EDU_API UClass* StaticClass<AMyTutoActor>()
{
	return AMyTutoActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyTutoActor);
AMyTutoActor::~AMyTutoActor() {}
// End Class AMyTutoActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyTutoActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyTutoActor, AMyTutoActor::StaticClass, TEXT("AMyTutoActor"), &Z_Registration_Info_UClass_AMyTutoActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyTutoActor), 1627339825U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyTutoActor_h_2764950484(TEXT("/Script/Unreal5_edu"),
	Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyTutoActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyTutoActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
