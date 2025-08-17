disableSerialization;

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
private _app  = uiNamespace getVariable ["AQPH_AppGroup", controlNull];
if (isNull _disp || {isNull _app}) exitWith {};

// подчистим всё внутри _app, КРОМЕ фоновой картинки приложения
private _appBg = uiNamespace getVariable ["AQPH_AppBgPic", controlNull];
{
  if (!isNull _x && {ctrlParent _x isEqualTo _app}) then {
    if (!(_x isEqualTo _appBg)) then { ctrlDelete _x; };
  };
} forEach (allControls ctrlParent _app);

// габариты окна
private _ap = ctrlPosition _app;
private _aw = _ap#2;
private _ah = _ap#3;

/* ===== LAYOUT СПИСКА (подгоняй тут) ===== */
private _padSide = 0.05 * _aw;    // боковые отступы списка
private _padTop  = 0.05 * _ah;    // отступ сверху
private _padBot  = 0.08 * _ah;    // отступ снизу (под кнопку)
private _gap     = 0.02 * _ah;    // расстояние между баблами

private _bW      = _aw - 2 * _padSide; // ширина мини-бабла
private _bH      = 0.12 * _ah;         // высота мини-бабла
private _bTextSize = 0.90;             // размер шрифта в мини-бабле
/* ======================================== */

// ФОН ВЬЮПОРТА СПИСКА — тот же спрайт бабла, растянутый под весь список
private _list = _disp ctrlCreate ["RscControlsGroup", -1, _app];
_list ctrlSetPosition [ _padSide, _padTop, _bW, _ah - _padTop - _padBot ];
_list ctrlCommit 0;

// ПРОКРУЧИВАЕМЫЙ контейнер списка (лежит поверх фоновой картинки)
private _list = _disp ctrlCreate ["RscControlsGroup", -1, _app];
_list ctrlSetPosition [ _padSide, _padTop, _bW, _ah - _padTop - _padBot ];
_list ctrlCommit 0;

// данные
private _mails = + (missionNamespace getVariable ["AQPH_Mails", []]);

if ((count _mails) == 0) exitWith {
  private _empty = _disp ctrlCreate ["RscStructuredText", -1, _list];
  _empty ctrlSetPosition [0, 0, _bW, 0.10 * _ah];
  _empty ctrlSetBackgroundColor [0,0,0,0];
  _empty ctrlSetStructuredText parseText "<t size='0.9' color='#555555'>Нет сообщений</t>";
  _empty ctrlCommit 0;
};

// строим мини-баблы
private _y = 0;
for "_i" from 0 to ((count _mails) - 1) do {
  // фон каждого мини-бабла
  private _bPic = _disp ctrlCreate ["RscPicture", -1, _list];
  _bPic ctrlSetText "aq_phone\ui\icon_mail_bable_ca.paa";
  _bPic ctrlSetPosition [0, _y, _bW, _bH];
  _bPic ctrlCommit 0;

  // текст "Новое сообщение" + время (правую часть можно сместить вёрсткой)
  private _d = date; private _h = _d#3; private _m = _d#4;
  private _hh = if (_h < 10) then { format["0%1",_h] } else { str _h };
  private _mm = if (_m < 10) then { format["0%1",_m] } else { str _m };
  private _timeStr = format ["%1:%2", _hh, _mm];

  private _label = _disp ctrlCreate ["RscStructuredText", -1, _list];
  _label ctrlSetPosition [ 0.04*_bW, _y + 0.22*_bH, 0.92*_bW, 0.50*_bH ];  // ← ПОЗИЦИЯ ТЕКСТА В МИНИ-БАБЛЕ
  _label ctrlSetBackgroundColor [0,0,0,0];
  _label ctrlSetStructuredText parseText format [
    "<t size='%1' color='#111111'>Новое сообщение</t><t align='right' size='%1' color='#666666'>%2</t>",
    _bTextSize, _timeStr
  ];
  _label ctrlCommit 0;

  // кнопка-строка
  private _btn = _disp ctrlCreate ["RscButton", -1, _list];
  _btn ctrlSetText "";
  _btn ctrlSetBackgroundColor [0,0,0,0];
  _btn ctrlSetPosition [0, _y, _bW, _bH];
  _btn ctrlCommit 0;
  _btn ctrlAddEventHandler ["ButtonClick", format ["[%1] call AQPH_fnc_mailOpenMessage;", _i]];

  _y = _y + _bH + _gap;
};

// кнопка Назад у низа приложения
private _back = _disp ctrlCreate ["RscButton", -1, _app];
_back ctrlSetText "Назад";
_back ctrlSetPosition [ _padSide, _ah - _padBot + 0.02*_ah, 0.22 * _aw, 0.07 * _ah ];
_back ctrlCommit 0;
_back ctrlAddEventHandler ["ButtonClick", { [] call AQPH_fnc_home }];
