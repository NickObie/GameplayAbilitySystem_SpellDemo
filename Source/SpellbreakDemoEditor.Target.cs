

using UnrealBuildTool;
using System.Collections.Generic;

public class SpellbreakDemoEditorTarget : TargetRules
{
	public SpellbreakDemoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "SpellbreakDemo" } );
	}
}
