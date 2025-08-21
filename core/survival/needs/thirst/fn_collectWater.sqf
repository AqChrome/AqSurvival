/*
  В колёсике появляется "Набрать воду" ТОЛЬКО возле объектов из AQ_WaterSourceClasses.
  После выбора — hold-action (5 сек). По завершении первая пустая тара (aq_canFill=1)
  меняется на класс из aq_fillWith.

  Требования к конфигу:
    ПУСТАЯ: aq_canFill = 1; aq_fillWith = "Класс_полной";
    ПОЛНАЯ: replaceWith = "Класс_пустой";  // это для питья, этот скрипт не трогает
*/

if (!hasInterface) exitWith {};

AQ_WATER_DEBUG = false;

// ========= НАСТРОЙКИ =========
if (isNil "AQ_WaterSourceClasses") then {
  AQ_WaterSourceClasses = [
    "Land_WaterPump_F",
    "Land_WellPump_F",
    "Land_Pumpa",
    "Land_WaterCooler_01_new_F",
    "Land_WaterCooler_01_old_F",
    "Land_BarrelWater_F",
    "Land_WaterTank_F",
    "Land_WaterTank_03_F"
  ];
};
if (isNil "AQ_WaterHoldDuration") then { AQ_WaterHoldDuration = 5; };
if (isNil "AQ_WaterSoundPath")   then { AQ_WaterSoundPath   = ""; };

AQ_fnc_water_buildMap = {
  private _map = []; // [empty, full]
  {
    private _cls = configName _x;
    if (getNumber (_x >> "aq_canFill") == 1) then {
      private _full = getText (_x >> "aq_fillWith");
      if (_full != "" && { isClass (configFile >> "CfgWeapons" >> _full) }) then {
        _map pushBack [_cls, _full];
      } else {
        if (AQ_WATER_DEBUG) then {
          systemChat format ["[WATER] '%1' has aq_canFill=1 but invalid aq_fillWith '%2'", _cls, _full];
        };
      };
    };
  } forEach ("true" configClasses (configFile >> "CfgWeapons"));

  missionNamespace setVariable ["AQ_water_map", _map];
  _map
};

AQ_fnc_water_fullFor = {
  params ["_emptyCls"];
  private _map = missionNamespace getVariable ["AQ_water_map", []];
  if (_map isEqualTo []) then { _map = [] call AQ_fnc_water_buildMap; };
  private _i = _map findIf { (_x select 0) isEqualTo _emptyCls };
  if (_i == -1) exitWith { "" };
  (_map select _i) select 1
};

AQ_fnc_water_findEmpty = {
  params [["_u", player, [objNull]]];
  private _map = missionNamespace getVariable ["AQ_water_map", []];
  if (_map isEqualTo []) then { _map = [] call AQ_fnc_water_buildMap; };
  private _empties = _map apply { _x select 0 };
  private _owned = (items _u) + (magazines _u);
  private _i = _owned findIf { _x in _empties };
  if (_i == -1) exitWith { "" };
  _owned select _i
};

// ========= ТОЛЬКО КОЛОНКИ: детектор источника =========
AQ_fnc_water_isNearSource = {
  params [["_u", player, [objNull]]];
  if (isNull _u) exitWith { false };
  (count (nearestObjects [_u, AQ_WaterSourceClasses, 3])) > 0
};

// ========= ПУНКТ В КОЛЕСО =========
AQ_fnc_water_setupAction = {
  if (isNil { player getVariable "AQ_collectWater_action" }) then {
    private _id = player addAction [
      localize "STR_AQ_ACTION_COLLECT_WATER",
      {
        private _e = [player] call AQ_fnc_water_findEmpty;
        if (_e isEqualTo "") exitWith { titleText ["Нет пустой тары.", "PLAIN DOWN", 0.25]; };

        private _f = [_e] call AQ_fnc_water_fullFor;
        if (_f isEqualTo "") exitWith { titleText ["Не удалось определить целевой предмет.", "PLAIN DOWN", 0.25]; };

        if !((currentWeapon player)=="") then {
          player action["SWITCHWEAPON",player,player,-1];
        };
        player playAction "Crouch";

        [
          "Набираем воду...",         // _title STRING
          7,                          // _totalTime NUMBER (сек)
          {                           // _condition CODE (каждый кадр; true => продолжаем)
            ([player] call AQ_fnc_water_isNearSource) && { alive player }
          },
          {                           // _onSuccess CODE
            params ["_args", "_ok", "_elapsed", "_total", "_failCode"];
            _args params ["_empty","_full"];

            // удалить пустую, добавить полную
            if (_empty in (items player)) then {
              player removeItem _empty;
            } else {
              if (_empty in (magazines player)) then { player removeMagazine _empty; };
            };

            if (isClass (configFile >> "CfgMagazines" >> _full)) then {
              player addMagazine _full;
            } else {
              player addItem _full;
            };

            titleText ["Вода набрана.", "PLAIN DOWN", 0.25];
          },
          {                           // _onFailure CODE (ушёл/ESC и т.п.)
            hintSilent "Набор воды прерван.";
          },
          [_e, _f]                    // _arguments ANY -> прилетят в коллбеки как _this #0
        ] call CBA_fnc_progressBar;
        
      },
      nil,
      1.5, true, true, "",
      "[player] call AQ_fnc_water_isNearSource",  // показывать ТОЛЬКО у источника
      3, false
    ];
    player setVariable ["AQ_collectWater_action", _id];
  };
};


// init
[] call AQ_fnc_water_buildMap;
[] call AQ_fnc_water_setupAction;
player addEventHandler ["Respawn", { [] call AQ_fnc_water_setupAction }];
