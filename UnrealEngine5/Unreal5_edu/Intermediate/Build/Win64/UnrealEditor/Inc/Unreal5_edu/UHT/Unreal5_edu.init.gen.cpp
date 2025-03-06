// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnreal5_edu_init() {}
	UNREAL5_EDU_API UFunction* Z_Construct_UDelegateFunction_Unreal5_edu_AnimDelegateTest3__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Unreal5_edu;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Unreal5_edu()
	{
		if (!Z_Registration_Info_UPackage__Script_Unreal5_edu.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Unreal5_edu_AnimDelegateTest3__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Unreal5_edu",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x87CB8188,
				0x05D8C507,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Unreal5_edu.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Unreal5_edu.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Unreal5_edu(Z_Construct_UPackage__Script_Unreal5_edu, TEXT("/Script/Unreal5_edu"), Z_Registration_Info_UPackage__Script_Unreal5_edu, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x87CB8188, 0x05D8C507));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
