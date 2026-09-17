# Highway

GitHub is the live link between this public isolate and Hector.

- Pull: `hector-build` `_beta_ue` (private Unreal bake — scripts, MetaHuman route).
- Push: only this repo (SpecialED). Never dump the private OS here.
- Unreal Editor runs on the machine that has UE 5.8. `metahuman.route.ts` spawns it there **only if** `UE_CANDIDATES` resolve to a real editor binary.
- This sandbox does not run Unreal Editor.

Bake in this isolate: plugin descriptors + compileable stub modules + persist (web / Godot / UE SaveGame). Design and private source stay in `hector-build`.

Fully free. Free to share. Apache-2.0.
