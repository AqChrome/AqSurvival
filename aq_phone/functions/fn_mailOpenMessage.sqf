disableSerialization;
params ["_idx"];

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
private _app  = uiNamespace getVariable ["AQPH_AppGroup", controlNull];
if (isNull _disp || {isNull _app}) exitWith {};

private _mails = + (missionNamespace getVariable ["AQPH_Mails", []]);
if (_idx < 0 || {_idx >= count _mails}) exitWith {};

private _ap  = ctrlPosition _app;
private _aw = _ap#2;
private _ah = _ap#3;

// корневая группа ЭКРАНА ПИСЬМА (её легко удалить при «Назад»)
private _msg = _disp ctrlCreate ["RscControlsGroupNoScrollbars", -1, _app];
_msg ctrlSetPosition [0, 0, _aw, _ah];
_msg ctrlCommit 0;
uiNamespace setVariable ["AQPH_MailViewGroup", _msg];

// фон приложения под письмом (тот же, что и в списке)
private _bg = _disp ctrlCreate ["RscPicture", -1, _msg];
_bg ctrlSetText "aq_phone\ui\app_mail_bg_ca.paa";
_bg ctrlSetPosition [0, 0, _aw, _ah];
_bg ctrlCommit 0;

// ---- LAYOUT письма ----
private _padX   = 0.06 * _aw;
private _padTop = 0.06 * _ah;
private _padBot = 0.10 * _ah;
private _gap    = 0.020 * _ah;

private _fromSize = 0.95;
private _subjSize = 0.90;
private _bodySize = 0.90;

private _from = _mails#_idx#0;
private _subj = _mails#_idx#1;
private _body = _mails#_idx#2;

// заголовки
private _y = _padTop;

private _hdrFrom = _disp ctrlCreate ["RscStructuredText", -1, _msg];
_hdrFrom ctrlSetPosition [_padX, _y, _aw - 2*_padX, 0.08 * _ah];
_hdrFrom ctrlSetBackgroundColor [0,0,0,0];
_hdrFrom ctrlSetStructuredText parseText format ["<t size='%1' color='#111111'>От: %2</t>", _fromSize, _from];
_hdrFrom ctrlCommit 0;
_y = _y + 0.08 * _ah + _gap;

private _hdrSubj = _disp ctrlCreate ["RscStructuredText", -1, _msg];
_hdrSubj ctrlSetPosition [_padX, _y, _aw - 2*_padX, 0.07 * _ah];
_hdrSubj ctrlSetBackgroundColor [0,0,0,0];
_hdrSubj ctrlSetStructuredText parseText format ["<t size='%1' color='#333333'>Тема: %2</t>", _subjSize, _subj];
_hdrSubj ctrlCommit 0;
_y = _y + 0.07 * _ah + _gap;

// большой «бабл» под тело письма
private _bubbleX = _padX;
private _bubbleY = _y;
private _bubbleW = _aw - 2*_padX;
private _maxH    = _ah - _padBot - _bubbleY;

// измерим высоту текста (учтём внутренние поля)
private _innerPadX = 0.04 * _aw;
private _innerPadY = 0.03 * _ah;

private _measure = _disp ctrlCreate ["RscStructuredText", -1, _msg];
_measure ctrlSetBackgroundColor [0,0,0,0];
_measure ctrlSetStructuredText parseText format ["<t size='%1' color='#111111'>%2</t>", _bodySize, _body];
_measure ctrlSetPosition [0, 0, _bubbleW - 2*_innerPadX, 0.001];
_measure ctrlCommit 0;
private _needH = ctrlTextHeight _measure;
ctrlDelete _measure;

private _bubbleH = (_needH + 2*_innerPadY) min _maxH;

private _bubble = _disp ctrlCreate ["RscPicture", -1, _msg];
_bubble ctrlSetText "aq_phone\ui\icon_mail_bable_ca.paa";
_bubble ctrlSetPosition [_bubbleX, _bubbleY, _bubbleW, _bubbleH];
_bubble ctrlCommit 0;

// прокручиваемая зона ВНУТРИ бабла
private _scroll = _disp ctrlCreate ["RscControlsGroup", -1, _msg];
_scroll ctrlSetPosition [_bubbleX + _innerPadX, _bubbleY + _innerPadY, _bubbleW - 2*_innerPadX, _bubbleH - 2*_innerPadY];
_scroll ctrlCommit 0;

private _txt = _disp ctrlCreate ["RscStructuredText", -1, _scroll];
_txt ctrlSetBackgroundColor [0,0,0,0];
_txt ctrlSetStructuredText parseText format ["<t size='%1' color='#111111'>%2</t>", _bodySize, _body];
_txt ctrlSetPosition [0, 0, _bubbleW - 2*_innerPadX, _needH max 0.001];
_txt ctrlCommit 0;

// кнопки внизу
private _btnBack = _disp ctrlCreate ["RscButton", -1, _msg];
_btnBack ctrlSetText "Назад";
_btnBack ctrlSetPosition [_padX, _ah - _padBot + 0.02 * _ah, 0.22 * _aw, 0.07 * _ah];
_btnBack ctrlCommit 0;
_btnBack ctrlAddEventHandler ["ButtonClick", {
  private _g = uiNamespace getVariable ["AQPH_MailViewGroup", controlNull];
  if (!isNull _g) then { ctrlDelete _g; uiNamespace setVariable ["AQPH_MailViewGroup", controlNull]; };
  [] call AQPH_fnc_mailRenderList;
}];

private _btnDel = _disp ctrlCreate ["RscButton", -1, _msg];
_btnDel ctrlSetText "Удалить";
_btnDel ctrlSetPosition [_padX + 0.25 * _aw, _ah - _padBot + 0.02 * _ah, 0.25 * _aw, 0.07 * _ah];
_btnDel ctrlCommit 0;
_btnDel ctrlAddEventHandler ["ButtonClick", format ["
  private _m = + (missionNamespace getVariable ['AQPH_Mails', []]);
  if (%1 >= 0 && {%1 < count _m}) then { _m deleteAt %1; missionNamespace setVariable ['AQPH_Mails', _m]; };
  private _g = uiNamespace getVariable ['AQPH_MailViewGroup', controlNull];
  if (!isNull _g) then { ctrlDelete _g; uiNamespace setVariable ['AQPH_MailViewGroup', controlNull]; };
  [] call AQPH_fnc_mailRenderList;
", _idx]];
