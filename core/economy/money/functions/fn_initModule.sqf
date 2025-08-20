/*
	Function: AQ_money_fnc_init
	Author: HallyG
	Module initialisation.

	Argument(s):
	None

	Return Value:
	None	

	Example:
	[] call AQ_money_fnc_initModule;
__________________________________________________________________*/
if (!isNil "AQ_money_moduleInit") exitWith {};
AQ_money_moduleInit = true;

if (isServer) then {call AQ_money_fnc_initServer};
if (hasInterface) then {call AQ_money_fnc_initClient};