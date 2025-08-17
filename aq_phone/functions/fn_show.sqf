if (uiNamespace getVariable ["AQPH_open", false]) exitWith {};
disableSerialization;

uiNamespace setVariable ["AQPH_open", true];
createDialog "AQPH_Dialog";
waitUntil { !isNull (uiNamespace getVariable ["AQPH_Display", displayNull]) };
private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];

private _grp = [] call AQPH_fnc_buildUI;
uiNamespace setVariable ["AQPH_Group", _grp];

// выезд снизу
private _p = ctrlPosition _grp;
private _startY = safeZoneY + safeZoneH + 0.01;
_grp ctrlSetPosition [_p#0, _startY, _p#2, _p#3];
_grp ctrlCommit 0;
_grp ctrlSetPosition [_p#0, _p#1, _p#2, _p#3];
_grp ctrlCommit 0.35;

// Right Shift (54) = закрыть
_disp displayAddEventHandler ["KeyDown", {
  params ["_d","_key"];
  if (_key isEqualTo 54) exitWith { [] spawn AQPH_fnc_hide; true };
  false
}];
