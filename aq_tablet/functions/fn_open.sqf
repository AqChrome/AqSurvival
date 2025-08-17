if (uiNamespace getVariable ["AQTB_open", false]) exitWith {};
disableSerialization;

uiNamespace setVariable ["AQTB_open", true];

private _layer = uiNamespace getVariable ["AQTB_Layer", -1];
if (_layer isEqualType 0 && {_layer >= 0}) then {
  _layer cutRsc ["AQTB_Tablet", "PLAIN", 0, false];
} else {
  cutRsc ["AQTB_Tablet", "PLAIN", 0, false];
};

waitUntil { !isNull (uiNamespace getVariable ["AQTB_Display", displayNull]) };
private _disp = uiNamespace getVariable ["AQTB_Display", displayNull];

// ← тут закрытие по ESC
_disp displayAddEventHandler ["KeyDown", {
  params ["_d","_key"];
  if (_key isEqualTo 1) exitWith { [] call AQTB_fnc_close; true }; // 1 = ESC
  false
}];

[] call AQTB_fnc_buildHome;
