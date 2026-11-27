#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

namespace gameplay_bug_fixes {
    struct InputState {
        bool player1JumpHeld = false;
        bool player2JumpHeld = false;
    };

    static InputState g_state;
    static bool g_resyncing = false;

    bool enabled() {
        return Mod::get()->getSettingValue<bool>("fix-held-input-checkpoint");
    }

    void resync(PlayLayer* layer) {
        if (!layer || g_resyncing || !enabled()) return;
        auto p1 = g_state.player1JumpHeld;
        auto p2 = g_state.player2JumpHeld;
        if (!p1 && !p2) return;

        g_resyncing = true;
        if (p1) layer->handleButton(true, 1, true);
        if (p2) layer->handleButton(true, 1, false);
        g_resyncing = false;

        if (Mod::get()->getSettingValue<bool>("diagnostics")) {
            log::debug("Checkpoint held-input resync attempted (P1={}, P2={}).", p1, p2);
        }
    }
}

class $modify(GBFInputTracker, GJBaseGameLayer) {
    void handleButton(bool down, int button, bool isPlayer1) {
        GJBaseGameLayer::handleButton(down, button, isPlayer1);
        if (button != 1 || gameplay_bug_fixes::g_resyncing) return;
        if (isPlayer1) gameplay_bug_fixes::g_state.player1JumpHeld = down;
        else gameplay_bug_fixes::g_state.player2JumpHeld = down;
    }
};

class $modify(GBFPlayLayer, PlayLayer) {
    void resetLevel() {
        PlayLayer::resetLevel();
        gameplay_bug_fixes::resync(this);
    }
};
