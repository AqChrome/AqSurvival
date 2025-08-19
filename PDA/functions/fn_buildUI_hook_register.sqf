disableSerialization;
[] call PDA_fnc_pageInit;

private _home   = uiNamespace getVariable ["PDA_HomeGroup", controlNull];
private _tasks  = uiNamespace getVariable ["PDA_TasksGroup", controlNull];
private _detail = uiNamespace getVariable ["PDA_TaskDetailGroup", controlNull];

if (!isNull _home)   then { ["home",   _home]   call PDA_fnc_pageRegister; };
if (!isNull _tasks)  then { ["tasks",  _tasks]  call PDA_fnc_pageRegister; };
if (!isNull _detail) then { ["detail", _detail] call PDA_fnc_pageRegister; };
