if (!hasInterface) exitWith {};

uiNamespace setVariable ["AQPH_open", false];
uiNamespace setVariable ["AQPH_Display", displayNull];
uiNamespace setVariable ["AQPH_Group", controlNull];
uiNamespace setVariable ["AQPH_Controls", []];

[] call AQPH_fnc_registerKeys;  // повесим обработчик на стрелку ↑
