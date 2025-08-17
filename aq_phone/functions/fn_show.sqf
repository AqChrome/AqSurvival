if (uiNamespace getVariable ["AQPH_open", false]) exitWith {};
disableSerialization;

uiNamespace setVariable ["AQPH_open", true];

createDialog "AQPH_Dialog";
waitUntil { !isNull (uiNamespace getVariable ["AQPH_Display", displayNull]) };
private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];

private _grp = [] call AQPH_fnc_buildUI;

// старт ниже экрана
private _p = ctrlPosition _grp;
private _startY = safeZoneY + safeZoneH + 0.01;
_grp ctrlSetPosition [_p#0, _startY, _p#2, _p#3];
_grp ctrlCommit 0;

// цель со снапом
private _pxH = 1 / (getResolution select 3);
private _targetY = round ((_p#1) / _pxH) * _pxH;
_grp ctrlSetPosition [_p#0, _targetY, _p#2, _p#3];
_grp ctrlCommit 0.35;

// ждём завершения выезда
waitUntil { ctrlCommitted _grp };

// OFF → спрятать, HOME widgets → показать
private _off  = uiNamespace getVariable ["AQPH_OffWallpaper", controlNull];
private _hw   = uiNamespace getVariable ["AQPH_HomeWidgets", []];
if (!isNull _off) then { _off ctrlSetFade 1; _off ctrlCommit 0.12; };
{ if (!isNull _x) then { _x ctrlSetFade 0; _x ctrlCommit 0.12; } } forEach _hw;

// запустить часы
private _clock = [] spawn AQPH_fnc_tickClock;
uiNamespace setVariable ["AQPH_ClockThread", _clock];

// RShift — закрыть
_disp displayAddEventHandler ["KeyDown", {
  params ["_d","_key"];
  if (_key isEqualTo 54) exitWith { [] spawn AQPH_fnc_hide; true };
  false
}];
