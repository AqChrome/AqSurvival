disableSerialization;

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
if (isNull _disp) exitWith { controlNull };

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> parent of a9997c0 (Фак)
// === ГЕОМЕТРИЯ ===
=======
// === БАЗОВАЯ ГЕОМЕТРИЯ (можно подгонять) ===
>>>>>>> parent of 9ea0e42 (2)
private _rightPad  = 0.08 * safeZoneW;
private _bottomPad = 0.02 * safeZoneH;
private _phoneW    = 0.181 * safeZoneW;
private _aspect    = 2.2;                 // высота/ширина твоих спрайтов
private _phoneH    = _phoneW * _aspect;
=======
=======
>>>>>>> parent of 26e0510 (hot fix KPK)
// --- Геометрия телефона (твои текущие числа) ---
private _rightPad  = 0.08 * safeZoneW;    // отступ справа
private _bottomPad = 0.02 * safeZoneH;    // отступ снизу
private _phoneW = 0.181 * safeZoneW;      // ширина телефона
private _aspect = 2.2;                    // ВЫСОТА/ШИРИНА (твоя текстура)
private _phoneH = _phoneW * _aspect;
<<<<<<< HEAD
>>>>>>> parent of 26e0510 (hot fix KPK)
=======
>>>>>>> parent of 26e0510 (hot fix KPK)
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

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> parent of a9997c0 (Фак)
// контейнер
=======
// контейнер (без скроллов, если класс есть)
>>>>>>> parent of 9ea0e42 (2)
private _grpClass = if (isClass (configFile >> "RscControlsGroupNoScrollbars")) then {
  "RscControlsGroupNoScrollbars"
} else {
  "RscControlsGroup"
};
private _grp = _disp ctrlCreate [_grpClass, -1];
_grp ctrlSetPosition [_x, _y, _phoneW, _phoneH];
_grp ctrlCommit 0;

// отрицательный bleed = -0.5 px внутрь (как ты сделал)
private _bleedPx = -0.5;
private _bleedW = _bleedPx * _pxW;
private _bleedH = _bleedPx * _pxH;

<<<<<<< HEAD
// СЛОИ: тень → OFF → HOME → часы → ИКОНКА → рамка → блик
<<<<<<< HEAD
=======
// Контейнер
private _grp = _disp ctrlCreate ["RscControlsGroup", -1];
_grp ctrlSetPosition [_x, _y, _phoneW, _phoneH];
_grp ctrlCommit 0;

// Overscan: расширим картинки на 2 пикселя по всем сторонам
private _bleedW = -0.5 * _pxW;
private _bleedH = -0.5 * _pxH;

// Тень
>>>>>>> parent of 26e0510 (hot fix KPK)
=======
// Контейнер
private _grp = _disp ctrlCreate ["RscControlsGroup", -1];
_grp ctrlSetPosition [_x, _y, _phoneW, _phoneH];
_grp ctrlCommit 0;

// Overscan: расширим картинки на 2 пикселя по всем сторонам
private _bleedW = -0.5 * _pxW;
private _bleedH = -0.5 * _pxH;

// Тень
>>>>>>> parent of 26e0510 (hot fix KPK)
=======
>>>>>>> parent of a9997c0 (Фак)
=======
// СЛОИ: тень → OFF (синий) → HOME (раб. стол) → [часы] → ИКОНКА ПОЧТЫ → рамка → блик
>>>>>>> parent of 9ea0e42 (2)
private _shadow = _disp ctrlCreate ["RscPicture", -1, _grp];
_shadow ctrlSetText "aq_phone\ui\phone_shadow_ca.paa";
_shadow ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_shadow ctrlCommit 0; _shadow ctrlEnable false;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
// выключенный экран (синий)
>>>>>>> parent of 9ea0e42 (2)
private _off = _disp ctrlCreate ["RscPicture", -1, _grp];
_off ctrlSetText "aq_phone\ui\phone_wallpaper_blue_ca.paa";
_off ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_off ctrlSetFade 0;
_off ctrlCommit 0;

// рабочий стол (твоя картинка уже со статус-баром поверх)
private _home = _disp ctrlCreate ["RscPicture", -1, _grp];
_home ctrlSetText "aq_phone\ui\phone_home_ca.paa";
_home ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_home ctrlSetFade 1;  // появится после выезда
_home ctrlCommit 0;

// --- ЧАСЫ (поверх твоего статус-бара на картинке) ---
// <--- ТУТ РАЗМЕТКА часов
private _clockXFrac = 0.62;  // от 0.00 (лево) до 1.00 (право)
private _clockWFrac = 0.25;  // доля ширины, отведённая под часы
private _clockYOff  = 0.155; // доля высоты телефона от верхнего края
private _clockSize  = 0.90;  // размер шрифта

private _barH = 0.085 * _phoneH;                // высота «статус-бара» на твоём арте
private _time = _disp ctrlCreate ["RscStructuredText", -1, _grp];
private _clockX = _clockXFrac * _phoneW;
private _clockW = _clockWFrac * _phoneW;
private _clockY = _clockYOff  * _phoneH;
_time ctrlSetPosition [ _clockX, _clockY, _clockW, _barH ];
_time ctrlSetStructuredText parseText format ["<t align='right' size='%1' color='#FFFFFF'>--:--</t>", _clockSize];
_time ctrlSetBackgroundColor [0,0,0,0];
_time ctrlSetFade 1;  // скрыт пока OFF-экран
_time ctrlCommit 0;

// --- ИКОНКА "ПОЧТА" НА РАБОЧЕМ СТОЛЕ (между HOME и FRAME/GLARE) ---
private _iconSize = 0.20 * _phoneW;
private _iconX    = 0.16 * _phoneW;
private _iconY    = _barH + 0.135 * _phoneH;

private _icoMail = _disp ctrlCreate ["RscPicture", -1, _grp];
_icoMail ctrlSetText "aq_phone\ui\icon_mail_ca.paa";
_icoMail ctrlSetTextColor [1,1,1,1];  // фикс: не «красить» текстуру
_icoMail ctrlSetPosition [_iconX, _iconY, _iconSize, _iconSize];
_icoMail ctrlSetFade 1;   // синхронно с домашним столом
_icoMail ctrlCommit 0;

private _btnMail = _disp ctrlCreate ["RscButton", -1, _grp];
_btnMail ctrlSetText "";
_btnMail ctrlSetBackgroundColor [0,0,0,0];
_btnMail ctrlSetPosition [_iconX, _iconY, _iconSize, _iconSize];
_btnMail ctrlSetFade 1;
_btnMail ctrlCommit 0;
_btnMail ctrlAddEventHandler ["ButtonClick", { [] call AQPH_fnc_openMail }];

<<<<<<< HEAD
// РАМКА (над внутренними элементами)
<<<<<<< HEAD
=======
// Обои
private _bg = _disp ctrlCreate ["RscPicture", -1, _grp];
_bg ctrlSetText "aq_phone\ui\phone_wallpaper_blue_ca.paa";
_bg ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_bg ctrlCommit 0;

// Рамка
>>>>>>> parent of 26e0510 (hot fix KPK)
=======
// Обои
private _bg = _disp ctrlCreate ["RscPicture", -1, _grp];
_bg ctrlSetText "aq_phone\ui\phone_wallpaper_blue_ca.paa";
_bg ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_bg ctrlCommit 0;

// Рамка
>>>>>>> parent of 26e0510 (hot fix KPK)
=======
>>>>>>> parent of a9997c0 (Фак)
=======
// РАМКА (над всеми внутренними элементами)
>>>>>>> parent of 9ea0e42 (2)
private _frame = _disp ctrlCreate ["RscPicture", -1, _grp];
_frame ctrlSetText "aq_phone\ui\phone_frame_black_ca.paa";
_frame ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_frame ctrlCommit 0; _frame ctrlEnable false;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
// БЛИК (верхний декоративный слой)
=======
// Блик
>>>>>>> parent of 26e0510 (hot fix KPK)
=======
// Блик
>>>>>>> parent of 26e0510 (hot fix KPK)
=======
// БЛИК (верхний декоративный слой)
>>>>>>> parent of a9997c0 (Фак)
=======
// БЛИК (самый верхний декоративный слой)
>>>>>>> parent of 9ea0e42 (2)
private _glare = _disp ctrlCreate ["RscPicture", -1, _grp];
_glare ctrlSetText "aq_phone\ui\phone_glare_ca.paa";
_glare ctrlSetPosition [-_bleedW, -_bleedH, _phoneW + 2*_bleedW, _phoneH + 2*_bleedH];
_glare ctrlSetFade 0.15;
_glare ctrlCommit 0; _glare ctrlEnable false;

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
// СТЕЙТ
=======
// ССЫЛКИ/СТЕЙТ
>>>>>>> parent of 9ea0e42 (2)
uiNamespace setVariable ["AQPH_Group", _grp];
uiNamespace setVariable ["AQPH_OffWallpaper", _off];
uiNamespace setVariable ["AQPH_Desktop", _home];
uiNamespace setVariable ["AQPH_TimeCtrl", _time];
uiNamespace setVariable ["AQPH_BarH", _barH];
uiNamespace setVariable ["AQPH_IconMail", _icoMail];
uiNamespace setVariable ["AQPH_IconMailBtn", _btnMail];

// все элементы домашнего стола (чтобы fade делать разом): фон, часы, иконка, кнопка
uiNamespace setVariable ["AQPH_HomeWidgets", [_home, _time, _icoMail, _btnMail]];
uiNamespace setVariable ["AQPH_Controls", [_shadow, _off, _home, _time, _icoMail, _btnMail, _frame, _glare]];
=======
uiNamespace setVariable ["AQPH_Controls", [_shadow, _bg, _frame, _glare]];
>>>>>>> parent of 26e0510 (hot fix KPK)
=======
uiNamespace setVariable ["AQPH_Controls", [_shadow, _bg, _frame, _glare]];
>>>>>>> parent of 26e0510 (hot fix KPK)
_grp
