disableSerialization;

private _disp   = uiNamespace getVariable ["PDA_Display", displayNull];
private _screen = uiNamespace getVariable ["PDA_ScreenGroup", controlNull];
if (isNull _disp || {isNull _screen}) exitWith {};

private _q = missionNamespace getVariable ["PDA_NotifyQueue", []];
if (_q isEqualTo []) exitWith {};

private _home   = uiNamespace getVariable ["PDA_HomeGroup", controlNull];
private _tasks  = uiNamespace getVariable ["PDA_TasksGroup", controlNull];
private _detail = uiNamespace getVariable ["PDA_TaskDetailGroup", controlNull];
{ if (!isNull _x) then { _x ctrlShow false; }; } forEach [_home, _tasks, _detail];

private _old = uiNamespace getVariable ["PDA_NotifyGroup", controlNull];
if (!isNull _old) then { ctrlDelete _old; uiNamespace setVariable ["PDA_NotifyGroup", controlNull]; };

private _pos = ctrlPosition _screen;
private _w = _pos select 2;
private _h = _pos select 3;

private _top   = _q select 0;
private _title = _top param [0,""];
private _text  = _top param [1,""];
private _tag   = toLower (_top param [2,"news"]);

private _bgCol  = [0.85,0.93,1.00,1];
private _hdrHex = "#0d2a4a";
switch (_tag) do {
  case "warning": { _bgCol=[1.00,0.96,0.78,1]; _hdrHex="#6b5e00"; };
  case "sos":     { _bgCol=[1.00,0.82,0.82,1]; _hdrHex="#5a0000"; };
};

private _notify = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1800, _screen];
_notify ctrlSetPosition [0, 0, _w, _h];
_notify ctrlCommit 0;
uiNamespace setVariable ["PDA_NotifyGroup", _notify];

private _bg = _disp ctrlCreate ["RscText", -1, _notify];
_bg ctrlSetPosition [0, 0, _w, _h];
_bg ctrlSetBackgroundColor _bgCol;
_bg ctrlCommit 0;

private _hdr = _disp ctrlCreate ["RscStructuredText", -1, _notify];
_hdr ctrlSetPosition [0.01, 0.03, _w - 0.02, 0.06];
_hdr ctrlCommit 0;
_hdr ctrlSetStructuredText parseText format [
  "<t shadow='0' align='center' color='%1' font='PuristaBold' size='1.0'>%2</t>",
  _hdrHex, _title
];

private _body = _disp ctrlCreate ["RscStructuredText", -1, _notify];
_body ctrlSetPosition [0.015, 0.11, _w - 0.03, _h - 0.11 - 0.12];
_body ctrlCommit 0;
_body ctrlSetStructuredText parseText format [
  "<t shadow='0' align='left' color='#151515' font='PuristaLight' size='0.9'>%1</t>",
  _text
];

private _btn = _disp ctrlCreate ["RscButton", 1850, _notify];
_btn ctrlSetText "Закрыть";
_btn ctrlSetPosition [_w*0.5 - 0.12, _h - 0.09, 0.24, 0.06];
_btn ctrlCommit 0;
_btn ctrlAddEventHandler ["ButtonClick", { [] call PDA_fnc_notifyClose }];
