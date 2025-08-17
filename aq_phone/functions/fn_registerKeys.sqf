[] spawn {
  waitUntil { !isNull findDisplay 46 };
  private _root = findDisplay 46;

  _root displayAddEventHandler ["KeyDown", {
    params ["_d","_key"];

    // ↑ открыть, если ещё не открыт (DIK_UP = 200)
    if (_key isEqualTo 200) exitWith {
      if (!(uiNamespace getVariable ["AQPH_open", false])) then {
        [] call AQPH_fnc_show;
        true
      } else { false };
    };

    // Right Shift закрыть, если открыт (DIK_RSHIFT = 54)
    if (_key isEqualTo 54) exitWith {
      if (uiNamespace getVariable ["AQPH_open", false]) then {
        [] spawn AQPH_fnc_hide;
        true
      } else { false };
    };

    false
  }];
};
