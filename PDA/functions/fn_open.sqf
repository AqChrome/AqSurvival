disableSerialization;

if (!isNull (uiNamespace getVariable ["PDA_Display", displayNull])) exitWith {};
createDialog "PDA_Dialog";
private _disp = uiNamespace getVariable ["PDA_Display", displayNull];
if (isNull _disp) exitWith {};

[_disp] call PDA_fnc_buildUI;

private _rootGrp = _disp displayCtrl 10;
if (!isNull _rootGrp) then {
  private _pos = ctrlPosition _rootGrp;
  _rootGrp ctrlSetPosition [(_pos select 0), (_pos select 1) + 0.06, (_pos select 2), (_pos select 3)];
  _rootGrp ctrlCommit 0;
  _rootGrp ctrlSetPosition _pos;
  _rootGrp ctrlCommit 0.15;
};

playSound "PDA_PowerOn";

[] spawn {
  uiSleep 0.48;
  [] call PDA_fnc_screenPowerOn;
};
