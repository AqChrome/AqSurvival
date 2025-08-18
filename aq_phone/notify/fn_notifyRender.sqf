/*
  Показать верхнее уведомление из очереди как оверлей на весь экран КПК.
*/
disableSerialization;

private _disp   = uiNamespace getVariable ["AQPH_Display", displayNull];
private _screen = uiNamespace getVariable ["AQPH_ScreenGroup", controlNull];
if (isNull _disp || {isNull _screen}) exitWith {};

private _q = missionNamespace getVariable ["AQPH_NotifyQueue", []];
if (_q isEqualTo []) exitWith {};

private _active = uiNamespace getVariable ["AQPH_NotifyOverlay", controlNull];
if (!isNull _active) exitWith {};

private _top   = _q select 0;               // [title, text, tag?]
private _title = _top param [0,""];
private _text  = _top param [1,""];
private _tag   = toLower (_top param [2,"news"]);

// Геометрия
private _pos = ctrlPosition _screen;
private _w = _pos select 2;
private _h = _pos select 3;

// Цвета по тегу (мягкие пастельные)
private _bgCol   = [0.85,0.93,1.00,0.97]; // news (голубоватый)
private _hdrHex  = "#0d2a4a";
switch (_tag) do {
  case "warning": {
    _bgCol  = [1.00,0.96,0.78,0.97];  // желтоватый
    _hdrHex = "#6b5e00";
  };
  case "sos": {
    _bgCol  = [1.00,0.82,0.82,0.97];  // красноватый
    _hdrHex = "#5a0000";
  };
};

// Оверлей
private _overlay = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1600, _screen];
_overlay ctrlSetPosition [0, 0, _w, _h];
_overlay ctrlSetFade 1;
_overlay ctrlCommit 0;
uiNamespace setVariable ["AQPH_NotifyOverlay", _overlay];

// Подложка
private _bg = _disp ctrlCreate ["RscText", -1, _overlay];
_bg ctrlSetPosition [0, 0, _w, _h];
_bg ctrlSetBackgroundColor _bgCol;
_bg ctrlCommit 0;

// Тема
private _hdr = _disp ctrlCreate ["RscStructuredText", -1, _overlay];
_hdr ctrlSetPosition [0.01, 0.03, _w - 0.02, 0.06];
_hdr ctrlCommit 0;
_hdr ctrlSetStructuredText parseText format [
  "<t shadow='0' align='center' color='%1' font='PuristaBold' size='1.0'>%2</t>",
  _hdrHex, _title
];

// Текст
private _body = _disp ctrlCreate ["RscStructuredText", -1, _overlay];
_body ctrlSetPosition [0.015, 0.11, _w - 0.03, _h - 0.11 - 0.12];
_body ctrlCommit 0;
_body ctrlSetStructuredText parseText format [
  "<t shadow='0' align='left' color='#151515' font='PuristaLight' size='0.9'>%1</t>",
  _text
];

// Кнопка закрыть
private _btn = _disp ctrlCreate ["RscButton", 1650, _overlay];
_btn ctrlSetText "Закрыть";
_btn ctrlSetPosition [_w*0.5 - 0.12, _h - 0.09, 0.24, 0.06];
_btn ctrlCommit 0;
_btn ctrlAddEventHandler ["ButtonClick", { [] call AQPH_fnc_notifyClose }];

// Плавное появление
_overlay ctrlSetFade 0;
_overlay ctrlCommit 0.12;
