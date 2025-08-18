/*
  Выключение экрана: скрываем все активные страницы и показываем off-оверлей.
*/
disableSerialization;

private _screen  = uiNamespace getVariable ["AQPH_ScreenGroup", controlNull];
private _offPic  = uiNamespace getVariable ["AQPH_OffOverlay", controlNull];
private _home    = uiNamespace getVariable ["AQPH_HomeGroup", controlNull];
private _tasks   = uiNamespace getVariable ["AQPH_TasksGroup", controlNull];
private _detail  = uiNamespace getVariable ["AQPH_TaskDetailGroup", controlNull];
if (isNull _screen) exitWith {};

// Скрыть страницы
{ if (!isNull _x) then { _x ctrlShow false; }; } forEach [_home, _tasks, _detail];

// Показать "выключенный" экран
if (!isNull _offPic) then {
  _offPic ctrlShow true;
  _offPic ctrlSetFade 0;
  _offPic ctrlCommit 0;
};
