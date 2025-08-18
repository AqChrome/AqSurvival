/*
  Полный конструктор UI (fixed no-scroll).
  Слои: shadow -> frame -> glare. Обои отключены.
  Контейнер дисплея с ЖЁЛТОЙ рамкой для юстировки.
*/
disableSerialization;
params ["_disp"];
if (isNull _disp) exitWith {};

///////////////////////////////
// 1) Позиции и размеры (ВАШИ ИДЕАЛЬНЫЕ, НЕ ТРОГАЕМ)
///////////////////////////////
private _PHONE_X = 1.13;
private _PHONE_Y = 0.54;
private _PHONE_W = 0.35;
private _PHONE_H = 0.79;

private _DISP_X = _PHONE_X + 0.0512;
private _DISP_Y = _PHONE_Y + 0.1245;
private _DISP_W = _PHONE_W - 0.100005;
private _DISP_H = _PHONE_H - 0.2552;

// Анти-скролл микро-отступ (без видимого влияния)
private _SAFE = 0.0008;   // общий зазор контейнеру экрана
private _EPS  = 0.0005;   // припуск ширине элементов

///////////////////////////////
// 2) Корневой контейнер (без скроллов)
///////////////////////////////
private _root = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 10];
_root ctrlSetPosition [_PHONE_X, _PHONE_Y, _PHONE_W, _PHONE_H];
_root ctrlCommit 0;

///////////////////////////////
// 3) Слои спрайтов
///////////////////////////////

// Тень
private _shadow = _disp ctrlCreate ["RscPicture", -1, _root];
_shadow ctrlSetText "aq_phone\ui\phone_shadow_ca.paa";
_shadow ctrlSetPosition [0, 0, _PHONE_W, _PHONE_H];
_shadow ctrlCommit 0;

// Рамка
private _frame = _disp ctrlCreate ["RscPicture", -1, _root];
_frame ctrlSetText "aq_phone\ui\phone_frame_black_ca.paa";
_frame ctrlSetPosition [0, 0, _PHONE_W, _PHONE_H];
_frame ctrlCommit 0;

// Блик (не интерактивный)
private _glare = _disp ctrlCreate ["RscPicture", -1, _root];
_glare ctrlSetText "aq_phone\ui\phone_glare_ca.paa";
_glare ctrlSetPosition [0, 0, _PHONE_W, _PHONE_H];
_glare ctrlEnable false;
_glare ctrlCommit 0;

///////////////////////////////
// 4) Контейнер дисплея (без скроллов) + ЖЁЛТАЯ рамка
///////////////////////////////
private _screen = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1000, _root];
_screen ctrlSetPosition [
  (_DISP_X - _PHONE_X) + _SAFE,
  (_DISP_Y - _PHONE_Y) + _SAFE,
  _DISP_W - 2*_SAFE,
  _DISP_H - 2*_SAFE
];
_screen ctrlCommit 0;

// Жёлтая рамка для юстировки
private _DBG_BORDER = 0.002;
if (_DBG_BORDER > 0) then {
  private _pos = ctrlPosition _screen;
  private _w = _pos select 2;
  private _h = _pos select 3;

  private _top = _disp ctrlCreate ["RscText", -1, _screen];
  _top ctrlSetBackgroundColor [1,1,0,1];
  _top ctrlSetPosition [0, 0, _w, _DBG_BORDER];
  _top ctrlCommit 0;

  private _bot = _disp ctrlCreate ["RscText", -1, _screen];
  _bot ctrlSetBackgroundColor [1,1,0,1];
  _bot ctrlSetPosition [0, _h - _DBG_BORDER, _w, _DBG_BORDER];
  _bot ctrlCommit 0;

  private _left = _disp ctrlCreate ["RscText", -1, _screen];
  _left ctrlSetBackgroundColor [1,1,0,1];
  _left ctrlSetPosition [0, 0, _DBG_BORDER, _h];
  _left ctrlCommit 0;

  private _right = _disp ctrlCreate ["RscText", -1, _screen];
  _right ctrlSetBackgroundColor [1,1,0,1];
  _right ctrlSetPosition [_w - _DBG_BORDER, 0, _DBG_BORDER, _h];
  _right ctrlCommit 0;
};

///////////////////////////////
// 5) Фон Ч/Б
///////////////////////////////
private _posScr = ctrlPosition _screen;
private _scrW = _posScr select 2;
private _scrH = _posScr select 3;

private _bg = _disp ctrlCreate ["RscText", -1, _screen];
_bg ctrlSetPosition [0, 0, _scrW, _scrH];
_bg ctrlSetBackgroundColor [0.92,0.92,0.92,1];
_bg ctrlCommit 0;

///////////////////////////////
// 6) Хедер без тени (на всю ширину)
///////////////////////////////
private _header = _disp ctrlCreate ["RscStructuredText", -1, _screen];
_header ctrlSetPosition [0, 0, _scrW, 0.035];
_header ctrlSetBackgroundColor [0.85,0.85,0.85,1];
_header ctrlCommit 0;
_header ctrlSetStructuredText parseText "<t align='center' shadow='0' color='#0d0d0d' font='PuristaBold' size='0.85'>Legion</t>";

///////////////////////////////
// 7) Список меню (без тени, с припуском по ширине)
///////////////////////////////
private _items = missionNamespace getVariable ["AQPH_MenuItems", []];
private _rowH = 0.035;
private _padX = 0.010;
private _startY = 0.045;

{
  private _i = _forEachIndex;
  private _title = _x select 0;

  // фон строки
  private _row = _disp ctrlCreate ["RscText", -1, _screen];
  _row ctrlSetPosition [_padX, _startY + _i * (_rowH + 0.003), _scrW - 2*_padX - _EPS, _rowH];
  _row ctrlSetBackgroundColor [0.98,0.98,0.98,1];
  _row ctrlCommit 0;

  // текст без тени
  private _txt = _disp ctrlCreate ["RscStructuredText", -1, _screen];
  _txt ctrlSetPosition [_padX + 0.008, _startY + _i * (_rowH + 0.003) + 0.003, _scrW - 2*_padX - 0.016 - _EPS, _rowH - 0.006];
  _txt ctrlCommit 0;
  _txt ctrlSetStructuredText parseText format ["<t shadow='0' color='#0d0d0d' font='PuristaMedium' size='0.85'>%1</t>", _title];

  // кнопка поверх
  private _btn = _disp ctrlCreate ["RscButton", 2000 + _i, _screen];
  _btn ctrlSetText "";
  _btn ctrlSetPosition [_padX, _startY + _i * (_rowH + 0.003), _scrW - 2*_padX - _EPS, _rowH];
  _btn ctrlSetBackgroundColor [0,0,0,0];
  _btn ctrlCommit 0;
  _btn ctrlAddEventHandler ["ButtonClick", format ["[%1] call AQPH_fnc_menuAction;", _i]];
} forEach _items;

///////////////////////////////
// 8) Подсказка снизу (без тени)
///////////////////////////////
private _hint = _disp ctrlCreate ["RscStructuredText", -1, _screen];
_hint ctrlSetPosition [0.0, _scrH - 0.028, _scrW, 0.026];
_hint ctrlSetBackgroundColor [0.85,0.85,0.85,1];
_hint ctrlCommit 0;
_hint ctrlSetStructuredText parseText "<t align='center' shadow='0' color='#1a1a1a' font='PuristaLight' size='0.75'>RShift — открыть/закрыть</t>";
