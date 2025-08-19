============================================================
PDA — Page Manager: Интеграция
============================================================
1) В конце fn_buildUI.sqf вызови:
   [] call PDA_fnc_buildUI_hook_register;

2) Переходы:
   ["tasks"] call PDA_fnc_pagePush;
   ["detail"] call PDA_fnc_pagePush;
   [] call PDA_fnc_pagePop;
   ["home"] call PDA_fnc_pageShowOnly;

3) Уведомления — модальные:
   [] call PDA_fnc_notifyRender;  // вызовет pageReplace("notify")

4) Авто‑показ уведомлений при включении экрана:
   [false] call PDA_fnc_notifyAutoOpenSet; // отключить
   [true]  call PDA_fnc_notifyAutoOpenSet; // включить (дефолт)
============================================================
