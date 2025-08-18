disableSerialization;

if (!isNull (uiNamespace getVariable ["AQPH_Display", displayNull])) exitWith {};
createDialog "AQPH_Dialog";
private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
if (isNull _disp) exitWith {};

[_disp] call AQPH_fnc_buildUI;

private _rootGrp = _disp displayCtrl 10;
if (!isNull _rootGrp) then {
  private _pos = ctrlPosition _rootGrp;
  _rootGrp ctrlSetPosition [(_pos select 0), (_pos select 1) + 0.06, (_pos select 2), (_pos select 3)];
  _rootGrp ctrlCommit 0;
  _rootGrp ctrlSetPosition _pos;
  _rootGrp ctrlCommit 0.15;
};

playSound "AQPH_PowerOn";

// После выезда — включаем экран (убираем off и показываем _home)
[] spawn {
  uiSleep 0.48;
  [] call AQPH_fnc_screenPowerOn;
};

// Если есть уведомления — покажем (после включения)
[] spawn {
  uiSleep 0.55;
  [] call AQPH_fnc_notifyRender;
};
