disableSerialization;

private _disp = uiNamespace getVariable ["AQTB_Display", displayNull];
if (isNull _disp) exitWith {};

// Прячем домашние контролы
{ if (!isNull _x) then { _x ctrlShow false } } forEach (uiNamespace getVariable ["AQTB_HomeCtrls", []]);

private _sx = safeZoneX;
private _sy = safeZoneY;
private _sw = safeZoneW;
private _sh = safeZoneH;

private _gw = 0.88 * _sw;
private _gh = 0.84 * _sh;

// Группа
private _grp = _disp ctrlCreate ["RscControlsGroup", -1];
_grp ctrlSetPosition [_sx + 0.06*_sw, _sy + 0.08*_sh, _gw, _gh];
_grp ctrlCommit 0;
uiNamespace setVariable ["AQTB_CurrentView", _grp];

// Фон блокнота
private _bg = _disp ctrlCreate ["RscPicture", -1, _grp];
_bg ctrlSetText "aq_tablet\\ui\\tasks_bg_ca.paa";
_bg ctrlSetPosition [0, 0, _gw, _gh];
_bg ctrlCommit 0;

// Текст задач
private _text = _disp ctrlCreate ["RscStructuredText", -1, _grp];
_text ctrlSetPosition [0.04*_gw, 0.04*_gh, 0.80*_gw, 0.70*_gh];
_text ctrlCommit 0;

private _tasks = missionNamespace getVariable ["AQTB_Tasks", []];
private _html = "<t align='left' size='1.0' color='#2a2a2a'>";
{
  _x params ["_title", "_body", ["_img",""]];
  _html = _html
    + format ["<t size='1.25' font='PuristaSemiBold'>%1</t><br/>", _title]
    + format ["%1<br/>", _body];
  if (_img != "") then {
    _html = _html + format ["<img image='%1' align='left' w='380' h='380'/><br/>", _img];
  };
  _html = _html + "<br/>";
} forEach _tasks;
_html = _html + "</t>";

_text ctrlSetStructuredText parseText _html;

// Подгоняем высоту под контент
private _th = ctrlTextHeight _text;
private _pos = ctrlPosition _text;
_text ctrlSetPosition [_pos#0, _pos#1, _pos#2, _th max (_pos#3)];
_text ctrlCommit 0;

// Назад
private _back = _disp ctrlCreate ["RscButton", -1, _grp];
_back ctrlSetText "Назад";
_back ctrlSetPosition [0.04*_gw, 0.78*_gh, 0.14*_gw, 0.05*_gh];
_back ctrlCommit 0;
_back ctrlAddEventHandler ["ButtonClick", {
  disableSerialization;
  private _grp = uiNamespace getVariable ["AQTB_CurrentView", controlNull];
  if (!isNull _grp) then { ctrlDelete _grp };
  { if (!isNull _x) then { _x ctrlShow true } } forEach (uiNamespace getVariable ["AQTB_HomeCtrls", []]);
  uiNamespace setVariable ["AQTB_CurrentView", controlNull];
}];
