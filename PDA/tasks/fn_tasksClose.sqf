disableSerialization;

private _home = uiNamespace getVariable ["PDA_HomeGroup", controlNull];
private _list = uiNamespace getVariable ["PDA_TasksGroup", controlNull];

if (!isNull _list) then {
  ctrlDelete _list;
  uiNamespace setVariable ["PDA_TasksGroup", controlNull];
};

if (!isNull _home) then {
  _home ctrlShow true;
};
