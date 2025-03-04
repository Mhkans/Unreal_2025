// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyAnimInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREAL5_EDU_MyAnimInstance_generated_h
#error "MyAnimInstance.generated.h already included, missing '#pragma once' in MyAnimInstance.h"
#endif
#define UNREAL5_EDU_MyAnimInstance_generated_h

#define FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyAnimInstance_h_18_DELEGATE \
UNREAL5_EDU_API void FAnimDelegateTest3_DelegateWrapper(const FMulticastScriptDelegate& AnimDelegateTest3);


#define FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyAnimInstance_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAnimNotify_Dead_Motion); \
	DECLARE_FUNCTION(execAnimNotify_Attack_Hit); \
	DECLARE_FUNCTION(execJumpToSection); \
	DECLARE_FUNCTION(execPlayAnimMontage_Attack);


#define FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyAnimInstance_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyAnimInstance(); \
	friend struct Z_Construct_UClass_UMyAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UMyAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Unreal5_edu"), NO_API) \
	DECLARE_SERIALIZER(UMyAnimInstance)


#define FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyAnimInstance_h_30_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMyAnimInstance(UMyAnimInstance&&); \
	UMyAnimInstance(const UMyAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyAnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMyAnimInstance) \
	NO_API virtual ~UMyAnimInstance();


#define FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyAnimInstance_h_27_PROLOG
#define FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyAnimInstance_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyAnimInstance_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyAnimInstance_h_30_INCLASS_NO_PURE_DECLS \
	FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyAnimInstance_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREAL5_EDU_API UClass* StaticClass<class UMyAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_2025_Unreal_Unreal_2025_UnrealEngine5_Unreal5_edu_Source_Unreal5_edu_Public_MyAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
