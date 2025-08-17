disableSerialization;

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
private _grp  = uiNamespace getVariable ["AQPH_Group",   controlNull];
if (isNull _disp || {isNull _grp}) exitWith {};

// спрячем домашний стол
{ if (!isNull _x) then { _x ctrlSetFade 1; _x ctrlCommit 0.10; } } forEach (uiNamespace getVariable ["AQPH_HomeWidgets", []]);

// убьём предыдущее приложение, если было
private _old = uiNamespace getVariable ["AQPH_AppGroup", controlNull];
if (!isNull _old) then { ctrlDelete _old; };

private _p  = ctrlPosition _grp;
private _gw = _p#2;
private _gh = _p#3;
private _barH = uiNamespace getVariable ["AQPH_BarH", 0.085 * _gh];

// базовая рамка окна почты (двигай при желании весь экран)
private _appX = 0;
private _appY = 0;
private _appW = _gw;
private _appH = _gh;

private _app = _disp ctrlCreate ["RscControlsGroup", -1, _grp];
_app ctrlSetPosition [_appX, _appY, _appW, _appH];
_app ctrlCommit 0;
uiNamespace setVariable ["AQPH_AppGroup", _app];

// ФОН ПРИЛОЖЕНИЯ — остаётся всегда под контентом
private _bgPic = _disp ctrlCreate ["RscPicture", -1, _app];
_bgPic ctrlSetText "aq_phone\ui\app_mail_bg_ca.paa";
_bgPic ctrlSetPosition [0, 0, _appW, _appH];

_bgPic ctrlCommit 0;
uiNamespace setVariable ["AQPH_AppBgPic", _bgPic];  // <- запомним, чтобы не удалить при перерисовке

// рендер списка
[] call AQPH_fnc_mailRenderList;
