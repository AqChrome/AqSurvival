class MyMissionHUD {
    idd = -1;
    duration = 1e+6;
    fadein = 0;
    fadeout = 0;
    movingEnable = 0;
    onLoad = "uiNamespace setVariable ['MyMissionHUD', _this select 0]";
    
    // Константы
    #define ICON_SIZE 0.08
    #define TEXT_WIDTH 0.18
    #define ROW_HEIGHT 0.08
    #define RIGHT_MARGIN 0.01
    #define BASE_Y_OFFSET 0.15
    #define VERTICAL_TEXT_OFFSET -0.0029
    
    class controls {
        // Главный контейнер (как в Misery)
        class MainContainer {
            idc = -1;
            type = 0;
            style = 0;
            x = 0;
            y = 0;
            w = 1;
            h = 1;
            text = ""; // ДОБАВЬТЕ ЭТУ СТРОКУ!
            colorBackground[] = {0,0,0,0};
            colorText[] = {1,1,1,1};
            font = "PuristaMedium";
            sizeEx = 0.05; 
            fixedWidth = 1; 
            shadow = 0; 
        };
        
        // Элементы HUD
        #define CREATE_HUD_ITEM(INDEX, NAME, IMAGE, TEXT, IDC) \
        class NAME##Icon { \
            idc = -1; \
            type = 0; \
            style = 48; \
            x = safezoneX + safezoneW - RIGHT_MARGIN - ICON_SIZE; \
            y = safezoneY + safezoneH / 2 - BASE_Y_OFFSET + (ROW_HEIGHT * INDEX); \
            w = ICON_SIZE; \
            h = ICON_SIZE; \
            text = IMAGE; \
            colorBackground[] = {0,0,0,0}; \
            colorText[] = {1,1,1,1}; \
            font = "PuristaMedium"; \
            sizeEx = 0.05; \
            fixedWidth = 1; \
            shadow = 0; \
        }; \
        class NAME##Text { \
            idc = IDC; \
            type = 0; \
            style = 1; \
            x = safezoneX + safezoneW - 0.18 - ICON_SIZE - 0.01; \
            y = safezoneY + safezoneH / 2 - BASE_Y_OFFSET + (ROW_HEIGHT * INDEX) + (VERTICAL_TEXT_OFFSET); \
            w = TEXT_WIDTH; \
            h = ICON_SIZE; \
            text = TEXT; \
            colorBackground[] = {0,0,0,0}; \
            colorText[] = {1,1,1,1}; \
            font = "PuristaBold"; \
            sizeEx = 0.04; \
            shadow = 1; \
            clippedText = 1; \
        };

        CREATE_HUD_ITEM(0, Money, "core\ui\hud\images\money.paa", "", 1000)
        CREATE_HUD_ITEM(1, Hunger, "core\ui\hud\images\hunger.paa", "", 1001)
        CREATE_HUD_ITEM(2, Thirst, "core\ui\hud\images\thirst.paa", "", 1002)
        CREATE_HUD_ITEM(3, Blood, "core\ui\hud\images\blood.paa", "", 1003)
    };
};
