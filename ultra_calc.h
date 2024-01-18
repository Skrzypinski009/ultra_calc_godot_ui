#ifndef ULTRA_CALC_H
#define ULTRA_CALC_H

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"

class UltraCalc : public RefCounted {
	GDCLASS(UltraCalc, RefCounted);

	String message;

protected:
	static void _bind_methods();

public:
	String getMessage();

	UltraCalc();
};

#endif // !ULTRA_CALC_H
