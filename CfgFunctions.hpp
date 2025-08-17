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
<<<<<<< HEAD
      class tickClock {};     // NEW
      class openMail {};   // NEW
      class mailRenderList {};  // Отрисовать список писем
      class mailOpenMessage {}; // Открыть конкретное письмо
      class mailDelete {};      // Удалить письмо
      class home {};            // Назад на рабочий стол
=======
>>>>>>> parent of 26e0510 (hot fix KPK)
    };
};

    