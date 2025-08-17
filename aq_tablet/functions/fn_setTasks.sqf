params ["_mode", "_data"];
switch (_mode) do {
  case "SET": { missionNamespace setVariable ["AQTB_Tasks", +_data, true]; };
  case "ADD": {
    private _arr = missionNamespace getVariable ["AQTB_Tasks", []];
    _arr pushBack _data;
    missionNamespace setVariable ["AQTB_Tasks", _arr, true];
  };
  default {};
};
