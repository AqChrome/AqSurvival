if (!hasInterface) exitWith {};
missionNamespace setVariable ["PDA_TaskHub", {
  params ["_tag", "_ctx"];
  private _plr = player;
  [_plr, _tag, _ctx] remoteExecCall ["AQ_fnc_taskHubServer", 2];
}];
