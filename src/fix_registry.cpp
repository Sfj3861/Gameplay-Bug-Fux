#include "fix_registry.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace gameplay_bug_fixes {
    void initialize() {
        auto mod = Mod::get();

        if (mod->getSettingValue<bool>("diagnostics")) {
            log::info("Gameplay Bug Fixes loaded; input-state tracking hook enabled.");
        }
        log::info("Gameplay Bug Fixes registry initialized.");
    }
}
