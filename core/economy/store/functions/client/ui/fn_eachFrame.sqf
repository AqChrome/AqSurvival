/*
	Function: AQ_store_fnc_eachFrame
	Author: HallyG
	Periodically checks if the player's money or items have changed.

	Argument(s):
	0: None

	Return Value:
	None

	Example:
	[] call AQ_store_fnc_eachFrame;
__________________________________________________________________*/
if (!hasInterface) exitWith {};
if (!isNil {missionNamespace getVariable "#AQ_store_money"}) exitWith {};

missionNamespace setVariable ["AQ_store_updated", false];
missionNamespace setVariable ["#AQ_store_money", [player] call AQ_money_fnc_getFunds];
missionNamespace setVariable ["#AQ_store_containers", [uniform player, vest player, backpack player]];
missionNamespace setVariable ["#AQ_store_nextUpdateTick", diag_tickTime];

addMissionEventHandler ["EachFrame", {
	if (isNull (uiNamespace getVariable ["AQ_store_display", displayNull])) exitWith {
		{missionNamespace setVariable [_x, nil]} forEach ["#AQ_store_nextUpdateTick", "AQ_store_updated", "#AQ_store_containers", "#AQ_store_money"];
		
		removeMissionEventHandler ["EachFrame", _thisEventHandler];
	};

	if (AQ_store_updated) then {
		["update"] call  AQ_store_fnc_main;
		
		missionNamespace setVariable ["#AQ_store_money", [player] call AQ_money_fnc_getFunds];
		missionNamespace setVariable ["#AQ_store_containers", [uniform player, vest player, backpack player]];
		AQ_store_updated = false;
	};

	if (diag_tickTime > missionNamespace getVariable ["#AQ_store_nextUpdateTick", diag_tickTime]) then {
		_containers = [uniform player, vest player, backpack player];
		_oldContainers = missionNamespace getVariable ["#AQ_store_containers", []];
		
		_money = [player] call AQ_money_fnc_getFunds;
		_oldMoney = missionNamespace getVariable ["#AQ_store_money", [player] call AQ_money_fnc_getFunds];

		if (_money != _oldMoney) then {
			missionNamespace setVariable ["#AQ_store_money", _money];
			AQ_store_updated = true;
		};

		if !(_containers isEqualTo _oldContainers) then {
			missionNamespace setVariable ["#AQ_store_containers", _containers];
			AQ_store_updated = true;
		};

		missionNamespace setVariable ["#AQ_store_nextUpdateTick", diag_tickTime + 0.25];
	};
}];