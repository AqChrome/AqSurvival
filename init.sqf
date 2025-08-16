[] execVM "core\settings.sqf";

[{
    // Инициализация только на клиенте
    if (hasInterface) then {
        // Подключаем основной скрипт инициализации мода
        [] execVM "core\ui\hud\initHUD.sqf";
        [] execVM "core\survival\initSurvival.sqf";
    };
}, [], 1] call CBA_fnc_waitAndExecute;