params ["_u", "_cls"];
if (isNull _u || {_cls isEqualTo ""}) exitWith { false };

private _cfg = configFile >> "CfgWeapons" >> _cls;
if !(isClass _cfg) exitWith { false };

private _isFood = (getNumber (_cfg >> "aq_isFood")) == 1;
private _hVal   = getNumber (_cfg >> "hungerValue");
private _repl   = getText   (_cfg >> "replaceWith");

if (!_isFood && {_hVal <= 0}) exitWith { false };

[_u, _cls, _hVal, _repl] spawn {
  params ["_u","_cls","_hVal","_repl"];
  if (!(_cls in (items _u))) exitWith { hintSilent "Этого предмета уже нет."; };

  if (_hVal > 0) then {
    private _h = _u getVariable ["aq_player_hunger", 100];
    _u setVariable ["aq_player_hunger", (_h + _hVal) min 100, true];
  };

  _u removeItem _cls;
  if (_repl != "" && {isClass (configFile >> "CfgWeapons" >> _repl)} && {_u canAdd _repl}) then {
    _u addItem _repl;
  };
};
true
