class AQPH {
	tag = "AQPH";
	class Phone
	{
		file = "aq_phone\functions";
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
      file = "aq_phone\notify";
      class notifyPush {};
      class notifyRender {};
      class notifyClose {};
	};
};