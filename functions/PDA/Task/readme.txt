============================================================
📱 PDA by AqChrome — Задачи
============================================================

О ЧЁМ ЭТО
------------------------------------------------------------
КПК-мод (PDA) показывает список задач игроку и при нажатии «Принять»
вызывает хаб миссии (missionNamespace["PDA_TaskHub"]) и передаёт туда ТЕГ
задачи (например "kill"). Дальше МИССИЯ/СЕРВЕР решают, какую ванильную
задачу создать: персональную (только игроку) или групповую (всем в группе).

ВАЖНО о префиксах:
- Внутри мода функции под префиксом PDA_ (например, PDA_fnc_taskPush).
- В миссии можешь называть свои серверные функции как угодно; ниже используются AqPDA_ для примера.
  Если у тебя другой префикс (MSN_, MY_ и т.д.) — просто замени имена.


1) МИНИМАЛЬНАЯ НАСТРОЙКА В МИССИИ
------------------------------------------------------------
1.1 Клиент: регистрация "Task Hub" (postInit на клиентах)
    (когда игрок жмёт «Принять», мод дергает именно эту переменную)

    // initPlayerLocal.sqf ИЛИ fn_registerPDAHub.sqf (подключи как postInit=1)
    missionNamespace setVariable ["PDA_TaskHub", {
      // выполняется НА КЛИЕНТЕ принявшего игрока
      params ["_tag","_ctx"];
      private _plr = player;
      // отправляем запрос на СЕРВЕР: "игрок P принял тег T"
      [_plr, _tag, _ctx] remoteExecCall ["AqPDA_fnc_taskHubServer", 2];
    }];

1.2 Сервер: роутер хаба (решает, какой тип задачи выдавать)
    // mission\functions\tasksHub\fn_taskHubServer.sqf  (SERVER ONLY)
    if (!isServer) exitWith {};
    params ["_plr","_tag","_ctx"];

    switch (toLower _tag) do {
      case "kill":     { [_plr,_tag,_ctx] call PDA_fnc_grantPersonalTask; };
      case "logistic": { [_plr,_tag,_ctx] call PDA_fnc_grantPersonalTask; };
      case "destroy":  { [_plr,_tag,_ctx] call PDA_fnc_grantGroupTask;    }; // ← пример: "destroy" делаем групповым
      default          { [_plr,_tag,_ctx] call PDA_fnc_grantPersonalTask; };
    };

1.3 Реализации выдачи (SERVER ONLY)

    a) Персональный ванильный таск ИГРОКУ:
       // mission\functions\tasksHub\fn_grantPersonalTask.sqf
       if (!isServer) exitWith {};
       params ["_plr","_tag","_ctx"];

       // Сервер решает цель/точку/тип, но создаёт таск ЛОКАЛЬНО у клиента
       private _dest = [getPos _plr, 400 + random 300, random 360] call BIS_fnc_relPos;
       private _taskId = format ["pda_p_%1_%2", getPlayerUID _plr, round time];
       private _title = "Персональная задача";
       private _desc  = format ["Выдано по тегу: %1", _tag];
       private _type  = "move"; // или "kill"/"destroy"/"attack" и т.д.

       [
         [_taskId,_title,_desc,_dest,_type],
         {
           params ["_taskId","_title","_desc","_dest","_type"];
           private _owner = player; // локальный клиент
           private _task = [
             _owner, _taskId, [_desc, _title, ""], _dest,
             "CREATED", 1, true, _type, true
           ] call BIS_fnc_taskCreate;
           [_task,"ASSIGNED",true] call BIS_fnc_taskSetState;
           [_task,_dest] call BIS_fnc_taskSetDestination;
         }
       ] remoteExecCall ["BIS_fnc_call", _plr];

    b) Групповая задача (для ВСЕЙ группы игрока):
       // mission\functions\tasksHub\fn_grantGroupTask.sqf
       if (!isServer) exitWith {};
       params ["_plr","_tag","_ctx"];

       private _grp = group _plr;
       private _dest = [getPos leader _grp, 600 + random 400, random 360] call BIS_fnc_relPos;
       private _taskId = format ["pda_g_%1_%2", groupId _grp, round time];
       private _title = "Групповая задача";
       private _desc  = format ["Группе %1. Тег: %2", groupId _grp, _tag];
       private _type  = "move";

       private _task = [
         _grp, _taskId, [_desc, _title, ""], _dest,
         "CREATED", 1, true, _type, true
       ] call BIS_fnc_taskCreate;
       [_task,"ASSIGNED",true] call BIS_fnc_taskSetState;
       [_task,_dest] call BIS_fnc_taskSetDestination;

1.4 CfgFunctions (пример вставки)
    class CfgFunctions {
      class AqPDA {
        class TasksHub {
          file = "mission\functions\tasksHub";
          class registerPDAHub  { postInit = 1; };
          class taskHubServer   {};
          class grantPersonalTask {};
          class grantGroupTask  {};
        };
      };
    }


2) КАК ПУШИТЬ ЗАДАЧИ В КПК ИГРОКАМ
------------------------------------------------------------
PDA_fnc_taskPush — КЛИЕНТСКАЯ функция мода, добавляет запись в КПК.
Зови её НА КЛИЕНТЕ получателя (с сервера через remoteExecCall).

СЕРВЕР → КОНКРЕТНОМУ ИГРОКУ:
  ["Ликвидация","Устранить конкурента","Описание...","kill"]
    remoteExecCall ["PDA_fnc_taskPush", _plr];

СЕРВЕР → ВСЕМ:
  ["Брифинг","Общий сбор у штаба.","logistic"]
    remoteExecCall ["PDA_fnc_taskPush", 0];

СЕРВЕР → СТОРОНЕ:
  {
    ["Приказ","Перестроиться в клин.","destroy"]
      remoteExecCall ["PDA_fnc_taskPush", _x];
  } forEach (allPlayers select { side _x == WEST });

СЕРВЕР → ГРУППЕ:
  {
    ["Логистика","Доставить ящики на FOB.","logistic"]
      remoteExecCall ["PDA_fnc_taskPush", _x];
  } forEach (units _grp select { isPlayer _x });


3) ПОЛНЫЙ ПОТОК (для понимания)
------------------------------------------------------------
- Сервер пушит запись задачи в КПК игрока → PDA_fnc_taskPush на его клиенте.
- Игрок открывает КПК → «Задачи» → выбирает → «Принять».
- Мод берёт ТЕГ и вызывает missionNamespace["PDA_TaskHub"] (на клиенте).
- Клиент шлёт на сервер: [_plr,_tag,_ctx] → PDA_fnc_taskHubServer.
- Сервер, по switch, вызывает grantPersonalTask ИЛИ grantGroupTask.
- Ванильная задача создаётся и назначается (персонально/группа).


4) ПРИМЕРЫ СХЕМ РОУТИНГА
------------------------------------------------------------
A) Всегда персонально
   switch (toLower _tag) do {
     default { [_plr,_tag,_ctx] call PDA_fnc_grantPersonalTask; };
   };

B) Смешанная (destroy → групповая, остальное → персонально)
   switch (toLower _tag) do {
     case "destroy":  { [_plr,_tag,_ctx] call PDA_fnc_grantGroupTask; };
     default:         { [_plr,_tag,_ctx] call PDA_fnc_grantPersonalTask; };
   };

C) Всегда групповая
   [_plr,_tag,_ctx] call PDA_fnc_grantGroupTask;


5) ЧАСТЫЕ ОШИБКИ
------------------------------------------------------------
- Не зарегистрирован PDA_TaskHub на клиентах → «Принять» ничего не делает.
- Пытаюсь вызвать PDA_fnc_taskPush с сервера напрямую (без remoteExecCall) → запись в КПК не появится.
- Персональные задачи нужно создавать ЛОКАЛЬНО у клиента (через remoteExec), а групповые — на сервере (владелец "group").
- Перепутаны префиксы: внутри мода — PDA_, в миссии — свой (PDA_/MSN_/MY_) по желанию.


6) ШПАРГАЛКА
------------------------------------------------------------
Пуш записи в КПК игроку (сервер):
  ["type","title","text","tag"] remoteExecCall ["PDA_fnc_taskPush", _plr];

Регистрация хаба (клиент):
  missionNamespace setVariable ["PDA_TaskHub", { params ["_tag","_ctx"]; [_this select 0, _this select 1] remoteExecCall ["AqPDA_fnc_taskHubServer", 2]; }];

Роутер на сервере:
  switch (toLower _tag) do {
    case "destroy": { [_plr,_tag,_ctx] call PDA_fnc_grantGroupTask; };
    default:        { [_plr,_tag,_ctx] call PDA_fnc_grantPersonalTask; };
  };

Персональная задача:
  [ [args], { /* BIS_fnc_taskCreate на клиенте */ } ] remoteExecCall ["BIS_fnc_call", _plr];

Групповая задача:
  /* BIS_fnc_taskCreate на сервере, owner = group */

============================================================
