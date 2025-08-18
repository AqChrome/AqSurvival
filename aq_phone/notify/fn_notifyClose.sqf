/*
  Закрыть текущий оверлей. Если в очереди остались уведомления — показать следующее.
*/
disableSerialization;

private _overlay = uiNamespace getVariable ["AQPH_NotifyOverlay", controlNull];
if (isNull _overlay) exitWith {};

_overlay ctrlSetFade 1;
_overlay ctrlCommit 0.10;

[_overlay] spawn {
  params ["_ov"];
  uiSleep 0.11;
  if (!isNull _ov) then { ctrlDelete _ov; };
  uiNamespace setVariable ["AQPH_NotifyOverlay", controlNull];

  // снять текущее из очереди
  private _q = missionNamespace getVariable ["AQPH_NotifyQueue", []];
  if (!(_q isEqualTo [])) then {
    _q deleteAt 0;
    missionNamespace setVariable ["AQPH_NotifyQueue", _q];
  };

  // показать следующее, если есть
  if !((missionNamespace getVariable ["AQPH_NotifyQueue", []]) isEqualTo []) then {
    [] call AQPH_fnc_notifyRender;
  };
};
