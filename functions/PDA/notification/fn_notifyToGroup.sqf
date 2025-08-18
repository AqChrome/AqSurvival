// [groupObj, title, text, tag]
if (!isServer) exitWith {};
params ["_grp","_title","_text",["_tag","news"]];
{
  [_title,_text,_tag] remoteExecCall ["PDA_fnc_notifyPush", _x];
} forEach (units _grp select { isPlayer _x });
