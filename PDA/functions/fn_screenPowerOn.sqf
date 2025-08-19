/*
  Если авто‑показ включён и в очереди есть уведомления — показываем их как модальную страницу.
  Иначе — открываем главную.
*/
disableSerialization;

private _offPic  = uiNamespace getVariable ["PDA_OffOverlay", controlNull];
private _home    = uiNamespace getVariable ["PDA_HomeGroup", controlNull];
if (!isNull _offPic) then { _offPic ctrlShow false; };

// init + регистрация home
[] call PDA_fnc_pageInit;
if (!isNull _home) then { ["home", _home] call PDA_fnc_pageRegister; };

private _auto = call PDA_fnc_notifyAutoOpenGet;
private _q    = missionNamespace getVariable ["PDA_NotifyQueue", []];

if (_auto && {!(_q isEqualTo [])}) then {
  [] call PDA_fnc_notifyRender;
} else {
  if (!isNull _home) then { ["home"] call PDA_fnc_pageShowOnly; };
};
