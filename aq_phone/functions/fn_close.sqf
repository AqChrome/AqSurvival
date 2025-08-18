/*
  Закрыть КПК: анимация вниз и закрытие диалога.
  Фикс: задержку уводим в spawn (scheduled), чтобы не падать из EH.
*/
disableSerialization;

private _disp = uiNamespace getVariable ["AQPH_Display", displayNull];
if (isNull _disp) exitWith {};

private _rootGrp = _disp displayCtrl 10;
if (!isNull _rootGrp) then {
  private _pos = ctrlPosition _rootGrp;

  // анимация "вниз"
  _rootGrp ctrlSetPosition [
    (_pos select 0),
    (_pos select 1) + 0.06,
    (_pos select 2),
    (_pos select 3)
  ];
  _rootGrp ctrlCommit 0.12;

  // закрываем Тот Же дисплей после анимации в scheduled-потоке
  [_disp] spawn {
    params ["_disp"];
    sleep 0.13;                 // можно и uiSleep, но тут уже scheduled
    if (!isNull _disp) then {
      _disp closeDisplay 0;     // гарантированно закрываем тот же дисплей
    };
  };
} else {
  // на всякий случай, если root-группа не найдена
  _disp closeDisplay 0;
};
