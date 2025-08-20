disableSerialization;

private _disp   = uiNamespace getVariable ["PDA_Display", displayNull];
private _screen = uiNamespace getVariable ["PDA_ScreenGroup", controlNull];
if (isNull _disp || {isNull _screen}) exitWith { controlNull };

private _pos = ctrlPosition _screen;
private _w = _pos select 2;
private _h = _pos select 3;

private _existing = uiNamespace getVariable ["PDA_HomeGroup", controlNull];
if (!isNull _existing) exitWith { _existing };

private _home = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1100, _screen];
_home ctrlSetPosition [0, 0, _w, _h];
_home ctrlCommit 0;
uiNamespace setVariable ["PDA_HomeGroup", _home];

["home", _home] call PDA_fnc_pageRegister;

private _hdr = _disp ctrlCreate ["RscStructuredText", -1, _home];
_hdr ctrlSetPosition [0.01, 0.03, _w - 0.02, 0.06];
_hdr ctrlCommit 0;
_hdr ctrlSetStructuredText parseText "<t shadow='0' align='center' color='#0d0d0d' font='PuristaBold' size='1.0'>Legion</t>";

private _items = missionNamespace getVariable ["PDA_MenuItems", [
  ["Задачи",   { [] call PDA_fnc_tasksOpen; }],
  ["Счётчик",  { /* [] call PDA_fnc_counterOpen; */ }],
  ["Детектор", { /* [] call PDA_fnc_detectorOpen; */ }]
]];

private _ROW_H   = 0.035;
private _ROW_GAP = 0.006;
private _padX    = 0.012;
private _startY  = 0.11;
private _EPS     = 0.0005;

{
  _x params ["_title", "_code"];
  private _i = _forEachIndex;
  private _y = _startY + _i * (_ROW_H + _ROW_GAP);

  private _row = _disp ctrlCreate ["RscText", -1, _home];
  _row ctrlSetPosition [_padX, _y, _w - 2*_padX - _EPS, _ROW_H];
  _row ctrlSetBackgroundColor [0.98,0.98,0.98,1];
  _row ctrlCommit 0;

  private _txt = _disp ctrlCreate ["RscStructuredText", -1, _home];
  _txt ctrlSetPosition [_padX + 0.008, _y + 0.003, _w - 2*_padX - 0.016 - _EPS, _ROW_H - 0.006];
  _txt ctrlCommit 0;
  _txt ctrlSetStructuredText parseText format ["<t shadow='0' color='#0d0d0d' font='PuristaMedium' size='0.85'>%1</t>", _title];

  private _btn = _disp ctrlCreate ["RscButton", 1200 + _i, _home];
  _btn ctrlSetText "";
  _btn ctrlSetPosition [_padX, _y, _w - 2*_padX - _EPS, _ROW_H];
  _btn ctrlSetBackgroundColor [0,0,0,0];
  _btn ctrlCommit 0;
  _btn ctrlAddEventHandler ["ButtonClick", {
    (_thisArgs select 0) call (_thisArgs select 1);
  }, [_i, _code]];
} forEach _items;

_home
