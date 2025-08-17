if !(uiNamespace getVariable ["AQPH_open", false]) exitWith {};
disableSerialization;

// закрыть приложение, если открыто
private _app = uiNamespace getVariable ["AQPH_AppGroup", controlNull];
if (!isNull _app) then { ctrlDelete _app; uiNamespace setVariable ["AQPH_AppGroup", controlNull]; };

// HOME widgets → спрятать, OFF → показать
private _off = uiNamespace getVariable ["AQPH_OffWallpaper", controlNull];
{ if (!isNull _x) then { _x ctrlSetFade 1; _x ctrlCommit 0.10; } } forEach (uiNamespace getVariable ["AQPH_HomeWidgets", []]);
if (!isNull _off) then { _off ctrlSetFade 0; _off ctrlCommit 0.10; };

// стопнуть часы
private _hdl = uiNamespace getVariable ["AQPH_ClockThread", scriptNull];
if (!isNil "_hdl" && {!isNull _hdl}) then { terminate _hdl; };
uiNamespace setVariable ["AQPH_ClockThread", scriptNull];

private _grp = uiNamespace getVariable ["AQPH_Group", controlNull];
if (!isNull _grp) then {
  uiSleep 0.02;
  private _p = ctrlPosition _grp;
  private _pxH = 1 / (getResolution select 3);
  private _offY = safeZoneY + safeZoneH + 0.01;
  _offY = round (_offY / _pxH) * _pxH;

  _grp ctrlSetPosition [_p#0, _offY, _p#2, _p#3];
  _grp ctrlCommit 0.30;
  waitUntil { ctrlCommitted _grp };
};

closeDialog 2;

uiNamespace setVariable ["AQPH_open", false];
uiNamespace setVariable ["AQPH_Display", displayNull];
uiNamespace setVariable ["AQPH_Group", controlNull];
uiNamespace setVariable ["AQPH_Controls", []];
uiNamespace setVariable ["AQPH_OffWallpaper", controlNull];
uiNamespace setVariable ["AQPH_Desktop", controlNull];
uiNamespace setVariable ["AQPH_StatusBar", controlNull];
uiNamespace setVariable ["AQPH_TimeCtrl", controlNull];
uiNamespace setVariable ["AQPH_IconMail", controlNull];
uiNamespace setVariable ["AQPH_IconMailBtn", controlNull];
uiNamespace setVariable ["AQPH_HomeWidgets", []];
