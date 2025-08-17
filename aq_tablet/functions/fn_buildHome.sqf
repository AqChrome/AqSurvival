disableSerialization;

private _disp = uiNamespace getVariable ["AQTB_Display", displayNull];
if (isNull _disp) exitWith {};

private _x = safeZoneX;
private _y = safeZoneY;
private _w = safeZoneW;
private _h = safeZoneH;

// Обои
private _bg = _disp ctrlCreate ["RscPicture", -1];
_bg ctrlSetText "aq_tablet\\ui\\tablet_wallpaper_ca.paa";
_bg ctrlSetPosition [_x, _y, _w, _h];
_bg ctrlCommit 0;

// Заголовок
private _title = _disp ctrlCreate ["RscStructuredText", -1];
_title ctrlSetPosition [_x + 0.02*_w, _y + 0.02*_h, 0.30*_w, 0.06*_h];
_title ctrlSetStructuredText parseText "<t size='1.2' color='#FFFFFF'>AQ Tablet</t>";
_title ctrlSetBackgroundColor [0,0,0,0.30];
_title ctrlCommit 0;

// Иконки
private _iconSize = 0.12 * _w;
private _pad = 0.02 * _w;
private _rowY = _y + 0.20 * _h;

private _btnTasks = _disp ctrlCreate ["RscActivePicture", -1];
_btnTasks ctrlSetText "aq_tablet\\ui\\icon_tasks_ca.paa";
_btnTasks ctrlSetTooltip "Tasks";
_btnTasks ctrlSetPosition [_x + _pad, _rowY, _iconSize, _iconSize];
_btnTasks ctrlCommit 0;
_btnTasks ctrlAddEventHandler ["ButtonClick", { ["tasks"] call AQTB_fnc_onHomeClick }];

private _btnMap = _disp ctrlCreate ["RscActivePicture", -1];
_btnMap ctrlSetText "aq_tablet\\ui\\icon_map_ca.paa";
_btnMap ctrlSetTooltip "Map";
_btnMap ctrlSetPosition [_x + _pad*2 + _iconSize, _rowY, _iconSize, _iconSize];
_btnMap ctrlCommit 0;
_btnMap ctrlAddEventHandler ["ButtonClick", { ["map"] call AQTB_fnc_onHomeClick }];

// Тень, рамка, блик
private _shadow = _disp ctrlCreate ["RscPicture", -1];
_shadow ctrlSetText "aq_tablet\\ui\\tablet_shadow_ca.paa";
_shadow ctrlSetPosition [_x, _y, _w, _h];
_shadow ctrlCommit 0; _shadow ctrlEnable false;

private _frame = _disp ctrlCreate ["RscPicture", -1];
_frame ctrlSetText "aq_tablet\\ui\\tablet_frame_land_ca.paa";
_frame ctrlSetPosition [_x, _y, _w, _h];
_frame ctrlCommit 0; _frame ctrlEnable false;

private _glare = _disp ctrlCreate ["RscPicture", -1];
_glare ctrlSetText "aq_tablet\\ui\\tablet_glare_ca.paa";
_glare ctrlSetPosition [_x, _y, _w, _h];
_glare ctrlSetFade 0.2;
_glare ctrlCommit 0; _glare ctrlEnable false;

// Сохраняем
uiNamespace setVariable ["AQTB_HomeCtrls", [_bg, _title, _btnTasks, _btnMap, _shadow, _frame, _glare]];
