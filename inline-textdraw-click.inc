/*
                                                      
    oo          dP oo                              dP                       dP         dP                                                dP oo          dP       
                88                                 88                       88         88                                                88             88       
    dP 88d888b. 88 dP 88d888b. .d8888b.          d8888P .d8888b. dP.  .dP d8888P .d888b88 88d888b. .d8888b. dP  dP  dP          .d8888b. 88 dP .d8888b. 88  .dP  
    88 88'  `88 88 88 88'  `88 88ooood8 88888888   88   88ooood8  `8bd8'    88   88'  `88 88'  `88 88'  `88 88  88  88 88888888 88'  `"" 88 88 88'  `"" 88888"   
    88 88    88 88 88 88    88 88.  ...            88   88.  ...  .d88b.    88   88.  .88 88       88.  .88 88.88b.88'          88.  ... 88 88 88.  ... 88  `8b. 
    dP dP    dP dP dP dP    dP `88888P'            dP   `88888P' dP'  `dP   dP   `88888P8 dP       `88888P8 8888P Y8P           `88888P' dP dP `88888P' dP   `YP 
                                                                                                                                                                

    inline-textdraw-click
         Copyright © 2026 by Mateus Mesquita Lima

    -» Author    	       : Mateus Mesquita Lima / mateus-bsod
    -» Credits of Includes : Y_Less (YSI) and Burak / Nexor (textdraw-streamer) 
    -» Release Date	       : 15 Jan 2026
    -» Description	       : Include


*/

#if defined _inline_textdraw_included
    #endinput
#endif
#define _inline_textdraw_included

// maximum values ??of the include

#if !defined MAX_CLICK_TEXT_DRAWS
    #define MAX_CLICK_TEXT_DRAWS (MAX_TEXT_DRAWS)
#endif

// include requirements

#if !defined _INC_textdraw_streamer
    #error "Please place \"inline-textdraw-click.inc\" below \"textdraw-streamer.inc\"!"
#endif

#tryinclude <YSI\YSI_Coding\y_hooks>
#if !defined _INC_y_hooks
    #tryinclude <YSI_Coding\y_hooks>
#endif

// include variables

new 
    //   Global                           |      Player
    Func:__f_ClickTD[MAX_CLICK_TEXT_DRAWS], Func:__f_ClickPTD[MAX_CLICK_TEXT_DRAWS], // __f_ = function (inline callback)
         __v_ClickTD[MAX_CLICK_TEXT_DRAWS],      __v_ClickPTD[MAX_CLICK_TEXT_DRAWS]  // __v_ = valid
;

/*

                    _____  __ __  ____     __ ______  ____  ___   ____   _____
                    |     ||  |  ||    \   /  ]      ||    |/   \ |    \ / ___/
                    |   __||  |  ||  _  | /  /|      | |  ||     ||  _  (   \_ 
                    |  |_  |  |  ||  |  |/  / |_|  |_| |  ||  O  ||  |  |\__  |
                    |   _] |  :  ||  |  /   \_  |  |   |  ||     ||  |  |/  \ |
                    |  |   |     ||  |  \     | |  |   |  ||     ||  |  |\    |
                    |__|    \__,_||__|__|\____| |__|  |____|\___/ |__|__| \___|

                    ___________________________________________________________                           

*/

TextDrawClick(Text:textid, Func:callback<i>)
{
    Indirect_Claim(callback);
    __f_ClickTD[textid] = Func:callback;
    __v_ClickTD[textid] = 0x1;
    return 1;
}

PlayerTextDrawClick(PlayerText:textid, Func:callback<i>)
{
    Indirect_Claim(callback);
    __f_ClickPTD[textid] = Func:callback;
    __v_ClickPTD[textid] = 0x1;
    return 1;
}

// ________________________________________________________________________________________________ //

static stock TextDraw_Call(playerid, Func:callback<i>) 
{
    Indirect_Claim(callback);
    @.callback(playerid);
    Callback_Restore(callback);
    return 1;
}


/*
                                __ __   ___    ___   __  _ _____
                                |  |  | /   \  /   \ |  |/ ] ___/
                                |  |  ||     ||     ||  ' (   \_ 
                                |  _  ||  O  ||  O  ||    \\__  |
                                |  |  ||     ||     ||     /  \ |
                                |  |  ||     ||     ||  .  \    |
                                |__|__| \___/  \___/ |__|\_|\___|
                                                
                                _________________________________                        
*/

// 
// @note click textdraw hooks

hook OnClickDynamicTD(playerid, Text:textid)
{
    if(IsValidDynamicTextDraw(Text:textid) && __v_ClickTD[textid])
    {
        TextDraw_Call(playerid, _:__f_ClickTD[textid]);
    }
    return 1;
}

hook OnClickDynPlayerTextDraw(playerid, PlayerText:textid)
{
    if(IsValidDynamicPlayerTextDraw(playerid, PlayerText:textid) && __v_ClickPTD[textid])
    {
        TextDraw_Call(playerid, _:__f_ClickPTD[textid]);
    }
    return 1;
}


// 
// @note destroy textdraw hooks

hook native TextDrawDestroy(Text:text)
{
    __v_ClickTD[text] = 0x0;
    Indirect_Release(_:__f_ClickTD[text]);
    return continue(text);
}

hook native PlayerTextDrawDestroy(playerid, PlayerText:text)
{
    __v_ClickPTD[text] = 0x0;
    Indirect_Release(_:__f_ClickPTD[text]);
    return continue(playerid, text);
}