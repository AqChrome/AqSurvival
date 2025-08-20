params ["_index"];
private _items = missionNamespace getVariable ["PDA_MenuItems", []];
if (_index < 0 || {_index >= count _items}) exitWith {};
private _entry = _items select _index;
private _code  = _entry select 1;
[] call _code;
