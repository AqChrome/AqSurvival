disableSerialization;
params ["_id"];

private _tasks = missionNamespace getVariable ["PDA_Tasks", []];
private _idx = _tasks findIf { (_x select 0) isEqualTo _id };
if (_idx < 0) exitWith {};

private _task = _tasks select _idx;
private _tag  = _task select 4;

private _ctx = [
  ["player", player],
  ["taskId", _id],
  ["time", diag_tickTime]
];

private _hub = missionNamespace getVariable ["PDA_TaskHub", objNull];
if (!isNil "_hub" && {typeName _hub isEqualTo "CODE"}) then {
  [_tag, _ctx] call _hub;
} else {
  diag_log format ["[PDA] No TaskHub registered (PDA_TaskHub). tag=%1 id=%2", _tag, _id];
};

_tasks deleteAt _idx;
missionNamespace setVariable ["PDA_Tasks", _tasks];

private _det = uiNamespace getVariable ["PDA_TaskDetailGroup", controlNull];
if (!isNull _det) then { ctrlDelete _det; uiNamespace setVariable ["PDA_TaskDetailGroup", controlNull]; };

private _list = uiNamespace getVariable ["PDA_TasksGroup", controlNull];
if (!isNull _list) then { ctrlDelete _list; uiNamespace setVariable ["PDA_TasksGroup", controlNull]; };
[] call PDA_fnc_tasksOpen;
