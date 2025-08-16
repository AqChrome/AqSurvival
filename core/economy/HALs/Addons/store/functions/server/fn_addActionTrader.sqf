/*
	Function: HALs_store_fnc_addActionTrader
	Author: HallyG
	Add an open store action to all targets.

	Argument(s):
	0: Trader <OBJECT>
	1: Target (Default: false) <ARRAY, GROUP, NUMBER, OBJECT, SIDE, STRING, BOOLEAN>

	Return Value:
	None

	Example:
	[trader1, west] call HALs_store_fnc_addActionTrader;
__________________________________________________________________*/
params [
	["_trader", objNull, [objNull]],
	["_target", false, [0, objNull, "", sideUnknown, grpNull, [], false]]
];

if (isNull _trader) exitWith {};
if (isNil {_trader getVariable "HALs_store_trader_type"}) exitWith {};

 if (_target isEqualType false) then {
	if (hasInterface) then {
		[
			_trader,
			format [localize "STR_HALS_STORE_OPEN_ACTION", _trader getVariable ["HALs_store_name", localize "STR_HALS_STORE_ACTION"]],
			"\a3\Ui_F_Oldman\Data\IGUI\Cfg\HoldActions\holdAction_market_ca.paa",
			"\a3\Ui_F_Oldman\Data\IGUI\Cfg\HoldActions\holdAction_market_ca.paa",
			"alive _target && _this distance _target < 3 && isNull objectParent _this",
			"_this distance _target < 3",
			{},
			{},
			{
				params ["_trader", "_caller", "_actionId", "_arguments"];

				[_trader] call HALs_store_fnc_openStore;
			}, {}, [], 0.1, nil, false, false
		] call BIS_fnc_holdActionAdd;
	};
} else {
	if (isServer) then {
		[_trader] remoteExecCall ["HALs_store_fnc_addActionTrader", _target, _trader];
	};
};


// adds the action to every client and JIP, but also adds it when it was already removed. E.g., Laptop has already been hacked by a player
/* [
	_myLaptop,											// Object the action is attached to
	"Hack Laptop",										// Title of the action
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",	// Idle icon shown on screen
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",	// Progress icon shown on screen
	"_this distance _target < 3",						// Condition for the action to be shown
	"_caller distance _target < 3",						// Condition for the action to progress
	{},													// Code executed when action starts
	{},													// Code executed on every progress tick
	{ _this call MY_fnc_hackingCompleted },				// Code executed on completion
	{},													// Code executed on interrupted
	[],													// Arguments passed to the scripts as _this select 3
	12,													// Action duration in seconds
	0,													// Priority
	true,												// Remove on completion
	false												// Show in unconscious state
] remoteExec ["BIS_fnc_holdActionAdd", 0, _myLaptop];	// MP compatible implementation */
