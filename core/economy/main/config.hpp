#ifdef AQ_DEF_FUNCTIONS
	#include "..\core\functions.cpp"
	#include "..\money\functions.cpp"
	#include "..\store\functions.cpp"
#endif

#ifdef AQ_DEF_INIT
	#include "..\store\dialog\dialog.hpp"

	class CfgAQAddons {
		enableLog = 1;

		#include "..\money\config.hpp"
		#include "..\store\config.hpp"
	};
#endif
