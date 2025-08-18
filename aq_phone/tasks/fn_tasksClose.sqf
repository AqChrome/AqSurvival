/*
  Закрыть страницу "Задачи": удалить список и показать главное меню.
*/
disableSerialization;

private _home = uiNamespace getVariable ["AQPH_HomeGroup", controlNull];
private _list = uiNamespace getVariable ["AQPH_TasksGroup", controlNull];

if (!isNull _list) then {
  ctrlDelete _list;
  uiNamespace setVariable ["AQPH_TasksGroup", controlNull];
};

if (!isNull _home) then {
  _home ctrlShow true;
};
