/*
  Открыть КПК: создаём диалог, строим UI, показываем с анимацией.
*/
disableSerialization;

if (!isNull (uiNamespace getVariable ["AQPH_Display", displayNull])) exitWith {};

createDialog "AQPH_Dialog";
private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
if (isNull _disp) exitWith {};

[_disp] call AQPH_fnc_buildUI;

// Слайд-ин: слегка поднимаем снизу
private _rootGrp = _disp displayCtrl 10;  // корневой группой сделаем idc=10
if (!isNull _rootGrp) then {
  private _pos = ctrlPosition _rootGrp;
  _rootGrp ctrlSetPosition [(_pos select 0), (_pos select 1) + 0.06, (_pos select 2), (_pos select 3)];
  _rootGrp ctrlCommit 0;
  _rootGrp ctrlSetPosition _pos;
  _rootGrp ctrlCommit 0.15;
};
