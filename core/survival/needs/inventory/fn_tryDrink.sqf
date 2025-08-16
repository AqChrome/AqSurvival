params ["_u", "_cls"];
if (isNull _u || {_cls isEqualTo ""}) exitWith { false };

private _cfg = configFile >> "CfgWeapons" >> _cls;
if !(isClass _cfg) exitWith { false };

private _isDrink = (getNumber (_cfg >> "aq_isDrink")) == 1;
private _tVal    = getNumber (_cfg >> "thirstValue");
private _repl    = getText   (_cfg >> "replaceWith");

if (!_isDrink && {_tVal <= 0}) exitWith { false };

[_u, _cls, _tVal, _repl] spawn {
  params ["_u","_cls","_tVal","_repl"];
  if (!(_cls in (items _u))) exitWith { hintSilent "Этого предмета уже нет."; };

  if (_tVal > 0) then {
    private _t = _u getVariable ["aq_player_thirst", 100];
    _u setVariable ["aq_player_thirst", (_t + _tVal) min 100, true];
  };

  _u removeItem _cls;
  if (_repl != "" && {isClass (configFile >> "CfgWeapons" >> _repl)} && {_u canAdd _repl}) then {
    _u addItem _repl;
  };
};
true
