#define HALs_DEF_FUNCTIONS
#include "core\economy\HALs\Addons\main\config.hpp"
#undef HALs_DEF_FUNCTIONS

class AQ {
	tag = "AQ";
	class Needs {
		file = "core\survival\needs\inventory";
		class onInventoryDblClick {};
		class tryEat {};
		class tryDrink {};
	};
};

    