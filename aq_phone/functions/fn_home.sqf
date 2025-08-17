disableSerialization;
private _app = uiNamespace getVariable ["AQPH_AppGroup", controlNull];
if (!isNull _app) then { ctrlDelete _app; };
uiNamespace setVariable ["AQPH_AppGroup", controlNull];

// показать виджеты домашнего стола
{ if (!isNull _x) then { _x ctrlSetFade 0; _x ctrlCommit 0.10; } } forEach (uiNamespace getVariable ["AQPH_HomeWidgets", []]);
