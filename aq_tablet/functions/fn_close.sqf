disableSerialization;

// закрываем диалог (если открыт)
closeDialog 2;

uiNamespace setVariable ["AQTB_open", false];
uiNamespace setVariable ["AQTB_Display", displayNull];
uiNamespace setVariable ["AQTB_CurrentView", controlNull];
uiNamespace setVariable ["AQTB_HomeCtrls", []];
uiNamespace setVariable ["AQTB_MapCtrl", controlNull];
uiNamespace setVariable ["AQTB_FocusCtrls", []];
uiNamespace setVariable ["AQTB_FocusIdx", 0];
