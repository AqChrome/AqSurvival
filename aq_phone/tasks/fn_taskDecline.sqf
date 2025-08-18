/*
  Отклонить задачу: убрать из списка и вернуться к списку.
*/
disableSerialization;
params ["_id"];

private _tasks = missionNamespace getVariable ["AQPH_Tasks", []];
private _idx = _tasks findIf { (_x select 0) isEqualTo _id };
if (_idx < 0) exitWith {};

_tasks deleteAt _idx;
missionNamespace setVariable ["AQPH_Tasks", _tasks];

// закрыть детальный и показать список снова (перерисовать)
private _det = uiNamespace getVariable ["AQPH_TaskDetailGroup", controlNull];
if (!isNull _det) then { ctrlDelete _det; uiNamespace setVariable ["AQPH_TaskDetailGroup", controlNull]; };

private _list = uiNamespace getVariable ["AQPH_TasksGroup", controlNull];
if (!isNull _list) then { ctrlDelete _list; uiNamespace setVariable ["AQPH_TasksGroup", controlNull]; };
[] call AQPH_fnc_tasksOpen;
