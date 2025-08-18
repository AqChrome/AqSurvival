disableSerialization;

private _notify = uiNamespace getVariable ["PDA_NotifyGroup", controlNull];
if (!isNull _notify) then {
  ctrlDelete _notify;
  uiNamespace setVariable ["PDA_NotifyGroup", controlNull];
};

private _q = missionNamespace getVariable ["PDA_NotifyQueue", []];
if (!(_q isEqualTo [])) then {
  _q deleteAt 0;
  missionNamespace setVariable ["PDA_NotifyQueue", _q];
};

if !((missionNamespace getVariable ["PDA_NotifyQueue", []]) isEqualTo []) exitWith {
  [] call PDA_fnc_notifyRender;
};

private _home = uiNamespace getVariable ["PDA_HomeGroup", controlNull];
if (!isNull _home) then {
  _home ctrlShow true;
};
