#include "ultra_calc.h"
#include "core/string/ustring.h"
#include "ultra_calc/src/workspace/table.h"
#include "ultra_calc/src/workspace/workspace.h"
#include <iostream>

UltraCalc::UltraCalc(){}

void UltraCalc::_bind_methods(){
	ClassDB::bind_method(D_METHOD("create_table", "widht", "height"), &UltraCalc::createTable);
	ClassDB::bind_method(D_METHOD("load_table_csv", "path"), &UltraCalc::loadTableCSV);
	ClassDB::bind_method(D_METHOD("save_table_csv", "path", "table_id", "is_raw"), &UltraCalc::saveTableCSV);
	ClassDB::bind_method(D_METHOD("calculate"), &UltraCalc::calculate);
	ClassDB::bind_method(D_METHOD("get_cells", "table_id"), &UltraCalc::getCells);
}

Error UltraCalc::createTable(int w, int h){
	ERR_FAIL_COND_V_MSG(w<1 || h<1, ERR_INVALID_PARAMETER, "Table min size is 1x1!");
	this->workspace.createTable(w, h);
	return OK;
}
Error UltraCalc::loadTableCSV(String p_path){
	std::string s_path(p_path.utf8().get_data());
	workspace.createTableFromCSV(s_path);
	return OK;
}
Error UltraCalc::saveTableCSV(String p_path, int table_id, bool raw){
	std::string s_path(p_path.utf8().get_data());
	workspace.saveTableCSV(s_path, workspace.getTable(table_id), raw);
	return OK;
}
Error UltraCalc::insertCell(int table_id, int w, int h, String p_tekst){
	ERR_FAIL_COND_V_MSG((size_t)table_id<0, ERR_INVALID_PARAMETER, "table_id has to be >= 0");
	ERR_FAIL_COND_V_MSG(
		(size_t)table_id>workspace.countTables(),
		ERR_INVALID_PARAMETER,
		vformat("There is no table with id %d", table_id)
	);
	std::string s_text(p_tekst.utf8().get_data());
	workspace.insertText(table_id, w, h, s_text);
	return OK;
}

Error UltraCalc::calculate(){
	workspace.calculate();
	return OK;
}

Array UltraCalc::getCells(int table_id){
	Array cells;
	ERR_FAIL_COND_V_MSG((size_t)table_id<0, cells, "table_id has to be >= 0");
	ERR_FAIL_COND_V_MSG(
		(size_t)table_id>workspace.countTables(),
		cells,
		vformat("There is no table with id %d", table_id)
	);
	Table* table = workspace.getTable(table_id);
	for(size_t h=0; h<table->getHeight(); h++){
		Array row;
		for(size_t w=0; w<table->getWidth(); w++){
			Cell* c = table->getCell(w, h);
			String str_c = c->getRawText().c_str();
			row.append(str_c);
		}
		cells.append(row);
	}
	return cells;
}

