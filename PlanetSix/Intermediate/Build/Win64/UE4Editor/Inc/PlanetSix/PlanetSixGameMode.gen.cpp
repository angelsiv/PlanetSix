// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PlanetSix/PlanetSixGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlanetSixGameMode() {}
// Cross Module References
	PLANETSIX_API UClass* Z_Construct_UClass_APlanetSixGameMode_NoRegister();
	PLANETSIX_API UClass* Z_Construct_UClass_APlanetSixGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_PlanetSix();
// End Cross Module References
	void APlanetSixGameMode::StaticRegisterNativesAPlanetSixGameMode()
	{
	}
	UClass* Z_Construct_UClass_APlanetSixGameMode_NoRegister()
	{
		return APlanetSixGameMode::StaticClass();
	}
	struct Z_Construct_UClass_APlanetSixGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlanetSixGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_PlanetSix,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlanetSixGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "PlanetSixGameMode.h" },
		{ "ModuleRelativePath", "PlanetSixGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlanetSixGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlanetSixGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APlanetSixGameMode_Statics::ClassParams = {
		&APlanetSixGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_APlanetSixGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlanetSixGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlanetSixGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APlanetSixGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APlanetSixGameMode, 2378101449);
	template<> PLANETSIX_API UClass* StaticClass<APlanetSixGameMode>()
	{
		return APlanetSixGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APlanetSixGameMode(Z_Construct_UClass_APlanetSixGameMode, &APlanetSixGameMode::StaticClass, TEXT("/Script/PlanetSix"), TEXT("APlanetSixGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlanetSixGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
