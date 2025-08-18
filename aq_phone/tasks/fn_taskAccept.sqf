/*
  Принять задачу: вызвать хаб и вернуться к списку (перерисовать).
*/
disableSerialization;
params ["_id"];

private _tasks = missionNamespace getVariable ["AQPH_Tasks", []];
private _idx = _tasks findIf { (_x select 0) isEqualTo _id };
if (_idx < 0) exitWith {};

private _task = _tasks select _idx;
private _tag  = _task select 4;

// вызвать твой хаб
[_tag] call AQPH_fnc_testHub;

// удалить из списка
_tasks deleteAt _idx;
missionNamespace setVariable ["AQPH_Tasks", _tasks];

// закрыть детальный и показать список снова (перерисовать)
private _det = uiNamespace getVariable ["AQPH_TaskDetailGroup", controlNull];
if (!isNull _det) then { ctrlDelete _det; uiNamespace setVariable ["AQPH_TaskDetailGroup", controlNull]; };

private _list = uiNamespace getVariable ["AQPH_TasksGroup", controlNull];
if (!isNull _list) then { ctrlDelete _list; uiNamespace setVariable ["AQPH_TasksGroup", controlNull]; };
[] call AQPH_fnc_tasksOpen;
