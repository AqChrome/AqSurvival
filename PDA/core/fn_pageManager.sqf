/* Менеджер страниц КПК (push/pop/showOnly/replace) + авто‑показ уведомлений. */
disableSerialization;

// INIT
PDA_fnc_pageInit = {
  if (isNil {uiNamespace getVariable "PDA_Pages"}) then {
    uiNamespace setVariable ["PDA_Pages", createHashMap];
  };
  if (isNil {uiNamespace getVariable "PDA_PageStack"}) then {
    uiNamespace setVariable ["PDA_PageStack", []];
  };
  if (isNil {uiNamespace getVariable "PDA_PageCurrent"}) then {
    uiNamespace setVariable ["PDA_PageCurrent", ["", controlNull]];
  };
  if (isNil {uiNamespace getVariable "PDA_NotifyAutoOpen"}) then {
    uiNamespace setVariable ["PDA_NotifyAutoOpen", true];
  };
};

// REGISTER / GET
PDA_fnc_pageRegister = { params ["_name","_ctrl"]; private _m = uiNamespace getVariable ["PDA_Pages", createHashMap]; _m set [_name,_ctrl]; uiNamespace setVariable ["PDA_Pages",_m]; };
PDA_fnc_pageGet      = { params ["_name"]; (uiNamespace getVariable ["PDA_Pages", createHashMap]) getOrDefault [_name, controlNull] };
PDA_fnc_pageCurrentName = { (uiNamespace getVariable ["PDA_PageCurrent", ["", controlNull]]) select 0 };
PDA_fnc_pageCurrentCtrl = { (uiNamespace getVariable ["PDA_PageCurrent", ["", controlNull]]) select 1 };

// OPS
PDA_fnc_pageShowOnly = {
  params ["_name"];
  private _ctrl = [_name] call PDA_fnc_pageGet;
  if (isNull _ctrl) exitWith {};
  private _cur = call PDA_fnc_pageCurrentCtrl;
  if (!isNull _cur) then { _cur ctrlShow false; };
  _ctrl ctrlShow true;
  uiNamespace setVariable ["PDA_PageCurrent", [_name,_ctrl]];
};

PDA_fnc_pagePush = {
  params ["_name"];
  private _ctrl = [_name] call PDA_fnc_pageGet;
  if (isNull _ctrl) exitWith {};
  private _pair = uiNamespace getVariable ["PDA_PageCurrent", ["", controlNull]];
  private _stack= uiNamespace getVariable ["PDA_PageStack", []];
  private _cur  = _pair select 1;
  if (!isNull _cur) then { _stack pushBack _pair; _cur ctrlShow false; };
  _ctrl ctrlShow true;
  uiNamespace setVariable ["PDA_PageCurrent", [_name,_ctrl]];
  uiNamespace setVariable ["PDA_PageStack", _stack];
};

PDA_fnc_pagePop = {
  private _stack= uiNamespace getVariable ["PDA_PageStack", []];
  private _cur  = call PDA_fnc_pageCurrentCtrl;
  if (!isNull _cur) then { _cur ctrlShow false; };
  if ((count _stack)==0) exitWith {
    private _home = ["home"] call PDA_fnc_pageGet;
    if (!isNull _home) then { _home ctrlShow true; uiNamespace setVariable ["PDA_PageCurrent", ["home",_home]]; } else { uiNamespace setVariable ["PDA_PageCurrent", ["",controlNull]]; };
  };
  private _prev = _stack deleteAt ((count _stack)-1);
  private _name = _prev select 0; private _ctrl = _prev select 1;
  if (!isNull _ctrl) then { _ctrl ctrlShow true; };
  uiNamespace setVariable ["PDA_PageCurrent", [_name,_ctrl]];
  uiNamespace setVariable ["PDA_PageStack", _stack];
};

PDA_fnc_pageReplace = {
  params ["_name"];
  private _ctrl = [_name] call PDA_fnc_pageGet;
  if (isNull _ctrl) exitWith {};
  private _cur = call PDA_fnc_pageCurrentCtrl;
  if (!isNull _cur) then { _cur ctrlShow false; };
  _ctrl ctrlShow true;
  uiNamespace setVariable ["PDA_PageCurrent", [_name,_ctrl]];
};

// AUTO-OPEN FLAG
PDA_fnc_notifyAutoOpenSet = { params ["_enabled"]; uiNamespace setVariable ["PDA_NotifyAutoOpen", _enabled]; };
PDA_fnc_notifyAutoOpenGet = { uiNamespace getVariable ["PDA_NotifyAutoOpen", true] };
