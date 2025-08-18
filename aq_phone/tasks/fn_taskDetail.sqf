/*
  Открыть страницу деталей задачи по id:
  - скрыть список задач
  - показать детали
*/
disableSerialization;
params ["_id"];

private _disp   = uiNamespace getVariable ["AQPH_Display", displayNull];
private _screen = uiNamespace getVariable ["AQPH_ScreenGroup", controlNull];
private _list   = uiNamespace getVariable ["AQPH_TasksGroup", controlNull];
if (isNull _disp || {isNull _screen}) exitWith {};

// Скрыть список
if (!isNull _list) then { _list ctrlShow false; };

// Найти задачу
private _tasks = missionNamespace getVariable ["AQPH_Tasks", []];
private _idx = _tasks findIf { (_x select 0) isEqualTo _id };
if (_idx < 0) exitWith {};

private _task = _tasks select _idx;
_task params ["_idT","_type","_title","_text","_tag"];

// Геометрия
private _pos = ctrlPosition _screen;
private _w = _pos select 2;
private _h = _pos select 3;

// Удалить старый детальный, если есть
private _oldDet = uiNamespace getVariable ["AQPH_TaskDetailGroup", controlNull];
if (!isNull _oldDet) then { ctrlDelete _oldDet; };

// Создать детальный
private _det = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1750, _screen];
_det ctrlSetPosition [0, 0, _w, _h];
_det ctrlCommit 0;
uiNamespace setVariable ["AQPH_TaskDetailGroup", _det];

// фон
private _bg = _disp ctrlCreate ["RscText", -1, _det];
_bg ctrlSetPosition [0, 0, _w, _h];
_bg ctrlSetBackgroundColor [0.96,0.96,0.96,1];
_bg ctrlCommit 0;

// заголовок
private _hdr = _disp ctrlCreate ["RscStructuredText", -1, _det];
_hdr ctrlSetPosition [0.01, 0.03, _w - 0.02, 0.06];
_hdr ctrlCommit 0;
_hdr ctrlSetStructuredText parseText format [
  "<t shadow='0' align='center' color='#0d0d0d' font='PuristaBold' size='1.0'>%1</t>",
  _title
];

// текст
private _body = _disp ctrlCreate ["RscStructuredText", -1, _det];
_body ctrlSetPosition [0.015, 0.11, _w - 0.03, _h - 0.11 - 0.18];
_body ctrlCommit 0;
_body ctrlSetStructuredText parseText format [
  "<t shadow='0' align='left' color='#151515' font='PuristaLight' size='0.9'>%1</t>",
  _text
];

private _BTN_W   = 0.1; // 0.18
private _BTN_H   = 0.055;
private _BTN_GAP = 0.015; // 0.016
private _BTN_Y   = _h - 0.085;

// Центрируем пары кнопок относительно середины экрана
private _totalW = _BTN_W*2 + _BTN_GAP;
private _startX = (_w*0.5) - (_totalW/2);

// кнопки Accept / Decline
private _btnAccept = _disp ctrlCreate ["RscButton", 1761, _det];
_btnAccept ctrlSetText "Принять";
_btnAccept ctrlSetPosition [_startX, _BTN_Y, _BTN_W, _BTN_H];
_btnAccept ctrlCommit 0;
_btnAccept ctrlAddEventHandler ["ButtonClick", format ["[%1] call AQPH_fnc_taskAccept;", _idT]];

private _btnDecline = _disp ctrlCreate ["RscButton", 1762, _det];
_btnDecline ctrlSetText "Отклонить";
_btnDecline ctrlSetPosition [_startX + _BTN_W + _BTN_GAP, _BTN_Y, _BTN_W, _BTN_H];
_btnDecline ctrlCommit 0;
_btnDecline ctrlAddEventHandler ["ButtonClick", format ["[%1] call AQPH_fnc_taskDecline;", _idT]];
