#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

namespace gameplay_bug_fixes {
    // Tracks physical/game input transitions routed through GD's input handler.
    // This is instrumentation for the upcoming resynchronization fix, not a
    // gameplay change by itself.
    struct InputState {
        bool player1JumpHeld = false;
        bool player2JumpHeld = false;
        bool initialized = false;
    };

    static InputState g_state;

    InputState const& state() {
        return g_state;
    }

    void resetTracking() {
        g_state = {};
    }
}

class $modify(GBFInputTracker, GJBaseGameLayer) {
    void handleButton(bool down, int button, bool isPlayer1) {
        GJBaseGameLayer::handleButton(down, button, isPlayer1);

        // Jump is button 1 in GD's input routing.
        if (button != 1) return;

        if (isPlayer1) {
            gameplay_bug_fixes::g_state.player1JumpHeld = down;
        }
        else {
            gameplay_bug_fixes::g_state.player2JumpHeld = down;
        }

        gameplay_bug_fixes::g_state.initialized = true;
        if (Mod::get()->getSettingValue<bool>("diagnostics")) {
            log::debug("Input tracker: jump={}, player2={}, held={}",
                down, !isPlayer1,
                isPlayer1 ? gameplay_bug_fixes::g_state.player1JumpHeld
                          : gameplay_bug_fixes::g_state.player2JumpHeld);
        }
    }
};
