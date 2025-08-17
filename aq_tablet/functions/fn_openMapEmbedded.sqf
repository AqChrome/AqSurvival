disableSerialization;

private _disp = uiNamespace getVariable ["AQTB_Display", displayNull];
if (isNull _disp) exitWith {};

// Прячем домашние контролы
{ if (!isNull _x) then { _x ctrlShow false } } forEach (uiNamespace getVariable ["AQTB_HomeCtrls", []]);

private _sx = safeZoneX;
private _sy = safeZoneY;
private _sw = safeZoneW;
private _sh = safeZoneH;

private _gw = 0.88 * _sw;
private _gh = 0.84 * _sh;

// Контейнер
private _grp = _disp ctrlCreate ["RscControlsGroup", -1];
_grp ctrlSetPosition [_sx + 0.06*_sw, _sy + 0.08*_sh, _gw, _gh];
_grp ctrlCommit 0;
uiNamespace setVariable ["AQTB_CurrentView", _grp];

// Фон (не обязателен)
private _bg = _disp ctrlCreate ["RscPicture", -1, _grp];
_bg ctrlSetText "aq_tablet\\ui\\tasks_bg_ca.paa";
_bg ctrlSetPosition [0, 0, _gw, _gh];
_bg ctrlCommit 0;

// Карта
private _map = _disp ctrlCreate ["RscMapControl", -1, _grp];
_map ctrlSetPosition [0.03*_gw, 0.06*_gh, 0.82*_gw, 0.72*_gh];
_map ctrlCommit 0;
uiNamespace setVariable ["AQTB_MapCtrl", _map];

// Центр и зум (используем сигнатуру [time, zoom, pos])
private _pp = getPos player;
_map ctrlMapAnimAdd [0.5, 0.35, [_pp select 0, _pp select 1]];
ctrlMapAnimCommit _map;

// Кнопки +/-
private _btnIn = _disp ctrlCreate ["RscButton", -1, _grp];
_btnIn ctrlSetText "+";
_btnIn ctrlSetPosition [0.86*_gw - 0.06*_gw, 0.06*_gh, 0.05*_gw, 0.05*_gh];
_btnIn ctrlCommit 0;
_btnIn ctrlAddEventHandler ["ButtonClick", {
  disableSerialization;
  private _map = uiNamespace getVariable ["AQTB_MapCtrl", controlNull];
  if (!isNull _map) then {
    private _scale = ctrlMapScale _map;
    private _center = _map ctrlMapScreenToWorld [0.5,0.5];
    _map ctrlMapAnimAdd [0.2, (_scale * 0.8) max 0.02, _center];
    ctrlMapAnimCommit _map;
  };
}];

private _btnOut = _disp ctrlCreate ["RscButton", -1, _grp];
_btnOut ctrlSetText "-";
_btnOut ctrlSetPosition [0.86*_gw - 0.06*_gw, 0.12*_gh, 0.05*_gw, 0.05*_gh];
_btnOut ctrlCommit 0;
_btnOut ctrlAddEventHandler ["ButtonClick", {
  disableSerialization;
  private _map = uiNamespace getVariable ["AQTB_MapCtrl", controlNull];
  if (!isNull _map) then {
    private _scale = ctrlMapScale _map;
    private _center = _map ctrlMapScreenToWorld [0.5,0.5];
    _map ctrlMapAnimAdd [0.2, (_scale * 1.25) min 3, _center];
    ctrlMapAnimCommit _map;
  };
}];

// Назад
private _back = _disp ctrlCreate ["RscButton", -1, _grp];
_back ctrlSetText "Назад";
_back ctrlSetPosition [0.04*_gw, 0.78*_gh, 0.14*_gw, 0.05*_gh];
_back ctrlCommit 0;
_back ctrlAddEventHandler ["ButtonClick", {
  disableSerialization;
  private _grp = uiNamespace getVariable ["AQTB_CurrentView", controlNull];
  if (!isNull _grp) then { ctrlDelete _grp };
  { if (!isNull _x) then { _x ctrlShow true } } forEach (uiNamespace getVariable ["AQTB_HomeCtrls", []]);
  uiNamespace setVariable ["AQTB_CurrentView", controlNull];
  uiNamespace setVariable ["AQTB_MapCtrl", controlNull];
}];
