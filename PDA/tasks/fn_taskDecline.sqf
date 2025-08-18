disableSerialization;
params ["_id"];

private _tasks = missionNamespace getVariable ["PDA_Tasks", []];
private _idx = _tasks findIf { (_x select 0) isEqualTo _id };
if (_idx < 0) exitWith {};

_tasks deleteAt _idx;
missionNamespace setVariable ["PDA_Tasks", _tasks];

private _det = uiNamespace getVariable ["PDA_TaskDetailGroup", controlNull];
if (!isNull _det) then { ctrlDelete _det; uiNamespace setVariable ["PDA_TaskDetailGroup", controlNull]; };

private _list = uiNamespace getVariable ["PDA_TasksGroup", controlNull];
if (!isNull _list) then { ctrlDelete _list; uiNamespace setVariable ["PDA_TasksGroup", controlNull]; };
[] call PDA_fnc_tasksOpen;
