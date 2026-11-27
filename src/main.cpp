#include <Geode/Geode.hpp>

using namespace geode::prelude;

// Initial scaffold. Behavior-changing hooks will be added only after each bug
// has a reliable reproduction and the hook has been validated for the target GD version.
$on_mod_loaded {
    log::info("Gameplay Bug Fixes loaded (scaffold). No fixes are active yet.");
}
