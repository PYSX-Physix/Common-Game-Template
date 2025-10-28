// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CommonGameTemplateEditor : ModuleRules
{
    public CommonGameTemplateEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                "CommonGameTemplateEditor"
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "EditorFramework",
                "UnrealEd",
                "PhysicsCore",
                "GameplayTagsEditor",
                "GameplayTasksEditor",
                "GameplayAbilities",
                "GameplayAbilitiesEditor",
                "StudioTelemetry",
                "CommonGameTemplate",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "InputCore",
                "Slate",
                "SlateCore",
                "ToolMenus",
                "ModularGameplayExperiences",
                "EditorStyle",
                "DataValidation",
                "MessageLog",
                "Projects",
                "ModularGameplayExperiences",
                "DeveloperToolSettings",
                "CollectionManager",
                "SourceControl",
                "Chaos"
            }
        );

        DynamicallyLoadedModuleNames.AddRange(
            new string[] {
            }
        );
    }
}
