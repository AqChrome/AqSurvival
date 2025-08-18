if (!hasInterface) exitWith {};

private _dispGame = findDisplay 46;
if (isNull _dispGame) exitWith {
  uiSleep 0.1;
  [] call PDA_fnc_registerKeys;
};

private _ehId = _dispGame getVariable ["PDA_KeyEH",-1];
if (_ehId >= 0) exitWith {};

missionNamespace setVariable ["PDA_LastToggle", -1];

_ehId = _dispGame displayAddEventHandler ["KeyDown", {
  params ["_display","_key","_shift","_ctrl","_alt"];

  if (_key != 54) exitWith { false };

  private _now = time;
  private _last = missionNamespace getVariable ["PDA_LastToggle", -1];
  if (_last >= 0 && { (_now - _last) < 0.25 }) exitWith { true };  // антидребезг

  missionNamespace setVariable ["PDA_LastToggle", _now];

  private _cur = uiNamespace getVariable ["PDA_Display", displayNull];
  if (isNull _cur) then {
    [] call PDA_fnc_open;
  } else {
    [] call PDA_fnc_close;
  };

  true
}];

_dispGame setVariable ["PDA_KeyEH", _ehId];
