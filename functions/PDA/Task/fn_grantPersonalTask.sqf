if (!isServer) exitWith {};
params ["_plr","_tag","_ctx"];

private _dest = [getPos _plr, 350 + random 300, random 360] call BIS_fnc_relPos;

private _title = switch (toLower _tag) do {
  case "kill":     { "Ликвидация: цель получена" };
  case "logistic": { "Логистика: доставка" };
  case "destroy":  { "Уничтожить объект" };
  default          { "Задача" };
};
private _desc  = "Детали задачи выдал координатор.";
private _type  = "move";
private _taskId = format ["pda_task_%1_%2", getPlayerUID _plr, floor time];

[
  [_taskId, _title, _desc, _dest, _type],
  {
    params ["_taskId","_title","_desc","_dest","_type"];
    private _owner = player;
    private _task = [
      _owner, _taskId, [_desc, _title, ""], _dest,
      "CREATED", 1, true, _type, true
    ] call BIS_fnc_taskCreate;

    [_task, "ASSIGNED", true] call BIS_fnc_taskSetState;
    [_task, _dest] call BIS_fnc_taskSetDestination;
  }
] remoteExecCall ["BIS_fnc_call", _plr];
