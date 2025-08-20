/*
	Function: AQ_money_fnc_getFunds
	Author: HallyG

	Arguments(s):
	0: Unit <OBJECT>

	Return Value:
	Funds <NUMBER>

	Example:
	[] call AQ_money_fnc_getFunds;
__________________________________________________________________*/
params [
	["_unit", objNull, [objNull]]
];

(_unit getVariable ["aq_player_money", 0])
