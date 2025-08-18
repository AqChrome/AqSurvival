/*
  Включение экрана: скрываем off-оверлей и показываем _home с небольшим фейдом.
*/
disableSerialization;

private _screen  = uiNamespace getVariable ["AQPH_ScreenGroup", controlNull];
private _offPic  = uiNamespace getVariable ["AQPH_OffOverlay", controlNull];
private _home    = uiNamespace getVariable ["AQPH_HomeGroup", controlNull];
if (isNull _screen) exitWith {};

// Убираем "выключенный" экран
if (!isNull _offPic) then { _offPic ctrlShow false; };

// Показываем главное меню
if (!isNull _home) then {
  _home ctrlShow true;
  _home ctrlSetFade 1;
  _home ctrlCommit 0;
  _home ctrlSetFade 0;
  _home ctrlCommit 0.12;
};
