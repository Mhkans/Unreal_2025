// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "testCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEST_testCharacter_generated_h
#error "testCharacter.generated.h already included, missing '#pragma once' in testCharacter.h"
#endif
#define TEST_testCharacter_generated_h

#define FID_2025_Unreal_UnrealEngine5_test_Source_test_testCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAtestCharacter(); \
	friend struct Z_Construct_UClass_AtestCharacter_Statics; \
public: \
	DECLARE_CLASS(AtestCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/test"), NO_API) \
	DECLARE_SERIALIZER(AtestCharacter)


#define FID_2025_Unreal_UnrealEngine5_test_Source_test_testCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AtestCharacter(AtestCharacter&&); \
	AtestCharacter(const AtestCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AtestCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AtestCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AtestCharacter) \
	NO_API virtual ~AtestCharacter();


#define FID_2025_Unreal_UnrealEngine5_test_Source_test_testCharacter_h_18_PROLOG
#define FID_2025_Unreal_UnrealEngine5_test_Source_test_testCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_2025_Unreal_UnrealEngine5_test_Source_test_testCharacter_h_21_INCLASS_NO_PURE_DECLS \
	FID_2025_Unreal_UnrealEngine5_test_Source_test_testCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class AtestCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_2025_Unreal_UnrealEngine5_test_Source_test_testCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
