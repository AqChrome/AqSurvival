/*
  Добавить задание в список.
  Параметры:
    0: STRING - type (отображаемая категория, напр. "ликвидация")
    1: STRING - title (заголовок в списке)
    2: STRING - text (описание на детальном экране)
    3: STRING - tag (англ. код типа для хаба), опционален
*/
params ["_type","_title","_text",["_tag",""]];
if (isNil "_type" || {isNil "_title"}) exitWith {};

if (_tag isEqualTo "") then {
  // fallback: если тег не передан — берём из типа (в нижнем регистре)
  _tag = toLower _type;
};

playSound "AQPH_TaskNew";

private _tasks  = missionNamespace getVariable ["AQPH_Tasks", []];
private _nextId = missionNamespace getVariable ["AQPH_TaskNextId", 1];

// Храним: [id, typeDisplay, title, text, tagForHub]
_tasks pushBack [_nextId, _type, _title, _text, _tag];
missionNamespace setVariable ["AQPH_Tasks", _tasks];
missionNamespace setVariable ["AQPH_TaskNextId", _nextId + 1];
