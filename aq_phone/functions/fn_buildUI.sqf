disableSerialization;

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
if (isNull _disp) exitWith { controlNull };

// --- Геометрия телефона (твои текущие числа) ---
private _rightPad  = 0.08 * safeZoneW;    // отступ справа
private _bottomPad = 0.02 * safeZoneH;    // отступ снизу
private _phoneW = 0.181 * safeZoneW;      // ширина телефона
private _aspect = 2.2;                    // ВЫСОТА/ШИРИНА (твоя текстура)
private _phoneH = _phoneW * _aspect;
_phoneH = _phoneH min (0.88 * safeZoneH);

private _x = safeZoneX + safeZoneW - _rightPad - _phoneW;
private _y = safeZoneY + safeZoneH - _bottomPad - _phoneH;

// --- Pixel snap к реальной пиксельной сетке ---
private _pxW = 1 / (getResolution select 2);
private _pxH = 1 / (getResolution select 3);

_x      = round (_x      / _pxW) * _pxW;
_y      = round (_y      / _pxH) * _pxH;
_phoneW = round (_phoneW / _pxW) * _pxW;
_phoneH = round (_phoneH / _pxH) * _pxH;

// Контейнер
private _grp = _disp ctrlCreate ["RscControlsGroup", -1];
_grp ctrlSetPosition [_x, _y, _phoneW, _phoneH];
_grp ctrlCommit 0;

// Overscan: расширим картинки на 2 пикселя по всем сторонам
private _bleedW = -0.5 * _pxW;
private _bleedH = -0.5 * _pxH;

// Тень
private _shadow = _disp ctrlCreate ["RscPicture", -1, _grp];
_shadow ctrlSetText "aq_phone\ui\phone_shadow_ca.paa";
_shadow ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_shadow ctrlCommit 0; _shadow ctrlEnable false;

// Обои
private _bg = _disp ctrlCreate ["RscPicture", -1, _grp];
_bg ctrlSetText "aq_phone\ui\phone_wallpaper_blue_ca.paa";
_bg ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_bg ctrlCommit 0;

// Рамка
private _frame = _disp ctrlCreate ["RscPicture", -1, _grp];
_frame ctrlSetText "aq_phone\ui\phone_frame_black_ca.paa";
_frame ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_frame ctrlCommit 0; _frame ctrlEnable false;

// Блик
private _glare = _disp ctrlCreate ["RscPicture", -1, _grp];
_glare ctrlSetText "aq_phone\ui\phone_glare_ca.paa";
_glare ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_glare ctrlSetFade 0.15;
_glare ctrlCommit 0; _glare ctrlEnable false;

uiNamespace setVariable ["AQPH_Controls", [_shadow, _bg, _frame, _glare]];
_grp
