disableSerialization;
params ["_task"];
_task params ["_idT","_type","_title","_text","_tag"];

private _disp   = uiNamespace getVariable ["PDA_Display", displayNull];
private _screen = uiNamespace getVariable ["PDA_ScreenGroup", controlNull];
if (isNull _disp || {isNull _screen}) exitWith { controlNull };

private _old = uiNamespace getVariable ["PDA_TaskDetailGroup", controlNull];
if (!isNull _old) then { ctrlDelete _old; uiNamespace setVariable ["PDA_TaskDetailGroup", controlNull]; };

private _pos = ctrlPosition _screen;
private _w = _pos select 2;
private _h = _pos select 3;

private _det = _disp ctrlCreate ["RscControlsGroupNoScrollbars", 1750, _screen];
_det ctrlSetPosition [0, 0, _w, _h];
_det ctrlCommit 0;
uiNamespace setVariable ["PDA_TaskDetailGroup", _det];

["detail", _det] call PDA_fnc_pageRegister;

private _bg = _disp ctrlCreate ["RscText", -1, _det];
_bg ctrlSetPosition [0, 0, _w, _h];
_bg ctrlSetBackgroundColor [0.96,0.96,0.96,1];
_bg ctrlCommit 0;

private _hdr = _disp ctrlCreate ["RscStructuredText", -1, _det];
_hdr ctrlSetPosition [0.01, 0.03, _w - 0.02, 0.06];
_hdr ctrlCommit 0;
_hdr ctrlSetStructuredText parseText format [
  "<t shadow='0' align='center' color='#0d0d0d' font='PuristaBold' size='1.0'>%1</t>", _title
];

private _body = _disp ctrlCreate ["RscStructuredText", -1, _det];
_body ctrlSetPosition [0.015, 0.11, _w - 0.03, _h - 0.11 - 0.18];
_body ctrlCommit 0;
_body ctrlSetStructuredText parseText format [
  "<t shadow='0' align='left' color='#151515' font='PuristaLight' size='0.9'>%1</t>", _text
];

private _BTN_W = 0.20; private _BTN_H = 0.06; private _BTN_GAP = 0.02; private _BTN_Y = _h - 0.09;
private _totalW = _BTN_W*2 + _BTN_GAP; private _startX = (_w*0.5) - (_totalW/2);

private _btnAccept = _disp ctrlCreate ["RscButton", 1761, _det];
_btnAccept ctrlSetText (localize "STR_AQ_PDA_BUTTON_ACCEPT");
_btnAccept ctrlSetPosition [_startX, _BTN_Y, _BTN_W, _BTN_H];
_btnAccept ctrlCommit 0;
_btnAccept ctrlAddEventHandler ["ButtonClick", format ["[%1] call PDA_fnc_taskAccept;", _idT]];

private _btnDecline = _disp ctrlCreate ["RscButton", 1762, _det];
_btnDecline ctrlSetText (localize "STR_AQ_PDA_BUTTON_DECLINE");
_btnDecline ctrlSetPosition [_startX + _BTN_W + _BTN_GAP, _BTN_Y, _BTN_W, _BTN_H];
_btnDecline ctrlCommit 0;
_btnDecline ctrlAddEventHandler ["ButtonClick", format ["[%1] call PDA_fnc_taskDecline;", _idT]];

_det
