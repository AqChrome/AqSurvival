if (!isServer) exitWith {};
params ["_plr","_tag","_ctx"];

if (isNull _plr || {!isPlayer _plr}) exitWith {};

switch (toLower _tag) do {
  case "kill":     { [_plr,_tag,_ctx] call AQ_fnc_grantPersonalTask; };
  case "logistic": { [_plr,_tag,_ctx] call AQ_fnc_grantPersonalTask; };
  case "destroy":  { [_plr,_tag,_ctx] call AQ_fnc_grantPersonalTask; };
  default          { [_plr,_tag,_ctx] call AQ_fnc_grantPersonalTask; };
};
