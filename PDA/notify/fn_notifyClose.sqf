/* Снимаем верх уведомления; если очередь ещё есть — показываем следующее, иначе — возврат. */
disableSerialization;

private _notify = ["notify"] call PDA_fnc_pageGet;
if (!isNull _notify) then {
  ctrlDelete _notify;
  private _map = uiNamespace getVariable ["PDA_Pages", createHashMap];
  _map deleteAt "notify";
  uiNamespace setVariable ["PDA_Pages", _map];
};

private _q = missionNamespace getVariable ["PDA_NotifyQueue", []];
if (!(_q isEqualTo [])) then { _q deleteAt 0; missionNamespace setVariable ["PDA_NotifyQueue", _q]; };

if !((missionNamespace getVariable ["PDA_NotifyQueue", []]) isEqualTo []) exitWith { [] call PDA_fnc_notifyRender; };

[] call PDA_fnc_pagePop;
