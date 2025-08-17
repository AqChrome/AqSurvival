disableSerialization;

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
private _grp  = uiNamespace getVariable ["AQPH_Group",   controlNull];
if (isNull _disp || {isNull _grp}) exitWith {};

// спрячем домашний стол
{ if (!isNull _x) then { _x ctrlSetFade 1; _x ctrlCommit 0.10; } } forEach (uiNamespace getVariable ["AQPH_HomeWidgets", []]);

// удалить прежний экран приложения (если был)
private _oldApp = uiNamespace getVariable ["AQPH_AppGroup", controlNull];
if (!isNull _oldApp) then { ctrlDelete _oldApp; uiNamespace setVariable ["AQPH_AppGroup", controlNull]; };

// удалить висящий экран письма (если вдруг остался)
private _oldMsg = uiNamespace getVariable ["AQPH_MailViewGroup", controlNull];
if (!isNull _oldMsg) then { ctrlDelete _oldMsg; uiNamespace setVariable ["AQPH_MailViewGroup", controlNull]; };

// окно приложения «Почта» на всю область телефона
private _p  = ctrlPosition _grp;
private _gw = _p#2;
private _gh = _p#3;

private _app = _disp ctrlCreate ["RscControlsGroupNoScrollbars", -1, _grp];
_app ctrlSetPosition [0, 0, _gw, _gh];
_app ctrlCommit 0;
uiNamespace setVariable ["AQPH_AppGroup", _app];

// фон приложения
private _bg = _disp ctrlCreate ["RscPicture", -1, _app];
_bg ctrlSetText "aq_phone\ui\app_mail_bg_ca.paa";
_bg ctrlSetPosition [0, 0, _gw, _gh];
_bg ctrlCommit 0;
uiNamespace setVariable ["AQPH_AppBgPic", _bg];

// разметка областей: список и футер
private _padSide = 0.05 * _gw;
private _padTop  = 0.05 * _gh;
private _padBot  = 0.12 * _gh;   // ↑ этой цифрой поднимаешь «Назад»
private _footerH = 0.07 * _gh;

private _listArea = _disp ctrlCreate ["RscControlsGroupNoScrollbars", -1, _app];
_listArea ctrlSetPosition [_padSide, _padTop, _gw - 2*_padSide, _gh - _padTop - _padBot - _footerH];
_listArea ctrlCommit 0;
uiNamespace setVariable ["AQPH_ListArea", _listArea];

private _footerY = _gh - _footerH - _padBot;
private _footer = _disp ctrlCreate ["RscControlsGroupNoScrollbars", -1, _app];
_footer ctrlSetPosition [_padSide, _footerY, _gw - 2*_padSide, _footerH];
_footer ctrlCommit 0;
uiNamespace setVariable ["AQPH_AppFooter", _footer];

private _back = _disp ctrlCreate ["RscButton", -1, _footer];
_back ctrlSetText "Назад";
_back ctrlSetPosition [0, 0, 0.22 * _gw, _footerH];
_back ctrlCommit 0;
_back ctrlAddEventHandler ["ButtonClick", { [] call AQPH_fnc_home }];

// отрисуем список
[] call AQPH_fnc_mailRenderList;
