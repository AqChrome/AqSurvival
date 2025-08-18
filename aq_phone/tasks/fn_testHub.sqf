/*
  aq_phone\tasks\testHub.sqf
  Тестовый Mission HUB: случайно выбирает задачу по тегу и назначает ванильный таск локальному игроку.

  Вызов: ["kill"] call AQ_missionHUB;
         ["logistic"] call AQ_missionHUB;
         ["destroy"] call AQ_missionHUB;
*/

params [["_tag","",[""]]];
_tag = toLower _tag;

// Владелец задачи — текущий игрок (локально). Так таск увидит только он.
private _owner = player;

// Простой уникальный id
private _cnt = missionNamespace getVariable ["AQPH_VanillaTaskCounter", 0];
_cnt = _cnt + 1;
missionNamespace setVariable ["AQPH_VanillaTaskCounter", _cnt];
private _taskId = format ["aqph_task_%1", _cnt];

// Случайная точка назначения недалеко от игрока
// (BIS_fnc_relPos: [центр, дистанция, азимут] -> позиция)
private _dest = [player, 400 + random 300, random 360] call BIS_fnc_relPos;

// Пулы шаблонов по тегам
private _pool = switch (_tag) do {
  case "kill": {
    [
      ["Ликвидация: связной", "Устранить цель в районе отметки.", "kill"],
      ["Ликвидация: дозорный", "Снять дозорного, избегая поднятия тревоги.", "kill"]
    ]
  };
  case "logistic": {
    [
      ["Логистика: доставка", "Доставить груз в указанную точку. Избегать боя.", "move"],
      ["Логистика: эвакуация", "Вывезти медикаменты на базу.", "transport"]
    ]
  };
  case "destroy": {
    [
      ["Уничтожить склад", "Подорвать вражеский склад боеприпасов.", "destroy"],
      ["Уничтожить технику", "Вывести из строя технику противника.", "destroy"]
    ]
  };
  default {
    [
      ["Разведка местности", "Осмотреть район и доложить обстановку.", "scout"],
      ["Передислокация", "Перейти в указанный квадрат.", "move"]
    ]
  };
};

// Выбираем случайный шаблон
private _tpl = selectRandom _pool;
_tpl params ["_title","_desc","_taskType"];

// Создаём ванильный таск ТОЛЬКО этому игроку
// BIS_fnc_taskCreate: [owner, id, [desc, title, marker], destination, state, priority, showNotif, type, visible3D]
private _task = [
  _owner,
  _taskId,
  [_desc, _title, ""],
  _dest,
  "CREATED",
  1,
  true,
  _taskType,
  true
] call BIS_fnc_taskCreate;

// Назначаем и задаём точку
[_task, "ASSIGNED", true] call BIS_fnc_taskSetState;
[_task, _dest] call BIS_fnc_taskSetDestination;

// Подсказка (можно убрать)
hint format ["Задача назначена: %1", _title];

// Вернём id (вдруг захочешь трекать)
_taskId
