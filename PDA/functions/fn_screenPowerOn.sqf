
disableSerialization;

private _offPic  = uiNamespace getVariable ["PDA_OffOverlay", controlNull];
private _home    = uiNamespace getVariable ["PDA_HomeGroup", controlNull];
if (!isNull _offPic) then { _offPic ctrlShow false; };

private _q = missionNamespace getVariable ["PDA_NotifyQueue", []];
if (!(_q isEqualTo [])) exitWith {
  [] call PDA_fnc_notifyRender;
};

if (!isNull _home) then {
  _home ctrlShow true;
  _home ctrlSetFade 1; _home ctrlCommit 0;
  _home ctrlSetFade 0; _home ctrlCommit 0.12;
};
