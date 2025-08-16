if (isServer) then {
  missionNamespace setVariable ["AQ_PRICE_SCALE", 1.00, true];

  [Trader_1, "VendorWeapon_T1", [west, civilian]] call HALs_store_fnc_addTrader;
  [Trader_2, "VendorWeapon_T2", [west, civilian]] call HALs_store_fnc_addTrader;
  [Trader_3, "VendorWeapon_T3", [west, civilian]] call HALs_store_fnc_addTrader;
};
