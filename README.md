# inline-textdraw-click
This include serves to minimize the infernal work of constantly using ALS or HOOK to make textdraws clickable.</br>
There is a version "with [textdraw-streamer](https://github.com/nexquery/samp-textdraw-streamer)" and a version without (default).
> Both versions (with or without textdraw-streamer) function the same way, meaning there are no additional or fewer features; I included two versions only for compatibility reasons.

> [!IMPORTANT]  
> It is crucial to use the [YSI library](https://github.com/pawn-lang/YSI-Includes/releases) for Include to work.


#### Functions
```pawn
TextDrawClick(Text:textid, Func:callback<i>);
PlayerTextDrawClick(PlayerText:textid, Func:callback<i>);
```

#### Example:
```pawn
new Text: Text_GClicks[1];
new PlayerText: Text_playerClicks[MAX_PLAYERS][1];

// global textdraw click

public OnGameModeInit()
{
    Text_GClicks[0] = TextDrawCreate(210.000, 170.000, "CLICK1");
    TextDrawLetterSize(Text_GClicks[0], 0.300, 1.500);
    TextDrawTextSize(Text_GClicks[0], 9.000, 67.000);
    TextDrawAlignment(Text_GClicks[0], 2);
    TextDrawColor(Text_GClicks[0], -1);
    TextDrawUseBox(Text_GClicks[0], 1);
    TextDrawBoxColor(Text_GClicks[0], 150);
    TextDrawSetShadow(Text_GClicks[0], 1);
    TextDrawSetOutline(Text_GClicks[0], 1);
    TextDrawBackgroundColor(Text_GClicks[0], 150);
    TextDrawFont(Text_GClicks[0], 1);
    TextDrawSetProportional(Text_GClicks[0], 1);
    TextDrawSetSelectable(Text_GClicks[0], 1);

	inline Click1(pid)
	{
        SendClientMessage(pid, -1, "click 1");
	}
    TextDrawClick(Text_GClicks[0], using inline Click1);
    return 1;
}

// player textdraw click

public OnPlayerConnect(playerid)
{
    Text_playerClicks[playerid][0] = CreatePlayerTextDraw(playerid, 431.000, 169.000, "PLAYER CLICK 1");
    PlayerTextDrawLetterSize(playerid, Text_playerClicks[playerid][0], 0.250, 1.500);
    PlayerTextDrawTextSize(playerid, Text_playerClicks[playerid][0], 9.000, 67.000);
    PlayerTextDrawAlignment(playerid, Text_playerClicks[playerid][0], 2);
    PlayerTextDrawColor(playerid, Text_playerClicks[playerid][0], -1);
    PlayerTextDrawUseBox(playerid, Text_playerClicks[playerid][0], 1);
    PlayerTextDrawBoxColor(playerid, Text_playerClicks[playerid][0], -12254977);
    PlayerTextDrawSetShadow(playerid, Text_playerClicks[playerid][0], 1);
    PlayerTextDrawSetOutline(playerid, Text_playerClicks[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, Text_playerClicks[playerid][0], 150);
    PlayerTextDrawFont(playerid, Text_playerClicks[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, Text_playerClicks[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, Text_playerClicks[playerid][0], 1);

	inline PClick1(pid)
	{
        SendClientMessage(pid, -1, "player click 1");
	}
    PlayerTextDrawClick(Text_playerClicks[playerid][0], using inline PClick1);

    return 1;
}
```
