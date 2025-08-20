class AQ_money {
	class Init {
		file = "core\economy\money\functions";
		class initModule {postInit = 1;};
	};
	
	class Client {
		file = "core\economy\money\functions\client";
		class initClient {};
	};
	
	class Server {
		file = "core\economy\money\functions\server";
		class addFunds {};
		class getFunds {};
		class initServer {};
	};
};
