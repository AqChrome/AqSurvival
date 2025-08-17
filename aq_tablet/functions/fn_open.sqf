if (uiNamespace getVariable ["AQTB_open", false]) exitWith {};
disableSerialization;

uiNamespace setVariable ["AQTB_open", true];

// Открываем диалог — курсор появится
createDialog "AQTB_Dialog";

// ждём дисплей
waitUntil { !isNull (uiNamespace getVariable ["AQTB_Display", displayNull]) };
private _disp = uiNamespace getVariable ["AQTB_Display", displayNull];

// ESC/клава-навигация
_disp displayAddEventHandler ["KeyDown", {
  params ["_d","_key"];
  private _focus = uiNamespace getVariable ["AQTB_FocusCtrls", []];
  private _idx   = uiNamespace getVariable ["AQTB_FocusIdx", 0];

  switch (_key) do {
    case 1:  { [] call AQTB_fnc_close; true };                           // ESC
    case 203: { // ←
      if ((count _focus) > 0) then {
        _idx = (_idx - 1 + count _focus) mod (count _focus);
        uiNamespace setVariable ["AQTB_FocusIdx", _idx];
        { _x ctrlSetBackgroundColor [0,0,0,0] } forEach _focus;
        (_focus select _idx) ctrlSetBackgroundColor [1,1,1,0.15];
        ctrlSetFocus (_focus select _idx);
      };
      true
    };
    case 205: { // →
      if ((count _focus) > 0) then {
        _idx = (_idx + 1) mod (count _focus);
        uiNamespace setVariable ["AQTB_FocusIdx", _idx];
        { _x ctrlSetBackgroundColor [0,0,0,0] } forEach _focus;
        (_focus select _idx) ctrlSetBackgroundColor [1,1,1,0.15];
        ctrlSetFocus (_focus select _idx);
      };
      true
    };
    case 28; case 156; case 57: { // Enter, NumpadEnter, Space
      if ((count _focus) > 0) then { ctrlActivate (_focus select _idx) };
      true
    };
    default { false };
  };
}];

[] call AQTB_fnc_buildHome;
