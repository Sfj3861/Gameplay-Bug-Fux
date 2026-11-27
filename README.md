# Gameplay Bug Fixes

A Geode mod for Geometry Dash 2.2091 that aims to fix frustrating gameplay bugs without altering intentional mechanics, creative techniques, or visual/audio behavior.

## Current implementation
- [x] Input-state tracking hook for routed jump press/release events (instrumentation only).
- [ ] Held-input resynchronization at level start.
- [ ] Held-input resynchronization after Practice checkpoints.
- [ ] Practice checkpoint state restoration.
- [ ] Trigger-state reset inconsistencies.
- [ ] Confirmed collision/physics edge cases.

## Notes
The current input tracker records jump transitions routed through `GJBaseGameLayer::handleButton`. It does **not** yet synthesize or restore inputs, so it does not claim to fix held-input loss. The hook needs to be compiled and validated against the target Geode SDK/platform before release.

## Build
Build with the Geode SDK's standard CMake workflow for the target platform. No release binary is provided.
