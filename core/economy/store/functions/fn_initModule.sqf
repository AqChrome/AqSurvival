/*
	Function: AQ_store_fnc_initModule;
	Author: HallyG
	Module initialisation.

	Argument(s):
	None

	Return Value:
	None

	Example:
	[] call AQ_store_fnc_initModule;
__________________________________________________________________*/
if (!isNil "AQ_store_moduleInit") exitWith {};
AQ_store_moduleInit = true;

if (isServer) then {call AQ_store_fnc_initServer};
if (hasInterface) then {call AQ_store_fnc_initClient};