// initPlayerLocal.sqf или твой fn_init.sqf (локально на клиенте)
if (hasInterface) then {
  [] execVM "core\survival\needs\thirst\fn_collectWater.sqf";
};


if (hasInterface) then {
  [{
        params ["", "_pfhId"];

        [] execVM "core\survival\needs\hunger\hungerLoop.sqf";
		    [] execVM "core\survival\needs\thirst\thirstLoop.sqf";
    }, 60] call CBA_fnc_addPerFrameHandler;
};

