class PDA {
	tag = "PDA";

	class PDA_Core {
		file = "PDA\core";
		class pageManager { postInit = 1; };
	};

	class PDA_Pages {
		file = "PDA\pages";
		class home          {};  // PDA_fnc_home
		class tasks_list    {};  // PDA_fnc_tasks_list
		class task_detail   {};  // PDA_fnc_task_detail_page  (имя функции см. ниже)
	};

	class PDA__Main {
		file = "PDA\functions";
		class init {};
		class registerKeys {};
		class open {};
		class close {};
		class buildUI {};
		class buildUI_hook_register {};
		class setMenuItems {};
		class menuAction {};
		class screenPowerOn {};
		class screenPowerOff {};
	};

  	class PDA_Notify {
      file = "PDA\notify";
      class notifyPush {};
      class notifyRender {};
      class notifyClose {};
	};

	class PDA_Tasks {
      file = "PDA\tasks";
      class taskPush {};
      class tasksOpen {};
      class tasksClose {};
      class taskDetail {};
      class taskAccept {};
      class taskDecline {};
    };
};