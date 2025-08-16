private _hunger = player getVariable ["aq_player_hunger", 100];
_hunger = (_hunger - AQ_HUNGER_HUNGER_PER_MIN) max 0;
player setVariable ["aq_player_hunger", _hunger, true];
