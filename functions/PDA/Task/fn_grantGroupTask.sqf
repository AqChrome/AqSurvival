if (!isServer) exitWith {};
params ["_plr","_tag","_ctx"];

private _grp = group _plr;
if (isNull _grp) exitWith {};

private _dest = [getPos _plr, 500 + random 400, random 360] call BIS_fnc_relPos;
private _taskId = format ["pda_grp_task_%1_%2", groupId _grp, floor time];
private _title = "Групповая задача";
private _desc  = "Выполнить совместно.";

// Владелец — группа: задача будет у всех в группе
private _task = [
  _grp, _taskId, [_desc, _title, ""], _dest,
  "CREATED", 1, true, "move", true
] call BIS_fnc_taskCreate;

[_task, "ASSIGNED", true] call BIS_fnc_taskSetState;
[_task, _dest] call BIS_fnc_taskSetDestination;
