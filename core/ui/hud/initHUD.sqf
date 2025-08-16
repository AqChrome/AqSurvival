if (hasInterface) then {
    Misery_fnc_createHUD = {
        private _layer = "MyMissionHUD" call BIS_fnc_rscLayer;
        _layer cutRsc ["MyMissionHUD", "PLAIN", 0.1, true];
        
        private _display = uiNamespace getVariable ["MyMissionHUD", displayNull];
        
        if (isNull _display) then {
            cutRsc ["MyMissionHUD", "PLAIN"];
            _display = uiNamespace getVariable "MyMissionHUD";
        };
        _display
    };
    
    private _display = call Misery_fnc_createHUD;
    
    [{
        params ["", "_pfhId"];
        
        private _display = uiNamespace getVariable ["MyMissionHUD", displayNull];
        private _player = player;
        
        if (isNull _display || isNull _player) then {
            if (isNull _display) then {
                _display = call Misery_fnc_createHUD;
            };
            if (isNull _player) exitWith {};
        };
        
        private _money = _player getVariable ["aq_player_money", 0]; // Деньги
        private _hunger = _player getVariable ["aq_player_hunger", 100]; // Голод
        private _thirst = _player getVariable ["aq_player_thirst", 100]; // Жажда
        private _blood = _player getVariable ["ace_medical_bloodVolume", 6.0]; // Кровь
        
        
        (_display displayCtrl 1000) ctrlSetText ([_money] call BIS_fnc_numberText);
        (_display displayCtrl 1001) ctrlSetText format["%1%2", floor _hunger, "%"];
        (_display displayCtrl 1002) ctrlSetText format["%1%2", floor _thirst, "%"];
        
        private _bloodCtrl = _display displayCtrl 1003;
        private _bloodPercent = linearConversion [2.4, 6.0, _blood, 0, 100, true];
        _bloodCtrl ctrlSetText format["%1%2", round _bloodPercent, "%"];
    }, 1] call CBA_fnc_addPerFrameHandler;
};