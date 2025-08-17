disableSerialization;

private _disp = uiNamespace getVariable ["AQTB_Display", displayNull];
if (isNull _disp) exitWith {};

private _x = safeZoneX; private _y = safeZoneY; private _w = safeZoneW; private _h = safeZoneH;

// фон
private _bg = _disp ctrlCreate ["RscPicture", -1];
_bg ctrlSetText "aq_tablet\ui\tablet_wallpaper_ca.paa";
_bg ctrlSetPosition [_x, _y, _w, _h];
_bg ctrlCommit 0;

// рамка/тень/блик — пониже (создаём раньше)
private _shadow = _disp ctrlCreate ["RscPicture", -1];
_shadow ctrlSetText "aq_tablet\ui\tablet_shadow_ca.paa";
_shadow ctrlSetPosition [_x, _y, _w, _h];
_shadow ctrlCommit 0; _shadow ctrlEnable false;

private _frame = _disp ctrlCreate ["RscPicture", -1];
_frame ctrlSetText "aq_tablet\ui\tablet_frame_land_ca.paa";
_frame ctrlSetPosition [_x, _y, _w, _h];
_frame ctrlCommit 0; _frame ctrlEnable false;

private _glare = _disp ctrlCreate ["RscPicture", -1];
_glare ctrlSetText "aq_tablet\ui\tablet_glare_ca.paa";
_glare ctrlSetPosition [_x, _y, _w, _h];
_glare ctrlSetFade 0.2;
_glare ctrlCommit 0; _glare ctrlEnable false;

// заголовок
private _title = _disp ctrlCreate ["RscStructuredText", -1];
_title ctrlSetPosition [_x + 0.02*_w, _y + 0.02*_h, 0.30*_w, 0.06*_h];
_title ctrlSetStructuredText parseText "<t size='1.2' color='#FFFFFF'>AQ Tablet</t>";
_title ctrlSetBackgroundColor [0,0,0,0.30];
_title ctrlCommit 0;

// иконки
private _iconSize = 0.12 * _w;
private _pad = 0.02 * _w;
private _rowY = _y + 0.20 * _h;

private _icoTasks = _disp ctrlCreate ["RscPicture", -1];
_icoTasks ctrlSetText "aq_tablet\ui\icon_tasks_ca.paa";
_icoTasks ctrlSetPosition [_x + _pad, _rowY, _iconSize, _iconSize];
_icoTasks ctrlCommit 0;

private _icoMap = _disp ctrlCreate ["RscPicture", -1];
_icoMap ctrlSetText "aq_tablet\ui\icon_map_ca.paa";
_icoMap ctrlSetPosition [_x + _pad*2 + _iconSize, _rowY, _iconSize, _iconSize];
_icoMap ctrlCommit 0;

// хитбоксы-кнопки над иконками (для мыши и клавы)
private _btnTasks = _disp ctrlCreate ["RscButton", -1];
_btnTasks ctrlSetText "";  // прозрачная
_btnTasks ctrlSetBackgroundColor [0,0,0,0];
_btnTasks ctrlSetPosition [_x + _pad, _rowY, _iconSize, _iconSize];
_btnTasks ctrlCommit 0;
_btnTasks ctrlAddEventHandler ["ButtonClick", { ["tasks"] call AQTB_fnc_onHomeClick }];

private _btnMap = _disp ctrlCreate ["RscButton", -1];
_btnMap ctrlSetText "";
_btnMap ctrlSetBackgroundColor [0,0,0,0];
_btnMap ctrlSetPosition [_x + _pad*2 + _iconSize, _rowY, _iconSize, _iconSize];
_btnMap ctrlCommit 0;
_btnMap ctrlAddEventHandler ["ButtonClick", { ["map"] call AQTB_fnc_onHomeClick }];

// крестик × (всегда сверху)
private _btnClose = _disp ctrlCreate ["RscButton", -1];
_btnClose ctrlSetText "×";
_btnClose ctrlSetPosition [_x + _w - 0.06*_w, _y + 0.02*_h, 0.04*_w, 0.05*_h];
_btnClose ctrlCommit 0;
_btnClose ctrlAddEventHandler ["ButtonClick", { [] call AQTB_fnc_close }];

// список фокуса для клавы
uiNamespace setVariable ["AQTB_FocusCtrls", [_btnTasks, _btnMap, _btnClose]];
uiNamespace setVariable ["AQTB_FocusIdx", 0];
{ _x ctrlSetBackgroundColor [0,0,0,0] } forEach (uiNamespace getVariable ["AQTB_FocusCtrls", []]);
(_btnTasks) ctrlSetBackgroundColor [1,1,1,0.15];
ctrlSetFocus _btnTasks;

// сохраним домашние контролы (для hide/show при входе в подэкраны)
uiNamespace setVariable ["AQTB_HomeCtrls", [_bg, _shadow, _frame, _glare, _title, _icoTasks, _icoMap, _btnTasks, _btnMap, _btnClose]];
