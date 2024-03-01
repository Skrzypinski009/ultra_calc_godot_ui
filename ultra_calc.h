#ifndef ULTRA_CALC_H
#define ULTRA_CALC_H

#include "core/object/ref_counted.h"
#include "core/string/ustring.h"
#include "ultra_calc/src/workspace/workspace.h"

class UltraCalc : public RefCounted {
	GDCLASS(UltraCalc, RefCounted);

	Workspace workspace;

protected:
	static void _bind_methods();

public:
	Error createTable(int w, int h);
	Error loadTableCSV(String p_path);
	Error saveTableCSV(String p_path, int table_id, bool raw);
	Error insertCell(int table_id, int w, int h, String tekst);
	Error calculate();
	Array getCells(int table_id);

	UltraCalc();
};

#endif // !ULTRA_CALC_H
