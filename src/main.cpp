#include <Geode/Geode.hpp>
#include "fix_registry.hpp"

using namespace geode::prelude;

$on_mod_loaded {
    gameplay_bug_fixes::initialize();
}
