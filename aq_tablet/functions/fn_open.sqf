if (uiNamespace getVariable ["AQTB_open", false]) exitWith {};
disableSerialization;

uiNamespace setVariable ["AQTB_open", true];

private _layer = uiNamespace getVariable ["AQTB_Layer", -1];
_layer cutRsc ["AQTB_Tablet", "PLAIN", 0, false];

waitUntil { !isNull (uiNamespace getVariable ["AQTB_Display", displayNull]) };
private _disp = uiNamespace getVariable ["AQTB_Display", displayNull];

// ESC закрывает планшет
_disp displayAddEventHandler ["KeyDown", {
  params ["_d","_key"];
  if (_key isEqualTo 1) exitWith { [] call AQTB_fnc_close; true }; // 1 = ESC
  false
}];

[] call AQTB_fnc_buildHome;
