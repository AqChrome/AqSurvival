disableSerialization;

[] call PDA_fnc_pagePop;

private _list = uiNamespace getVariable ["PDA_TasksGroup", controlNull];
if (!isNull _list) then {
  ctrlDelete _list;
  uiNamespace setVariable ["PDA_TasksGroup", controlNull];

  private _map = uiNamespace getVariable ["PDA_Pages", createHashMap];
  _map deleteAt "tasks";
  uiNamespace setVariable ["PDA_Pages", _map];
};
