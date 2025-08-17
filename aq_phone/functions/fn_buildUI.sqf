disableSerialization;

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
if (isNull _disp) exitWith { controlNull };

// === ГЕОМЕТРИЯ ТЕЛЕФОНА ===
private _rightPad  = 0.08 * safeZoneW;
private _bottomPad = 0.02 * safeZoneH;
private _phoneW    = 0.181 * safeZoneW;
private _aspect    = 2.2;                 // высота/ширина спрайтов телефона
private _phoneH    = _phoneW * _aspect;
_phoneH = _phoneH min (0.88 * safeZoneH);

private _x = safeZoneX + safeZoneW - _rightPad - _phoneW;
private _y = safeZoneY + safeZoneH - _bottomPad - _phoneH;

// pixel-snap
private _pxW = 1 / (getResolution select 2);
private _pxH = 1 / (getResolution select 3);
_x      = round (_x      / _pxW) * _pxW;
_y      = round (_y      / _pxH) * _pxH;
_phoneW = round (_phoneW / _pxW) * _pxW;
_phoneH = round (_phoneH / _pxH) * _pxH;

// контейнер телефона
private _grpClass = if (isClass (configFile >> "RscControlsGroupNoScrollbars")) then {
  "RscControlsGroupNoScrollbars"
} else {
  "RscControlsGroup"
};
private _grp = _disp ctrlCreate [_grpClass, -1];
_grp ctrlSetPosition [_x, _y, _phoneW, _phoneH];
_grp ctrlCommit 0;

// negative bleed (-0.5 px внутрь, как у тебя)
private _bleedPx = -0.5;
private _bleedW = _bleedPx * _pxW;
private _bleedH = _bleedPx * _pxH;

// ---- СЛОИ: тень → OFF → HOME → часы → ИКОНКА → рамка → блик ----
private _shadow = _disp ctrlCreate ["RscPicture", -1, _grp];
_shadow ctrlSetText "aq_phone\ui\phone_shadow_ca.paa";
_shadow ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_shadow ctrlCommit 0; _shadow ctrlEnable false;

private _off = _disp ctrlCreate ["RscPicture", -1, _grp];
_off ctrlSetText "aq_phone\ui\phone_wallpaper_blue_ca.paa";
_off ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_off ctrlSetFade 0;
_off ctrlCommit 0;

private _home = _disp ctrlCreate ["RscPicture", -1, _grp];
_home ctrlSetText "aq_phone\ui\phone_home_ca.paa";
_home ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_home ctrlSetFade 1;   // показывается при включении телефона
_home ctrlCommit 0;

// ЧАСЫ (поверх статус-бара на картинке)
private _barH = 0.085 * _phoneH;
private _clockXFrac = 0.62;
private _clockWFrac = 0.25;
private _clockYOff  = 0.155;
private _clockSize  = 0.90;

private _time = _disp ctrlCreate ["RscStructuredText", -1, _grp];
private _clockX = _clockXFrac * _phoneW;
private _clockW = _clockWFrac * _phoneW;
private _clockY = _clockYOff  * _phoneH;
_time ctrlSetPosition [ _clockX, _clockY, _clockW, _barH ];
_time ctrlSetStructuredText parseText format ["<t align='right' size='%1' color='#FFFFFF'>--:--</t>", _clockSize];
_time ctrlSetBackgroundColor [0,0,0,0];
_time ctrlSetFade 1;
_time ctrlCommit 0;

// ИКОНКА "ПОЧТА" (между HOME и FRAME/GLARE)
private _iconSize = 0.20 * _phoneW;
private _iconX    = 0.16 * _phoneW;
private _iconY    = _barH + 0.135 * _phoneH;

private _icoMail = _disp ctrlCreate ["RscPicture", -1, _grp];
private _iconPath = "aq_phone\ui\icon_mail_ca.paa";
if !(fileExists _iconPath) then {
  _iconPath = "a3\ui_f\data\IGUI\Cfg\Actions\gear_ca.paa"; // fallback, чтобы не было «бежевого квадрата»
};
_icoMail ctrlSetText _iconPath;
_icoMail ctrlSetTextColor [1,1,1,1];           // без «подкраса»
_icoMail ctrlSetBackgroundColor [0,0,0,0];
_icoMail ctrlSetPosition [_iconX, _iconY, _iconSize, _iconSize];
_icoMail ctrlSetFade 1;
_icoMail ctrlCommit 0;

private _btnMail = _disp ctrlCreate ["RscButton", -1, _grp];
_btnMail ctrlSetText "";
_btnMail ctrlSetBackgroundColor [0,0,0,0];
_btnMail ctrlSetPosition [_iconX, _iconY, _iconSize, _iconSize];
_btnMail ctrlSetFade 1;
_btnMail ctrlCommit 0;
_btnMail ctrlAddEventHandler ["ButtonClick", { [] call AQPH_fnc_openMail }];

// РАМКА
private _frame = _disp ctrlCreate ["RscPicture", -1, _grp];
_frame ctrlSetText "aq_phone\ui\phone_frame_black_ca.paa";
_frame ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_frame ctrlCommit 0; _frame ctrlEnable false;

// БЛИК (верхний декоративный слой; клики не ловит)
private _glare = _disp ctrlCreate ["RscPicture", -1, _grp];
_glare ctrlSetText "aq_phone\ui\phone_glare_ca.paa";
_glare ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_glare ctrlSetFade 0.15;
_glare ctrlCommit 0; _glare ctrlEnable false;

// СТЕЙТ
uiNamespace setVariable ["AQPH_Group", _grp];
uiNamespace setVariable ["AQPH_OffWallpaper", _off];
uiNamespace setVariable ["AQPH_Desktop", _home];
uiNamespace setVariable ["AQPH_TimeCtrl", _time];
uiNamespace setVariable ["AQPH_BarH", _barH];
uiNamespace setVariable ["AQPH_IconMail", _icoMail];
uiNamespace setVariable ["AQPH_IconMailBtn", _btnMail];
// домашние виджеты (чтобы show/hide работали разом)
uiNamespace setVariable ["AQPH_HomeWidgets", [_home, _time, _icoMail, _btnMail]];
uiNamespace setVariable ["AQPH_Controls", [_shadow, _off, _home, _time, _icoMail, _btnMail, _frame, _glare]];
_grp
