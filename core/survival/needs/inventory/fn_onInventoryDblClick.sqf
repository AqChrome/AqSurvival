params ["_ctrl", "_idx"];
if (isNull _ctrl) exitWith {};
if (_idx < 0) exitWith {};

private _idc = ctrlIDC _ctrl;
private _txt = lbText [_idc, _idx];
if (_txt isEqualTo "") exitWith {};

private _u = player;
if (isNull _u) exitWith {};

// найти точный класс по названию среди реально имеющихся у игрока
private _owned = items _u + assignedItems _u;  // только CfgWeapons
private _itemClass = "";
{
  if (getText (configFile >> "CfgWeapons" >> _x >> "displayName") == _txt) exitWith { _itemClass = _x; };
} forEach _owned;

if (_itemClass isEqualTo "") exitWith {};
if !(_itemClass in _owned) exitWith {};  // защита от гонки

// последовательные вызовы, БЕЗ вложенных exitWith (это и убирает GIF pre stack)
private _handled = false;

if (!isNil "AQ_fnc_tryDrink") then {
  _handled = [_u, _itemClass] call AQ_fnc_tryDrink;
};
if (_handled) exitWith {};

if (!isNil "AQ_fnc_tryEat") then {
  _handled = [_u, _itemClass] call AQ_fnc_tryEat;
};
