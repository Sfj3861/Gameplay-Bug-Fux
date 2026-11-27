# Gameplay Bug Fixes

A Geode mod for Geometry Dash 2.2091 that aims to fix frustrating gameplay bugs without altering intentional mechanics, creative techniques, or visual/audio behavior.

## Project foundation
- Modular fix registry: each fix should be isolated and independently toggleable.
- Configuration switches are defined in `mod.json`.
- Diagnostics setting for initialization/module status.
- Fix switches are scaffolding only until their implementation and reproduction tests are verified.

## Planned modules
- [ ] Held input at level start
- [ ] Held input after Practice checkpoints
- [ ] Practice checkpoint state restoration
- [ ] Trigger-state reset inconsistencies
- [ ] Confirmed collision/physics edge cases

## Build
Build with the Geode SDK's standard CMake workflow for the target platform. This scaffold has not yet been compiled against a platform-specific SDK and should not be treated as a release binary.

## Scope
No audio fixes, visual-only bugs, or intentionally useful gameplay mechanics.
