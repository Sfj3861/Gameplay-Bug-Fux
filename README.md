# Gameplay Bug Fixes

A Geode mod for Geometry Dash 2.2091 that aims to fix frustrating gameplay bugs without altering intentional mechanics, creative techniques, or visual/audio behavior.

## Current implementation
- [x] Jump input-state tracking for P1 and P2.
- [x] Experimental re-routing of a tracked held jump after `PlayLayer::resetLevel` when the Practice-resync setting is enabled.
- [ ] Held-input resynchronization at level start (hardware state detection remains unresolved).
- [ ] Practice checkpoint state restoration.
- [ ] Trigger-state reset inconsistencies.
- [ ] Confirmed collision/physics edge cases.

## Experimental behavior
The checkpoint feature re-routes a press for jump inputs the tracker observed as held before `resetLevel`. It may not cover inputs that never reached the game's input handler, and must be compiled and tested on the target build before use. The setting is independently toggleable.

## Build
Build with the Geode SDK's standard CMake workflow for the target platform. No release binary is provided.
