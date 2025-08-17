class AQ {
	tag = "AQ";
		class Needs {
			file = "core\survival\needs\inventory";
			class onInventoryDblClick {};
			class tryEat {};
			class tryDrink {};
		};
	};
	
	class AQTB {
	tag = "AQTB";
		class Tablet {
			file = "aq_tablet\\functions";
			class init {};
			class registerAction {};
			class open {};
			class close {};
			class buildHome {};
			class onHomeClick {};
			class openTasks {};
			class openMapEmbedded {};
			class setTasks {};
		};
	};

    #define HALs_DEF_FUNCTIONS
    #include "core\economy\HALs\Addons\main\config.hpp"
    #undef HALs_DEF_FUNCTIONS