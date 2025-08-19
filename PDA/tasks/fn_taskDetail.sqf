disableSerialization;
params ["_id"];

private _tasks = missionNamespace getVariable ["PDA_Tasks", []];
private _idx = _tasks findIf { (_x select 0) isEqualTo _id };
if (_idx < 0) exitWith {};

private _task = _tasks select _idx;

private _page = [_task] call PDA_fnc_task_detail;
if (isNull _page) exitWith {};

["detail"] call PDA_fnc_pagePush;
