// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class APlayerController;
class UCancelFindSessionsCallbackProxy;
#ifdef ADVANCEDSESSIONS_CancelFindSessionsCallbackProxy_generated_h
#error "CancelFindSessionsCallbackProxy.generated.h already included, missing '#pragma once' in CancelFindSessionsCallbackProxy.h"
#endif
#define ADVANCEDSESSIONS_CancelFindSessionsCallbackProxy_generated_h

#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_SPARSE_DATA
#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCancelFindSessions) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UCancelFindSessionsCallbackProxy**)Z_Param__Result=UCancelFindSessionsCallbackProxy::CancelFindSessions(Z_Param_WorldContextObject,Z_Param_PlayerController); \
		P_NATIVE_END; \
	}


#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCancelFindSessions) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UCancelFindSessionsCallbackProxy**)Z_Param__Result=UCancelFindSessionsCallbackProxy::CancelFindSessions(Z_Param_WorldContextObject,Z_Param_PlayerController); \
		P_NATIVE_END; \
	}


#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCancelFindSessionsCallbackProxy(); \
	friend struct Z_Construct_UClass_UCancelFindSessionsCallbackProxy_Statics; \
public: \
	DECLARE_CLASS(UCancelFindSessionsCallbackProxy, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSessions"), ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UCancelFindSessionsCallbackProxy)


#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_INCLASS \
private: \
	static void StaticRegisterNativesUCancelFindSessionsCallbackProxy(); \
	friend struct Z_Construct_UClass_UCancelFindSessionsCallbackProxy_Statics; \
public: \
	DECLARE_CLASS(UCancelFindSessionsCallbackProxy, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSessions"), ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UCancelFindSessionsCallbackProxy)


#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UCancelFindSessionsCallbackProxy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCancelFindSessionsCallbackProxy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UCancelFindSessionsCallbackProxy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCancelFindSessionsCallbackProxy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSESSIONS_API UCancelFindSessionsCallbackProxy(UCancelFindSessionsCallbackProxy&&); \
	ADVANCEDSESSIONS_API UCancelFindSessionsCallbackProxy(const UCancelFindSessionsCallbackProxy&); \
public:


#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UCancelFindSessionsCallbackProxy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSESSIONS_API UCancelFindSessionsCallbackProxy(UCancelFindSessionsCallbackProxy&&); \
	ADVANCEDSESSIONS_API UCancelFindSessionsCallbackProxy(const UCancelFindSessionsCallbackProxy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UCancelFindSessionsCallbackProxy); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCancelFindSessionsCallbackProxy); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCancelFindSessionsCallbackProxy)


#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_PRIVATE_PROPERTY_OFFSET
#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_9_PROLOG
#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_PRIVATE_PROPERTY_OFFSET \
	PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_SPARSE_DATA \
	PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_RPC_WRAPPERS \
	PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_INCLASS \
	PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_PRIVATE_PROPERTY_OFFSET \
	PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_SPARSE_DATA \
	PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_INCLASS_NO_PURE_DECLS \
	PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h_12_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class CancelFindSessionsCallbackProxy."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVANCEDSESSIONS_API UClass* StaticClass<class UCancelFindSessionsCallbackProxy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PlanetSix_Plugins_AdvancedSessions_AdvancedSessions_Source_AdvancedSessions_Classes_CancelFindSessionsCallbackProxy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
