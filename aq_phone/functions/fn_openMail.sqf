disableSerialization;

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
private _grp  = uiNamespace getVariable ["AQPH_Group", controlNull];
if (isNull _disp || {isNull _grp}) exitWith {};

// спрячем виджеты домашнего стола (фон+иконка)
{ if (!isNull _x) then { _x ctrlSetFade 1; _x ctrlCommit 0.10; } } forEach (uiNamespace getVariable ["AQPH_HomeWidgets", []]);

// геометрия
private _p  = ctrlPosition _grp;
private _gw = _p#2;
private _gh = _p#3;
private _barH = 0.085 * _gh;   // должно совпадать с buildUI

// контейнер приложения
private _app = _disp ctrlCreate ["RscControlsGroup", -1, _grp];
_app ctrlSetPosition [0, _barH, _gw, _gh - _barH];
_app ctrlCommit 0;
uiNamespace setVariable ["AQPH_AppGroup", _app];

// белый фон
private _bg = _disp ctrlCreate ["RscText", -1, _app];
_bg ctrlSetBackgroundColor [1,1,1,1];
_bg ctrlSetPosition [0, 0, _gw, _gh - _barH];
_bg ctrlCommit 0;

// карточка письма
private _pad = 0.04 * _gw;
private _cardH = 0.38 * _gh;

private _card = _disp ctrlCreate ["RscText", -1, _app];
_card ctrlSetBackgroundColor [0.95,0.95,0.98,1];
_card ctrlSetPosition [_pad, 0.04 * _gh, _gw - 2*_pad, _cardH];
_card ctrlCommit 0;

// заголовок
private _from = "От: HQ";
private _subj = "Тема: Новая задача";
private _hdr = _disp ctrlCreate ["RscStructuredText", -1, _app];
_hdr ctrlSetPosition [_pad + 0.012*_gw, 0.04*_gh + 0.012*_gh, _gw - 3*_pad, 0.06*_gh];
_hdr ctrlSetBackgroundColor [0,0,0,0];
_hdr ctrlSetStructuredText parseText format [
  "<t size='0.95' color='#111111'>%1</t><br/><t size='0.9' color='#333333'>%2</t>",
  _from, _subj
];
_hdr ctrlCommit 0;

// тело
private _body = "Группа «Альфа», выдвигайтесь к точке БРАВО. Дальнейшие инструкции получите на месте.";
private _txt = _disp ctrlCreate ["RscStructuredText", -1, _app];
_txt ctrlSetPosition [_pad + 0.012*_gw, 0.04*_gh + 0.09*_gh, _gw - 3*_pad, _cardH - 0.12*_gh];
_txt ctrlSetBackgroundColor [0,0,0,0];
_txt ctrlSetStructuredText parseText format ["<t size='0.9' color='#111111'>%1</t>", _body];
_txt ctrlCommit 0;

// кнопка Назад
private _back = _disp ctrlCreate ["RscButton", -1, _app];
_back ctrlSetText "Назад";
_back ctrlSetPosition [_pad, 0.04*_gh + _cardH + 0.02*_gh, 0.18*_gw, 0.06*_gh];
_back ctrlCommit 0;
_back ctrlAddEventHandler ["ButtonClick", { [] call AQPH_fnc_home }];
