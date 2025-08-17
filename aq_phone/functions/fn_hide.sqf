/* aq_phone\functions\fn_hide.sqf */

if !(uiNamespace getVariable ["AQPH_open", false]) exitWith {};
disableSerialization;

private _grp = uiNamespace getVariable ["AQPH_Group", controlNull];

// Анимация уезда вниз (если группа ещё жива)
if (!isNull _grp) then {
  private _p = ctrlPosition _grp;
  private _offY = safeZoneY + safeZoneH + 0.01;
  _grp ctrlSetPosition [_p select 0, _offY, _p select 2, _p select 3];
  _grp ctrlCommit 0.30;

  // подождём завершения коммита; это ок в scheduled-среде
  waitUntil { ctrlCommitted _grp };
};

// Закрываем диалог и чистим стейт
closeDialog 2;

uiNamespace setVariable ["AQPH_open", false];
uiNamespace setVariable ["AQPH_Display", displayNull];
uiNamespace setVariable ["AQPH_Group", controlNull];
uiNamespace setVariable ["AQPH_Controls", []];
