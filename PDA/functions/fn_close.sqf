disableSerialization;

private _disp = uiNamespace getVariable ["PDA_Display", displayNull];
if (isNull _disp) exitWith {};
playSound "PDA_PowerOff";

[] call PDA_fnc_screenPowerOff;

private _rootGrp = _disp displayCtrl 10;
if (!isNull _rootGrp) then {
  private _pos = ctrlPosition _rootGrp;

  [_disp, _rootGrp, _pos] spawn {
    params ["_d","_rg","_p"];
    uiSleep 0.14;
	
    _rg ctrlSetPosition [(_p select 0), (_p select 1) + 0.06, (_p select 2), (_p select 3)];
    _rg ctrlCommit 0.12;
    uiSleep 0.12;
	
    if (!isNull _d) then { _d closeDisplay 0; };
  };
} else {
  _disp closeDisplay 0;
};
