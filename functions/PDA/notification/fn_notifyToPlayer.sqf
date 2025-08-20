// [playerObj, title, text, tag]
if (!isServer) exitWith {};
params ["_plr","_title","_text",["_tag","news"]];
if (isNull _plr || {!isPlayer _plr}) exitWith {};
[_title,_text,_tag] remoteExecCall ["PDA_fnc_notifyPush", _plr];
