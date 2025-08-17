disableSerialization;

private _layer = uiNamespace getVariable ["AQTB_Layer", -1];
if (_layer != -1) then { _layer cutText ["", "PLAIN"]; };

uiNamespace setVariable ["AQTB_open", false];
uiNamespace setVariable ["AQTB_Display", displayNull];
uiNamespace setVariable ["AQTB_CurrentView", controlNull];
uiNamespace setVariable ["AQTB_HomeCtrls", []];
uiNamespace setVariable ["AQTB_MapCtrl", controlNull];
