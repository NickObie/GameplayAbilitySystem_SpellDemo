

using UnrealBuildTool;
using System.Collections.Generic;

public class SpellbreakDemoTarget : TargetRules
{
	public SpellbreakDemoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "SpellbreakDemo" } );
	}
}
