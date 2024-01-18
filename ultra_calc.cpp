#include "ultra_calc.h"
#include "core/string/ustring.h"

UltraCalc::UltraCalc(){
	message = "Uuuuu SIGMA SIGMA";
}

void UltraCalc::_bind_methods(){
	ClassDB::bind_method(D_METHOD("get_message"), &UltraCalc::getMessage);
}

String UltraCalc::getMessage(){
	return message;
}
