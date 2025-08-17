params ["_unit"];
if (isNull _unit) exitWith {};

// не создаём дубликаты
private _id = _unit getVariable ["AQTB_ActionId", -1];
if (_id >= 0) then { _unit removeAction _id; };

_id = _unit addAction [
  "<t color='#C0FFAA'>Open Tablet</t>",
  { [] call AQTB_fnc_open; },
  nil,          // args
  1.5,          // priority
  true,         // showWindow
  true,         // hideOnUse
  "",           // shortcut
  "true",       // condition (всегда)
  5,            // radius
  false,        // unconscious
  "",           // selection
  ""            // memoryPoint
];
_unit setVariable ["AQTB_ActionId", _id];
