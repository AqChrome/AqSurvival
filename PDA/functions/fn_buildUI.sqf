/*
  PDA/functions/fn_buildUI.sqf
  Масштаб и позиция управляются двумя числами:
    _SCALE — общий масштаб всего КПК (по центру)
    _MOVE  — равномерный сдвиг вправо/вниз (одним числом)

  При необходимости тонкой правки можно использовать _SHIFT_X/_SHIFT_Y (опционально).
*/

disableSerialization;
params ["_disp"];
if (isNull _disp) exitWith {};

// -------------------- КОНТРОЛЬНЫЕ РУЧКИ --------------------
private _SCALE   = 1.15;   // 1.15 = +15%, 0.85 = −15%
private _MOVE    = 0.00;   // сдвиг вправо/вниз одним числом (например, 0.02)
private _LOCKCTR = true;   // сохранять центр при масштабировании (рекомендую true)

// (опционально) тонкая подстройка по осям — оставь 0.00, если не нужно:
private _SHIFT_X = 0.00;
private _SHIFT_Y = -0.15;
// -----------------------------------------------------------

// БАЗОВАЯ ГЕОМЕТРИЯ (как у тебя)
private _BASE_X = 1.13;
private _BASE_Y = 0.54;
private _BASE_W = 0.35;
private _BASE_H = 0.79;

// Отступы дисплея внутри корпуса (абсолютные, в тех же единицах)
private _OX = 0.0512;     // от левого края корпуса до дисплея
private _OY = 0.1245;     // от верхнего края корпуса до дисплея
private _SW = 0.100005;   // на сколько урезать ширину дисплея от ширины корпуса
private _SH = 0.2552;     // на сколько урезать высоту дисплея от высоты корпуса

private _SAFE = 0.0008;
private _EPS  = 0.0005;

// ---------- 1) масштабируем корпус вокруг центра ----------
private _W = _BASE_W * _SCALE;
private _H = _BASE_H * _SCALE;

private _X = _BASE_X;
private _Y = _BASE_Y;

if (_LOCKCTR) then {
  private _cx = _BASE_X + _BASE_W/2;
  private _cy = _BASE_Y + _BASE_H/2;
  _X = _cx - _W/2;
  _Y = _cy - _H/2;
};

// единый сдвиг + тонкая подстройка
_X = _X + _MOVE + _SHIFT_X;
_Y = _Y + _MOVE + _SHIFT_Y;

// ---------- 2) дисплей внутри корпуса (масштабируемые отступы) ----------
private _DISP_X = _X + (_OX * _SCALE);
private _DISP_Y = _Y + (_OY * _SCALE);
private _DISP_W = _W - (_SW * _SCALE);
private _DISP_H = _H - (_SH * _SCALE);

// ---------- 3) корневой контейнер корпуса ----------
private _root = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 10];
_root ctrlSetPosition [_X, _Y, _W, _H];
_root ctrlCommit 0;

// ---------- 4) спрайты корпуса ----------
private _shadow = _disp ctrlCreate ["RscPicture", -1, _root];
_shadow ctrlSetText "PDA\ui\phone_shadow_ca.paa";
_shadow ctrlSetPosition [0, 0, _W, _H];
_shadow ctrlCommit 0;

private _frame = _disp ctrlCreate ["RscPicture", -1, _root];
_frame ctrlSetText "PDA\ui\phone_frame_black_ca.paa";
_frame ctrlSetPosition [0, 0, _W, _H];
_frame ctrlCommit 0;

private _glare = _disp ctrlCreate ["RscPicture", -1, _root];
_glare ctrlSetText "PDA\ui\phone_glare_ca.paa";
_glare ctrlSetPosition [0, 0, _W, _H];
_glare ctrlEnable false;
_glare ctrlCommit 0;

// ---------- 5) контейнер «экрана» (внутри root) ----------
private _screen = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1000, _root];
private _relX = (_DISP_X - _X) + _SAFE;
private _relY = (_DISP_Y - _Y) + _SAFE;
private _relW =  _DISP_W - 2 * _SAFE;
private _relH =  _DISP_H - 2 * _SAFE;
_screen ctrlSetPosition [_relX, _relY, _relW, _relH];
_screen ctrlCommit 0;
uiNamespace setVariable ["PDA_ScreenGroup", _screen];

// реальные размеры экрана
private _posScr = ctrlPosition _screen;
private _scrW = _posScr select 2;
private _scrH = _posScr select 3;

// фон экрана
private _bg = _disp ctrlCreate ["RscText", -1, _screen];
_bg ctrlSetPosition [0, 0, _scrW, _scrH];
_bg ctrlSetBackgroundColor [0.92,0.92,0.92,1];
_bg ctrlCommit 0;

// «выключенный» экран
private _offPic = _disp ctrlCreate ["RscPicture", 1050, _screen];
_offPic ctrlSetText "PDA\ui\phone_off_ca.paa";
_offPic ctrlSetPosition [0, 0, _scrW, _scrH];
_offPic ctrlCommit 0;
uiNamespace setVariable ["PDA_OffOverlay", _offPic];

// главная страница
private _home = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1100, _screen];
_home ctrlSetPosition [0, 0, _scrW, _scrH];
_home ctrlCommit 0;
uiNamespace setVariable ["PDA_HomeGroup", _home];
_home ctrlShow false;

// хедер
private _header = _disp ctrlCreate ["RscStructuredText", -1, _home];
_header ctrlSetPosition [0, 0, _scrW, 0.035];
_header ctrlSetBackgroundColor [0.85,0.85,0.85,1];
_header ctrlCommit 0;
_header ctrlSetStructuredText parseText "<t shadow='0' align='center' color='#0d0d0d' font='PuristaBold' size='0.85'>Legion</t>";

// меню
private _items   = missionNamespace getVariable ["PDA_MenuItems", []];
private _ROW_H   = 0.035;
private _ROW_GAP = 0.006;
private _padX    = 0.010;
private _startY  = 0.045;

{
  private _i = _forEachIndex;
  private _title = _x select 0;
  private _y = _startY + _i * (_ROW_H + _ROW_GAP);

  private _row = _disp ctrlCreate ["RscText", -1, _home];
  _row ctrlSetPosition [_padX, _y, _scrW - 2*_padX - _EPS, _ROW_H];
  _row ctrlSetBackgroundColor [0.98,0.98,0.98,1];
  _row ctrlCommit 0;

  private _txt = _disp ctrlCreate ["RscStructuredText", -1, _home];
  _txt ctrlSetPosition [_padX + 0.008, _y + 0.003, _scrW - 2*_padX - 0.016 - _EPS, _ROW_H - 0.006];
  _txt ctrlCommit 0;
  _txt ctrlSetStructuredText parseText format [
    "<t shadow='0' color='#0d0d0d' font='PuristaMedium' size='0.85'>%1</t>", _title
  ];

  private _btn = _disp ctrlCreate ["RscButton", 2000 + _i, _home];
  _btn ctrlSetText "";
  _btn ctrlSetPosition [_padX, _y, _scrW - 2*_padX - _EPS, _ROW_H];
  _btn ctrlSetBackgroundColor [0,0,0,0];
  _btn ctrlCommit 0;
  _btn ctrlAddEventHandler ["ButtonClick", format ["[%1] call PDA_fnc_menuAction;", _i]];
} forEach _items;

// хинт
private _hint = _disp ctrlCreate ["RscStructuredText", -1, _home];
_hint ctrlSetPosition [0.0, _scrH - 0.028, _scrW, 0.026];
_hint ctrlSetBackgroundColor [0.85,0.85,0.85,1];
_hint ctrlCommit 0;
_hint ctrlSetStructuredText parseText format [
  "<t align='center' shadow='0' font='PuristaLight' size='0.75'>%1</t>",
  localize "STR_AQ_PDA_TOGGLE_HINT"
];

uiNamespace setVariable ["PDA_TasksGroup", controlNull];
uiNamespace setVariable ["PDA_TaskDetailGroup", controlNull];

[] call PDA_fnc_pageInit;
["home", _home] call PDA_fnc_pageRegister;
