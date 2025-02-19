// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "testGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEST_testGameMode_generated_h
#error "testGameMode.generated.h already included, missing '#pragma once' in testGameMode.h"
#endif
#define TEST_testGameMode_generated_h

#define FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAtestGameMode(); \
	friend struct Z_Construct_UClass_AtestGameMode_Statics; \
public: \
	DECLARE_CLASS(AtestGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/test"), TEST_API) \
	DECLARE_SERIALIZER(AtestGameMode)


#define FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AtestGameMode(AtestGameMode&&); \
	AtestGameMode(const AtestGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(TEST_API, AtestGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AtestGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AtestGameMode) \
	TEST_API virtual ~AtestGameMode();


#define FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h_9_PROLOG
#define FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h_12_INCLASS_NO_PURE_DECLS \
	FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class AtestGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_2025_Unreal_UnrealEngine5_test_Source_test_testGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
