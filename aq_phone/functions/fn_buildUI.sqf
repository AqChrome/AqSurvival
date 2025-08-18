/*
  Полный конструктор UI.
  Спрайты: shadow -> frame -> wallpaper -> glare
  Контейнер дисплея с ЖЁЛТОЙ рамкой: подгоняй позицию/размер тут (DISP_*).
  Меню: из AQPH_MenuItems (кнопки красятся тёмным на светлом фоне).
*/
disableSerialization;
params ["_disp"];
if (isNull _disp) exitWith {};

///////////////////////////////
// 1) Позиции и размеры
///////////////////////////////

// Габариты всего телефона (на экране)
private _PHONE_X = 1.13; // 0.78;
private _PHONE_Y = 0.54; // 0.42;
private _PHONE_W = 0.35; // 0.20;
private _PHONE_H = 0.79; // 0.46;

// Внутри рамки — позиция "дисплея" (ТОЧНО подгоняем жёлтой рамкой)
private _DISP_X = _PHONE_X + 0.0512; // Идеально
private _DISP_Y = _PHONE_Y + 0.1245; // Идеально
private _DISP_W = _PHONE_W - 0.100005; // - это + 095
private _DISP_H = _PHONE_H - 0.2552; // - это +

///////////////////////////////
// 2) Корневой контейнер
///////////////////////////////
private _root = _disp ctrlCreate ["RscControlsGroup", 10];
_root ctrlSetPosition [_PHONE_X, _PHONE_Y, _PHONE_W, _PHONE_H];
_root ctrlCommit 0;

///////////////////////////////
// 3) Слои спрайтов
///////////////////////////////

// Тень (самый нижний)
private _shadow = _disp ctrlCreate ["RscPicture", -1, _root];
_shadow ctrlSetText "aq_phone\ui\phone_shadow_ca.paa";
_shadow ctrlSetPosition [0, 0, _PHONE_W, _PHONE_H];
_shadow ctrlCommit 0;

// Рамка
private _frame = _disp ctrlCreate ["RscPicture", -1, _root];
_frame ctrlSetText "aq_phone\ui\phone_frame_black_ca.paa";
_frame ctrlSetPosition [0, 0, _PHONE_W, _PHONE_H];
_frame ctrlCommit 0;

// Блик (верхний визуальный, не интерактивный)
private _glare = _disp ctrlCreate ["RscPicture", -1, _root];
_glare ctrlSetText "aq_phone\ui\phone_glare_ca.paa";
_glare ctrlSetPosition [0, 0, _PHONE_W, _PHONE_H];
_glare ctrlEnable false;  // НЕ ловит клики
_glare ctrlCommit 0;

///////////////////////////////
// 4) Контейнер дисплея (сюда рисуем UI)
///////////////////////////////
private _screen = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1000, _root];
_screen ctrlSetPosition [
  _DISP_X - _PHONE_X,
  _DISP_Y - _PHONE_Y,
  _DISP_W,
  _DISP_H
];
_screen ctrlCommit 0;

///////////////////////////////
// 5) Отрисовка меню (Ч/Б стиль)
///////////////////////////////
private _items = missionNamespace getVariable ["AQPH_MenuItems", []];

// Фон дисплея — светло-серый, текст тёмный
private _bg = _disp ctrlCreate ["RscText", -1, _screen];
_bg ctrlSetPosition [0, 0, _DISP_W, _DISP_H];
_bg ctrlSetBackgroundColor [0.92,0.92,0.92,1];
_bg ctrlCommit 0;

// Заголовок
private _screenPos = ctrlPosition _screen;                 // [x,y,w,h]
private _screenW   = _screenPos select 2;

private _header = _disp ctrlCreate ["RscStructuredText", -1, _screen];
_header ctrlSetPosition [0, 0, _screenW, 0.035];
_header ctrlSetBackgroundColor [0.85,0.85,0.85,1];
_header ctrlCommit 0;

// тёмный текст без тени
private _hdrTxt = parseText "<t shadow='0' color='#0d0d0d' font='PuristaMedium' size='0.85'>КПК — Главное меню</t>";
_header ctrlSetStructuredText _hdrTxt;

// Список
private _rowH = 0.035;
private _padX = 0.010;
private _startY = 0.045;
private _epsilon = 0.0005;   // микроприпуск по ширине

{
  private _i = _forEachIndex;
  private _title = _x select 0;

  // полоса строки (фон)
  private _row = _disp ctrlCreate ["RscText", -1, _screen];
  _row ctrlSetPosition [_padX, _startY + _i * (_rowH + 0.003), _DISP_W - 2*_padX - _epsilon, _rowH];
  _row ctrlSetBackgroundColor [0.98,0.98,0.98,1];
  _row ctrlCommit 0;

  // текст без тени
  private _txt = _disp ctrlCreate ["RscStructuredText", -1, _screen];
  _txt ctrlSetPosition [_padX + 0.008, _startY + _i * (_rowH + 0.003) + 0.003, _DISP_W - 2*_padX - 0.016 - _epsilon, _rowH - 0.006];
  _txt ctrlCommit 0;

  private _txtValue = parseText format [
    "<t shadow='0' color='#0d0d0d' font='PuristaLight' size='0.85'>%1</t>",
    _title
  ];
  _txt ctrlSetStructuredText _txtValue;

  // кнопка поверх — та же геометрия, прозрачная
  private _btn = _disp ctrlCreate ["RscButton", 2000 + _i, _screen];
  _btn ctrlSetText "";
  _btn ctrlSetPosition [_padX, _startY + _i * (_rowH + 0.003), _DISP_W - 2*_padX - _epsilon, _rowH];
  _btn ctrlSetBackgroundColor [0,0,0,0];
  _btn ctrlCommit 0;

  _btn ctrlAddEventHandler ["ButtonClick", format ["[%1] call AQPH_fnc_menuAction;", _i]];
} forEach _items;


// Подсказка снизу
private _hint = _disp ctrlCreate ["RscStructuredText", -1, _screen];
_hint ctrlSetPosition [0.0, _DISP_H - 0.028, _screenW, 0.026];
_hint ctrlSetBackgroundColor [0.85,0.85,0.85,1];
_hint ctrlCommit 0;

private _hintTxt = parseText "<t shadow='0' color='#1a1a1a' font='PuristaLight' size='0.75'>RShift — открыть/закрыть</t>";
_hint ctrlSetStructuredText _hintTxt;

