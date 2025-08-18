/*
  Построение UI КПК (страницы + OFF-оверлей).
  Порядок: shadow -> frame -> glare -> _screen
  Внутри _screen:
    - _offPic (phone_off_ca) — картинка "экран выкл", поверх всего контента дисплея
    - _home   — главное меню (изначально скрыто, пока "выкл")
*/
disableSerialization;
params ["_disp"];
if (isNull _disp) exitWith {};

// === Геометрия (твои идеальные) ===
private _PHONE_X = 1.13;
private _PHONE_Y = 0.54;
private _PHONE_W = 0.35;
private _PHONE_H = 0.79;

private _DISP_X = _PHONE_X + 0.0512;
private _DISP_Y = _PHONE_Y + 0.1245;
private _DISP_W = _PHONE_W - 0.100005;
private _DISP_H = _PHONE_H - 0.2552;

private _SAFE = 0.0008;
private _EPS  = 0.0005;

// === Корневой контейнер ===
private _root = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 10];
_root ctrlSetPosition [_PHONE_X, _PHONE_Y, _PHONE_W, _PHONE_H];
_root ctrlCommit 0;

// Спрайты
private _shadow = _disp ctrlCreate ["RscPicture", -1, _root];
_shadow ctrlSetText "aq_phone\ui\phone_shadow_ca.paa";
_shadow ctrlSetPosition [0, 0, _PHONE_W, _PHONE_H];
_shadow ctrlCommit 0;

private _frame = _disp ctrlCreate ["RscPicture", -1, _root];
_frame ctrlSetText "aq_phone\ui\phone_frame_black_ca.paa";
_frame ctrlSetPosition [0, 0, _PHONE_W, _PHONE_H];
_frame ctrlCommit 0;

private _glare = _disp ctrlCreate ["RscPicture", -1, _root];
_glare ctrlSetText "aq_phone\ui\phone_glare_ca.paa";
_glare ctrlSetPosition [0, 0, _PHONE_W, _PHONE_H];
_glare ctrlEnable false;
_glare ctrlCommit 0;

// Рабочая область (экран)
private _screen = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1000, _root];
_screen ctrlSetPosition [
  (_DISP_X - _PHONE_X) + _SAFE,
  (_DISP_Y - _PHONE_Y) + _SAFE,
  _DISP_W - 2*_SAFE,
  _DISP_H - 2*_SAFE
];
_screen ctrlCommit 0;

// Сохраняем
uiNamespace setVariable ["AQPH_ScreenGroup", _screen];

// Геометрия экрана
private _posScr = ctrlPosition _screen;
private _scrW = _posScr select 2;
private _scrH = _posScr select 3;

// Фон дисплея (под контентом)
private _bg = _disp ctrlCreate ["RscText", -1, _screen];
_bg ctrlSetPosition [0, 0, _scrW, _scrH];
_bg ctrlSetBackgroundColor [0.92,0.92,0.92,1];
_bg ctrlCommit 0;

// === Картинка "экран выкл" поверх дисплея ===
private _offPic = _disp ctrlCreate ["RscPicture", 1050, _screen];
_offPic ctrlSetText "aq_phone\ui\phone_off_ca.paa";
_offPic ctrlSetPosition [0, 0, _scrW, _scrH];
_offPic ctrlCommit 0;
uiNamespace setVariable ["AQPH_OffOverlay", _offPic];

// === Главная страница (_home) — изначально скрыта (экран "выкл") ===
private _home = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1100, _screen];
_home ctrlSetPosition [0, 0, _scrW, _scrH];
_home ctrlCommit 0;
uiNamespace setVariable ["AQPH_HomeGroup", _home];
_home ctrlShow false;

// Заголовок
private _header = _disp ctrlCreate ["RscStructuredText", -1, _home];
_header ctrlSetPosition [0, 0, _scrW, 0.035];
_header ctrlSetBackgroundColor [0.85,0.85,0.85,1];
_header ctrlCommit 0;
_header ctrlSetStructuredText parseText "<t shadow='0' align='center' color='#0d0d0d' font='PuristaBold' size='0.85'>КПК — Главное меню</t>";

// Список меню
private _items = missionNamespace getVariable ["AQPH_MenuItems", []];
private _ROW_H    = 0.035;
private _ROW_GAP  = 0.006;
private _padX     = 0.010;
private _startY   = 0.045;

{
  private _i = _forEachIndex;
  private _title = _x select 0;
  private _y = _startY + _i * (_ROW_H + _ROW_GAP);

  // фон строки
  private _row = _disp ctrlCreate ["RscText", -1, _home];
  _row ctrlSetPosition [_padX, _y, _scrW - 2*_padX - _EPS, _ROW_H];
  _row ctrlSetBackgroundColor [0.98,0.98,0.98,1];
  _row ctrlCommit 0;

  // текст
  private _txt = _disp ctrlCreate ["RscStructuredText", -1, _home];
  _txt ctrlSetPosition [_padX + 0.008, _y + 0.003, _scrW - 2*_padX - 0.016 - _EPS, _ROW_H - 0.006];
  _txt ctrlCommit 0;
  _txt ctrlSetStructuredText parseText format ["<t shadow='0' color='#0d0d0d' font='PuristaMedium' size='0.85'>%1</t>", _title];

  // кнопка поверх
  private _btn = _disp ctrlCreate ["RscButton", 2000 + _i, _home];
  _btn ctrlSetText "";
  _btn ctrlSetPosition [_padX, _y, _scrW - 2*_padX - _EPS, _ROW_H];
  _btn ctrlSetBackgroundColor [0,0,0,0];
  _btn ctrlCommit 0;
  _btn ctrlAddEventHandler ["ButtonClick", format ["[%1] call AQPH_fnc_menuAction;", _i]];
} forEach _items;

// Подсказка снизу
private _hint = _disp ctrlCreate ["RscStructuredText", -1, _home];
_hint ctrlSetPosition [0.0, _scrH - 0.028, _scrW, 0.026];
_hint ctrlSetBackgroundColor [0.85,0.85,0.85,1];
_hint ctrlCommit 0;
_hint ctrlSetStructuredText parseText "<t align='center' shadow='0' font='PuristaLight' size='0.75'>RShift — открыть/закрыть</t>";

// Страницы задач (позже создаются функциями)
uiNamespace setVariable ["AQPH_TasksGroup", controlNull];
uiNamespace setVariable ["AQPH_TaskDetailGroup", controlNull];
