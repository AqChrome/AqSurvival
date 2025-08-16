Экономика
[_unit] call HALs_money_fnc_getFunds; - получить баланс игрока
[_unit, +N] call HALs_money_fnc_addFunds; - Выдать/списать деньги
[_trader, _type, _targets] call HALs_store_fnc_addTrader; - Регистрация торговца
Категории: core\economy\HALs\Addons\store\config.hpp

[_trader, _targets] call HALs_store_fnc_addActionTrader — повесить интеракт «Открыть магазин»
[_trader] call HALs_store_fnc_openStore — принудительно открыть диалог у клиента


Переменные:
player setVariable ["aq_player_money", 100]; - деньги игрока
player setVariable ["aq_player_hunger", 100]; - голод
player setVariable ["aq_player_thirst", 100]; - жажда
player setVariable ["ace_medical_bloodVolume", 6.0] - кровь

missionNamespace setVariable ["AQ_PRICE_SCALE", 1]; - Коэфициент цен в магазине