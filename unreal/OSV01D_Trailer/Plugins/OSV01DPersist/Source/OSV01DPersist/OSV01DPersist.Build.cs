using UnrealBuildTool;

public class OSV01DPersist : ModuleRules
{
	public OSV01DPersist(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine" });
	}
}
