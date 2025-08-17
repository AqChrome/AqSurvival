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

if (isNil { missionNamespace getVariable "AQPH_Mails" }) then {
  missionNamespace setVariable ["AQPH_Mails", [
    ["HQ", "Новая задача", "Группа «Альфа», выдвигайтесь к точке БРАВО. Дальнейшие инструкции получите на месте."],
    ["HQ", "Пополнение", "Боеприпасы доставлены на склад. Заберите в любой момент."],
    ["Оператор", "Фотоцели", "См. вложение. Цели помечены маркерами. Действовать скрытно."]
  ]];
};
