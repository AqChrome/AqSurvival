class AQ_store {
	class Init {
		file = "core\economy\store\functions";
		class initModule {postInit = 1;};
	};

	class Cargo {
		file = "core\economy\store\functions\system\cargo";
		class addContainerCargo {};
		class getContainerCargo {};
		class getContainerItems {};
		class getPlayerCargo {};
		class getPlayerItems {};
		class clearContainerCargo {};
		class removeContainerItem {};
		class removePlayerItem {};
	};
	
	class Hash {
		file = "core\economy\store\functions\system\hash";
		class hashSet {};
		class hashGet {};
		class hashGetOrDefault {headerType = -1;};
	};

	class Client {
		file = "core\economy\store\functions\client";
		class initClient {};
		class openStore {};
		class systemChat {};
	};

	class Config {
		file = "core\economy\store\functions\system\config";
		class getCompatibleItems {};
		class getItemMass {};
		class getItemStats {};
		class getItemType {};
		class getCargoMass {};
		class getParentClassname {headerType = -1;};
	};

	class Server {
		file = "core\economy\store\functions\server";
		class addTrader {};
		class addActionTrader {};
		class initServer {};
		class purchase {};
		class sell {};
	};

	class Stock {
		file = "core\economy\store\functions\server\stock";
		class getTraderStock {};
		class setTraderStock {};
		class updateStock {};
	};

	class System {
		file = "core\economy\store\functions\system";
		class addItemCargo {};
		class canAddItem {};
		class canEquipItem {};
		class equipItem {};
	};

	class UI {
		file = "core\economy\store\functions\client\ui";
		class main {};
		class update {};
		class eachFrame {headerType = -1;};
	};
};
