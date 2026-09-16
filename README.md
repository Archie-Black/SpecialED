# SpecialED

Public isolate for the **OS V01D** trailer.

Fully free. Free to share. Apache-2.0.

This repository is **not** the operating system, **not** Spectral HX private source, and **not** GhostIT. Those stay private. SpecialED is the marketing cut, the Unreal/Godot rebuild scaffolding, and the WebGL look — nothing else.

## What is in here

| Path | What |
|------|------|
| `web/` | WebGL compositor persistence (localStorage) |
| `unreal/OSV01D_Trailer/` | UE 5.8 project stub + plugin architectures |
| `godot/os_v01d_trailer/` | Godot 4.3 persist autoload |
| `captions/` | SRT + speech.json for the 180s feature |

Large video plates are **not** stored here (GitHub API isolate). The live preview still holds the picture. Rebuild stills in Unreal, motion in Godot.

## Persistence (learning / adapting)

`web/persist.ts` and Godot `scripts/persist.gd` and Unreal `USpecialEDSaveGame`:

- play count, last timecode, mute
- WebGL/GPU fail count
- adapted look strength
- after **two** look failures, the compositor is skipped

Nothing phones home. Slot name: `SpecialED`.

## Unreal

This does **not** install Unreal Engine. Open `unreal/OSV01D_Trailer/OS_V01D_Trailer.uproject` on a PC with **UE 5.8**. Enable the listed engine plugins (Python, Sequencer, Movie Render Queue, Niagara). Project plugins:

- `OSV01DLook` — Runtime
- `OSV01DPersist` — Runtime SaveGame
- `OSV01DEditor` — Editor only

Lumen is a project rendering feature, not a git binary.

## Godot

Open `godot/os_v01d_trailer/project.godot` in Godot 4.3+. Autoload `Persist`.

## Licence

Apache-2.0. Fully free. Free to share. If it's any use, pass it on.

DeltaKingZero / Archie-Black
