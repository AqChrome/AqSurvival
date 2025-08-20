params ["_type","_title","_text",["_tag",""]];
if (isNil "_type" || {isNil "_title"}) exitWith {};

if (_tag isEqualTo "") then {
  _tag = toLower _type;
};

playSound "PDA_TaskNew";

private _tasks  = missionNamespace getVariable ["PDA_Tasks", []];
private _nextId = missionNamespace getVariable ["PDA_TaskNextId", 1];

_tasks pushBack [_nextId, _type, _title, _text, _tag];
missionNamespace setVariable ["PDA_Tasks", _tasks];
missionNamespace setVariable ["PDA_TaskNextId", _nextId + 1];
