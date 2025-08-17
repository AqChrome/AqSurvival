disableSerialization;

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
if (isNull _disp) exitWith { controlNull };

// Геометрия телефона
private _rightPad = 0.08 * safeZoneW;     // отступ справа
private _bottomPad = 0.02 * safeZoneH;    // отступ снизу
private _phoneW = 0.181 * safeZoneW;
private _aspect = 2.2;                     // высота/ширина картинки
private _phoneH = _phoneW * _aspect;
_phoneH = _phoneH min (0.88 * safeZoneH);

private _x = safeZoneX + safeZoneW - _rightPad - _phoneW;
private _y = safeZoneY + safeZoneH - _bottomPad - _phoneH;

// Группа-контейнер
private _grp = _disp ctrlCreate ["RscControlsGroup", -1];
_grp ctrlSetPosition [_x, _y, _phoneW, _phoneH];
_grp ctrlCommit 0;

// Тень (подложка)
private _shadow = _disp ctrlCreate ["RscPicture", -1, _grp];
_shadow ctrlSetText "aq_phone\ui\phone_shadow_ca.paa";
_shadow ctrlSetPosition [0, 0, _phoneW, _phoneH];
_shadow ctrlCommit 0; _shadow ctrlEnable false;

// Обои (экран)
private _bg = _disp ctrlCreate ["RscPicture", -1, _grp];
_bg ctrlSetText "aq_phone\ui\phone_wallpaper_blue_ca.paa";
_bg ctrlSetPosition [0, 0, _phoneW, _phoneH];
_bg ctrlCommit 0;

// Рамка смартфона
private _frame = _disp ctrlCreate ["RscPicture", -1, _grp];
_frame ctrlSetText "aq_phone\ui\phone_frame_black_ca.paa";
_frame ctrlSetPosition [0, 0, _phoneW, _phoneH];
_frame ctrlCommit 0; _frame ctrlEnable false;

// Блик
private _glare = _disp ctrlCreate ["RscPicture", -1, _grp];
_glare ctrlSetText "aq_phone\ui\phone_glare_ca.paa";
_glare ctrlSetPosition [0, 0, _phoneW, _phoneH];
_glare ctrlSetFade 0.15;
_glare ctrlCommit 0; _glare ctrlEnable false;

uiNamespace setVariable ["AQPH_Controls", [_shadow, _bg, _frame, _glare]];
_grp
