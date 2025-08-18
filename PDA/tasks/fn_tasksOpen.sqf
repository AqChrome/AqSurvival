disableSerialization;

private _disp   = uiNamespace getVariable ["PDA_Display", displayNull];
private _screen = uiNamespace getVariable ["PDA_ScreenGroup", controlNull];
private _home   = uiNamespace getVariable ["PDA_HomeGroup", controlNull];
if (isNull _disp || {isNull _screen} || {isNull _home}) exitWith {};

_home ctrlShow false;

private _old = uiNamespace getVariable ["PDA_TasksGroup", controlNull];
if (!isNull _old) then { ctrlDelete _old; };

private _pos = ctrlPosition _screen;
private _w = _pos select 2;
private _h = _pos select 3;

private _list = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1700, _screen];
_list ctrlSetPosition [0, 0, _w, _h];
_list ctrlCommit 0;
uiNamespace setVariable ["PDA_TasksGroup", _list];

private _bg = _disp ctrlCreate ["RscText", -1, _list];
_bg ctrlSetPosition [0, 0, _w, _h];
_bg ctrlSetBackgroundColor [0.92,0.92,0.92,1];
_bg ctrlCommit 0;

private _hdr = _disp ctrlCreate ["RscStructuredText", -1, _list];
_hdr ctrlSetPosition [0.01, 0.03, _w - 0.02, 0.06];
_hdr ctrlCommit 0;
_hdr ctrlSetStructuredText parseText "<t shadow='0' align='center' color='#0d0d0d' font='PuristaBold' size='1.0'>Задачи</t>";

private _tasks = missionNamespace getVariable ["PDA_Tasks", []];
private _ROW_H   = 0.035;
private _ROW_GAP = 0.006;
private _padX    = 0.012;
private _startY  = 0.11;
private _EPS     = 0.0005;

if (_tasks isEqualTo []) then {
  private _empty = _disp ctrlCreate ["RscStructuredText", -1, _list];
  _empty ctrlSetPosition [0.015, _startY, _w - 0.03, 0.06];
  _empty ctrlCommit 0;
  _empty ctrlSetStructuredText parseText "<t shadow='0' color='#333333' size='0.9'>Нет доступных заданий</t>";
} else {
  {
    private _i = _forEachIndex;
    _x params ["_id","_type","_title","_text","_tag"];
    private _y = _startY + _i * (_ROW_H + _ROW_GAP);

    private _row = _disp ctrlCreate ["RscText", -1, _list];
    _row ctrlSetPosition [_padX, _y, _w - 2*_padX - _EPS, _ROW_H];
    _row ctrlSetBackgroundColor [0.98,0.98,0.98,1];
    _row ctrlCommit 0;

    private _txt = _disp ctrlCreate ["RscStructuredText", -1, _list];
    _txt ctrlSetPosition [_padX + 0.008, _y + 0.003, _w - 2*_padX - 0.016 - _EPS, _ROW_H - 0.006];
    _txt ctrlCommit 0;
    _txt ctrlSetStructuredText parseText format [
      "<t align='center' shadow='0' color='#0d0d0d' font='PuristaMedium' size='0.85'>%1</t>",
      _type
    ];

    private _btn = _disp ctrlCreate ["RscButton", 1710 + _i, _list];
    _btn ctrlSetText "";
    _btn ctrlSetPosition [_padX, _y, _w - 2*_padX - _EPS, _ROW_H];
    _btn ctrlSetBackgroundColor [0,0,0,0];
    _btn ctrlCommit 0;
    _btn ctrlAddEventHandler ["ButtonClick", format ["[%1] call PDA_fnc_taskDetail;", _id]];
  } forEach _tasks;
};

private _back = _disp ctrlCreate ["RscButton", 1790, _list];
_back ctrlSetText "Назад";
_back ctrlSetPosition [_w*0.5 - 0.12, _h - 0.09, 0.24, 0.06];
_back ctrlCommit 0;
_back ctrlAddEventHandler ["ButtonClick", { [] call PDA_fnc_tasksClose }];
