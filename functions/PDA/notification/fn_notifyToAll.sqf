// [title, text, tag]
if (!isServer) exitWith {};
params ["_title","_text",["_tag","news"]];
[_title,_text,_tag] remoteExecCall ["PDA_fnc_notifyPush", 0];
