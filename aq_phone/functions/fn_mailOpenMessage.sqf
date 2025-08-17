disableSerialization;
params ["_idx"];

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
private _grp  = uiNamespace getVariable ["AQPH_Group",   controlNull];
if (isNull _disp || {isNull _grp}) exitWith {};

private _mails = + (missionNamespace getVariable ["AQPH_Mails", []]);
if (_idx < 0 || {_idx >= count _mails}) exitWith {};

// перерисуем окно приложения целиком
private _old = uiNamespace getVariable ["AQPH_AppGroup", controlNull];
if (!isNull _old) then { ctrlDelete _old; };

// ====== LAYOUT окна приложения (как в openMail) ======
private _p  = ctrlPosition _grp;
private _gw = _p#2;
private _gh = _p#3;
private _barH = uiNamespace getVariable ["AQPH_BarH", 0.085 * _gh];

private _appX = 0;
private _appY = 0;
private _appW = _gw;
private _appH = _gh;
// =====================================================

private _app = _disp ctrlCreate ["RscControlsGroup", -1, _grp];
_app ctrlSetPosition [_appX, _appY, _appW, _appH];
_app ctrlCommit 0;
uiNamespace setVariable ["AQPH_AppGroup", _app];

// ФОН ПРИЛОЖЕНИЯ (твоя картинка)
private _bgPic = _disp ctrlCreate ["RscPicture", -1, _app];
_bgPic ctrlSetText "aq_phone\ui\app_mail_bg_ca.paa";
_bgPic ctrlSetPosition [0, 0, _appW, _appH];
_bgPic ctrlCommit 0;

// ====== LAYOUT письма (двигай тут) ======================================
private _padX   = 0.15 * _appW;   // боковые поля
private _padTop = 0.17 * _appH;   // верхний отступ
private _padBot = 0.26 * _appH;   // нижний отступ (под кнопки)
private _gap    = -0.01 * _appH;  // зазор между элементами

private _fromSize = 0.95;         // размер шрифта «От»
private _subjSize = 0.90;         // размер шрифта «Тема»
private _bodySize = 0.90;         // размер шрифта «Тело»
// ========================================================================

private _from = _mails#_idx#0;
private _subj = _mails#_idx#1;
private _body = _mails#_idx#2;

// заголовки
private _y = _padTop;

private _hdrFrom = _disp ctrlCreate ["RscStructuredText", -1, _app];
_hdrFrom ctrlSetPosition [_padX, _y, _appW - 2*_padX, 0.08 * _appH];  // <-- ПОЗИЦИЯ «От»
_hdrFrom ctrlSetBackgroundColor [0,0,0,0];
_hdrFrom ctrlSetStructuredText parseText format ["<t size='%1' color='#111111'>От: %2</t>", _fromSize, _from];
_hdrFrom ctrlCommit 0;
_y = _y + 0.08 * _appH + _gap;

private _hdrSubj = _disp ctrlCreate ["RscStructuredText", -1, _app];
_hdrSubj ctrlSetPosition [_padX, _y, _appW - 2*_padX, 0.07 * _appH];  // <-- ПОЗИЦИЯ «Тема»
_hdrSubj ctrlSetBackgroundColor [0,0,0,0];
_hdrSubj ctrlSetStructuredText parseText format ["<t size='%1' color='#333333'>Тема: %2</t>", _subjSize, _subj];
_hdrSubj ctrlCommit 0;
_y = _y + 0.07 * _appH + _gap;

// === БОЛЬШОЙ «БАБЛ» ПОД ТЕЛО ПИСЬМА ===
// наружные размеры бабла (можно тянуть хоть на всю высоту)
private _bubbleX = _padX;                             // <-- ПОЗИЦИЯ бабла X
private _bubbleY = _y;                                // <-- ПОЗИЦИЯ бабла Y
private _bubbleW = _appW - 2*_padX;                   // <-- ШИРИНА бабла
private _maxH    = _appH - _padBot - _bubbleY;        // доступная высота до низа

// измеряем высоту текста (с учётом внутренних полей)
private _innerPadX = 0.04 * _appW;  // <-- ВНУТРЕННЕЕ поле текста слева/справа
private _innerPadY = 0.03 * _appH;  // <-- ВНУТРЕННЕЕ поле текста сверху/снизу

private _measure = _disp ctrlCreate ["RscStructuredText", -1, _app];
_measure ctrlSetBackgroundColor [0,0,0,0];
_measure ctrlSetStructuredText parseText format ["<t size='%1' color='#111111'>%2</t>", _bodySize, _body];
_measure ctrlSetPosition [0, 0, _bubbleW - 2*_innerPadX, 0.001];
_measure ctrlCommit 0;
private _needH = ctrlTextHeight _measure;
ctrlDelete _measure;

private _bubbleH = (_needH + 2*_innerPadY) min _maxH; // фактическая высота бабла

// фон-картинка бабла (тянем по вертикали)
private _bubble = _disp ctrlCreate ["RscPicture", -1, _app];
_bubble ctrlSetText "aq_phone\ui\icon_mail_bable_ca.paa";
_bubble ctrlSetPosition [_bubbleX, _bubbleY, _bubbleW, _bubbleH];
_bubble ctrlCommit 0;

// прокручиваемая зона ВНУТРИ бабла
private _scroll = _disp ctrlCreate ["RscControlsGroup", -1, _app];
_scroll ctrlSetPosition [_bubbleX + _innerPadX, _bubbleY + _innerPadY, _bubbleW - 2*_innerPadX, _bubbleH - 2*_innerPadY];
_scroll ctrlCommit 0;

private _txt = _disp ctrlCreate ["RscStructuredText", -1, _scroll];
_txt ctrlSetBackgroundColor [0,0,0,0];
_txt ctrlSetStructuredText parseText format ["<t size='%1' color='#111111'>%2</t>", _bodySize, _body];
_txt ctrlSetPosition [0, 0, _bubbleW - 2*_innerPadX, _needH max 0.001];
_txt ctrlCommit 0;

// КНОПКИ: Назад + Удалить
private _btnBack = _disp ctrlCreate ["RscButton", -1, _app];
_btnBack ctrlSetText "Назад";
_btnBack ctrlSetPosition [_padX, _appH - _padBot + 0.02*_appH, 0.22 * _appW, 0.07 * _appH];
_btnBack ctrlCommit 0;
_btnBack ctrlAddEventHandler ["ButtonClick", { [] call AQPH_fnc_openMail }];

private _btnDel = _disp ctrlCreate ["RscButton", -1, _app];
_btnDel ctrlSetText "Удалить";
_btnDel ctrlSetPosition [_padX + 0.25*_appW, _appH - _padBot + 0.02*_appH, 0.25 * _appW, 0.07 * _appH];
_btnDel ctrlCommit 0;
_btnDel ctrlAddEventHandler ["ButtonClick", format ["[%1] call AQPH_fnc_mailDelete;", _idx]];
