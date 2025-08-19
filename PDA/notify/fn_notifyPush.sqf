params ["_title","_text",["_tag","news"]];
if (isNil "_title") exitWith {};

private _q = missionNamespace getVariable ["PDA_NotifyQueue", []];
_q pushBack [_title, _text, _tag];
missionNamespace setVariable ["PDA_NotifyQueue", _q];

private _now  = diag_tickTime;
private _last = missionNamespace getVariable ["PDA_LastNotifySound", -1];
if (_last < 0 || {(_now - _last) > 0.5}) then {
  private _snd = switch (toLower _tag) do {
    case "warning": {"PDA_NotifyWarning"};
    case "sos":     {"PDA_NotifySOS"};
    default        {"PDA_NotifyNews"};
  };
  playSound _snd;
  missionNamespace setVariable ["PDA_LastNotifySound", _now];
};

disableSerialization;
private _disp   = uiNamespace getVariable ["PDA_Display", displayNull];
private _screen = uiNamespace getVariable ["PDA_ScreenGroup", controlNull];
if (!isNull _disp && {!isNull _screen} && {ctrlShown _screen}) then {
  [] call PDA_fnc_notifyRender;
};
