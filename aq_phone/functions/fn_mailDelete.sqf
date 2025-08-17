disableSerialization;
params ["_idx"];

private _mails = + (missionNamespace getVariable ["AQPH_Mails", []]);
if (_idx < 0 || {_idx >= count _mails}) exitWith {};

_mails deleteAt _idx;
missionNamespace setVariable ["AQPH_Mails", _mails];

// перерисуем список
[] call AQPH_fnc_openMail;
