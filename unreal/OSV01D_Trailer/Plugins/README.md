# Unreal plugin architectures (SpecialED)

This isolate does **not** install Unreal Engine. It ships the **plugin descriptors** Epic actually uses so a machine with UE 5.8 can enable them.

Official module `Type` values (we use three):

| Type | When it loads | This isolate |
|------|----------------|--------------|
| Runtime | cooked game + editor | `OSV01DLook`, `OSV01DPersist` |
| Editor | editor only | `OSV01DEditor` |
| UncookedOnly | editor / -game uncooked | not required here |
| Developer | non-shipped tools | not required here |
| RuntimeAndProgram | runtime + programs | not required here |

Engine plugins listed in the uproject (enable on a PC, do not vendor):

- PythonScriptPlugin
- EditorScriptingUtilities
- SequencerScripting
- MovieRenderPipeline
- MovieRenderPipelineRenderPasses
- Takes
- Niagara

Lumen is a **project rendering feature**, not a plugin you copy from git.
