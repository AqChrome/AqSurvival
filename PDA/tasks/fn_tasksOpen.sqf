disableSerialization;

private _page = [] call PDA_fnc_tasks_list;
if (isNull _page) exitWith {};

["tasks"] call PDA_fnc_pagePush;
