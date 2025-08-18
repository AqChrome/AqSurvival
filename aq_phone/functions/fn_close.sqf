/*
  Закрыть КПК: гасим экран, затем анимация вниз и закрытие.
*/
disableSerialization;

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
if (isNull _disp) exitWith {};
playSound "AQPH_PowerOff";

// Сначала выключаем экран
[] call AQPH_fnc_screenPowerOff;

private _rootGrp = _disp displayCtrl 10;
if (!isNull _rootGrp) then {
  private _pos = ctrlPosition _rootGrp;

  // даём экрану погаснуть, потом прячем
  [_disp, _rootGrp, _pos] spawn {
    params ["_d","_rg","_p"];
    uiSleep 0.14; // чуть больше fade экрана
	
    _rg ctrlSetPosition [(_p select 0), (_p select 1) + 0.06, (_p select 2), (_p select 3)];
    _rg ctrlCommit 0.12;
    uiSleep 0.12;
	
    if (!isNull _d) then { _d closeDisplay 0; };
  };
} else {
  _disp closeDisplay 0;
};
