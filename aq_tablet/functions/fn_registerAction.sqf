params ["_unit"];
if (isNull _unit) exitWith {};

private _id = _unit getVariable ["AQTB_ActionId", -1];
if (_id >= 0) then { _unit removeAction _id; };

_id = _unit addAction [
  "<t color='#C0FFAA'>Tablet (Open/Close)</t>",
  {
    if (uiNamespace getVariable ["AQTB_open", false]) then {
      [] call AQTB_fnc_close;
    } else {
      [] call AQTB_fnc_open;
    };
  },
  nil, 1.5, true, true, "", "true", 5, false, "", ""
];
_unit setVariable ["AQTB_ActionId", _id];
