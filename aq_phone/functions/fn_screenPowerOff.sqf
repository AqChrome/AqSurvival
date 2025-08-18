/*
  Выключение экрана: плавно гасим контейнер _screen и играем звук.
*/
disableSerialization;

private _screen = uiNamespace getVariable ["AQPH_ScreenGroup", controlNull];
if (isNull _screen) exitWith {};

_screen ctrlSetFade 1;
_screen ctrlCommit 0.12;

[_screen] spawn {
  params ["_s"];
  uiSleep 0.12;
  if (!isNull _s) then {
    _s ctrlShow false;
  };
};


