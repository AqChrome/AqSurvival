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

class AQPH {
    tag = "AQPH";
    class Phone {
      file = "aq_phone\functions";
      class init {};
      class registerKeys {};
      class show {};
      class hide {};
      class buildUI {};
      class tickClock {};     // NEW
      class openMail {};   // NEW
      class home {}; 
    };
};

    