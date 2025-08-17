if !(uiNamespace getVariable ["AQPH_open", false]) exitWith {};
disableSerialization;

private _grp = uiNamespace getVariable ["AQPH_Group", controlNull];
if (!isNull _grp) then {
  private _p = ctrlPosition _grp;
  private _offY = safeZoneY + safeZoneH + 0.01;
  _grp ctrlSetPosition [_p#0, _offY, _p#2, _p#3];
  _grp ctrlCommit 0.30;
  uiSleep 0.32;
};
closeDialog 2;

uiNamespace setVariable ["AQPH_open", false];
uiNamespace setVariable ["AQPH_Display", displayNull];
uiNamespace setVariable ["AQPH_Group", controlNull];
uiNamespace setVariable ["AQPH_Controls", []];
