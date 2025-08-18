// [side, title, text, tag]
if (!isServer) exitWith {};
params ["_side","_title","_text",["_tag","news"]];
{
  [_title,_text,_tag] remoteExecCall ["PDA_fnc_notifyPush", _x];
} forEach (allPlayers select { side _x == _side });
