class RscTitles {
    #include "hud\config.cpp"

    class AQTB_Tablet {
    idd = -1;
    movingEnable = 0;
    enableSimulation = 1;
    duration = 1e10;
    fadein = 0.1;
    fadeout = 0.1;

    // эти строки позволяют получить дескриптор дисплея из SQF
    onLoad  = "uiNamespace setVariable ['AQTB_Display', _this select 0]";
    onUnload= "uiNamespace setVariable ['AQTB_Display', displayNull]";

    class controls {};
    class controlsBackground {};
  };
};