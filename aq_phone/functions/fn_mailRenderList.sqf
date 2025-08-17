disableSerialization;

private _disp     = uiNamespace getVariable ["AQPH_Display", displayNull];
private _app      = uiNamespace getVariable ["AQPH_AppGroup", controlNull];
private _listArea = uiNamespace getVariable ["AQPH_ListArea", controlNull];
if (isNull _disp || {isNull _app} || {isNull _listArea}) exitWith {};

// гарантированно уберём прошлый экран письма (чтобы он не перекрывал верхние строки)
private _msgView = uiNamespace getVariable ["AQPH_MailViewGroup", controlNull];
if (!isNull _msgView) then { ctrlDelete _msgView; uiNamespace setVariable ["AQPH_MailViewGroup", controlNull]; };

// подчистим ТОЛЬКО содержимое области списка
{ ctrlDelete _x } forEach (allControls _listArea);

// габариты зоны списка
private _lp = ctrlPosition _listArea;
private _lw = _lp#2;
private _lh = _lp#3;
if (_lh <= 0.001) exitWith {};

// ===== LAYOUT =====
private _headerH    = 0.10 * _lh;     // высота шапки "Мессенджер"
private _headerGap  = 0.015 * _lh;    // зазор под шапкой

private _gap        = 0.02 * _lh;     // промежуток между мини-баблами
private _bW         = _lw;            // ширина мини-бабла
private _bH         = 0.14 * _lh;     // высота мини-бабла
private _bTextSize  = 0.90;

// позиция текста внутри мини-бабла (фракции от _bW/_bH)
private _textXFrac  = 0.06;
private _textYFrac  = 0.25;
private _textWFrac  = 0.90;
private _textHFrac  = 0.50;
// ===================

// шапка (НЕ скроллится и НЕ ловит мышь)
private _hdr = _disp ctrlCreate ["RscStructuredText", -1, _listArea];
_hdr ctrlSetPosition [0, 0, _lw, _headerH];
_hdr ctrlSetBackgroundColor [0,0,0,0];
_hdr ctrlSetStructuredText parseText "<t align='center' size='1.0' color='#111111'>Мессенджер</t>";
_hdr ctrlEnable false;
_hdr ctrlCommit 0;

// скролл со строками (прокручиваются только баблы)
private _scrollY = _headerH + _headerGap;
private _scrollH = (_lh - _scrollY) max 0.001;

private _scroll = _disp ctrlCreate ["RscControlsGroup", -1, _listArea];
_scroll ctrlSetPosition [0, _scrollY, _lw, _scrollH];
_scroll ctrlCommit 0;
uiNamespace setVariable ["AQPH_ListScroll", _scroll];

// данные
private _mails = + (missionNamespace getVariable ["AQPH_Mails", []]);

if ((count _mails) == 0) exitWith {
  private _empty = _disp ctrlCreate ["RscStructuredText", -1, _scroll];
  _empty ctrlSetPosition [0, 0, _lw, 0.18 * _scrollH];
  _empty ctrlSetBackgroundColor [0,0,0,0];
  _empty ctrlSetStructuredText parseText "<t size='0.9' color='#555555'>Нет сообщений</t>";
  _empty ctrlCommit 0;
};

// строки
private _y = 0;
for "_i" from 0 to ((count _mails) - 1) do {
  private _mail = _mails select _i;   // [from, subject, body]
  _mail params ["_from","_subject","_body"];

  // тема (обрезка по длине)
  private _maxChars = 42;
  private _subjShort = _subject;
  if ((count toArray _subjShort) > _maxChars) then {
    _subjShort = toString ((toArray _subjShort) select [0, _maxChars]) + "…";
  };

  // 1) фон мини-бабла
  private _bPic = _disp ctrlCreate ["RscPicture", -1, _scroll];
  _bPic ctrlSetText "aq_phone\ui\icon_mail_bable_ca.paa";
  _bPic ctrlSetPosition [0, _y, _bW, _bH];
  _bPic ctrlCommit 0;

  // 2) текст (тема слева, время справа HH:MM)
  private _d = date; private _h = _d#3; private _m = _d#4;
  private _hh = if (_h < 10) then { format["0%1",_h] } else { str _h };
  private _mm = if (_m < 10) then { format["0%1",_m] } else { str _m };
  private _timeStr = format ["%1:%2", _hh, _mm];

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

  // 3) КНОПКА (создаём ПОСЛЕДНЕЙ и в тех же координатах, что фон)
  private _btn = _disp ctrlCreate ["RscButton", -1, _scroll];
  _btn ctrlSetText "";
  _btn ctrlSetBackgroundColor [0,0,0,0];
  _btn ctrlSetPosition [0, _y, _bW, _bH];   // ВАЖНО: Y = _y, W/H = _bW/_bH
  _btn ctrlCommit 0;
  _btn ctrlAddEventHandler ["ButtonClick", format ["[%1] call AQPH_fnc_mailOpenMessage;", _i]];

  _y = _y + _bH + _gap;
};
