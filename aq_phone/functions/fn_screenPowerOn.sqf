/*
  Включение экрана: плавно показываем контейнер _screen и играем звук.
*/
disableSerialization;

private _screen = uiNamespace getVariable ["AQPH_ScreenGroup", controlNull];
if (isNull _screen) exitWith {};

_screen ctrlShow true;
_screen ctrlSetFade 1;
_screen ctrlCommit 0;

_screen ctrlSetFade 0;
_screen ctrlCommit 0.15;


