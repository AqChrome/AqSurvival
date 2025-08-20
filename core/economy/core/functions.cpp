class AQ_Core {
	tag = "AQ";
	class Common {
		file = "core\economy\core\functions";
		class log {headerType = -1};
	};

	class Numbers {
		file = "core\economy\core\functions\numbers";
		class numberToString {};
	};

	class Arrays {
		file = "core\economy\core\functions\arrays";
		class sortArray {};
	};

	class Config {
		file = "core\economy\core\functions\config";
		class getConfigClass {headerType=-1;};
		class getConfigValue {headerType=-1;};
		class getModuleSettings {};
	};
};
