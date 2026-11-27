#include "fix_registry.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace gameplay_bug_fixes {
    void initialize() {
        auto mod = Mod::get();

        // Settings are scaffolding switches only. They intentionally do not
        // change gameplay until the corresponding fix is implemented and tested.
        if (mod->getSettingValue<bool>("diagnostics")) {
            log::info("Fix modules: held-input start={}, held-input checkpoint={}, practice-state={}",
                mod->getSettingValue<bool>("fix-held-input-start"),
                mod->getSettingValue<bool>("fix-held-input-checkpoint"),
                mod->getSettingValue<bool>("fix-practice-state"));
        }

        log::info("Gameplay Bug Fixes module registry initialized.");
    }
}
