/*
  Добавить уведомление в очередь.
  Параметры:
    0: STRING - тема
    1: STRING - текст
    2: STRING - тег ("news" | "warning" | "sos"), по умолчанию "news"
*/
params ["_title","_text",["_tag","news"]];
if (isNil "_title") exitWith {};

private _q = missionNamespace getVariable ["AQPH_NotifyQueue", []];
_q pushBack [_title, _text, _tag];
missionNamespace setVariable ["AQPH_NotifyQueue", _q];

// --- звук по тегу с анти-спамом ---
private _now  = diag_tickTime;   // локальный таймер
private _last = missionNamespace getVariable ["AQPH_LastNotifySound", -1];
if (_last < 0 || {(_now - _last) > 0.5}) then {
  private _snd = switch (toLower _tag) do {
    case "warning": {"AQPH_NotifyWarning"};
    case "sos":     {"AQPH_NotifySOS"};
    default        {"AQPH_NotifyNews"};
  };
  playSound _snd;
  missionNamespace setVariable ["AQPH_LastNotifySound", _now];
};

// Если экран уже открыт — показать сразу (без повторного звука)
disableSerialization;
private _disp   = uiNamespace getVariable ["AQPH_Display", displayNull];
private _screen = uiNamespace getVariable ["AQPH_ScreenGroup", controlNull];
if (!isNull _disp && {!isNull _screen} && {ctrlShown _screen}) then {
  [] call AQPH_fnc_notifyRender;
};
