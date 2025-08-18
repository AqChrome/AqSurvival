/*
  Единственная кнопка управления КПК: Right Shift (DIK 54).
  Логика: если закрыт — открыть; если открыт — закрыть.
  Встроен антидребезг 250 мс, чтобы удержание не вызывало повторов.
*/
if (!hasInterface) exitWith {};

private _dispGame = findDisplay 46;
if (isNull _dispGame) exitWith {
  uiSleep 0.1;
  [] call AQPH_fnc_registerKeys;
};

// Если уже есть наш EH — не дублируем
private _ehId = _dispGame getVariable ["AQPH_KeyEH",-1];
if (_ehId >= 0) exitWith {};

missionNamespace setVariable ["AQPH_LastToggle", -1];

_ehId = _dispGame displayAddEventHandler ["KeyDown", {
  params ["_display","_key","_shift","_ctrl","_alt"];

  // Right Shift = 54
  if (_key != 54) exitWith { false };

  private _now = time;
  private _last = missionNamespace getVariable ["AQPH_LastToggle", -1];
  if (_last >= 0 && { (_now - _last) < 0.25 }) exitWith { true };  // антидребезг

  missionNamespace setVariable ["AQPH_LastToggle", _now];

  // Тоггл
  private _cur = uiNamespace getVariable ["AQPH_Display", displayNull];
  if (isNull _cur) then {
    [] call AQPH_fnc_open;
  } else {
    [] call AQPH_fnc_close;
  };

  true  // мы обработали клавишу
}];

_dispGame setVariable ["AQPH_KeyEH", _ehId];
