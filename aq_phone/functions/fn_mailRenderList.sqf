disableSerialization;

private _disp     = uiNamespace getVariable ["AQPH_Display", displayNull];
private _app      = uiNamespace getVariable ["AQPH_AppGroup", controlNull];
if (isNull _disp || {isNull _app}) exitWith {};

// ── LAYOUT ГРАНИЦ СПИСКА (подгоняй здесь) ───────────────────────────────
private _appPos   = ctrlPosition _app;
private _appW     = _appPos#2;
private _appH     = _appPos#3;

// поля окна списка (должны совпадать логикой с fn_openMail.sqf)
private _padSide  = 0.15 * _appW;   // поля слева/справа
private _padTop   = 0.19 * _appH;   // отступ сверху
private _padBot   = 0.10 * _appH;   // отступ снизу (под футер/кнопки)
private _footerH  = 0.07 * _appH;   // высота футера (как в fn_openMail.sqf)
// ────────────────────────────────────────────────────────────────────────

// 1) найдём/создадим фиксированную область списка (НЕ скроллится)
private _listArea = uiNamespace getVariable ["AQPH_ListArea", controlNull];
if (isNull _listArea) then {
  _listArea = _disp ctrlCreate ["RscControlsGroupNoScrollbars", -1, _app];
  uiNamespace setVariable ["AQPH_ListArea", _listArea];
};
_listArea ctrlSetPosition [
  _padSide,
  _padTop,
  _appW - 2*_padSide,
  _appH - _padTop - _padBot - _footerH
];
_listArea ctrlCommit 0;

// подчистим прошлое содержимое _listArea (фон приложения и футер не трогаем — они вне этой группы)
{ ctrlDelete _x } forEach (allControls _listArea);

// 2) проверим высоту видимой области
private _lp = ctrlPosition _listArea;
private _lw = _lp#2;
private _lh = _lp#3;
if (_lh <= 0.001) exitWith {
  private _warn = _disp ctrlCreate ["RscStructuredText", -1, _app];
  _warn ctrlSetPosition [ _padSide, 0.02 * _appH, _appW - 2*_padSide, 0.08*_appH ];
  _warn ctrlSetBackgroundColor [0,0,0,0];
  _warn ctrlSetStructuredText parseText "<t size='0.9' color='#FF4444'>[Mail] Высота зоны списка = 0. Уменьши _padTop/_padBot/_footerH.</t>";
  _warn ctrlCommit 0;
};

// ── LAYOUT СПИСКА (строки и шапка) ──────────────────────────────────────
private _headerH    = 0.10 * _lh;  // высота шапки "Мессенджер"
private _headerGap  = 0.015 * _lh; // зазор под шапкой

private _gap        = 0.02 * _lh;  // промежутки между мини-баблами
private _bW         = _lw;         // ширина мини-бабла (по ширине области)
private _bH         = 0.14 * _lh;  // высота мини-бабла
private _bTextSize  = 0.90;        // размер шрифта в бабле

// позиция текста внутри мини-бабла (фракции от _bW/_bH)
private _textXFrac  = 0.06;        // 6% слева
private _textYFrac  = 0.25;        // 25% сверху
private _textWFrac  = 0.90;        // 90% ширины
private _textHFrac  = 0.50;        // 50% высоты
// ────────────────────────────────────────────────────────────────────────

// 3) статичная шапка «Мессенджер» (НЕ скроллится)
private _hdr = _disp ctrlCreate ["RscStructuredText", -1, _listArea];
_hdr ctrlSetPosition [0, 0, _lw, _headerH];
_hdr ctrlSetBackgroundColor [0,0,0,0];
_hdr ctrlSetStructuredText parseText "<t align='center' size='1.0' color='#111111'>Мессенджер</t>";
_hdr ctrlCommit 0;

// 4) реальный СКРОЛЛ со строками (прокручиваются только мини-баблы)
private _scrollY = _headerH + _headerGap;
private _scrollH = (_lh - _scrollY) max 0.001;

private _scroll = _disp ctrlCreate ["RscControlsGroup", -1, _listArea];
_scroll ctrlSetPosition [0, _scrollY, _lw, _scrollH];
_scroll ctrlCommit 0;
uiNamespace setVariable ["AQPH_ListScroll", _scroll];

// 5) данные
private _mails = + (missionNamespace getVariable ["AQPH_Mails", []]);

if ((count _mails) == 0) exitWith {
  private _empty = _disp ctrlCreate ["RscStructuredText", -1, _scroll];
  _empty ctrlSetPosition [0, 0, _lw, 0.18 * _scrollH];
  _empty ctrlSetBackgroundColor [0,0,0,0];
  _empty ctrlSetStructuredText parseText "<t size='0.9' color='#555555'>Нет сообщений</t>";
  _empty ctrlCommit 0;
};

// 6) рисуем строки
private _y = 0;
for "_i" from 0 to ((count _mails) - 1) do {
  private _mail = _mails select _i;   // [from, subject, body]
  _mail params ["_from","_subject","_body"];

  // укоротим слишком длинную тему (если нужно)
  private _maxChars = 42;
  private _subjShort = _subject;
  if ((count toArray _subjShort) > _maxChars) then {
    _subjShort = toString ((toArray _subjShort) select [0, _maxChars]) + "…";
  };

  // фон мини-бабла
  private _bPic = _disp ctrlCreate ["RscPicture", -1, _scroll];
  _bPic ctrlSetText "aq_phone\ui\icon_mail_bable_ca.paa";
  _bPic ctrlSetPosition [0, _y, _bW, _bH];
  _bPic ctrlCommit 0;

  // время справа HH:MM
  private _d = date; private _h = _d#3; private _m = _d#4;
  private _hh = if (_h < 10) then { format["0%1",_h] } else { str _h };
  private _mm = if (_m < 10) then { format["0%1",_m] } else { str _m };
  private _timeStr = format ["%1:%2", _hh, _mm];

  // текст в бабле (тема слева, время справа)
  private _tx = _textXFrac * _bW;
  private _ty = _y + _textYFrac * _bH;
  private _tw = _textWFrac * _bW;
  private _th = _textHFrac * _bH;

  private _label = _disp ctrlCreate ["RscStructuredText", -1, _scroll];
  _label ctrlSetPosition [_tx, _ty, _tw, _th];
  _label ctrlSetBackgroundColor [0,0,0,0];
  _label ctrlSetStructuredText parseText format [
    "<t size='%1' color='#111111'>%2</t><t align='right' size='%1' color='#666666'>%3</t>",
    _bTextSize, _subjShort, _timeStr
  ];
  _label ctrlCommit 0;

  // кнопка-строка (RscButton) — даёт стандартный hover/press затемнение
  private _btn = _disp ctrlCreate ["RscButton", -1, _scroll];
  _btn ctrlSetText "";
  _btn ctrlSetBackgroundColor [0,0,0,0];
  _btn ctrlSetPosition [0, _y, _bW, _bH];            // ВАЖНО: совпадает с фоном
  _btn ctrlCommit 0;
  _btn ctrlAddEventHandler ["ButtonClick", format ["[%1] call AQPH_fnc_mailOpenMessage;", _i]];

  _y = _y + _bH + _gap;
};

// конец — ничего не добавляем после цикла: скролл сам посчитает высоту
