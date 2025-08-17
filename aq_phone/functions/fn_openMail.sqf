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

// ======== LAYOUT ОКНА (правь при нужде) ========
private _appX = 0;        // смещение всего окна почты по X
private _appY = 0;        // смещение по Y (0 = от самого верха телефона)
private _appW = _gw;      // ширина окна
private _appH = _gh;      // высота окна
// ===============================================

// корневой контейнер приложения
private _app = _disp ctrlCreate ["RscControlsGroup", -1, _grp];
_app ctrlSetPosition [_appX, _appY, _appW, _appH];
_app ctrlCommit 0;
uiNamespace setVariable ["AQPH_AppGroup", _app];

// ФОН приложения (НЕ в скролле, остаётся под всем)
private _bgPic = _disp ctrlCreate ["RscPicture", -1, _app];
_bgPic ctrlSetText "aq_phone\ui\app_mail_bg_ca.paa";
_bgPic ctrlSetPosition [0, 0, _appW, _appH];
_bgPic ctrlCommit 0;
uiNamespace setVariable ["AQPH_AppBgPic", _bgPic];

// ======== LAYOUT ВНУТРИ ОКНА (список/футер) ==================
private _padSide = 0.15 * _appW;   // боковые поля списка/футера
private _padTop  = 0.05 * _appH;   // отступ сверху для списка
private _padBot  = 0.17 * _appH;   // ← ВОТ ЭТОЙ ЦИФРОЙ БУДЕШЬ ПОДНИМАТЬ "НАЗАД"
private _footerH = 0.07 * _appH;   // высота полосы футера
// ==============================================================

// Область списка (НЕ скроллится сама, скролл внутри неё)
private _listArea = _disp ctrlCreate ["RscControlsGroupNoScrollbars", -1, _app];
_listArea ctrlSetPosition [
  _padSide,
  _padTop,
  _appW - 2*_padSide,
  _appH - _padTop - _padBot - _footerH   // ← место до футера
];
_listArea ctrlCommit 0;

// Футер с кнопкой "Назад" (фиксированный)
private _footerY = _appH - _footerH - _padBot;        // ← вместо прежнего -0.02*_appH
private _footer = _disp ctrlCreate ["RscControlsGroupNoScrollbars", -1, _app];
_footer ctrlSetPosition [ _padSide, _footerY, _appW - 2*_padSide, _footerH ];
_footer ctrlCommit 0;

private _back = _disp ctrlCreate ["RscButton", -1, _footer];
_back ctrlSetText "Назад";
_back ctrlSetPosition [ 0, 0, 0.22 * _appW, _footerH ];
_back ctrlCommit 0;
_back ctrlAddEventHandler ["ButtonClick", { [] call AQPH_fnc_home }];


// Теперь отрисуем содержимое списка
[] call AQPH_fnc_mailRenderList;
