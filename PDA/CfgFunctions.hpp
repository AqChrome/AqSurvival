class PDA {
	tag = "PDA";
	class Phone
	{
		file = "PDA\functions";
		class init {};
		class registerKeys {};
		class open {};
		class close {};
		class buildUI {};
		class setMenuItems {};
		class menuAction {};
		class screenPowerOn {};
		class screenPowerOff {};
	};

  	class Notify {
      file = "PDA\notify";
      class notifyPush {};
      class notifyRender {};
      class notifyClose {};
	};

	class Tasks {
      file = "PDA\tasks";
      class taskPush {};
      class tasksOpen {};
      class tasksClose {};
      class taskDetail {};
      class taskAccept {};
      class taskDecline {};
    };
};