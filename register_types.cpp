#include "register_types.h"

#include "core/object/class_db.h"
#include "ultra_calc.h"

void initialize_ultracalc_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
	ClassDB::register_class<UltraCalc>();
}

void uninitialize_ultracalc_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
			return;
	}
   // Nothing to do here in this example.
}
