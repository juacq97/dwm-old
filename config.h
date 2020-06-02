/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 6;
static const unsigned int snap      = 32;       /* snap pixel */
static const int rmaster            = 0;        /* 1 means master-area is initially on the right */
int barPadding			    = 8;
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 2;        /* horizontal padding for statusbar */
static const int vertpadbar         = 8;        /* vertical padding for statusbar */
static const char *fonts[]          = {"JetBrains Mono:Regular:size=9", "Material Design Icons:Regular:pixelsize=16:antialias:true"};
static const char dmenufont[]       = "monospace:size=10";
static char normbgcolor[]           = "#282828";
static char normbordercolor[]       = "#282828";
static char normfgcolor[]           = "#fbf2c7";
static char selfgcolor[]            = "#fbf2c7";
static char selbordercolor[]        = "#98971a";
static char selbgcolor[]            = "#98971a";
static char *colors[][3] = {
               /*               fg           bg           border   */
       [SchemeNorm]	=  { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  	=  { selfgcolor,  selbgcolor,  selbordercolor  },
       [SchemeStatus]   =  { normfgcolor, normbgcolor, "#000000"       },
       [SchemeTagsSel]  =  { normbgcolor, selbgcolor,  "#000000"       },
       [SchemeTagsNorm] =  { normfgcolor, normbgcolor, "#000000"       }, 
       [SchemeInfoSel]  =  {normfgcolor, normbgcolor, "#000000"       },
       [SchemeInfoNorm] =  { normfgcolor, normbgcolor, "#000000"       },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "fibonacci.c"
#include "layouts.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󰕲",      tile },    /* first entry is default */
 	{ "󰕴",      dwindle },
	{ "󰹪",      grid },
	{ "󱒅",      centeredmaster },
	{ "󰕬",      centeredfloatingmaster },
	{ "󱒆",      monocle },
	{ "[D]",      deck },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,		KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggletag,      {.ui = 1 << TAG} },

/* COSAS QUE TENGO QUE AVERIGUAR COMO QUITAR */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"
#include "nextprevtag.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_bar,      togglermaster,  {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ControlMask,             XK_j,      inplacerotate,  {.i = +1} },
	{ MODKEY|ControlMask,             XK_k,      inplacerotate,  {.i = -1} },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_g,      zoom,           {0} }, /*mandar a master*/
	{ MODKEY,                       XK_g,      switchcol,    {0} }, /*mandar a master*/
	{ MODKEY,                       XK_Tab,    view,           {0} }, /*tag anterior*/
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, /*tiled*/
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[5]} }, /*monocle*/
	{ MODKEY,                       XK_s,      togglefloating, {0} }, /*float*/
	{ MODKEY,			XK_F11,    togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } }, /*ver todos los tags a la vez*/
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, /*ventana enfocada en todos los tags*/
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ControlMask,           XK_l,      view_adjacent,  { .i = +1 } },
	{ MODKEY|ControlMask,           XK_h,      view_adjacent,  { .i = -1 } },
	{ MODKEY|ControlMask,           XK_comma,  incnmaster,     {.i = +1 } },
        { MODKEY|ControlMask,           XK_period, incnmaster,     {.i = -1 } },
	{ MODKEY|ControlMask,		XK_r,      xrdb,           {.v = NULL } },
	{ MODKEY|ControlMask|ShiftMask, XK_r,      quit,           {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|Mod1Mask,              XK_space,  cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_c,      setlayout,      {.v = &layouts[6]} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};



