private _thirst = player getVariable ["aq_player_thirst", 100];
_thirst = (_thirst - AQ_HUNGER_THIRST_PER_MIN) max 0;
player setVariable ["aq_player_thirst", _thirst, true];