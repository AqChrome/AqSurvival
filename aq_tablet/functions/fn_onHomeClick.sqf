params ["_app"];
switch (_app) do {
  case "tasks": { [] call AQTB_fnc_openTasks; };
  case "map":   { [] call AQTB_fnc_openMapEmbedded; };
  default {};
};
