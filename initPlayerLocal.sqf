[] call AQPH_fnc_init;
player addEventHandler ["InventoryOpened", {
    [{
        !(isNull (findDisplay 602))
    }, {
        {
            private _ctrl = (findDisplay 602) displayCtrl _x;
            if (!isNull _ctrl) then {
                _ctrl ctrlSetEventHandler ["LBDblClick", "_this call AQ_fnc_onInventoryDblClick"];
            };
        } forEach [633, 638, 619];
    }] call CBA_fnc_waitUntilAndExecute;
}];