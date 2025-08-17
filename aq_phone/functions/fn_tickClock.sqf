disableSerialization;
while { uiNamespace getVariable ["AQPH_open", false] } do {
  private _timeCtrl = uiNamespace getVariable ["AQPH_TimeCtrl", controlNull];
  if (isNull _timeCtrl) exitWith {};
  private _d = date;                    // [Y,M,D,H,Min]
  private _h = _d select 3;
  private _m = _d select 4;
  private _hh = if (_h < 10) then { format ["0%1", _h] } else { str _h };
  private _mm = if (_m < 10) then { format ["0%1", _m] } else { str _m };
  _timeCtrl ctrlSetStructuredText parseText format [
    "<t align='right' size='0.9' color='#FFFFFF'>%1:%2</t>", _hh, _mm
  ];
  uiSleep 1;
};
