// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PLANETSIX_PlanetSixCharacter_generated_h
#error "PlanetSixCharacter.generated.h already included, missing '#pragma once' in PlanetSixCharacter.h"
#endif
#define PLANETSIX_PlanetSixCharacter_generated_h

#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_SPARSE_DATA
#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_RPC_WRAPPERS
#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlanetSixCharacter(); \
	friend struct Z_Construct_UClass_APlanetSixCharacter_Statics; \
public: \
	DECLARE_CLASS(APlanetSixCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PlanetSix"), NO_API) \
	DECLARE_SERIALIZER(APlanetSixCharacter)


#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPlanetSixCharacter(); \
	friend struct Z_Construct_UClass_APlanetSixCharacter_Statics; \
public: \
	DECLARE_CLASS(APlanetSixCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PlanetSix"), NO_API) \
	DECLARE_SERIALIZER(APlanetSixCharacter)


#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlanetSixCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlanetSixCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlanetSixCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlanetSixCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlanetSixCharacter(APlanetSixCharacter&&); \
	NO_API APlanetSixCharacter(const APlanetSixCharacter&); \
public:


#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlanetSixCharacter(APlanetSixCharacter&&); \
	NO_API APlanetSixCharacter(const APlanetSixCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlanetSixCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlanetSixCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlanetSixCharacter)


#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(APlanetSixCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(APlanetSixCharacter, FollowCamera); }


#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_9_PROLOG
#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_SPARSE_DATA \
	PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_RPC_WRAPPERS \
	PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_INCLASS \
	PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_SPARSE_DATA \
	PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_INCLASS_NO_PURE_DECLS \
	PlanetSix_Source_PlanetSix_PlanetSixCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PLANETSIX_API UClass* StaticClass<class APlanetSixCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PlanetSix_Source_PlanetSix_PlanetSixCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
