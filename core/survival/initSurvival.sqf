if (hasInterface) then {
  [{
        params ["", "_pfhId"];

        [] execVM "core\survival\needs\hunger\hungerLoop.sqf";
		    [] execVM "core\survival\needs\thirst\thirstLoop.sqf";
    }, 60] call CBA_fnc_addPerFrameHandler;
};