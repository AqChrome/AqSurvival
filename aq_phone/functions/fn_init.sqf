/*
  Инициализация: регистрируем клавиши, настраиваем список меню.
*/
if (!hasInterface) exitWith {};
[] call AQPH_fnc_setMenuItems;
[] call AQPH_fnc_registerKeys;
