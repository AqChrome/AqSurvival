if (!hasInterface) exitWith {};

uiNamespace setVariable ["AQTB_open", false];
uiNamespace setVariable ["AQTB_CurrentView", controlNull];
uiNamespace setVariable ["AQTB_HomeCtrls", []];
uiNamespace setVariable ["AQTB_MapCtrl", controlNull];
uiNamespace setVariable ["AQTB_Layer", ["AQTB"] call BIS_fnc_rscLayer];

// Пример задач для экрана Tasks
private _example = [
  ["Основная задача", "Захватить радиовышку и удерживать до прибытия подкрепления.", ""],
  ["Цель на ликвидацию", "Ликвидировать «Ворона». Фото цели ниже.", "aq_tablet\\ui\\tasks_bg_ca.paa"]
];
["SET", _example] call AQTB_fnc_setTasks;

// Пункт колёсика + восстановление после респавна
[] spawn {
  waitUntil { !isNull player && {player == player} };
  [player] call AQTB_fnc_registerAction;
  player addEventHandler ["Respawn", {
    params ["_unit"];
    [_unit] call AQTB_fnc_registerAction;
  }];
};
