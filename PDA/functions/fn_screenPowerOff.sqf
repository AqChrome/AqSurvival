disableSerialization;

private _screen  = uiNamespace getVariable ["PDA_ScreenGroup", controlNull];
private _offPic  = uiNamespace getVariable ["PDA_OffOverlay", controlNull];
private _home    = uiNamespace getVariable ["PDA_HomeGroup", controlNull];
private _tasks   = uiNamespace getVariable ["PDA_TasksGroup", controlNull];
private _detail  = uiNamespace getVariable ["PDA_TaskDetailGroup", controlNull];
if (isNull _screen) exitWith {};

{ if (!isNull _x) then { _x ctrlShow false; }; } forEach [_home, _tasks, _detail];

if (!isNull _offPic) then {
  _offPic ctrlShow true;
  _offPic ctrlSetFade 0;
  _offPic ctrlCommit 0;
};
