# SpecialED

Public isolate for the **OS V01D** trailer.

Fully free. Free to share. Apache-2.0.

This repository is **not** the operating system, **not** Spectral HX private source, and **not** GhostIT. Those stay private.

Live cut is the Grok Build preview. This git holds scaffolding only — no private OS, no giant plates.

## Layout

- `web/persist.ts` — learning persistence (mute, look fails, adapted strength)
- `unreal/OSV01D_Trailer/` — UE 5.8 stub + Runtime/Editor plugins
  - `OSV01DLook` — runtime palette constants (vanta / cobalt / uranium)
  - `OSV01DPersist` — SaveGame + Blueprint library
  - `OSV01DEditor` — editor-only module stub
- `godot/os_v01d_trailer/scripts/persist.gd` — Godot autoload
- `captions/` — SRT + speech metadata

WebGL: context lost/restored, visibility, DPR. Two GPU fails and the look is skipped.

Unreal is **not** installed from this repo and is **not** running in any remote sandbox. Open the `.uproject` on a PC with UE 5.8. Hector `metahuman.route.ts` launches the editor only when `UE_CANDIDATES` exist on that PC.

If it's any use, pass it on.
