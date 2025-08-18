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

	class PDA_Notify {
		file = "functions\PDA\notification";
		class notifyToPlayer {};
		class notifyToGroup {};
		class notifyToSide {};
		class notifyToAll {};
	};

	class PDA_Task {
		file = "functions\PDA\Task";
		class registerPDAHub {};
		class taskHubServer {};     
		class grantPersonalTask {};  
		class grantGroupTask {};
	};
};