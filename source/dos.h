/*
------------------------------------------------------------------------------
          Licensing information can be found at the end of the file.
------------------------------------------------------------------------------

Note that different files in this project has different licenses. Each source
file contains licensing information for the code in that file.

*/

#ifndef dos_h
#define dos_h

enum videomode_t
{
    videomode_40x25_8x8,
    videomode_40x25_9x16,
    videomode_80x25_8x8,
    videomode_80x25_8x16,
    videomode_80x25_9x16,
    videomode_80x43_8x8,
    videomode_80x50_8x8,
    videomode_320x200,
    videomode_320x240,
    videomode_320x400,
    videomode_640x200,
    videomode_640x350,
    videomode_640x400,
    videomode_640x480,

    force_size_videomode = 0x7ffffff // ensure videomode_t is 32-bit value
};

void setvideomode(enum videomode_t mode);
void setdoublebuffer(int enabled);
int screenwidth(void);
int screenheight(void);
unsigned char *screenbuffer(void);
unsigned char *swapbuffers(void);
void waitvbl(void);
void setpal(int index, int r, int g, int b);
void getpal(int index, int *r, int *g, int *b);

int shuttingdown(void);

void cputs(char const *string);
void textcolor(int color);
void textbackground(int color);
void gotoxy(int x, int y);
int wherex(void);
int wherey(void);
void clrscr(void);
void curson(void);
void cursoff(void);

unsigned char *loadgif(char const *filename, int *width, int *height, int *palcount, unsigned char palette[768]);

void blit(int x, int y, unsigned char *source, int width, int height, int srcx, int srcy, int srcw, int srch);
void maskblit(int x, int y, unsigned char *source, int width, int height, int srcx, int srcy, int srcw, int srch,
              int colorkey);

void clearscreen(void);
int getpixel(int x, int y);
void hline(int x, int y, int len, int color);
void putpixel(int x, int y, int color);

void setdrawtarget(unsigned char *pixels, int width, int height);
void resetdrawtarget(void);

void setcolor(int color);
int getcolor(void);
void line(int x1, int y1, int x2, int y2);
void rectangle(int x, int y, int w, int h);
void bar(int x, int y, int w, int h);
void circle(int x, int y, int r);
void fillcircle(int x, int y, int r);
void ellipse(int x, int y, int rx, int ry);
void fillellipse(int x, int y, int rx, int ry);
void drawpoly(int *points_xy, int count);
void fillpoly(int *points_xy, int count);
void floodfill(int x, int y);
void boundaryfill(int x, int y, int boundary);

void outtextxy(int x, int y, char const *text);
void wraptextxy(int x, int y, char const *text, int width);
void centertextxy(int x, int y, char const *text, int width);

enum
{
    DEFAULT_FONT_8X8 = 1,
    DEFAULT_FONT_8X16 = 2,
    DEFAULT_FONT_9X16 = 3,
};

void settextstyle(int font, int bold, int italic, int underline);
int installuserfont(char const *filename);

enum
{
    DEFAULT_SOUNDBANK_AWE32 = 1,
    DEFAULT_SOUNDBANK_SB16 = 2,
};

void setsoundbank(int soundbank);
int installusersoundbank(char const *filename);

#define MUSIC_CHANNELS 16
void noteon(int channel, int note, int velocity);
void noteoff(int channel, int note);
void allnotesoff(int channel);
void setinstrument(int channel, int instrument);

struct music_t;
struct music_t *loadmid(char const *filename);
struct music_t *loadmus(char const *filename);
struct music_t *loadmod(char const *filename);
struct music_t *loadopb(char const *filename);
struct music_t *createmus(void *data, int size);
void playmusic(struct music_t *music, int loop, int volume);
void stopmusic(void);
int musicplaying(void);
void musicvolume(int volume);

enum soundmode_t
{
    soundmode_8bit_mono_5000,
    soundmode_8bit_mono_8000,
    soundmode_8bit_mono_11025,
    soundmode_8bit_mono_16000,
    soundmode_8bit_mono_22050,
    soundmode_8bit_mono_32000,
    soundmode_8bit_mono_44100,
    soundmode_16bit_mono_5000,
    soundmode_16bit_mono_8000,
    soundmode_16bit_mono_11025,
    soundmode_16bit_mono_16000,
    soundmode_16bit_mono_22050,
    soundmode_16bit_mono_32000,
    soundmode_16bit_mono_44100,
    soundmode_8bit_stereo_5000,
    soundmode_8bit_stereo_8000,
    soundmode_8bit_stereo_11025,
    soundmode_8bit_stereo_16000,
    soundmode_8bit_stereo_22050,
    soundmode_8bit_stereo_32000,
    soundmode_8bit_stereo_44100,
    soundmode_16bit_stereo_5000,
    soundmode_16bit_stereo_8000,
    soundmode_16bit_stereo_11025,
    soundmode_16bit_stereo_16000,
    soundmode_16bit_stereo_22050,
    soundmode_16bit_stereo_32000,
    soundmode_16bit_stereo_44100,
};

void setsoundmode(enum soundmode_t mode);

#define SOUND_CHANNELS 16
struct sound_t;
struct sound_t *loadwav(char const *filename);
struct sound_t *createsound(int channels, int samplerate, int framecount, short *samples);
void playsound(int channel, struct sound_t *sound, int loop, int volume);
void stopsound(int channel);
int soundplaying(int channel);
void soundvolume(int channel, int left, int right);

enum keycode_t
{
    KEY_INVALID,
    KEY_LBUTTON,
    KEY_RBUTTON,
    KEY_CANCEL,
    KEY_MBUTTON,
    KEY_XBUTTON1,
    KEY_XBUTTON2,
    KEY_BACK,
    KEY_TAB,
    KEY_CLEAR,
    KEY_RETURN,
    KEY_SHIFT,
    KEY_CONTROL,
    KEY_MENU,
    KEY_PAUSE,
    KEY_CAPITAL,
    KEY_KANA,
    KEY_HANGUL = KEY_KANA,
    KEY_JUNJA,
    KEY_FINAL,
    KEY_HANJA,
    KEY_KANJI = KEY_HANJA,
    KEY_ESCAPE,
    KEY_CONVERT,
    KEY_NONCONVERT,
    KEY_ACCEPT,
    KEY_MODECHANGE,
    KEY_SPACE,
    KEY_PRIOR,
    KEY_NEXT,
    KEY_END,
    KEY_HOME,
    KEY_LEFT,
    KEY_UP,
    KEY_RIGHT,
    KEY_DOWN,
    KEY_SELECT,
    KEY_PRINT,
    KEY_EXEC,
    KEY_SNAPSHOT,
    KEY_INSERT,
    KEY_DELETE,
    KEY_HELP,
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_LWIN,
    KEY_RWIN,
    KEY_APPS,
    KEY_SLEEP,
    KEY_NUMPAD0,
    KEY_NUMPAD1,
    KEY_NUMPAD2,
    KEY_NUMPAD3,
    KEY_NUMPAD4,
    KEY_NUMPAD5,
    KEY_NUMPAD6,
    KEY_NUMPAD7,
    KEY_NUMPAD8,
    KEY_NUMPAD9,
    KEY_MULTIPLY,
    KEY_ADD,
    KEY_SEPARATOR,
    KEY_SUBTRACT,
    KEY_DECIMAL,
    KEY_DIVIDE,
    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_F5,
    KEY_F6,
    KEY_F7,
    KEY_F8,
    KEY_F9,
    KEY_F10,
    KEY_F11,
    KEY_F12,
    KEY_F13,
    KEY_F14,
    KEY_F15,
    KEY_F16,
    KEY_F17,
    KEY_F18,
    KEY_F19,
    KEY_F20,
    KEY_F21,
    KEY_F22,
    KEY_F23,
    KEY_F24,
    KEY_NUMLOCK,
    KEY_SCROLL,
    KEY_LSHIFT,
    KEY_RSHIFT,
    KEY_LCONTROL,
    KEY_RCONTROL,
    KEY_LMENU,
    KEY_RMENU,
    KEY_BROWSER_BACK,
    KEY_BROWSER_FORWARD,
    KEY_BROWSER_REFRESH,
    KEY_BROWSER_STOP,
    KEY_BROWSER_SEARCH,
    KEY_BROWSER_FAVORITES,
    KEY_BROWSER_HOME,
    KEY_VOLUME_MUTE,
    KEY_VOLUME_DOWN,
    KEY_VOLUME_UP,
    KEY_MEDIA_NEXT_TRACK,
    KEY_MEDIA_PREV_TRACK,
    KEY_MEDIA_STOP,
    KEY_MEDIA_PLAY_PAUSE,
    KEY_LAUNCH_MAIL,
    KEY_LAUNCH_MEDIA_SELECT,
    KEY_LAUNCH_APP1,
    KEY_LAUNCH_APP2,
    KEY_OEM_1,
    KEY_OEM_PLUS,
    KEY_OEM_COMMA,
    KEY_OEM_MINUS,
    KEY_OEM_PERIOD,
    KEY_OEM_2,
    KEY_OEM_3,
    KEY_OEM_4,
    KEY_OEM_5,
    KEY_OEM_6,
    KEY_OEM_7,
    KEY_OEM_8,
    KEY_OEM_102,
    KEY_PROCESSKEY,
    KEY_ATTN,
    KEY_CRSEL,
    KEY_EXSEL,
    KEY_EREOF,
    KEY_PLAY,
    KEY_ZOOM,
    KEY_NONAME,
    KEY_PA1,
    KEY_OEM_CLEAR,
    KEYCOUNT,
    KEYPADDING = 0xFFFFFFFF
};

int keystate(enum keycode_t key);

#define KEY_MODIFIER_RELEASED 0x80000000
enum keycode_t *readkeys(void);
char const *readchars(void);

int mousex(void);
int mousey(void);
int mouserelx(void);
int mouserely(void);

#endif /* dos_h */

#ifdef DOS_IMPLEMENTATION

#ifndef NO_MAIN_DEF
#ifdef main
#undef main
#endif
#endif

#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libs/app.h"
#include "libs/crtemu_pc.h"
#include "libs/dr_wav.h"
#include "libs/frametimer.h"
#include "libs/mus.h"
#include "libs/opblib.h"
#include "libs/opl.h"
#include "libs/pixelfont.h"
#include "libs/tsf.h"

#define JAR_MOD_IMPLEMENTATION
#pragma warning(push)
#pragma warning(disable : 4100)
#pragma warning(disable : 4242)
#pragma warning(disable : 4244)
#include "libs/jar_mod.h"
#pragma warning(pop)

#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable : 4201)
#endif
#include "libs/tml.h"
#ifdef _WIN32
#pragma warning(pop)
#endif

#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable : 4024)
#pragma warning(disable : 4047)
#pragma warning(disable : 4242)
#pragma warning(disable : 4244)
#pragma warning(disable : 4701)
#endif
#include "libs/gif_load.h"
#ifdef _WIN32
#pragma warning(pop)
#endif

bool app_has_focus(app_t *app);

#include "libs/awe32rom.h"
#include "libs/crtframe.h"
#include "libs/thread.h"
#ifdef __wasm__
#define WA_CORO_IMPLEMENT_NANOSLEEP
#include <wajic_coro.h>
#endif

static uint32_t default_palette[256] = {
    0x000000,
    0xaa0000,
    0x00aa00,
    0xaaaa00,
    0x0000aa,
    0xaa00aa,
    0x0055aa,
    0xaaaaaa,
    0x555555,
    0xff5555,
    0x55ff55,
    0xffff55,
    0x5555ff,
    0xff55ff,
    0x55ffff,
    0xffffff,
    0x000000,
    0x141414,
    0x202020,
    0x2c2c2c,
    0x383838,
    0x454545,
    0x515151,
    0x616161,
    0x717171,
    0x828282,
    0x929292,
    0xa2a2a2,
    0xb6b6b6,
    0xcbcbcb,
    0xe3e3e3,
    0xffffff,
    0xff0000,
    0xff0041,
    0xff007d,
    0xff00be,
    0xff00ff,
    0xbe00ff,
    0x7d00ff,
    0x4100ff,
    0x0000ff,
    0x0041ff,
    0x007dff,
    0x00beff,
    0x00ffff,
    0x00ffbe,
    0x00ff7d,
    0x00ff41,
    0x00ff00,
    0x41ff00,
    0x7dff00,
    0xbeff00,
    0xffff00,
    0xffbe00,
    0xff7d00,
    0xff4100,
    0xff7d7d,
    0xff7d9e,
    0xff7dbe,
    0xff7ddf,
    0xff7dff,
    0xdf7dff,
    0xbe7dff,
    0x9e7dff,
    0x7f7dff,
    0x7d9eff,
    0x7dbeff,
    0x7ddfff,
    0x7dffff,
    0x7dffdf,
    0x7dffbe,
    0x7dff9e,
    0x7dff7d,
    0x9eff7d,
    0xbeff7d,
    0xdfff7d,
    0xffff7d,
    0xffdf7d,
    0xffbe7d,
    0xff9e7d,
    0xffb6b6,
    0xffb6c7,
    0xffb6db,
    0xffb6eb,
    0xffb6ff,
    0xebb6ff,
    0xdbb6ff,
    0xc7b6ff,
    0xb6b6ff,
    0xb6c7ff,
    0xb6dbff,
    0xb6ebff,
    0xb6ffff,
    0xb6ffeb,
    0xb6ffdb,
    0xb6ffc7,
    0xb6ffb6,
    0xc7ffb6,
    0xdbffb6,
    0xebffb6,
    0xffffb6,
    0xffebb6,
    0xffdbb6,
    0xffc7b6,
    0x710000,
    0x71001c,
    0x710038,
    0x710055,
    0x710071,
    0x550071,
    0x380071,
    0x1c0071,
    0x000071,
    0x001c71,
    0x003871,
    0x005571,
    0x007171,
    0x007155,
    0x007138,
    0x00711c,
    0x007100,
    0x1c7100,
    0x387100,
    0x557100,
    0x717100,
    0x715500,
    0x713800,
    0x711c00,
    0x713838,
    0x713845,
    0x713855,
    0x713861,
    0x713871,
    0x613871,
    0x553871,
    0x453871,
    0x383871,
    0x384571,
    0x385571,
    0x386171,
    0x387171,
    0x387161,
    0x387155,
    0x387145,
    0x387138,
    0x457138,
    0x557138,
    0x617138,
    0x717138,
    0x716138,
    0x715538,
    0x714538,
    0x715151,
    0x715159,
    0x715161,
    0x715169,
    0x715171,
    0x695171,
    0x615171,
    0x595171,
    0x515171,
    0x515971,
    0x516171,
    0x516971,
    0x517171,
    0x517169,
    0x517161,
    0x517159,
    0x517151,
    0x597151,
    0x617151,
    0x697151,
    0x717151,
    0x716951,
    0x716151,
    0x715951,
    0x410000,
    0x410010,
    0x410020,
    0x410030,
    0x410041,
    0x300041,
    0x200041,
    0x100041,
    0x000041,
    0x001041,
    0x002041,
    0x003041,
    0x004141,
    0x004130,
    0x004120,
    0x004110,
    0x004100,
    0x104100,
    0x204100,
    0x304100,
    0x414100,
    0x413000,
    0x412000,
    0x411000,
    0x412020,
    0x412028,
    0x412030,
    0x412038,
    0x412041,
    0x382041,
    0x302041,
    0x282041,
    0x202041,
    0x202841,
    0x203041,
    0x203841,
    0x204141,
    0x204138,
    0x204130,
    0x204128,
    0x204120,
    0x284120,
    0x304120,
    0x384120,
    0x414120,
    0x413820,
    0x413020,
    0x412820,
    0x412c2c,
    0x412c30,
    0x412c34,
    0x412c3c,
    0x412c41,
    0x3c2c41,
    0x342c41,
    0x302c41,
    0x2c2c41,
    0x2c3041,
    0x2c3441,
    0x2c3c41,
    0x2c4141,
    0x2c413c,
    0x2c4134,
    0x2c4130,
    0x2c412c,
    0x30412c,
    0x34412c,
    0x3c412c,
    0x41412c,
    0x413c2c,
    0x41342c,
    0x41302c,
    0x000000,
    0x000000,
    0x000000,
    0x000000,
    0x000000,
    0x000000,
    0x000000,
    0x000000,
};

static uint32_t font8x8[] = {
    8,
    8,
    6,
    0x367e7e00,
    0x00081c08,
    0xf0ff00ff,
    0x18fefc3c,
    0x66184001,
    0x18007cfe,
    0x00001818,
    0x00000000,
    0x7fff8100,
    0x00083e1c,
    0xe0c33cff,
    0xdbc6cc66,
    0x663c7007,
    0x3c00c6db,
    0x0c18183c,
    0xff182400,
    0x7fdba500,
    0x181c1c3e,
    0xf09966e7,
    0x3cfefc66,
    0x667e7c1f,
    0x7e001cdb,
    0x0630187e,
    0xff3c6603,
    0x7fff8100,
    0x3c3e7f7f,
    0xbebd42c3,
    0xe7c60c66,
    0x66187f7f,
    0x180036de,
    0x7f7f1818,
    0x7e7eff03,
    0x3ec3bd00,
    0x3c7f7f3e,
    0x33bd42c3,
    0xe7c60c3c,
    0x66187c1f,
    0x7e7e36d8,
    0x06307e18,
    0x3cff6603,
    0x1ce79900,
    0x183e6b1c,
    0x339966e7,
    0x3ce60e18,
    0x007e7007,
    0x3c7e1cd8,
    0x0c183c18,
    0x18ff247f,
    0x08ff8100,
    0x00080808,
    0x33c33cff,
    0xdb670f7e,
    0x663c4001,
    0x187e33d8,
    0x00001818,
    0x00000000,
    0x007e7e00,
    0x001c1c00,
    0x1eff00ff,
    0x18030718,
    0x00180000,
    0xff001e00,
    0x00000000,
    0x00000000,
    0x36360c00,
    0x061c000c,
    0x00000618,
    0x60000000,
    0x1e1e0c3e,
    0x3f1c3f38,
    0x00001e1e,
    0x1e060018,
    0x36361e00,
    0x0636633e,
    0x0c660c0c,
    0x30000000,
    0x33330e63,
    0x3306033c,
    0x0c0c3333,
    0x330c000c,
    0x7f361e00,
    0x031c3303,
    0x0c3c1806,
    0x18000000,
    0x30300c73,
    0x30031f36,
    0x0c0c3333,
    0x30183f06,
    0x36000c00,
    0x006e181e,
    0x3fff1806,
    0x0c003f00,
    0x1c1c0c7b,
    0x181f3033,
    0x00003e1e,
    0x18300003,
    0x7f000c00,
    0x003b0c30,
    0x0c3c1806,
    0x06000000,
    0x30060c6f,
    0x0c33307f,
    0x00003033,
    0x0c180006,
    0x36000000,
    0x0033661f,
    0x0c660c0c,
    0x030c000c,
    0x33330c67,
    0x0c333330,
    0x0c0c1833,
    0x000c3f0c,
    0x36000c00,
    0x006e630c,
    0x00000618,
    0x010c000c,
    0x1e3f3f3e,
    0x0c1e1e78,
    0x0c0c0e1e,
    0x0c060018,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000006,
    0x00000000,
    0x00000000,
    0x06000000,
    0x00000000,
    0x3c3f0c3e,
    0x3c7f7f1f,
    0x67781e33,
    0x1c63630f,
    0x1e3f1e3f,
    0x6333333f,
    0x1e7f3363,
    0x00081e03,
    0x66661e63,
    0x66464636,
    0x66300c33,
    0x36677706,
    0x33663366,
    0x6333332d,
    0x06633363,
    0x001c1806,
    0x0366337b,
    0x03161666,
    0x36300c33,
    0x636f7f06,
    0x06663366,
    0x6333330c,
    0x06313336,
    0x0036180c,
    0x033e337b,
    0x031e1e66,
    0x1e300c3f,
    0x637b7f06,
    0x0c3e333e,
    0x6b33330c,
    0x06181e1c,
    0x00631818,
    0x03663f7b,
    0x73161666,
    0x36330c33,
    0x63736b46,
    0x18363b06,
    0x7f33330c,
    0x064c0c1c,
    0x00001830,
    0x66663303,
    0x66064636,
    0x66330c33,
    0x36636366,
    0x33661e06,
    0x771e330c,
    0x06660c36,
    0x00001860,
    0x3c3f331e,
    0x7c0f7f1f,
    0x671e1e33,
    0x1c63637f,
    0x1e67380f,
    0x630c3f1e,
    0x1e7f1e63,
    0x00001e40,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0xff000000,
    0x0007000c,
    0x001c0038,
    0x07300c07,
    0x0000000e,
    0x00000000,
    0x00000008,
    0x38000000,
    0x006e0718,
    0x0006000c,
    0x00360030,
    0x06000006,
    0x0000000c,
    0x00000000,
    0x0000000c,
    0x0c000000,
    0x083b0c18,
    0x1e061e18,
    0x6e061e30,
    0x66300e36,
    0x1e1f330c,
    0x3e3b6e3b,
    0x6333333e,
    0x0c3f3363,
    0x1c000c18,
    0x333e3000,
    0x330f333e,
    0x36300c6e,
    0x33337f0c,
    0x036e3366,
    0x6b33330c,
    0x07193336,
    0x36003800,
    0x03663e00,
    0x33063f33,
    0x1e300c66,
    0x33337f0c,
    0x1e663366,
    0x7f33330c,
    0x0c0c331c,
    0x63000c18,
    0x33663300,
    0x3e060333,
    0x36330c66,
    0x33336b0c,
    0x30063e3e,
    0x7f1e332c,
    0x0c263e36,
    0x63000c18,
    0x1e3b6e00,
    0x300f1e6e,
    0x67331e67,
    0x1e33631e,
    0x1f0f3006,
    0x360c6e18,
    0x383f3063,
    0x7f000718,
    0x00000000,
    0x1f000000,
    0x001e0000,
    0x00000000,
    0x0000780f,
    0x00000000,
    0x00001f00,
    0x00000000,
    0x7e38001e,
    0x000c0733,
    0x3307337e,
    0x0c63073e,
    0x1e7c0038,
    0x001e0000,
    0x1833c300,
    0x701f331c,
    0xc3003333,
    0x000c0000,
    0x000000c3,
    0x0c1c0063,
    0x33360000,
    0x07330733,
    0x18001833,
    0xd8333336,
    0x3c1e0003,
    0x1e1e1e1e,
    0x0e1e1e3c,
    0x00360e1c,
    0x0033fe3f,
    0x00000000,
    0x7e333c00,
    0x18331e26,
    0x60333333,
    0x03303030,
    0x0c333366,
    0x1e630c18,
    0x1e7f3006,
    0x33331e1e,
    0x03336633,
    0x3c5f3f0f,
    0x7c3f331e,
    0x033e3e3e,
    0x0c3f3f7e,
    0x337f0c18,
    0x3333fe1e,
    0x33333333,
    0x03336633,
    0x18630c06,
    0x66033318,
    0x1e333333,
    0x0c030306,
    0x3f630c18,
    0x33333306,
    0x33333333,
    0x7e333c3e,
    0x18f33f67,
    0xfc1e7e30,
    0x307e7e7e,
    0x1e1e1e3c,
    0x33631e3c,
    0x1e73fe3f,
    0x7e7e1e1e,
    0x181e1830,
    0x1b630c3f,
    0x0000001e,
    0x1c000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x1800001f,
    0x0ee30c00,
    0x00001c38,
    0x1c3c3f00,
    0xc300000c,
    0x000018c3,
    0x18dbaa44,
    0x006c1818,
    0x006c6c00,
    0x00186c6c,
    0x38380000,
    0x3636001f,
    0x63000000,
    0x33cc1863,
    0x18ee5511,
    0x006c1818,
    0x006c6c00,
    0x00186c6c,
    0x00000e1e,
    0x36363300,
    0x3300000c,
    0x66660033,
    0x18dbaa44,
    0x006c1f18,
    0x7f6c6f1f,
    0x001f6c6f,
    0x331e0c30,
    0x1c7c371f,
    0x7b3f3f06,
    0xcc3318db,
    0x18775511,
    0x006c1818,
    0x606c6018,
    0x00186c60,
    0x33330c3e,
    0x00003f33,
    0xcc300303,
    0x666618ec,
    0x18dbaa44,
    0x7f6f1f1f,
    0x6f6c6f1f,
    0x1f1f7f7f,
    0x33330c33,
    0x3e7e3b33,
    0x66300333,
    0x33cc18f6,
    0x18ee5511,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x7e1e1e7e,
    0x00003333,
    0x3300001e,
    0x000018f3,
    0x18dbaa44,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x00000000,
    0x00000000,
    0xf0000000,
    0x000000c0,
    0x18775511,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x18001818,
    0x6c181800,
    0x006c006c,
    0x186c006c,
    0x6c00006c,
    0x6c000018,
    0xff001818,
    0xfff00f00,
    0x18001818,
    0x6c181800,
    0x006c006c,
    0x186c006c,
    0x6c00006c,
    0x6c000018,
    0xff001818,
    0xfff00f00,
    0x18001818,
    0x6cf81800,
    0xffeffcec,
    0xffefffec,
    0x6c00ff6c,
    0x6c00f8f8,
    0xff0018ff,
    0xfff00f00,
    0x18001818,
    0x6c181800,
    0x00000c0c,
    0x0000000c,
    0x6c00006c,
    0x6c001818,
    0xff001818,
    0xfff00f00,
    0xf8fffff8,
    0xecf8ffff,
    0xefffecfc,
    0xffefffec,
    0xfcffffff,
    0xfffcf8f8,
    0xfff81fff,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x00000000,
    0x0000003f,
    0x381c1c3f,
    0x1e1c6000,
    0x18060c00,
    0x000c1870,
    0xf000001c,
    0x00000e1e,
    0x7f3f1e00,
    0x6e660033,
    0x0c36360c,
    0x33063000,
    0x0c0c0c3f,
    0x6e0c18d8,
    0x30000036,
    0x00001836,
    0x3633336e,
    0x3b667e06,
    0x1863631e,
    0x33037e7e,
    0x06183f00,
    0x3b0018d8,
    0x30000036,
    0x003c0c36,
    0x36031f3b,
    0x18661b0c,
    0x3e637f33,
    0x331fdbdb,
    0x0c0c0c3f,
    0x003f1818,
    0x3000181c,
    0x003c0636,
    0x36033313,
    0x18661b06,
    0x33366333,
    0x3303dbdb,
    0x18060c00,
    0x6e001818,
    0x37181800,
    0x003c1e36,
    0x36031f3b,
    0x183e1b33,
    0x3336361e,
    0x33067e7e,
    0x0000003f,
    0x3b0c1b18,
    0x36000000,
    0x003c0000,
    0x3603036e,
    0x18060e3f,
    0x1e771c0c,
    0x331c0600,
    0x3f3f3f00,
    0x000c1b18,
    0x3c000000,
    0x00000000,
    0x00000300,
    0x00030000,
    0x0000003f,
    0x00000300,
    0x00000000,
    0x00000e18,
    0x38000000,
    0x00000000,
};

static uint32_t font8x16[] = {
    8,
    16,
    11,
    0x00000000,
    0x00000000,
    0x00ff00ff,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00ff00ff,
    0x00000000,
    0x00004001,
    0x00003e00,
    0x00000000,
    0x00000000,
    0x007e7e00,
    0x00000000,
    0x78ff00ff,
    0x00fefc3c,
    0x66186003,
    0x180063fe,
    0x00001818,
    0x00000000,
    0x00ff8100,
    0x00181800,
    0x70ff00ff,
    0x18c6cc66,
    0x663c7007,
    0x3c0006db,
    0x0000183c,
    0x00000000,
    0x36dba500,
    0x003c3c08,
    0x58ff00ff,
    0x18fefc66,
    0x667e780f,
    0x7e001cdb,
    0x0000187e,
    0x7f080000,
    0x7fff8100,
    0x007e3c1c,
    0x4cc33cff,
    0xdbc60c66,
    0x66187c1f,
    0x180036db,
    0x0c181818,
    0x7f1c1400,
    0x7fff8100,
    0x18ffe73e,
    0x1e9966e7,
    0x3cc60c66,
    0x66187f7f,
    0x180063de,
    0x06301818,
    0x3e1c3603,
    0x7fc3bd00,
    0x3cffe77f,
    0x33bd42c3,
    0xe7c60c3c,
    0x66187c1f,
    0x180063d8,
    0x7f7f1818,
    0x3e3e7f03,
    0x7fe79900,
    0x3c7ee73e,
    0x33bd42c3,
    0x3cc60c18,
    0x667e780f,
    0x7e7f36d8,
    0x06301818,
    0x1c3e3603,
    0x3eff8100,
    0x1818181c,
    0x339966e7,
    0xdbe60e7e,
    0x003c7007,
    0x3c7f1cd8,
    0x0c187e18,
    0x1c7f147f,
    0x1cff8100,
    0x00181808,
    0x33c33cff,
    0x18e70f18,
    0x66186003,
    0x187f30d8,
    0x00003c18,
    0x087f0000,
    0x087e7e00,
    0x003c3c00,
    0x1eff00ff,
    0x18670718,
    0x66004001,
    0x7e7f63d8,
    0x00001818,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00ff00ff,
    0x00030000,
    0x00000000,
    0x00003e00,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00ff00ff,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00ff00ff,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00ff00ff,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000018,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00660000,
    0x0c000018,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00661800,
    0x0c1c003e,
    0x00000c30,
    0x00000000,
    0x3e3e181c,
    0x7f1c7f30,
    0x00003e3e,
    0x3e000000,
    0x36663c00,
    0x0c360063,
    0x00001818,
    0x00000000,
    0x63631c36,
    0x63060338,
    0x00006363,
    0x63060060,
    0x36243c00,
    0x06364343,
    0x0000300c,
    0x40000000,
    0x60601e63,
    0x6003033c,
    0x18186363,
    0x630c0030,
    0x7f003c00,
    0x001c6303,
    0x1866300c,
    0x60000000,
    0x60301863,
    0x60030336,
    0x18186363,
    0x30187e18,
    0x36001800,
    0x006e303e,
    0x183c300c,
    0x30000000,
    0x3c18186b,
    0x303f3f33,
    0x00007e3e,
    0x1830000c,
    0x36001800,
    0x003b1860,
    0x7eff300c,
    0x18007f00,
    0x600c186b,
    0x1863607f,
    0x00006063,
    0x18600006,
    0x36001800,
    0x00330c60,
    0x183c300c,
    0x0c000000,
    0x60061863,
    0x0c636030,
    0x00006063,
    0x18307e0c,
    0x7f000000,
    0x00330661,
    0x1866300c,
    0x06000018,
    0x60031863,
    0x0c636030,
    0x18186063,
    0x00180018,
    0x36001800,
    0x00336363,
    0x00001818,
    0x03180018,
    0x63631836,
    0x0c636330,
    0x18183063,
    0x180c0030,
    0x36001800,
    0x006e613e,
    0x00000c30,
    0x01180018,
    0x3e7f7e1c,
    0x0c3e3e78,
    0x0c001e3e,
    0x18060060,
    0x00000000,
    0x00000018,
    0x00000000,
    0x0000000c,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000018,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00080000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x001c0000,
    0x3c3f0800,
    0x3c7f7f1f,
    0x67783c63,
    0x3e63630f,
    0x3e3f3e3f,
    0x6363637e,
    0x3c7f6663,
    0x00363c00,
    0x66661c3e,
    0x66666636,
    0x66301863,
    0x63677706,
    0x63666366,
    0x6363637e,
    0x0c636663,
    0x00633001,
    0x43663663,
    0x43464666,
    0x66301863,
    0x636f7f06,
    0x63666366,
    0x6363635a,
    0x0c616636,
    0x00003003,
    0x03666363,
    0x03161666,
    0x36301863,
    0x637f7f06,
    0x06666366,
    0x63636318,
    0x0c30663e,
    0x00003007,
    0x033e637b,
    0x031e1e66,
    0x1e30187f,
    0x637b6b06,
    0x1c3e633e,
    0x6b636318,
    0x0c183c1c,
    0x0000300e,
    0x03667f7b,
    0x7b161666,
    0x1e301863,
    0x63736306,
    0x30366306,
    0x6b636318,
    0x0c0c181c,
    0x0000301c,
    0x0366637b,
    0x63060666,
    0x36331863,
    0x63636306,
    0x60666306,
    0x6b636318,
    0x0c06183e,
    0x00003038,
    0x4366633b,
    0x63064666,
    0x66331863,
    0x63636346,
    0x63666b06,
    0x7f366318,
    0x0c431836,
    0x00003070,
    0x66666303,
    0x66066636,
    0x66331863,
    0x63636366,
    0x63667b06,
    0x771c6318,
    0x0c631863,
    0x00003060,
    0x3c3f633e,
    0x5c0f7f1f,
    0x671e3c63,
    0x3e63637f,
    0x3e673e0f,
    0x36083e3c,
    0x3c7f3c63,
    0x00003c40,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00003000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00007000,
    0x00000000,
    0x00000000,
    0xff000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x0000000c,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x006e0000,
    0x00070018,
    0x00380038,
    0x07601807,
    0x0000001c,
    0x00000000,
    0x00000008,
    0x70000000,
    0x003b0e18,
    0x00060030,
    0x006c0030,
    0x06601806,
    0x00000018,
    0x00000000,
    0x0000000c,
    0x18000000,
    0x00001818,
    0x00060000,
    0x004c0030,
    0x06000006,
    0x00000018,
    0x00000000,
    0x0000000c,
    0x18000000,
    0x08001818,
    0x3e1e1e00,
    0x6e0c3e3c,
    0x66701c36,
    0x3e3b3718,
    0x3e3b6e3b,
    0x6363333f,
    0x187f6363,
    0x1c001818,
    0x63363000,
    0x331e6336,
    0x3660186e,
    0x63667f18,
    0x636e3366,
    0x6363330c,
    0x0e336336,
    0x36007018,
    0x03663e00,
    0x330c7f33,
    0x1e601866,
    0x63666b18,
    0x06663366,
    0x6b63330c,
    0x1818631c,
    0x63001818,
    0x03663300,
    0x330c0333,
    0x1e601866,
    0x63666b18,
    0x1c063366,
    0x6b63330c,
    0x180c631c,
    0x63001818,
    0x03663300,
    0x330c0333,
    0x36601866,
    0x63666b18,
    0x30063366,
    0x6b63330c,
    0x1806631c,
    0x63001818,
    0x63663300,
    0x330c6333,
    0x66601866,
    0x63666b18,
    0x63063366,
    0x7f36336c,
    0x18636336,
    0x7f001818,
    0x3e3e6e00,
    0x3e1e3e6e,
    0x67603c67,
    0x3e66633c,
    0x3e0f3e3e,
    0x361c6e38,
    0x707f7e63,
    0x00000e18,
    0x00000000,
    0x30000000,
    0x00660000,
    0x00000000,
    0x00003006,
    0x00000000,
    0x00006000,
    0x00000000,
    0x00000000,
    0x33000000,
    0x00660000,
    0x00000000,
    0x00003006,
    0x00000000,
    0x00003000,
    0x00000000,
    0x00000000,
    0x1e000000,
    0x003c0000,
    0x00000000,
    0x0000780f,
    0x00000000,
    0x00001f00,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x1c000000,
    0x00000030,
    0x00000000,
    0x00000000,
    0x00000000,
    0x08300000,
    0x001c0600,
    0x00060008,
    0x36630618,
    0x08000018,
    0x060c0600,
    0x18636300,
    0x701f001c,
    0x1c18333c,
    0x00360c33,
    0x660c631c,
    0x1c000c3c,
    0x1c7c0000,
    0x0c1e0c63,
    0x18000063,
    0xd8336636,
    0x360c0066,
    0x001c1800,
    0x00180036,
    0x08081866,
    0x3636007f,
    0x18331800,
    0x3e633e00,
    0x18336626,
    0x00000043,
    0x00000000,
    0x00000000,
    0x1c1c0000,
    0x00330066,
    0x00000000,
    0x63636300,
    0x181f3c06,
    0x1e3e3303,
    0x3e1e1e1e,
    0x1c3e3e3e,
    0x36361c1c,
    0x3e333746,
    0x33333e3e,
    0x03636363,
    0x1823180f,
    0x30633303,
    0x63303030,
    0x18636363,
    0x63631818,
    0x637f6c16,
    0x33336363,
    0x03636363,
    0x7e337e06,
    0x3e7f3303,
    0x033e3e3e,
    0x187f7f7f,
    0x7f631818,
    0x63336c1e,
    0x33336363,
    0x03636363,
    0x187b1806,
    0x33033303,
    0x03333333,
    0x18030303,
    0x637f1818,
    0x63337e16,
    0x33336363,
    0x63636363,
    0x18337e06,
    0x33033343,
    0x03333333,
    0x18030303,
    0x63631818,
    0x63331b46,
    0x33336363,
    0x3e636363,
    0x18331806,
    0x33633366,
    0x63333333,
    0x18636363,
    0x63631818,
    0x63331b66,
    0x33336363,
    0x18636363,
    0x1b331867,
    0x6e3e6e3c,
    0x3e6e6e6e,
    0x3c3e3e3e,
    0x63633c3c,
    0x3e73767f,
    0x6e6e3e3e,
    0x183e3e7e,
    0x0e63183f,
    0x00000018,
    0x18000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000060,
    0x00000000,
    0x0000000e,
    0x0e000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000030,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x0000001e,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00006e00,
    0x00000000,
    0x00000000,
    0x18bbaa88,
    0x006c1818,
    0x006c6c00,
    0x00186c6c,
    0x18183018,
    0x00003b00,
    0x06000000,
    0x00000006,
    0x18ee5522,
    0x006c1818,
    0x006c6c00,
    0x00186c6c,
    0x0c0c180c,
    0x1c3c006e,
    0x0700000c,
    0x00001807,
    0x18bbaa88,
    0x006c1818,
    0x006c6c00,
    0x00186c6c,
    0x06060c06,
    0x3636633b,
    0x4600000c,
    0x00001846,
    0x18ee5522,
    0x006c1818,
    0x006c6c00,
    0x00186c6c,
    0x00000000,
    0x36366700,
    0x66000000,
    0x00000066,
    0x18bbaa88,
    0x006c1818,
    0x006c6c00,
    0x00186c6c,
    0x333e1c1e,
    0x1c7c6f3b,
    0x3600000c,
    0x1b6c1836,
    0x18ee5522,
    0x006c1f18,
    0x7f6c6f1f,
    0x001f6c6f,
    0x33631830,
    0x00007f66,
    0x187f7f0c,
    0x36361818,
    0x18bbaa88,
    0x006c1818,
    0x606c6018,
    0x00186c60,
    0x3363183e,
    0x3e7e7b66,
    0x0c600306,
    0x6c1b180c,
    0x18ee5522,
    0x7f6f1f1f,
    0x6f6c6f1f,
    0x1f1f7f7f,
    0x33631833,
    0x00007366,
    0x06600303,
    0x36363c66,
    0x18bbaa88,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x33631833,
    0x00006366,
    0x3b600363,
    0x1b6c3c73,
    0x18ee5522,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x33631833,
    0x00006366,
    0x61600363,
    0x00003c59,
    0x18bbaa88,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x6e3e3c6e,
    0x00006366,
    0x3000003e,
    0x000018fc,
    0x18ee5522,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x00000000,
    0x00000000,
    0x18000000,
    0x00000060,
    0x18bbaa88,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x00000000,
    0x00000000,
    0x7c000000,
    0x00000060,
    0x18ee5522,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x18bbaa88,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x18ee5522,
    0x6c6c1818,
    0x6c6c6c18,
    0x18000000,
    0x18001818,
    0x6c181800,
    0x006c006c,
    0x186c006c,
    0x6c00006c,
    0x6c000018,
    0xff001818,
    0xfff00f00,
    0x18001818,
    0x6c181800,
    0x006c006c,
    0x186c006c,
    0x6c00006c,
    0x6c000018,
    0xff001818,
    0xfff00f00,
    0x18001818,
    0x6c181800,
    0x006c006c,
    0x186c006c,
    0x6c00006c,
    0x6c000018,
    0xff001818,
    0xfff00f00,
    0x18001818,
    0x6c181800,
    0x006c006c,
    0x186c006c,
    0x6c00006c,
    0x6c000018,
    0xff001818,
    0xfff00f00,
    0x18001818,
    0x6c181800,
    0x006c006c,
    0x186c006c,
    0x6c00006c,
    0x6c000018,
    0xff001818,
    0xfff00f00,
    0x18001818,
    0x6cf81800,
    0xffeffcec,
    0xffefffec,
    0x6c00ff6c,
    0x6c00f8f8,
    0xff0018ff,
    0xfff00f00,
    0x18001818,
    0x6c181800,
    0x00000c0c,
    0x0000000c,
    0x6c00006c,
    0x6c001818,
    0xff001818,
    0xfff00f00,
    0xf8fffff8,
    0xecf8ffff,
    0xefffecfc,
    0xffefffec,
    0xfcffffff,
    0xfffcf8f8,
    0xfff81fff,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x18180000,
    0x6c181800,
    0x6c006c00,
    0x006c006c,
    0x006c1800,
    0x6c6c1800,
    0xff180018,
    0x00f00fff,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00001800,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00001800,
    0xf000001c,
    0x00003c36,
    0x007f1e00,
    0x0000007f,
    0x781c1c7e,
    0x00380000,
    0x00000000,
    0x00001870,
    0x30000036,
    0x0000666c,
    0x00633300,
    0x00000063,
    0x0c363618,
    0x3e0cc000,
    0x300c0000,
    0x000018d8,
    0x30000036,
    0x0000306c,
    0x00633300,
    0x6e000006,
    0x1863633c,
    0x63066000,
    0x1818187f,
    0x000018d8,
    0x3000001c,
    0x007e186c,
    0x7f03336e,
    0x3b667e0c,
    0x30636366,
    0x63067e7e,
    0x0c301800,
    0x6e181818,
    0x30000000,
    0x007e4c6c,
    0x36031b3b,
    0x18661b18,
    0x7c637f66,
    0x633edbdb,
    0x06607e00,
    0x3b001818,
    0x30000000,
    0x007e7e6c,
    0x3603331b,
    0x18661b18,
    0x66366366,
    0x6306dbdb,
    0x0c30187f,
    0x007e1818,
    0x37181800,
    0x007e0000,
    0x3603631b,
    0x18661b0c,
    0x66366366,
    0x6306cfdb,
    0x18181800,
    0x6e001818,
    0x36001800,
    0x007e0000,
    0x3603631b,
    0x18661b06,
    0x6636633c,
    0x63067e7e,
    0x300c0000,
    0x3b181b18,
    0x36000000,
    0x007e0000,
    0x3603633b,
    0x18661b63,
    0x66363618,
    0x630c0600,
    0x0000007f,
    0x00001b18,
    0x3c000000,
    0x007e0000,
    0x3603336e,
    0x183e0e7f,
    0x3c771c7e,
    0x63380300,
    0x7e7e7e00,
    0x00001b18,
    0x38000000,
    0x00000000,
    0x00000000,
    0x00060000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000e18,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00060000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000018,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00030000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000018,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000018,
    0x00000000,
    0x00000000,
};

static uint32_t font9x16[] = {
    9,
    16,
    11,
    0x00000000,
    0x00000000,
    0xfc00ff00,
    0x00000003,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0xfc00ff00,
    0x00000003,
    0x80010000,
    0xc0000000,
    0x00000007,
    0x00000000,
    0x01f8fc00,
    0x00000000,
    0xfc00ff00,
    0x9f83c3c3,
    0xc003003f,
    0x6fe33060,
    0x180c000c,
    0x00000030,
    0x03fd0200,
    0x06030000,
    0xfc00ff00,
    0x99866383,
    0xe0070c31,
    0xcdb330f0,
    0x3c1e0000,
    0x00000030,
    0xb36d4a00,
    0x0f078081,
    0xfc00ff00,
    0x9f8662c3,
    0xf00f0c3f,
    0x8db331f8,
    0x7e3f0003,
    0x00000030,
    0xfbfd0200,
    0x1f8781c3,
    0x0c78ff00,
    0x81866263,
    0xf81f6db1,
    0xcdb33060,
    0x180c0006,
    0x00606030,
    0xfbfd0200,
    0x3fdce3e3,
    0x64cce70c,
    0x818660f2,
    0xfe7f1e31,
    0x6de33060,
    0x180c000c,
    0x0030c030,
    0xfb0d7a00,
    0x3fdce7f3,
    0xf484c31e,
    0x8183c19a,
    0xf81f73b1,
    0x6d833060,
    0x180c000c,
    0x03f9fc30,
    0xfb9d3200,
    0x1f9ce3e3,
    0xf484c31e,
    0x8181819a,
    0xf00f1e31,
    0xcd8331f8,
    0x183f1fc6,
    0x0030c030,
    0xf3fd0200,
    0x060301c1,
    0x64cce70c,
    0x81c7e19a,
    0xe0076db9,
    0x8d8000f0,
    0x181e1fc3,
    0x006060fc,
    0xe3fd0200,
    0x06030080,
    0x0c78ff00,
    0xc1e1819b,
    0xc0030c39,
    0x0d833060,
    0x180c1fc6,
    0x00000078,
    0x41f8fc00,
    0x0f078000,
    0xfc00ff00,
    0xc0e180f3,
    0x80010c19,
    0x6d833000,
    0x183f1fcc,
    0x00000030,
    0x00000000,
    0x00000000,
    0xfc00ff00,
    0xc0000003,
    0x00000000,
    0xc0000000,
    0x00000007,
    0x00000000,
    0x00000000,
    0x00000000,
    0xfc00ff00,
    0x00000003,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0xfc00ff00,
    0x00000003,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0xfc00ff00,
    0x00000003,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00001800,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x19800000,
    0x00001800,
    0x00000060,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x19830000,
    0x70003e00,
    0x01830060,
    0x00000000,
    0x03c00000,
    0x301f0f83,
    0x03f870fe,
    0x00000000,
    0x19878000,
    0xd800631b,
    0x03018060,
    0x00000000,
    0x86600000,
    0x383198c3,
    0x03181806,
    0xf8200000,
    0x09078003,
    0xd886431b,
    0x0600c030,
    0x00000000,
    0xcc320000,
    0x3c301803,
    0x03000c06,
    0xf8704800,
    0x80078003,
    0x70c6033f,
    0x8600c000,
    0x00000c19,
    0x0c330000,
    0x36300c03,
    0x03000c06,
    0xf070cc03,
    0x00030001,
    0xb8603e1b,
    0x0600c001,
    0x00000c0f,
    0x0db18000,
    0x331e0603,
    0x0180fc7e,
    0xf0f9fe03,
    0x00030001,
    0xec30601b,
    0xc600c000,
    0xfe003f3f,
    0x0db0c000,
    0x7f300303,
    0x00c18cc0,
    0xe0f8cc03,
    0x00030000,
    0xcc18601b,
    0x0600c000,
    0x00000c0f,
    0x0c306000,
    0x30300183,
    0x00618cc0,
    0xe1fc487f,
    0x80000000,
    0xcc0c613f,
    0x8600c000,
    0x00180c19,
    0x0c303000,
    0x303000c3,
    0x00618cc0,
    0x41fc0000,
    0x00030000,
    0xccc6631b,
    0x03018000,
    0x00180000,
    0x06601860,
    0x303198c3,
    0x00618cc6,
    0x00000000,
    0x00030000,
    0xb8c23e1b,
    0x01830001,
    0x00180000,
    0xc3c00860,
    0x781f1fcf,
    0x0060f87c,
    0x00000000,
    0x00000000,
    0x00001800,
    0x00000000,
    0x000c0000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00001800,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00007c3e,
    0x00000000,
    0xfc10001f,
    0xcfe1f1e0,
    0x78631e1f,
    0x60f339e0,
    0x3f1f18d8,
    0x01f0fc7c,
    0x0000c663,
    0x81800600,
    0x98383e31,
    0x8cc36331,
    0x30633319,
    0xe06330c0,
    0x663199dc,
    0x031998c6,
    0xc060c663,
    0x83000300,
    0x986c6331,
    0x88c66219,
    0x30632191,
    0xe06330c0,
    0x66319bdf,
    0x031998c6,
    0xc060c663,
    0x060fc180,
    0x98c66318,
    0x82c66019,
    0x30630185,
    0xe061b0c0,
    0x66319fdf,
    0x003198c6,
    0x0000fc3e,
    0x0c0000c0,
    0xf8c67b0c,
    0x83c66018,
    0x307f0187,
    0x6060f0c0,
    0x3e319edb,
    0x00e0f8c6,
    0x0000c063,
    0x18000060,
    0x98fe7b0c,
    0x82c66019,
    0x30633d85,
    0x6060f0c0,
    0x06319cd8,
    0x0180d8c6,
    0x0000c063,
    0x0c0fc0c0,
    0x98c67b0c,
    0x80c66019,
    0x30633181,
    0x6061b0cc,
    0x063198d8,
    0x030198c6,
    0xc060c063,
    0x06000180,
    0x98c63b00,
    0x88c66219,
    0x30633181,
    0x646330cc,
    0x063198d8,
    0x031998d6,
    0xc0606063,
    0x03000300,
    0x98c6030c,
    0x8cc36331,
    0x30633301,
    0x666330cc,
    0x063198d8,
    0x031998f6,
    0x60003c3e,
    0x01800600,
    0xfcc63e0c,
    0xcfe1f1e0,
    0x78632e03,
    0x67f33878,
    0x0f1f18d8,
    0x01f19c7c,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000060,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x000000e0,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x20000000,
    0x0000c000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x70000000,
    0x0000c000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x1b0cc6ff,
    0x3fd86c36,
    0xd878001e,
    0xc0018000,
    0x00380001,
    0x00700070,
    0x1c039803,
    0x00000000,
    0x1b0cc6db,
    0x30d86c36,
    0x8c600106,
    0x80000001,
    0x00300001,
    0x006000d8,
    0x18031803,
    0x00000000,
    0x1b0cc699,
    0x18586666,
    0x00600306,
    0x80000000,
    0x00300001,
    0x00600098,
    0x18030000,
    0x00000000,
    0x1b0cc618,
    0x0c0cc3c6,
    0x00600706,
    0x83c00000,
    0x7c3c1f07,
    0x83637018,
    0x18331c03,
    0x01f0ecce,
    0x1b0cc618,
    0x06078186,
    0x00600e06,
    0x86000000,
    0xc636318d,
    0x06e1983c,
    0x181b1803,
    0x031999fe,
    0xdb0cc618,
    0x03030186,
    0x00601c06,
    0x87c00000,
    0xfe330199,
    0x06619818,
    0x180f1803,
    0x031999b6,
    0xdb0cc618,
    0x018303c6,
    0x00603806,
    0x86600000,
    0x06330199,
    0x06619818,
    0x180f1803,
    0x031999b6,
    0xf998c618,
    0x20c30667,
    0x00607006,
    0x86600000,
    0x06330199,
    0x06619818,
    0x181b1803,
    0x031999b6,
    0x30f0c618,
    0x30c30c33,
    0x00606006,
    0x86600000,
    0xc6333199,
    0x06619818,
    0x18331803,
    0x031999b6,
    0x30607c3c,
    0x3fc78c33,
    0x0078401e,
    0x8dc00000,
    0x7c6e1f0f,
    0x8671f03c,
    0x3c339807,
    0x01f199b6,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00018000,
    0x00001980,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x000007f8,
    0x00000000,
    0x00019800,
    0x00001980,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x0000f000,
    0x00000f00,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0xc00040c0,
    0x08000700,
    0x00001800,
    0x00000000,
    0x00000080,
    0x00000000,
    0x81c18380,
    0x663c001b,
    0x8330e060,
    0x1c000d81,
    0x033030c6,
    0x00000000,
    0x000000c0,
    0x00000000,
    0xc30180c0,
    0x0066000e,
    0x0001b030,
    0x36000703,
    0x00006000,
    0x00000000,
    0x000000c0,
    0x00000000,
    0x030180c0,
    0x00430400,
    0x00000000,
    0x001e0000,
    0x00000000,
    0xf0ecdc3b,
    0xb0c663f1,
    0xfcc6c361,
    0x030180c1,
    0x66030e00,
    0xc1e0f0f8,
    0x3e330783,
    0x00e0f87c,
    0x19b86666,
    0xb0c660c3,
    0xccc66661,
    0x0e000070,
    0x66031b00,
    0x0301818c,
    0x63030c06,
    0x00c18cc6,
    0x31986666,
    0xb0c660c0,
    0x60c63c61,
    0x030180c0,
    0x66033180,
    0xc3e1f1fc,
    0x7f030f87,
    0x00c1fcfe,
    0xe0186666,
    0xb0c660c0,
    0x30c6186d,
    0x030180c0,
    0x66433180,
    0x6331980c,
    0x03330cc6,
    0x00c00c06,
    0x80186666,
    0x998660c1,
    0x18c63c6d,
    0x030180c0,
    0x66663180,
    0x6331980c,
    0x031e0cc6,
    0x00c00c06,
    0x18186666,
    0x8f0666c3,
    0x8cc6667f,
    0x030180c1,
    0x663c3f80,
    0x6331998c,
    0x63180cc6,
    0x00c18cc6,
    0xf03c7c3e,
    0x060dc381,
    0xfcfcc333,
    0x01c18381,
    0xdc300000,
    0xc6e370f8,
    0x3e301b8d,
    0x01e0f87c,
    0x00006006,
    0x00000000,
    0x00c00000,
    0x00000000,
    0x00600000,
    0x00000000,
    0x001e0000,
    0x00000000,
    0x00006006,
    0x00000000,
    0x00600000,
    0x00000000,
    0x003e0000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x0000f00f,
    0x00000000,
    0x003e0000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0xe0000000,
    0x00000180,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x000000dc,
    0xb18c0c18,
    0x000000c1,
    0x300c0004,
    0xcc600030,
    0x001c0c18,
    0x018380fc,
    0x000c0606,
    0x00e0f076,
    0xe000183c,
    0x1f000060,
    0x7818630e,
    0x00063060,
    0x86360c00,
    0x00c6c199,
    0x6e060303,
    0x01b0d800,
    0x00203066,
    0x0d800000,
    0xcc30001b,
    0xc7c000c0,
    0xcc263f18,
    0x8060c198,
    0x3b030181,
    0x01b0d8c6,
    0xe0700000,
    0x0cc007f0,
    0x00000000,
    0xcc600000,
    0x78066198,
    0x0000c0f8,
    0x00000000,
    0x00e1f0ce,
    0xb0d8381c,
    0x0ccec661,
    0xcc7c3e1f,
    0xcc663198,
    0x300f0198,
    0x81e0c118,
    0x3b198f83,
    0x000000de,
    0x198c3018,
    0x9fdb8063,
    0xccc66331,
    0xcc663198,
    0xfe060198,
    0x0303f199,
    0x661998c3,
    0x01f1f8fe,
    0x198c3018,
    0x8cdb03e3,
    0xccc66331,
    0xcc663198,
    0x30060198,
    0x03e0c3d8,
    0x661998c3,
    0x000000f6,
    0xf9fc3018,
    0x8ccfc063,
    0xccc66331,
    0xcc663198,
    0xfe066198,
    0x0330c199,
    0x661998c3,
    0x000000e6,
    0x198c3018,
    0x8cc36063,
    0xccc66331,
    0xcc663198,
    0x30063f18,
    0x0330c198,
    0x661998c3,
    0x000000c6,
    0x198c3018,
    0x8cc76663,
    0xccc66331,
    0xcc663198,
    0x30670c18,
    0x0330c198,
    0x661998c3,
    0x000000c6,
    0x198c783c,
    0x1cddc7f3,
    0xb87c3e1f,
    0x87c7e371,
    0x303f0c0f,
    0x86e0c33c,
    0x66370f87,
    0x000000c6,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00060000,
    0x00000000,
    0x0000d800,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00030000,
    0x00000000,
    0x00007000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x0001e000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0xef558800,
    0x030180c6,
    0xd800001b,
    0x86c001b0,
    0x1800060d,
    0x00c00030,
    0x18000000,
    0x00000030,
    0xb8aa2200,
    0x030180c7,
    0xd800001b,
    0x86c001b0,
    0x1800060d,
    0x00c00030,
    0x1800000c,
    0x00030030,
    0xef558800,
    0x030180c6,
    0xd800001b,
    0x86c001b0,
    0x1800060d,
    0x00c00030,
    0x1800000c,
    0x00030432,
    0xb8aa2200,
    0x030180c7,
    0xd800001b,
    0x86c001b0,
    0x1800060d,
    0x00c00030,
    0x18000000,
    0x00000633,
    0xef558800,
    0x030180c6,
    0xd800001b,
    0x86c001b0,
    0x1800060d,
    0x00c00030,
    0x9800000c,
    0x9b030331,
    0xb8aa220d,
    0x03e180c7,
    0xde1f001b,
    0x86f3f9b0,
    0x180007cd,
    0x00c00030,
    0xc1fcfe0c,
    0x0d830180,
    0xef55881b,
    0x030180c6,
    0xc018001b,
    0x860301b0,
    0x1800060d,
    0x00c00030,
    0x61800606,
    0x06c300c0,
    0xb8aa2236,
    0xc3e1f0c7,
    0xde1f3f9b,
    0xe7f379b0,
    0xf80f87cf,
    0x0fc7ffff,
    0x31800603,
    0x0d878660,
    0xef55881b,
    0x030180c6,
    0xd818361b,
    0x000361b0,
    0x000c0000,
    0x00c06000,
    0x99800663,
    0x9b078733,
    0xb8aa220d,
    0x030180c7,
    0xd818361b,
    0x000361b0,
    0x000c0000,
    0x00c06000,
    0xc9800663,
    0x00078696,
    0xef558800,
    0x030180c6,
    0xd818361b,
    0x000361b0,
    0x000c0000,
    0x00c06000,
    0x0000003e,
    0x000307c3,
    0xb8aa2200,
    0x030180c7,
    0xd818361b,
    0x000361b0,
    0x000c0000,
    0x00c06000,
    0x80000000,
    0x00000601,
    0xef558800,
    0x030180c6,
    0xd818361b,
    0x000361b0,
    0x000c0000,
    0x00c06000,
    0xc0000000,
    0x00000607,
    0xb8aa2200,
    0x030180c7,
    0xd818361b,
    0x000361b0,
    0x000c0000,
    0x00c06000,
    0x00000000,
    0x00000000,
    0xef558800,
    0x030180c6,
    0xd818361b,
    0x000361b0,
    0x000c0000,
    0x00c06000,
    0x00000000,
    0x00000000,
    0xb8aa2200,
    0x030180c7,
    0xd818361b,
    0x000361b0,
    0x000c0000,
    0x00c06000,
    0x60603000,
    0x1b0006c3,
    0xb0006c00,
    0x0006c0c1,
    0x00183600,
    0x01836000,
    0x00ff8003,
    0x0fffc01e,
    0x60603000,
    0x1b0006c3,
    0xb0006c00,
    0x0006c0c1,
    0x00183600,
    0x01836000,
    0x00ff8003,
    0x0fffc01e,
    0x60603000,
    0x1b0006c3,
    0xb0006c00,
    0x0006c0c1,
    0x00183600,
    0x01836000,
    0x00ff8003,
    0x0fffc01e,
    0x60603000,
    0x1b0006c3,
    0xb0006c00,
    0x0006c0c1,
    0x00183600,
    0x01836000,
    0x00ff8003,
    0x0fffc01e,
    0x60603000,
    0x1b0006c3,
    0xb0006c00,
    0x0006c0c1,
    0x00183600,
    0x01836000,
    0x00ff8003,
    0x0fffc01e,
    0x67e03000,
    0xfbff9ec3,
    0xbfffecff,
    0x3fe6cfff,
    0xf1f83600,
    0x1ff36003,
    0x00ff8003,
    0x0fffc01e,
    0x60603000,
    0x000180c3,
    0x00000c00,
    0x0006c000,
    0x30183600,
    0x01836000,
    0x00ff8003,
    0x0fffc01e,
    0x67e3ffff,
    0xfffd9fcf,
    0xbfffecf7,
    0xffffffff,
    0xf1f8fe7f,
    0xfffffff3,
    0xfffffe03,
    0x0007c01f,
    0x60603000,
    0x000d8003,
    0xb0006c36,
    0x03000001,
    0x3000001b,
    0x018361b0,
    0xffff8600,
    0x0007c01f,
    0x60603000,
    0x000d8003,
    0xb0006c36,
    0x03000001,
    0x3000001b,
    0x018361b0,
    0xffff8600,
    0x0007c01f,
    0x60603000,
    0x000d8003,
    0xb0006c36,
    0x03000001,
    0x3000001b,
    0x018361b0,
    0xffff8600,
    0x0007c01f,
    0x60603000,
    0x000d8003,
    0xb0006c36,
    0x03000001,
    0x3000001b,
    0x018361b0,
    0xffff8600,
    0x0007c01f,
    0x60603000,
    0x000d8003,
    0xb0006c36,
    0x03000001,
    0x3000001b,
    0x018361b0,
    0xffff8600,
    0x0007c01f,
    0x60603000,
    0x000d8003,
    0xb0006c36,
    0x03000001,
    0x3000001b,
    0x018361b0,
    0xffff8600,
    0x0007c01f,
    0x60603000,
    0x000d8003,
    0xb0006c36,
    0x03000001,
    0x3000001b,
    0x018361b0,
    0xffff8600,
    0x0007c01f,
    0x60603000,
    0x000d8003,
    0xb0006c36,
    0x03000001,
    0x3000001b,
    0x018361b0,
    0xffff8600,
    0x0007c01f,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000003,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x1c000003,
    0x07800000,
    0x01fc3c00,
    0x00000000,
    0x70000000,
    0x000003c0,
    0x0000000e,
    0x07000000,
    0x36000003,
    0x01800000,
    0x018c6600,
    0x000007f0,
    0xd8387e00,
    0x18000060,
    0x00001f03,
    0x0d818030,
    0x36000003,
    0x01800000,
    0xf98c6600,
    0x19800633,
    0x8c6c1837,
    0x8c0000c1,
    0x307f3181,
    0x0d80c060,
    0x1c000603,
    0x01800000,
    0xb00c666e,
    0x998fc061,
    0x8cc63c1d,
    0x8fc7e181,
    0x30003181,
    0x018060c0,
    0x00370603,
    0x01800000,
    0xb00c363b,
    0x198360c1,
    0x8cc6660c,
    0x9b6db3e1,
    0xfc00318f,
    0x01803180,
    0x001d8003,
    0x01800000,
    0xb00c661b,
    0x19836181,
    0xd8fe660c,
    0x9b6db330,
    0x307f3181,
    0x018060c0,
    0x00001f83,
    0x01b80030,
    0xb00cc61b,
    0x198360c1,
    0xd8c6660c,
    0x99edb330,
    0x30003181,
    0x6180c060,
    0x00370003,
    0x01b06030,
    0xb00cc61b,
    0x0f836061,
    0xd8c63c0c,
    0x8fc7e330,
    0x00003181,
    0x61818030,
    0x001d8603,
    0x01b00000,
    0xb00cc63b,
    0x01836631,
    0xd86c180c,
    0x00c00330,
    0x007f3183,
    0x61800000,
    0x00000603,
    0x01e00000,
    0xb00c666e,
    0x0181c7f1,
    0xdc387e0c,
    0x006001e1,
    0xfe00318e,
    0xc183f1f9,
    0x00000001,
    0x01c00000,
    0x00000000,
    0x00c00000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x01800000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x01800000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x01800000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x01800000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00001c1b,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00003636,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00001836,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00f80c36,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00f82636,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00f83e36,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00f80000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00f80000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00f80000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00f80000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
};

pixelfont_t *internals_build_font(uint32_t *font)
{
    uint32_t const *data = font;
    int chr_width = (int)*data++;
    int chr_height = (int)*data++;
    int chr_baseline = (int)*data++;
    int chr_mod = 256 / chr_width;
    PIXELFONT_U8 pixels[32 * 32];
    pixelfont_builder_t *builder = pixelfont_builder_create(chr_height, chr_baseline, chr_height, NULL);
    for (int c = 0; c < 256; ++c)
    {
        int sx = (c % chr_mod) * chr_width;
        int sy = (c / chr_mod) * chr_height;
        for (int y = 0; y < chr_height; ++y)
        {
            for (int x = 0; x < chr_width; ++x)
            {
                int v = (sx + x) / 32;
                int u = (sx + x) - (v * 32);
                uint32_t b = data[v + (sy + y) * 8];
                if (b & (1 << u))
                {
                    pixels[x + y * chr_width] = 1;
                }
                else
                {
                    pixels[x + y * chr_width] = 0;
                }
            }
        }
        pixelfont_builder_glyph(builder, c, chr_width, pixels, chr_width, 0, chr_width);
    }
    pixelfont_t *pixelfont = pixelfont_builder_font(builder);
    pixelfont_t *output = (pixelfont_t *)malloc(pixelfont->size_in_bytes);
    memcpy(output, pixelfont, pixelfont->size_in_bytes);
    pixelfont_builder_destroy(builder);
    return output;
}

#define DEFAULT_SOUNDBANK_NONE 0

enum audio_command_type_t
{
    AUDIO_COMMAND_NOTE_ON,
    AUDIO_COMMAND_NOTE_OFF,
    AUDIO_COMMAND_NOTE_OFF_ALL,
    AUDIO_COMMAND_SET_INSTRUMENT,
};

struct audio_command_t
{
    enum audio_command_type_t type;
    int channel;
    int note;
    int velocity;
    int instrument;
    int frame_stamp;
};

enum soundbank_type_t
{
    SOUNDBANK_TYPE_NONE,
    SOUNDBANK_TYPE_SF2,
    // SOUNDBANK_TYPE_IBK,
    SOUNDBANK_TYPE_OP2,
};

struct internals_t
{
    thread_mutex_t mutex;
    thread_atomic_int_t exit_flag;

    struct
    {
        thread_signal_t signal;
        thread_atomic_int_t count;
    } vbl;

    struct
    {
        enum videomode_t mode;
        int width;
        int height;
        uint32_t *font;
        int cellwidth;
        int cellheight;
        bool doublebuffer;
        uint8_t *buffer;
        uint8_t buffer0[1024 * 1024];
        uint8_t buffer1[1024 * 1024];
        uint32_t palette[256];
    } screen;

    struct
    {
        uint8_t *buffer;
        int width;
        int height;
    } draw;

    struct
    {
        int color;

        pixelfont_t *fonts[256];
        int fonts_count;

        int current_font;
        int bold;
        int italic;
        int underline;
    } graphics;

    struct
    {
        int x;
        int y;
        int fg;
        int bg;
        bool curs;
    } conio;

    struct
    {
        bool keystate[KEYCOUNT];
        enum keycode_t *keybuffer;
        enum keycode_t keybuffer0[256];
        enum keycode_t keybuffer1[256];
        char *charbuffer;
        char charbuffer0[256];
        char charbuffer1[256];
        int mouse_x;
        int mouse_y;
        int mouse_relx;
        int mouse_rely;
    } input;

    struct
    {
        int frame_stamp;
        int commands_count;
        struct audio_command_t commands[256];
        struct music_t *current_music;
        bool loop_music;
        int music_volume;
        int music_play_counter;
        enum soundmode_t soundmode;
        struct
        {
            struct sound_t *sound;
            bool loop;
            int volume_left;
            int volume_right;
            int play_counter;
        } channels[SOUND_CHANNELS];

        int current_soundbank;
        int soundbanks_count;
        struct
        {
            enum soundbank_type_t type;
            tsf *sf2;
            void *data;
            size_t size;
        } soundbanks[256];
    } audio;

#ifdef __wasm__
    struct
    {
        int swap_counts;
        int read_counts;
        WaCoro user_coro;
    } wasm;
#endif

} *internals;

static void internals_create(int sound_buffer_size)
{
    (void)sound_buffer_size;
    internals = (struct internals_t *)malloc(sizeof(struct internals_t));
    memset(internals, 0, sizeof(*internals));

    thread_mutex_init(&internals->mutex);

    thread_signal_init(&internals->vbl.signal);
    thread_atomic_int_store(&internals->vbl.count, 0);

    internals->screen.mode = videomode_80x25_9x16;
    internals->screen.width = 80;
    internals->screen.height = 25;
    internals->screen.font = font9x16;
    internals->screen.cellwidth = 9;
    internals->screen.cellheight = 16;
    internals->screen.buffer = internals->screen.buffer0;
    memcpy(internals->screen.palette, default_palette, 1024);

    internals->draw.buffer = internals->screen.buffer;
    internals->draw.width = internals->screen.width;
    internals->draw.height = internals->screen.height;

    internals->graphics.color = 15;
    internals->graphics.fonts_count = 4;
    internals->graphics.current_font = 1;

    internals->conio.fg = 7;
    internals->conio.curs = true;

    internals->input.keybuffer = internals->input.keybuffer0;
    internals->input.charbuffer = internals->input.charbuffer0;

    internals->graphics.fonts[DEFAULT_FONT_8X8] = internals_build_font(font8x8);
    internals->graphics.fonts[DEFAULT_FONT_8X16] = internals_build_font(font8x16);
    internals->graphics.fonts[DEFAULT_FONT_9X16] = internals_build_font(font9x16);

    internals->audio.current_soundbank = DEFAULT_SOUNDBANK_NONE;
    internals->audio.soundbanks_count = 3;
    internals->audio.soundbanks[DEFAULT_SOUNDBANK_AWE32].type = SOUNDBANK_TYPE_SF2;
    internals->audio.soundbanks[DEFAULT_SOUNDBANK_AWE32].sf2 = NULL; // load when first used
    internals->audio.soundbanks[DEFAULT_SOUNDBANK_AWE32].data = NULL;
    internals->audio.soundbanks[DEFAULT_SOUNDBANK_AWE32].size = 0;
    internals->audio.soundbanks[DEFAULT_SOUNDBANK_SB16].type = SOUNDBANK_TYPE_NONE;
    internals->audio.soundbanks[DEFAULT_SOUNDBANK_SB16].sf2 = NULL;
    internals->audio.soundbanks[DEFAULT_SOUNDBANK_SB16].data = NULL;
    internals->audio.soundbanks[DEFAULT_SOUNDBANK_SB16].size = 0;

    internals->audio.soundmode = soundmode_8bit_mono_22050;
}

static void internals_destroy(void)
{
    for (int i = 1; i < internals->graphics.fonts_count; ++i)
    {
        if (internals->graphics.fonts[i])
        {
            free(internals->graphics.fonts[i]);
        }
    }
    for (int i = 1; i < internals->audio.soundbanks_count; ++i)
    {
        if (internals->audio.soundbanks[i].data)
        {
            free(internals->audio.soundbanks[i].data);
        }
        else if (internals->audio.soundbanks[i].sf2)
        {
            tsf_close(internals->audio.soundbanks[i].sf2);
        }
    }
    thread_signal_term(&internals->vbl.signal);
    thread_mutex_term(&internals->mutex);
    free(internals);
    internals = NULL;
}

int shuttingdown(void)
{

    return thread_atomic_int_load(&internals->exit_flag);
}

void setvideomode(enum videomode_t mode)
{
    thread_mutex_lock(&internals->mutex);
    internals->screen.mode = mode;
    memcpy(internals->screen.palette, default_palette, 1024);
    internals->conio.curs = true;
    switch (mode)
    {
    case videomode_40x25_8x8:
        internals->screen.width = 40;
        internals->screen.height = 25;
        internals->screen.font = font8x8;
        internals->screen.cellwidth = 8;
        internals->screen.cellheight = 8;
        break;
    case videomode_40x25_9x16:
        internals->screen.width = 40;
        internals->screen.height = 25;
        internals->screen.font = font9x16;
        internals->screen.cellwidth = 9;
        internals->screen.cellheight = 16;
        break;
    case videomode_80x25_8x8:
        internals->screen.width = 80;
        internals->screen.height = 25;
        internals->screen.font = font8x8;
        internals->screen.cellwidth = 8;
        internals->screen.cellheight = 8;
        break;
    case videomode_80x25_8x16:
        internals->screen.width = 80;
        internals->screen.height = 25;
        internals->screen.font = font8x16;
        internals->screen.cellwidth = 8;
        internals->screen.cellheight = 16;
        break;
    case videomode_80x25_9x16:
        internals->screen.width = 80;
        internals->screen.height = 25;
        internals->screen.font = font9x16;
        internals->screen.cellwidth = 9;
        internals->screen.cellheight = 16;
        break;
    case videomode_80x43_8x8:
        internals->screen.width = 80;
        internals->screen.height = 43;
        internals->screen.font = font8x8;
        internals->screen.cellwidth = 8;
        internals->screen.cellheight = 8;
        break;
    case videomode_80x50_8x8:
        internals->screen.width = 80;
        internals->screen.height = 50;
        internals->screen.font = font8x8;
        internals->screen.cellwidth = 8;
        internals->screen.cellheight = 8;
        break;
    case videomode_320x200:
        internals->screen.width = 320;
        internals->screen.height = 200;
        internals->screen.font = NULL;
        internals->screen.cellwidth = 1;
        internals->screen.cellheight = 1;
        break;
    case videomode_320x240:
        internals->screen.width = 320;
        internals->screen.height = 240;
        internals->screen.font = NULL;
        internals->screen.cellwidth = 1;
        internals->screen.cellheight = 1;
        break;
    case videomode_320x400:
        internals->screen.width = 320;
        internals->screen.height = 400;
        internals->screen.font = NULL;
        internals->screen.cellwidth = 1;
        internals->screen.cellheight = 1;
        break;
    case videomode_640x200:
        internals->screen.width = 640;
        internals->screen.height = 200;
        internals->screen.font = NULL;
        internals->screen.cellwidth = 1;
        internals->screen.cellheight = 1;
        break;
    case videomode_640x350:
        internals->screen.width = 640;
        internals->screen.height = 350;
        internals->screen.font = NULL;
        internals->screen.cellwidth = 1;
        internals->screen.cellheight = 1;
        break;
    case videomode_640x400:
        internals->screen.width = 640;
        internals->screen.height = 400;
        internals->screen.font = NULL;
        internals->screen.cellwidth = 1;
        internals->screen.cellheight = 1;
        break;
    case videomode_640x480:
        internals->screen.width = 640;
        internals->screen.height = 480;
        internals->screen.font = NULL;
        internals->screen.cellwidth = 1;
        internals->screen.cellheight = 1;
        break;
    default:
    {
        uint32_t custom_mode = (uint32_t)mode;
        internals->screen.width = ((custom_mode & 0xffc00) >> 10) + 1;
        internals->screen.height = (custom_mode & 0x003ff) + 1;
        if (custom_mode & 0x100000)
        {
            if (custom_mode & 0x200000)
            {
                internals->screen.font = font9x16;
                internals->screen.cellwidth = 9;
                internals->screen.cellheight = 16;
            }
            else
            {
                internals->screen.font = font8x8;
                internals->screen.cellwidth = 8;
                internals->screen.cellheight = 8;
            }
        }
        else
        {
            internals->screen.font = NULL;
            internals->screen.cellwidth = 1;
            internals->screen.cellheight = 1;
        }
    }
    }
    memset(internals->screen.buffer0, 0, internals->screen.width * internals->screen.height * (internals->screen.font ? 2 : 1));
    memset(internals->screen.buffer1, 0, internals->screen.width * internals->screen.height * (internals->screen.font ? 2 : 1));
    resetdrawtarget();
    thread_mutex_unlock(&internals->mutex);
};

int screenwidth(void)
{
    return internals->screen.width;
}

int screenheight(void)
{
    return internals->screen.height;
}

unsigned char *screenbuffer(void)
{
    return internals->screen.buffer;
}

void setdoublebuffer(int enabled)
{
    internals->screen.doublebuffer = (enabled != 0);
}

unsigned char *swapbuffers(void)
{
#ifdef __wasm__
    if (internals->wasm.swap_counts++ > 2)
    {
        // In WebAssembly without real threads, if a dos-like application never calls waitvbl
        // by itself, we force a call to it every few calls to swapbuffer
        waitvbl();
    }
#endif
    if (internals->screen.doublebuffer)
    {
        thread_mutex_lock(&internals->mutex);
        if (internals->screen.buffer == internals->screen.buffer0)
        {
            if (internals->draw.buffer == internals->screen.buffer)
            {
                internals->draw.buffer = internals->screen.buffer1;
            }
            internals->screen.buffer = internals->screen.buffer1;
        }
        else
        {
            if (internals->draw.buffer == internals->screen.buffer)
            {
                internals->draw.buffer = internals->screen.buffer0;
            }
            internals->screen.buffer = internals->screen.buffer0;
        }
        thread_mutex_unlock(&internals->mutex);
    }
    return internals->screen.buffer;
}

void setpal(int index, int r, int g, int b)
{
    if (index < 0 || index >= 256)
    {
        return;
    }

    r = (r & 63) << 2;
    g = (g & 63) << 2;
    b = (b & 63) << 2;
    internals->screen.palette[index] = (b << 16) | (g << 8) | (r);
}

void getpal(int index, int *r, int *g, int *b)
{
    if (index < 0 || index >= 256)
    {
        return;
    }

    uint32_t c = internals->screen.palette[index];
    uint32_t cr = (c) & 0xff;
    uint32_t cg = (c >> 8) & 0xff;
    uint32_t cb = (c >> 16) & 0xff;
    if (r)
    {
        *r = cr >> 2;
    }
    if (g)
    {
        *g = cg >> 2;
    }
    if (b)
    {
        *b = cb >> 2;
    }
}

int getpixel(int x, int y)
{
    if (internals->screen.font)
        return 0;
    if (x >= 0 && y >= 0 && x < internals->draw.width && y < internals->draw.height)
    {
        return internals->draw.buffer[x + internals->draw.width * y];
    }
    else
    {
        return 0;
    }
}

void putpixel(int x, int y, int color)
{
    if (internals->screen.font)
        return;
    if (x >= 0 && y >= 0 && x < internals->draw.width && y < internals->draw.height)
    {
        internals->draw.buffer[x + internals->draw.width * y] = (uint8_t)color;
    }
}

void setdrawtarget(unsigned char *pixels, int width, int height)
{
    if (internals->screen.font)
        return;
    internals->draw.buffer = pixels;
    internals->draw.width = width;
    internals->draw.height = height;
}

void resetdrawtarget(void)
{
    if (internals->screen.font)
        return;
    internals->draw.buffer = internals->screen.buffer;
    internals->draw.width = internals->screen.width;
    internals->draw.height = internals->screen.height;
}

void setcolor(int color)
{
    if (internals->screen.font)
        return;
    if (color >= 0 && color <= 255)
    {
        internals->graphics.color = color;
    }
}

int getcolor(void)
{
    if (internals->screen.font)
        return 0;
    return internals->graphics.color;
}

int installuserfont(char const *filename)
{
    if (internals->graphics.fonts_count >= sizeof(internals->graphics.fonts) / sizeof(*internals->graphics.fonts))
    {
        return 0;
    }
    FILE *fp = fopen(filename, "rb");
    if (!fp)
        return 0;
    fseek(fp, 0, SEEK_END);
    size_t sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint8_t *data = (uint8_t *)malloc(sz);
    fread(data, 1, sz, fp);
    fclose(fp);

    internals->graphics.fonts[internals->graphics.fonts_count] = (pixelfont_t *)data;

    return internals->graphics.fonts_count++;
}

void settextstyle(int font, int bold, int italic, int underline)
{
    if (internals->screen.font)
        return;
    if (font >= 1 && font < internals->graphics.fonts_count)
    {
        internals->graphics.current_font = font;
        internals->graphics.bold = bold;
        internals->graphics.italic = italic;
        internals->graphics.underline = underline;
    }
}

void wraptextxy(int x, int y, char const *text, int wrap_width)
{
    if (internals->screen.font)
        return;
    int color = internals->graphics.color;
    pixelfont_t *font = internals->graphics.fonts[internals->graphics.current_font];
    PIXELFONT_COLOR *target = internals->draw.buffer;
    int width = internals->draw.width;
    int height = internals->draw.height;
    pixelfont_align_t align = PIXELFONT_ALIGN_LEFT;
    int hspacing = 0;
    int vspacing = 0;
    int limit = -1;
    pixelfont_bold_t bold = internals->graphics.bold ? PIXELFONT_BOLD_ON : PIXELFONT_BOLD_OFF;
    pixelfont_italic_t italic = internals->graphics.italic ? PIXELFONT_ITALIC_ON : PIXELFONT_ITALIC_OFF;
    pixelfont_underline_t underline = internals->graphics.underline ? PIXELFONT_UNDERLINE_ON : PIXELFONT_UNDERLINE_OFF;

    pixelfont_blit(font, x, y, text, (PIXELFONT_COLOR)color, target, width, height, align, wrap_width, hspacing, vspacing, limit, bold,
                   italic, underline, NULL);
}

void centertextxy(int x, int y, char const *text, int wrap_width)
{
    if (internals->screen.font)
        return;
    int color = internals->graphics.color;
    pixelfont_t *font = internals->graphics.fonts[internals->graphics.current_font];
    PIXELFONT_COLOR *target = internals->draw.buffer;
    int width = internals->draw.width;
    int height = internals->draw.height;
    pixelfont_align_t align = PIXELFONT_ALIGN_CENTER;
    int hspacing = 0;
    int vspacing = 0;
    int limit = -1;
    pixelfont_bold_t bold = internals->graphics.bold ? PIXELFONT_BOLD_ON : PIXELFONT_BOLD_OFF;
    pixelfont_italic_t italic = internals->graphics.italic ? PIXELFONT_ITALIC_ON : PIXELFONT_ITALIC_OFF;
    pixelfont_underline_t underline = internals->graphics.underline ? PIXELFONT_UNDERLINE_ON : PIXELFONT_UNDERLINE_OFF;

    pixelfont_blit(font, x, y, text, (PIXELFONT_COLOR)color, target, width, height, align, wrap_width, hspacing, vspacing, limit, bold,
                   italic, underline, NULL);
}

void outtextxy(int x, int y, char const *text)
{
    if (internals->screen.font)
        return;
    int color = internals->graphics.color;
    pixelfont_t *font = internals->graphics.fonts[internals->graphics.current_font];
    PIXELFONT_COLOR *target = internals->draw.buffer;
    int width = internals->draw.width;
    int height = internals->draw.height;
    pixelfont_align_t align = PIXELFONT_ALIGN_LEFT;
    int wrap_width = 0;
    int hspacing = 0;
    int vspacing = 0;
    int limit = -1;
    pixelfont_bold_t bold = internals->graphics.bold ? PIXELFONT_BOLD_ON : PIXELFONT_BOLD_OFF;
    pixelfont_italic_t italic = internals->graphics.italic ? PIXELFONT_ITALIC_ON : PIXELFONT_ITALIC_OFF;
    pixelfont_underline_t underline = internals->graphics.underline ? PIXELFONT_UNDERLINE_ON : PIXELFONT_UNDERLINE_OFF;

    pixelfont_blit(font, x, y, text, (PIXELFONT_COLOR)color, target, width, height, align, wrap_width, hspacing, vspacing, limit, bold,
                   italic, underline, NULL);
}

void waitvbl(void)
{
    if (thread_atomic_int_load(&internals->exit_flag) == 0)
    {
#ifndef __wasm__
        int current_vbl_count = thread_atomic_int_load(&internals->vbl.count);
        while (current_vbl_count == thread_atomic_int_load(&internals->vbl.count))
        {
            thread_signal_wait(&internals->vbl.signal, 1000);
        }
#else
        WaCoroSwitch(0);
        internals->wasm.swap_counts = internals->wasm.read_counts = 0;
#endif
    }
}

static void signalvbl(void)
{
    thread_atomic_int_inc(&internals->vbl.count);
    thread_signal_raise(&internals->vbl.signal);
#ifdef __wasm__
    WaCoroSwitch(internals->wasm.user_coro);
#endif
}

void clearscreen(void)
{
    memset(internals->screen.buffer, 0, internals->screen.width * internals->screen.height * (internals->screen.font ? 2 : 1));
}

static bool blitclip(int *px, int *py, int width, int height, int *psrcx, int *psrcy, int *psrcw, int *psrch)
{
    int x = *px;
    int y = *py;
    int srcx = *psrcx;
    int srcy = *psrcy;
    int srcw = *psrcw;
    int srch = *psrch;
    if (x < 0)
    {
        srcx -= x;
        srcw += x;
        x = 0;
    }
    if (y < 0)
    {
        srcy -= y;
        srch += y;
        y = 0;
    }
    if (srcx < 0)
    {
        x += srcx;
        srcw += srcx;
        srcx = 0;
    }
    if (srcy < 0)
    {
        y += srcy;
        srch += srcy;
        srcy = 0;
    }
    if (srcx + srcw >= width)
    {
        srcw += (width - (srcx + srcw));
    }
    if (srcy + srch >= height)
    {
        srch += (height - (srcy + srch));
    }
    if (x + srcw >= internals->draw.width)
    {
        srcw += (internals->draw.width - (x + srcw));
    }
    if (y + srch >= internals->draw.height)
    {
        srch += (internals->draw.height - (y + srch));
    }
    if (srcw <= 0 || srch <= 0 || x + srcw < 0 || y + srch < 0 || x > internals->draw.width || y > internals->draw.height)
    {
        return false;
    }
    else
    {
        *px = x;
        *py = y;
        *psrcx = srcx;
        *psrcy = srcy;
        *psrcw = srcw;
        *psrch = srch;
        return true;
    }
}

void blit(int x, int y, unsigned char *source, int width, int height, int srcx, int srcy, int srcw, int srch)
{
    if (internals->screen.font)
        return;
    if (!blitclip(&x, &y, width, height, &srcx, &srcy, &srcw, &srch))
    {
        return;
    }

    uint8_t *dst = internals->draw.buffer + x + y * internals->draw.width;
    uint8_t *src = source + srcx + srcy * width;
    for (int iy = 0; iy < srch; ++iy)
    {
        memcpy(dst, src, srcw);
        src += width;
        dst += internals->draw.width;
    }
}

void maskblit(int x, int y, unsigned char *source, int width, int height, int srcx, int srcy, int srcw, int srch, int colorkey)
{
    if (internals->screen.font)
        return;
    if (!blitclip(&x, &y, width, height, &srcx, &srcy, &srcw, &srch))
    {
        return;
    }

    uint8_t *dst = internals->draw.buffer + x + y * internals->draw.width;
    uint8_t *src = source + srcx + srcy * width;
    for (int iy = 0; iy < srch; ++iy)
    {
        for (int ix = 0; ix < srcw; ++ix)
        {
            if (src[ix] != colorkey)
            {
                dst[ix] = src[ix];
            }
        }
        src += width;
        dst += internals->draw.width;
    }
}

struct gif_load_context_t
{
    int width;
    int height;
    uint8_t *pixels;
    int palcount;
    uint8_t palette[768];
};

static void load_gif_frame(void *data, struct GIF_WHDR *whdr)
{
    struct gif_load_context_t *context = (struct gif_load_context_t *)data;
    if (context->pixels)
    {
        return;
    }
    context->width = whdr->xdim;
    context->height = whdr->ydim;
    context->palcount = whdr->clrs;
    memcpy(context->palette, whdr->cpal, whdr->clrs * 3);
    context->pixels = (uint8_t *)malloc(whdr->xdim * whdr->ydim);
    memset(context->pixels, 0, whdr->xdim * whdr->ydim);

    uint32_t ddst = (uint32_t)(whdr->xdim * whdr->fryo + whdr->frxo);
    uint32_t iter = (whdr->intr) ? 0 : 4;
    uint32_t ifin = (!iter) ? 4 : 5; // interlacing support
    for (uint32_t dsrc = (uint32_t)-1; iter < ifin; ++iter)
    {
        for (uint32_t yoff = 16U >> ((iter > 1) ? iter : 1), y = (8 >> iter) & 7;
             y < (uint32_t)whdr->fryd; y += yoff)
        {
            for (uint32_t x = 0; x < (uint32_t)whdr->frxd; x++)
            {
                if (whdr->tran != (long)whdr->bptr[++dsrc])
                {
                    context->pixels[(uint32_t)whdr->xdim * y + x + ddst] = whdr->bptr[dsrc];
                }
            }
        }
    }
}

unsigned char *loadgif(char const *filename, int *width, int *height, int *palcount, unsigned char palette[768])
{
    FILE *fp = fopen(filename, "rb");
    if (!fp)
        return NULL;
    fseek(fp, 0, SEEK_END);
    size_t sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint8_t *data = (uint8_t *)malloc(sz);
    fread(data, 1, sz, fp);
    fclose(fp);

    struct gif_load_context_t context;
    memset(&context, 0, sizeof(context));
    GIF_Load(data, (long)sz, load_gif_frame, NULL, &context, 0);
    free(data);

    if (width)
    {
        *width = context.width;
    }

    if (height)
    {
        *height = context.height;
    }

    if (palcount)
    {
        *palcount = context.palcount;
    }

    if (palette)
    {
        for (int i = 0; i < context.palcount * 3; ++i)
        {
            palette[i] = context.palette[i] >> 2;
        }
    }
    return context.pixels;
}

void hline(int x, int y, int len, int color)
{
    if (internals->screen.font)
        return;
    if (y < 0 || y >= internals->draw.height)
    {
        return;
    }
    if (x < 0)
    {
        len += x;
        x = 0;
    }
    if (x + len > internals->draw.width)
    {
        len = internals->draw.width - x;
    }
    uint8_t *scr = internals->draw.buffer + y * internals->draw.width + x;
    uint8_t *end = scr + len;
    while (scr < end)
        *scr++ = (uint8_t)color;
}

void line(int x1, int y1, int x2, int y2)
{
    if (internals->screen.font)
        return;
    int color = internals->graphics.color;
    int dx = x2 - x1;
    dx = dx < 0 ? -dx : dx;
    int sx = x1 < x2 ? 1 : -1;
    int dy = y2 - y1;
    dy = dy < 0 ? -dy : dy;
    int sy = y1 < y2 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int x = x1;
    int y = y1;
    while (x != x2 || y != y2)
    {
        putpixel(x, y, color);
        int e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y += sy;
        }
    }
    putpixel(x, y, color);
}

void rectangle(int x, int y, int w, int h)
{
    if (internals->screen.font)
        return;
    int color = internals->graphics.color;
    hline(x, y, w, color);
    hline(x, y + h, w, color);
    line(x, y, x, y + h);
    line(x + w - 1, y, x + w - 1, y + h);
}

void bar(int x, int y, int w, int h)
{
    if (internals->screen.font)
        return;
    int color = internals->graphics.color;
    for (int i = y; i < y + h; ++i)
    {
        hline(x, i, w, color);
    }
}

void circle(int x, int y, int r)
{
    if (internals->screen.font)
        return;
    int color = internals->graphics.color;
    int f = 1 - r;
    int dx = 0;
    int dy = -2 * r;
    int ix = 0;
    int iy = r;

    putpixel(x, y + r, color);
    putpixel(x, y - r, color);
    putpixel(x + r, y, color);
    putpixel(x - r, y, color);

    while (ix < iy)
    {
        if (f >= 0)
        {
            --iy;
            dy += 2;
            f += dy;
        }
        ++ix;
        dx += 2;
        f += dx + 1;

        putpixel(x + ix, y + iy, color);
        putpixel(x - ix, y + iy, color);
        putpixel(x + ix, y - iy, color);
        putpixel(x - ix, y - iy, color);
        putpixel(x + iy, y + ix, color);
        putpixel(x - iy, y + ix, color);
        putpixel(x + iy, y - ix, color);
        putpixel(x - iy, y - ix, color);
    }
}

void fillcircle(int x, int y, int r)
{
    if (internals->screen.font)
        return;
    int color = internals->graphics.color;
    int f = 1 - r;
    int dx = 0;
    int dy = -2 * r;
    int ix = 0;
    int iy = r;

    while (ix <= iy)
    {
        hline(x - iy, y + ix, 2 * iy, color);
        hline(x - iy, y - ix, 2 * iy, color);
        if (f >= 0)
        {
            hline(x - ix, y + iy, 2 * ix, color);
            hline(x - ix, y - iy, 2 * ix, color);

            --iy;
            dy += 2;
            f += dy;
        }
        ++ix;
        dx += 2;
        f += dx + 1;
    }
}

void ellipse(int x, int y, int rx, int ry)
{
    if (internals->screen.font)
        return;
    int color = internals->graphics.color;
    int asq = rx * rx;
    int bsq = ry * ry;

    putpixel(x, y + ry, color);
    putpixel(x, y - ry, color);

    int wx = 0;
    int wy = ry;
    int xa = 0;
    int ya = asq * 2 * ry;
    int thresh = asq / 4 - asq * ry;

    for (;;)
    {
        thresh += xa + bsq;

        if (thresh >= 0)
        {
            ya -= asq * 2;
            thresh -= ya;
            --wy;
        }

        xa += bsq * 2;
        ++wx;

        if (xa >= ya)
        {
            break;
        }

        putpixel(x + wx, y - wy, color);
        putpixel(x - wx, y - wy, color);
        putpixel(x + wx, y + wy, color);
        putpixel(x - wx, y + wy, color);
    }

    putpixel(x + rx, y, color);
    putpixel(x - rx, y, color);

    wx = rx;
    wy = 0;
    xa = bsq * 2 * rx;

    ya = 0;
    thresh = bsq / 4 - bsq * rx;

    for (;;)
    {
        thresh += ya + asq;

        if (thresh >= 0)
        {
            xa -= bsq * 2;
            thresh = thresh - xa;
            --wx;
        }

        ya += asq * 2;
        ++wy;

        if (ya > xa)
        {
            break;
        }

        putpixel(x + wx, y - wy, color);
        putpixel(x - wx, y - wy, color);
        putpixel(x + wx, y + wy, color);
        putpixel(x - wx, y + wy, color);
    }
}

void fillellipse(int x, int y, int rx, int ry)
{
    if (internals->screen.font)
        return;
    int color = internals->graphics.color;
    int asq = rx * rx;
    int bsq = ry * ry;

    int wx = 0;
    int wy = ry;
    int xa = 0;
    int ya = asq * 2 * ry;
    int thresh = asq / 4 - asq * ry;

    for (;;)
    {
        thresh += xa + bsq;

        if (thresh >= 0)
        {
            ya -= asq * 2;
            thresh -= ya;
            hline(x - wx, y - wy, wx * 2, color);
            hline(x - wx, y + wy, wx * 2, color);
            --wy;
        }

        xa += bsq * 2;
        ++wx;
        if (xa >= ya)
        {
            break;
        }
    }

    hline(x - rx, y, rx * 2, color);

    wx = rx;
    wy = 0;
    xa = bsq * 2 * rx;

    ya = 0;
    thresh = bsq / 4 - bsq * rx;

    for (;;)
    {
        thresh += ya + asq;

        if (thresh >= 0)
        {
            xa -= bsq * 2;
            thresh = thresh - xa;
            --wx;
        }

        ya += asq * 2;
        ++wy;

        if (ya > xa)
        {
            break;
        }

        hline(x - wx, y - wy, wx * 2, color);
        hline(x - wx, y + wy, wx * 2, color);
    }
}

void drawpoly(int *points_xy, int count)
{
    if (internals->screen.font)
        return;
    for (int i = 0; i < count - 1; ++i)
    {
        line(points_xy[i * 2 + 0], points_xy[i * 2 + 1],
             points_xy[(i + 1) * 2 + 0], points_xy[(i + 1) * 2 + 1]);
    }
}

void fillpoly(int *points_xy, int count)
{
#define MAX_POLYGON_POINTS 256
    static int node_x[MAX_POLYGON_POINTS];

    if (internals->screen.font)
        return;

    if (count <= 0 || count > MAX_POLYGON_POINTS)
    {
        return;
    }

    int color = internals->graphics.color;

    int min_y = points_xy[0 + 1];
    int max_y = min_y;

    // find extents
    for (int i = 1; i < count; ++i)
    {
        if (points_xy[i * 2 + 1] < min_y)
            min_y = points_xy[i * 2 + 1];
        if (points_xy[i * 2 + 1] > max_y)
            max_y = points_xy[i * 2 + 1];
    }

    for (int y = min_y; y < max_y; ++y)
    {
        //  find intersection points_xy
        int nodes = 0;
        int j = count - 1;
        for (int i = 0; i < count; ++i)
        {
            if ((points_xy[i * 2 + 1] <= y && points_xy[j * 2 + 1] > y) ||
                (points_xy[j * 2 + 1] <= y && points_xy[i * 2 + 1] > y))
            {

                int dx = points_xy[j * 2 + 0] - points_xy[i * 2 + 0];
                int dy = points_xy[j * 2 + 1] - points_xy[i * 2 + 1];
                node_x[nodes++] = points_xy[i * 2 + 0] + ((y - points_xy[i * 2 + 1]) * dx) / dy;
            }
            j = i;
        }

        // sort by x
        int xi = 0;
        while (xi < nodes - 1)
        {
            if (node_x[xi] > node_x[xi + 1])
            {
                int swap = node_x[xi];
                node_x[xi] = node_x[xi + 1];
                node_x[xi + 1] = swap;
                if (xi)
                    --xi;
            }
            else
            {
                ++xi;
            }
        }

        for (int i = 0; i < nodes; i += 2)
        {
            hline(node_x[i], y, node_x[i + 1] - node_x[i], color);
        }
    }
}

/*
 * A Seed Fill Algorithm
 * by Paul Heckbert
 * from "Graphics Gems", Academic Press, 1990
 *
 * user provides pixelread() and pixelwrite() routines
 *
 * fill.c : simple seed fill program
 * Calls pixelread() to read pixels, pixelwrite() to write pixels.
 *
 * Paul Heckbert	13 Sept 1982, 28 Jan 1987
 *
 * fill: set the pixel at (x,y) and all of its 4-connected neighbors
 * with the same pixel value to the new pixel value nv.
 * A 4-connected neighbor is a pixel above, below, left, or right of a pixel.
 *
 * LICENSE
 * The Graphics Gems code is copyright-protected. In other words, you cannot
 * claim the text of the code as your own and resell it. Using the code is
 * permitted in any program, product, or library, non-commercial or commercial.
 * Giving credit is not required, though is a nice gesture. The code comes
 * as-is, and if there are any flaws or problems with any Gems code, nobody
 * involved with Gems - authors, editors, publishers, or webmasters - are to be
 * held responsible. Basically, don't be a jerk, and remember that anything
 * free comes with no guarantee.
 */

void floodfill(int x, int y)
{
#define FILLMAX 10000 /* FILLMAX depth of stack */

#define FILLPUSH(Y, XL, XR, DY) /* FILLPUSH new segment on stack */                 \
    if (sp < stack + FILLMAX && Y + (DY) >= 0 && Y + (DY) < internals->draw.height) \
    {                                                                               \
        sp->y = Y;                                                                  \
        sp->xl = XL;                                                                \
        sp->xr = XR;                                                                \
        sp->dy = DY;                                                                \
        ++sp;                                                                       \
    }

#define FILLPOP(Y, XL, XR, DY) /* FILLPOP segment off stack */ \
    {                                                          \
        --sp;                                                  \
        Y = sp->y + (DY = sp->dy);                             \
        XL = sp->xl;                                           \
        XR = sp->xr;                                           \
    }

    if (internals->screen.font)
        return;
    int color = internals->graphics.color;

    /*
     * Filled horizontal segment of scanline y for xl<=x<=xr.
     * Parent segment was on line y-dy.  dy=1 or -1
     */
    struct segment_t
    {
        int y, xl, xr, dy;
    };

    int l, x1, x2, dy;
    int ov;                                       /* old pixel value */
    struct segment_t stack[FILLMAX], *sp = stack; /* stack of filled segments */

    ov = getpixel(x, y); /* read pv at seed point */
    if (ov == color || x < 0 || x >= internals->draw.width || y < 0 || y >= internals->draw.height)
        return;
    FILLPUSH(y, x, x, 1);      /* needed in some cases */
    FILLPUSH(y + 1, x, x, -1); /* seed segment (FILLPOPped 1st) */

    while (sp > stack)
    {
        /* FILLPOP segment off stack and fill a neighboring scan line */
        FILLPOP(y, x1, x2, dy);
        /*
         * segment of scan line y-dy for x1<=x<=x2 was previously filled,
         * now explore adjacent pixels in scan line y
         */
        int xs;
        for (x = x1; x >= 0 && getpixel(x, y) == ov; --x) /* nothing */
            ;
        hline(x + 1, y, x1 - x, color);
        if (x >= x1)
            goto skip;
        l = x + 1;
        if (l < x1)
            FILLPUSH(y, l, x1 - 1, -dy); /* leak on left? */
        x = x1 + 1;
        do
        {
            xs = x;
            for (; x < internals->draw.width && getpixel(x, y) == ov; ++x) /* nothing */
                ;
            hline(xs, y, x - xs, color);
            FILLPUSH(y, l, x - 1, dy);
            if (x > x2 + 1)
                FILLPUSH(y, x2 + 1, x - 1, -dy); /* leak on right? */
        skip:
            for (x++; x <= x2 && getpixel(x, y) != ov; ++x)
                ;
            l = x;
        } while (x <= x2);
    }

#undef FILLMAX
}

void boundaryfill(int x, int y, int boundary)
{
#define FILLMAX 10000 /* FILLMAX depth of stack */

#define FILLPUSH(Y, XL, XR, DY) /* FILLPUSH new segment on stack */                 \
    if (sp < stack + FILLMAX && Y + (DY) >= 0 && Y + (DY) < internals->draw.height) \
    {                                                                               \
        sp->y = Y;                                                                  \
        sp->xl = XL;                                                                \
        sp->xr = XR;                                                                \
        sp->dy = DY;                                                                \
        ++sp;                                                                       \
    }

#define FILLPOP(Y, XL, XR, DY) /* FILLPOP segment off stack */ \
    {                                                          \
        --sp;                                                  \
        Y = sp->y + (DY = sp->dy);                             \
        XL = sp->xl;                                           \
        XR = sp->xr;                                           \
    }

    if (internals->screen.font)
        return;
    int color = internals->graphics.color;

    /*
     * Filled horizontal segment of scanline y for xl<=x<=xr.
     * Parent segment was on line y-dy.  dy=1 or -1
     */
    struct segment_t
    {
        int y, xl, xr, dy;
    };

    int l, x1, x2, dy;
    int ov;                                       /* old pixel value */
    struct segment_t stack[FILLMAX], *sp = stack; /* stack of filled segments */

    ov = boundary;
    if (x < 0 || x >= internals->draw.width || y < 0 || y >= internals->draw.height)
        return;
    FILLPUSH(y, x, x, 1);      /* needed in some cases */
    FILLPUSH(y + 1, x, x, -1); /* seed segment (FILLPOPped 1st) */

    while (sp > stack)
    {
        /* FILLPOP segment off stack and fill a neighboring scan line */
        FILLPOP(y, x1, x2, dy);
        /*
         * segment of scan line y-dy for x1<=x<=x2 was previously filled,
         * now explore adjacent pixels in scan line y
         */
        int xs;
        for (x = x1; x >= 0 && getpixel(x, y) != ov; --x) /* nothing */
            ;
        hline(x + 1, y, x1 - x, color);
        if (x >= x1)
            goto skip;
        l = x + 1;
        if (l < x1)
            FILLPUSH(y, l, x1 - 1, -dy); /* leak on left? */
        x = x1 + 1;
        do
        {
            xs = x;
            for (; x < internals->draw.width && getpixel(x, y) != ov; ++x) /* nothing */
                ;
            hline(xs, y, x - xs, color);
            FILLPUSH(y, l, x - 1, dy);
            if (x > x2 + 1)
                FILLPUSH(y, x2 + 1, x - 1, -dy); /* leak on right? */
        skip:
            for (x++; x <= x2 && getpixel(x, y) == ov; ++x)
                ;
            l = x;
        } while (x <= x2);
    }

#undef FILLMAX
}

void cputs(char const *string)
{
    if (!internals->screen.font)
        return;

    while (*string)
    {
        if (internals->conio.y >= internals->screen.height)
            break;

        uint16_t ch = (uint16_t)(unsigned char)*string;
        ch |= (internals->conio.fg & 0xf) << 8;
        ch |= (internals->conio.bg & 0xf) << 12;

        ((uint16_t *)internals->screen.buffer)[internals->conio.x + internals->conio.y * internals->screen.width] = ch;

        ++internals->conio.x;
        if (internals->conio.x >= internals->screen.width)
        {
            if (internals->conio.y < internals->screen.height - 1)
            {
                ++internals->conio.y;
            }
            else
            {
                --internals->conio.x;
                break;
            }
            internals->conio.x = 0;
        }

        ++string;
    }
}

void curson(void)
{
    if (!internals->screen.font)
        return;
    internals->conio.curs = 1;
}

void cursoff(void)
{
    if (!internals->screen.font)
        return;
    internals->conio.curs = 0;
}

void gotoxy(int x, int y)
{
    if (!internals->screen.font)
        return;
    internals->conio.x = x;
    internals->conio.y = y;
}

int wherex(void)
{
    if (!internals->screen.font)
        return 0;
    return internals->conio.x;
}

int wherey(void)
{
    if (!internals->screen.font)
        return 0;
    return internals->conio.y;
}

void textcolor(int color)
{
    if (!internals->screen.font)
        return;
    internals->conio.fg = color < 0 ? 0 : color > 15 ? 15
                                                     : color;
}

void textbackground(int color)
{
    if (!internals->screen.font)
        return;
    internals->conio.bg = color < 0 ? 0 : color > 15 ? 15
                                                     : color;
}

void clrscr(void)
{
    if (!internals->screen.font)
        return;
    uint16_t *p = ((uint16_t *)internals->screen.buffer);
    uint16_t c = (uint16_t)' ';
    c |= (internals->conio.fg & 0xf) << 8;
    c |= (internals->conio.bg & 0xf) << 12;
    for (int y = 0; y < screenheight(); ++y)
    {
        for (int x = 0; x < screenwidth(); ++x)
        {
            *p++ = c;
        }
    }
}

int keystate(enum keycode_t key)
{
    int index = (int)key;
    if (index >= 0 && index < KEYCOUNT)
    {
        return internals->input.keystate[index];
    }
    return false;
}

enum keycode_t *readkeys(void)
{
#ifdef __wasm__
    if (internals->wasm.read_counts++ > 100)
    {
        // In WebAssembly without real threads, if a dos-like application never calls waitvbl
        // by itself, we force a call to it every 100 calls to readkeys/readchars
        waitvbl();
    }
#endif
    thread_mutex_lock(&internals->mutex);
    memset(internals->input.keybuffer, 0, sizeof(internals->input.keybuffer0));
    if (internals->input.keybuffer == internals->input.keybuffer0)
    {
        internals->input.keybuffer = internals->input.keybuffer1;
    }
    else
    {
        internals->input.keybuffer = internals->input.keybuffer0;
    }
    thread_mutex_unlock(&internals->mutex);
    return internals->input.keybuffer;
};

char const *readchars(void)
{
#ifdef __wasm__
    if (internals->wasm.read_counts++ > 100)
    {
        // In WebAssembly without real threads, if a dos-like application never calls waitvbl
        // by itself, we force a call to it every 100 calls to readkeys/readchars
        waitvbl();
    }
#endif
    thread_mutex_lock(&internals->mutex);
    memset(internals->input.charbuffer, 0, sizeof(internals->input.charbuffer0));
    if (internals->input.charbuffer == internals->input.charbuffer0)
    {
        internals->input.charbuffer = internals->input.charbuffer1;
    }
    else
    {
        internals->input.charbuffer = internals->input.charbuffer0;
    }
    thread_mutex_unlock(&internals->mutex);
    return internals->input.charbuffer;
}

int mousex(void)
{
    return internals->input.mouse_x;
}

int mousey(void)
{
    return internals->input.mouse_y;
}

int mouserelx(void)
{
    return internals->input.mouse_relx;
}

int mouserely(void)
{
    return internals->input.mouse_rely;
}

void setsoundbank(int soundbank)
{
    if (soundbank >= 1 && soundbank < internals->audio.soundbanks_count)
    {
        internals->audio.current_soundbank = soundbank;
    }
}

int installusersoundbank(char const *filename)
{
    if (internals->audio.soundbanks_count >= sizeof(internals->audio.soundbanks) / sizeof(*internals->audio.soundbanks))
    {
        return 0;
    }
    char const *pext = strrchr(filename, '.');
    if (!pext || strlen(pext) != 4)
        return 0;
    char ext[4] = {0};
    memcpy(ext, pext + 1, 3);
    ext[0] = (char)tolower(ext[0]);
    ext[1] = (char)tolower(ext[1]);
    ext[2] = (char)tolower(ext[2]);
    enum soundbank_type_t type = SOUNDBANK_TYPE_NONE;
    if (strcmp(ext, "sf2") == 0)
    {
        type = SOUNDBANK_TYPE_SF2;
        //} else if( strcmp( ext, "ibk" ) == 0 ) {
        //    type = SOUNDBANK_TYPE_IBK;
    }
    else if (strcmp(ext, "op2") == 0)
    {
        type = SOUNDBANK_TYPE_OP2;
    }
    if (type == SOUNDBANK_TYPE_NONE)
        return 0;

    FILE *fp = fopen(filename, "rb");
    if (!fp)
        return 0;
    fseek(fp, 0, SEEK_END);
    size_t sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    void *data = malloc(sz);
    fread(data, 1, sz, fp);
    fclose(fp);

    internals->audio.soundbanks[internals->audio.soundbanks_count].type = type;
    if (type == SOUNDBANK_TYPE_SF2)
    {
        internals->audio.soundbanks[internals->audio.soundbanks_count].sf2 = tsf_load_memory(data, (int)sz);
        internals->audio.soundbanks[internals->audio.soundbanks_count].data = NULL;
        internals->audio.soundbanks[internals->audio.soundbanks_count].size = 0;
        free(data);
    }
    else
    {
        internals->audio.soundbanks[internals->audio.soundbanks_count].sf2 = NULL;
        internals->audio.soundbanks[internals->audio.soundbanks_count].data = data;
        internals->audio.soundbanks[internals->audio.soundbanks_count].size = sz;
    }

    return internals->audio.soundbanks_count++;
}

static void load_default_sf2(void)
{
    // Delay loading of built-in soundfont until first used
    // This also allows the linker to not include the entire large sf2 file if this function is not used
    if (!internals->audio.soundbanks[DEFAULT_SOUNDBANK_AWE32].sf2)
    {
        internals->audio.soundbanks[DEFAULT_SOUNDBANK_AWE32].sf2 = tsf_load_memory(awe32rom, sizeof(awe32rom));
        if (internals->audio.current_soundbank == DEFAULT_SOUNDBANK_NONE)
        {
            setsoundbank(DEFAULT_SOUNDBANK_AWE32);
        }
    }
}

void noteon(int channel, int note, int velocity)
{
    load_default_sf2();
    if (channel < 0 || channel > MUSIC_CHANNELS || note < 0 || note > 127 || velocity < 0 || velocity > 127)
        return;
    struct audio_command_t command;
    command.type = AUDIO_COMMAND_NOTE_ON;
    command.channel = channel;
    command.note = note;
    command.velocity = velocity;

    thread_mutex_lock(&internals->mutex);
    command.frame_stamp = internals->audio.frame_stamp;
    if (internals->audio.commands_count < sizeof(internals->audio.commands) / sizeof(*internals->audio.commands))
    {
        internals->audio.commands[internals->audio.commands_count++] = command;
    }
    thread_mutex_unlock(&internals->mutex);
}

void noteoff(int channel, int note)
{
    load_default_sf2();
    if (channel < 0 || channel > MUSIC_CHANNELS || note < 0 || note > 127)
        return;
    struct audio_command_t command;
    command.type = AUDIO_COMMAND_NOTE_OFF;
    command.channel = channel;
    command.note = note;

    thread_mutex_lock(&internals->mutex);
    command.frame_stamp = internals->audio.frame_stamp;
    if (internals->audio.commands_count < sizeof(internals->audio.commands) / sizeof(*internals->audio.commands))
    {
        internals->audio.commands[internals->audio.commands_count++] = command;
    }
    thread_mutex_unlock(&internals->mutex);
}

void allnotesoff(int channel)
{
    load_default_sf2();
    if (channel < 0 || channel > MUSIC_CHANNELS)
        return;
    struct audio_command_t command;
    command.type = AUDIO_COMMAND_NOTE_OFF_ALL;
    command.channel = channel;

    thread_mutex_lock(&internals->mutex);
    command.frame_stamp = internals->audio.frame_stamp;
    if (internals->audio.commands_count < sizeof(internals->audio.commands) / sizeof(*internals->audio.commands))
    {
        internals->audio.commands[internals->audio.commands_count++] = command;
    }
    thread_mutex_unlock(&internals->mutex);
}

void setinstrument(int channel, int instrument)
{
    load_default_sf2();
    if (channel < 0 || channel > MUSIC_CHANNELS || instrument < 0 || instrument > 128)
        return;
    struct audio_command_t command;
    command.type = AUDIO_COMMAND_SET_INSTRUMENT;
    command.channel = channel;
    command.instrument = instrument;

    thread_mutex_lock(&internals->mutex);
    command.frame_stamp = internals->audio.frame_stamp;
    if (internals->audio.commands_count < sizeof(internals->audio.commands) / sizeof(*internals->audio.commands))
    {
        internals->audio.commands[internals->audio.commands_count++] = command;
    }
    thread_mutex_unlock(&internals->mutex);
}

enum music_format_t
{
    MUSIC_FORMAT_MID,
    MUSIC_FORMAT_MUS,
    MUSIC_FORMAT_MOD,
    MUSIC_FORMAT_OPB,
};

struct music_t
{
    enum music_format_t format;
};

void *tml_mus_custom_malloc(size_t size)
{
    struct music_t *data = (struct music_t *)malloc(size + sizeof(struct music_t));
    return (void *)(data + 1);
}

void *tml_mus_custom_realloc(void *ptr, size_t size)
{
    ptr = ptr ? (void *)(((struct music_t *)ptr) - 1) : NULL;
    struct music_t *data = (struct music_t *)realloc(ptr, size + sizeof(struct music_t));
    return (void *)(data + 1);
}

void tml_mus_custom_free(void *ptr)
{
    ptr = ptr ? (void *)(((struct music_t *)ptr) - 1) : NULL;
    free(ptr);
}

struct music_t *loadmid(char const *filename)
{
    load_default_sf2();
    tml_message *mid = tml_load_filename(filename);
    if (!mid)
        return NULL;
    struct music_t *music = ((struct music_t *)mid) - 1;
    music->format = MUSIC_FORMAT_MID;
    return music;
}

struct music_t *loadmus(char const *filename)
{
    load_default_sf2();
    FILE *fp = fopen(filename, "rb");
    if (!fp)
        return NULL;
    fseek(fp, 0, SEEK_END);
    size_t sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint8_t *data = (uint8_t *)malloc(sz);
    fread(data, 1, sz, fp);
    fclose(fp);
    if (!data)
        return NULL;
    mus_t *mus = mus_create(data, sz, NULL);
    free(data);
    if (!mus)
        return NULL;
    struct music_t *music = ((struct music_t *)mus) - 1;
    music->format = MUSIC_FORMAT_MUS;
    return music;
}

struct music_t *createmus(void *data, int size)
{
    load_default_sf2();
    mus_t *mus = mus_create(data, size, NULL);
    if (!mus)
        return NULL;
    struct music_t *music = ((struct music_t *)mus) - 1;
    music->format = MUSIC_FORMAT_MUS;
    return music;
}

struct music_t *loadmod(char const *filename)
{

    FILE *fp = fopen(filename, "rb");
    if (!fp)
        return NULL;
    fseek(fp, 0, SEEK_END);
    size_t sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    uint8_t *data = (uint8_t *)malloc(sz + sizeof(struct music_t) + sizeof(jar_mod_context_t));
    uint8_t *file = data + sizeof(struct music_t) + sizeof(jar_mod_context_t);
    fread(file, 1, sz, fp);
    fclose(fp);
    if (!data)
        return NULL;
    struct music_t *music = (struct music_t *)data;
    music->format = MUSIC_FORMAT_MOD;
    jar_mod_context_t *modctx = (jar_mod_context_t *)(music + 1);
    if (!jar_mod_init(modctx) || !jar_mod_load(modctx, (void *)file, (int)sz))
    {
        free(data);
        return NULL;
    }
    modctx->modfile = (muchar *)file;
    modctx->modfilesize = (int)sz;
    return music;
}

struct opb_context_t
{
    OPB_Command *commands;
    int capacity;
    int count;
};

int opb_callback(OPB_Command *commands, size_t count, void *user_data)
{
    struct opb_context_t *context = (struct opb_context_t *)user_data;
    if (context->count + (int)count > context->capacity)
    {
        context->capacity = context->count + (int)count > context->capacity * 2 ? context->count + (int)count : context->capacity * 2;
        context->commands = (OPB_Command *)realloc(context->commands, sizeof(OPB_Command) * context->capacity);
    }
    memcpy(context->commands + context->count, commands, sizeof(OPB_Command) * count);
    context->count += (int)count;
    return 0;
}

struct opb_t
{
    int position;
    double accumulated_time;
    int commands_count;
    OPB_Command commands[1];
};

struct music_t *loadopb(char const *filename)
{
    struct opb_context_t context;
    context.count = 0;
    context.capacity = 4096;
    context.commands = (OPB_Command *)malloc(sizeof(OPB_Command) * context.capacity);

    int res = OPB_FileToOpl(filename, opb_callback, &context);

    if (res != 0 || context.count == 0)
    {
        free(context.commands);
        return NULL;
    }

    struct music_t *music = (struct music_t *)malloc(sizeof(struct music_t) + sizeof(struct opb_t) + sizeof(OPB_Command) * (context.count - 1));
    struct opb_t *opb = (struct opb_t *)(music + 1);
    music->format = MUSIC_FORMAT_OPB;
    opb->position = 0;
    opb->accumulated_time = 0.0;
    opb->commands_count = context.count;
    memcpy(opb->commands, context.commands, sizeof(OPB_Command) * context.count);
    free(context.commands);
    return music;
}

void playmusic(struct music_t *music, int loop, int volume)
{
    if (!music)
        return;
    if (volume < 0)
        volume = 0;
    if (volume > 255)
        volume = 255;
    thread_mutex_lock(&internals->mutex);
    internals->audio.current_music = music;
    internals->audio.loop_music = loop;
    internals->audio.music_volume = volume;
    internals->audio.music_play_counter++;
    thread_mutex_unlock(&internals->mutex);
}

void stopmusic(void)
{
    thread_mutex_lock(&internals->mutex);
    internals->audio.current_music = NULL;
    thread_mutex_unlock(&internals->mutex);
}

int musicplaying(void)
{
    return internals->audio.current_music != NULL;
}

void musicvolume(int volume)
{
    if (volume < 0)
        volume = 0;
    if (volume > 255)
        volume = 255;
    thread_mutex_lock(&internals->mutex);
    internals->audio.music_volume = volume;
    thread_mutex_unlock(&internals->mutex);
}

void setsoundmode(enum soundmode_t mode)
{
    thread_mutex_lock(&internals->mutex);
    internals->audio.soundmode = mode;
    thread_mutex_unlock(&internals->mutex);
};

struct sound_t
{
    int channels;
    int samplerate;
    int framecount;
};

void *wav_custom_malloc(size_t size)
{
    struct sound_t *data = (struct sound_t *)malloc(size + sizeof(struct sound_t));
    return (void *)(data + 1);
}

void *wav_custom_realloc(void *ptr, size_t size)
{
    ptr = ptr ? (void *)(((struct sound_t *)ptr) - 1) : NULL;
    struct sound_t *data = (struct sound_t *)realloc(ptr, size + sizeof(struct sound_t));
    return (void *)(data + 1);
}

void wav_custom_free(void *ptr)
{
    ptr = ptr ? (void *)(((struct sound_t *)ptr) - 1) : NULL;
    free(ptr);
}

struct sound_t *loadwav(char const *filename)
{
    unsigned int channels = 0;
    unsigned int samplerate = 0;
    drwav_uint64 framecount = 0;
    drwav_int16 *samples = drwav_open_file_and_read_pcm_frames_s16(filename, &channels, &samplerate, &framecount, NULL);
    if (samples == NULL || channels <= 0 || channels > 2 || samplerate < 4000 || samplerate > 48000 || framecount == 0 || framecount >= 0x7fffffff)
    {
        if (samples)
        {
            drwav_free(samples, NULL);
        }
        return NULL;
    }
    struct sound_t *sound = ((struct sound_t *)samples) - 1;
    sound->channels = (int)channels;
    sound->samplerate = (int)samplerate;
    sound->framecount = (int)framecount;
    return sound;
}

struct sound_t *createsound(int channels, int samplerate, int framecount, short *samples)
{
    if (channels < 1 || channels > 2 || samplerate < 1000 || samplerate > 44100 || framecount <= 0 || !samples)
    {
        return NULL;
    }
    struct sound_t *sound = (struct sound_t *)malloc(sizeof(struct sound_t) + framecount * channels * sizeof(short));
    memcpy(sound + 1, samples, framecount * channels * sizeof(short));
    sound->channels = channels;
    sound->samplerate = samplerate;
    sound->framecount = framecount;
    return sound;
}

void playsound(int channel, struct sound_t *sound, int loop, int volume)
{
    if (channel < 0 || channel >= SOUND_CHANNELS)
        return;
    if (!sound)
        return;
    if (volume < 0)
        volume = 0;
    if (volume > 255)
        volume = 255;
    thread_mutex_lock(&internals->mutex);
    internals->audio.channels[channel].sound = sound;
    internals->audio.channels[channel].loop = loop;
    internals->audio.channels[channel].volume_left = volume;
    internals->audio.channels[channel].volume_right = volume;
    internals->audio.channels[channel].play_counter++;
    thread_mutex_unlock(&internals->mutex);
}

void stopsound(int channel)
{
    if (channel < 0 || channel >= SOUND_CHANNELS)
        return;
    thread_mutex_lock(&internals->mutex);
    internals->audio.channels[channel].sound = NULL;
    thread_mutex_unlock(&internals->mutex);
}

int soundplaying(int channel)
{
    if (channel < 0 || channel >= SOUND_CHANNELS)
        return 0;
    return internals->audio.channels[channel].sound != NULL;
}

void soundvolume(int channel, int left, int right)
{
    if (channel < 0 || channel >= SOUND_CHANNELS)
        return;
    if (left < 0)
        left = 0;
    if (left > 255)
        left = 255;
    if (right < 0)
        right = 0;
    if (right > 255)
        right = 255;
    thread_mutex_lock(&internals->mutex);
    internals->audio.channels[channel].volume_left = left;
    internals->audio.channels[channel].volume_right = right;
    thread_mutex_unlock(&internals->mutex);
}

struct app_context_t
{
    int argc;
    char **argv;
};

struct user_thread_context_t
{
    struct app_context_t *app_context;
    int sound_buffer_size;
    thread_signal_t user_thread_initialized;
    thread_atomic_int_t user_thread_finished;
    thread_signal_t app_loop_finished;
    thread_signal_t user_thread_terminated;
};

int dosmain(int argc, char *argv[]);

#ifndef __wasm__
static
#else
WA_EXPORT(user_thread_proc)
#endif
    int
    user_thread_proc(void *user_data)
{
    struct user_thread_context_t *context = (struct user_thread_context_t *)user_data;

    internals_create(context->sound_buffer_size);

    thread_signal_raise(&context->user_thread_initialized);

    waitvbl();

    int result = dosmain(context->app_context->argc, context->app_context->argv);

    thread_atomic_int_store(&context->user_thread_finished, 1);
    thread_signal_wait(&context->app_loop_finished, 5000);
#ifdef __wasm__
    WaCoroSwitch(0);
#endif
    internals_destroy();

    thread_signal_raise(&context->user_thread_terminated);
#ifdef __wasm__
    WaCoroSwitch(0);
#endif
    return result;
}

void initsoundmode(enum soundmode_t mode, int *freq, bool *is8bit, bool *mono)
{
    switch (mode)
    {
    case soundmode_8bit_mono_5000:
        *freq = 5000;
        *is8bit = true;
        *mono = true;
        break;
    case soundmode_8bit_mono_8000:
        *freq = 8000;
        *is8bit = true;
        *mono = true;
        break;
    case soundmode_8bit_mono_11025:
        *freq = 11025;
        *is8bit = true;
        *mono = true;
        break;
    case soundmode_8bit_mono_16000:
        *freq = 16000;
        *is8bit = true;
        *mono = true;
        break;
    case soundmode_8bit_mono_22050:
        *freq = 22050;
        *is8bit = true;
        *mono = true;
        break;
    case soundmode_8bit_mono_32000:
        *freq = 32000;
        *is8bit = true;
        *mono = true;
        break;
    case soundmode_8bit_mono_44100:
        *freq = 44100;
        *is8bit = true;
        *mono = true;
        break;
    case soundmode_16bit_mono_5000:
        *freq = 5000;
        *is8bit = false;
        *mono = true;
        break;
    case soundmode_16bit_mono_8000:
        *freq = 8000;
        *is8bit = false;
        *mono = true;
        break;
    case soundmode_16bit_mono_11025:
        *freq = 11025;
        *is8bit = false;
        *mono = true;
        break;
    case soundmode_16bit_mono_16000:
        *freq = 16000;
        *is8bit = false;
        *mono = true;
        break;
    case soundmode_16bit_mono_22050:
        *freq = 22050;
        *is8bit = false;
        *mono = true;
        break;
    case soundmode_16bit_mono_32000:
        *freq = 32000;
        *is8bit = false;
        *mono = true;
        break;
    case soundmode_16bit_mono_44100:
        *freq = 44100;
        *is8bit = false;
        *mono = true;
        break;
    case soundmode_8bit_stereo_5000:
        *freq = 5000;
        *is8bit = true;
        *mono = false;
        break;
    case soundmode_8bit_stereo_8000:
        *freq = 8000;
        *is8bit = true;
        *mono = false;
        break;
    case soundmode_8bit_stereo_11025:
        *freq = 11025;
        *is8bit = true;
        *mono = false;
        break;
    case soundmode_8bit_stereo_16000:
        *freq = 16000;
        *is8bit = true;
        *mono = false;
        break;
    case soundmode_8bit_stereo_22050:
        *freq = 220050;
        *is8bit = true;
        *mono = false;
        break;
    case soundmode_8bit_stereo_32000:
        *freq = 32000;
        *is8bit = true;
        *mono = false;
        break;
    case soundmode_8bit_stereo_44100:
        *freq = 44100;
        *is8bit = true;
        *mono = false;
        break;
    case soundmode_16bit_stereo_5000:
        *freq = 5000;
        *is8bit = false;
        *mono = false;
        break;
    case soundmode_16bit_stereo_8000:
        *freq = 8000;
        *is8bit = false;
        *mono = false;
        break;
    case soundmode_16bit_stereo_11025:
        *freq = 11025;
        *is8bit = false;
        *mono = false;
        break;
    case soundmode_16bit_stereo_16000:
        *freq = 16000;
        *is8bit = false;
        *mono = false;
        break;
    case soundmode_16bit_stereo_22050:
        *freq = 22050;
        *is8bit = false;
        *mono = false;
        break;
    case soundmode_16bit_stereo_32000:
        *freq = 32000;
        *is8bit = false;
        *mono = false;
        break;
    case soundmode_16bit_stereo_44100:
        *freq = 44100;
        *is8bit = false;
        *mono = false;
        break;
    }
}

tml_message *render_mid_tsf(struct music_t *mid, tml_message *next, double *msec, int loop, APP_S16 *sample_pairs, int sample_pairs_count, tsf *soundfont)
{
    int SampleBlock, SampleCount = sample_pairs_count;
    for (SampleBlock = 64; SampleCount; SampleCount -= SampleBlock, sample_pairs += (SampleBlock * 2))
    {
        if (SampleBlock > SampleCount)
            SampleBlock = SampleCount;

        for ((*msec) += SampleBlock * (1000.0 / 44100.0); next && (*msec) >= next->time; next = next->next)
        {
            switch (next->type)
            {
            case TML_PROGRAM_CHANGE:
                tsf_channel_set_presetnumber(soundfont, next->channel, next->program, (next->channel == 9));
                break;
            case TML_NOTE_ON:
                tsf_channel_note_on(soundfont, next->channel, next->key, next->velocity / 127.0f);
                break;
            case TML_NOTE_OFF:
                tsf_channel_note_off(soundfont, next->channel, next->key);
                break;
            case TML_PITCH_BEND:
                tsf_channel_set_pitchwheel(soundfont, next->channel, next->pitch_bend);
                break;
            case TML_CONTROL_CHANGE:
                tsf_channel_midi_control(soundfont, next->channel, next->control, next->control_value);
                break;
            }
        }

        tsf_render_short(soundfont, sample_pairs, SampleBlock, 1);
        if (next == NULL)
        {
            if (loop)
            {
                next = (tml_message *)(mid + 1);
                (*msec) = 0.0;
            }
            else
            {
                return NULL;
            }
        }
    }
    return next;
}

tml_message *render_mid_opl(struct music_t *mid, tml_message *next, double *msec, int loop, APP_S16 *sample_pairs, int sample_pairs_count, opl_t *opl)
{
    int SampleBlock, SampleCount = sample_pairs_count;
    for (SampleBlock = 64; SampleCount; SampleCount -= SampleBlock, sample_pairs += (SampleBlock * 2))
    {
        if (SampleBlock > SampleCount)
            SampleBlock = SampleCount;

        for ((*msec) += SampleBlock * (1000.0 / 44100.0); next && (*msec) >= next->time; next = next->next)
        {
            switch (next->type)
            {
            case TML_PROGRAM_CHANGE: // channel program (preset) change (special handling for 10th MIDI channel with drums)
                opl_midi_changeprog(opl, next->channel, next->program);
                break;
            case TML_NOTE_ON: // play a note
                opl_midi_noteon(opl, next->channel, next->key, next->velocity);
                break;
            case TML_NOTE_OFF: // stop a note
                opl_midi_noteoff(opl, next->channel, next->key);
                break;
            case TML_PITCH_BEND: // pitch wheel modification
                opl_midi_pitchwheel(opl, next->channel, (next->pitch_bend - 8192) / 64);
                break;
            case TML_CONTROL_CHANGE: // MIDI controller messages
                opl_midi_controller(opl, next->channel, next->control, next->control_value);
                break;
            }
        }

        opl_render(opl, sample_pairs, SampleBlock, internals->audio.music_volume / 255.0f);
        if (next == NULL)
        {
            if (loop)
            {
                next = (tml_message *)(mid + 1);
                (*msec) = 0.0;
            }
            else
            {
                return NULL;
            }
        }
    }
    return next;
}

int render_mus_tsf(mus_t *mus, int left_over, int loop, APP_S16 *sample_pairs, int sample_pairs_count, tsf *soundfont)
{
    int left_over_from_previous = left_over;
    int remaining = sample_pairs_count;
    APP_S16 *output = sample_pairs;
    left_over = 0;
    if (left_over_from_previous)
    {
        int count = left_over_from_previous;
        if (count > remaining)
        {
            left_over = count - remaining;
            count = remaining;
        }
        tsf_render_short(soundfont, output, count, 1);
        remaining -= count;
        output += count * 2;
    }
    if (left_over)
    {
        return left_over;
    }

    while (remaining)
    {
        mus_event_t event;
        mus_next_event(mus, &event);
        switch (event.cmd)
        {
        case MUS_CMD_RELEASE_NOTE:
        {
            tsf_channel_note_off(soundfont, event.channel, event.data.release_note.note);
        }
        break;
        case MUS_CMD_PLAY_NOTE:
        {
            tsf_channel_note_on(soundfont, event.channel, event.data.play_note.note, event.data.play_note.volume / 127.0f);
        }
        break;
        case MUS_CMD_PITCH_BEND:
        {
            int pitch_bend = (event.data.pitch_bend.bend_amount - 128) * 64 + 8192;
            tsf_channel_set_pitchwheel(soundfont, event.channel, pitch_bend);
        }
        break;
        case MUS_CMD_SYSTEM_EVENT:
        {
            switch (event.data.system_event.event)
            {
            case MUS_SYSTEM_EVENT_ALL_SOUNDS_OFF:
            {
                tsf_channel_sounds_off_all(soundfont, event.channel);
            }
            break;
            case MUS_SYSTEM_EVENT_ALL_NOTES_OFF:
            {
                tsf_channel_note_off_all(soundfont, event.channel);
            }
            break;
            case MUS_SYSTEM_EVENT_MONO:
            {
                // Not supported
            }
            break;
            case MUS_SYSTEM_EVENT_POLY:
            {
                // Not supported
            }
            break;
            case MUS_SYSTEM_EVENT_RESET_ALL_CONTROLLERS:
            {
                tsf_channel_midi_control(soundfont, event.channel, 121, 0);
            }
            break;
            }
        }
        break;
        case MUS_CMD_CONTROLLER:
        {
            int value = event.data.controller.value;
            switch (event.data.controller.controller)
            {
            case MUS_CONTROLLER_CHANGE_INSTRUMENT:
            {
                if (event.channel == 15)
                {
                    tsf_channel_set_presetnumber(soundfont, 15, 0, 1);
                }
                else
                {
                    tsf_channel_set_presetnumber(soundfont, event.channel, value, 0);
                }
            }
            break;
            case MUS_CONTROLLER_BANK_SELECT:
            {
                tsf_channel_set_bank(soundfont, event.channel, value);
            }
            break;
            case MUS_CONTROLLER_MODULATION:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_VOLUME:
            {
                tsf_channel_midi_control(soundfont, event.channel, 7, value);
            }
            break;
            case MUS_CONTROLLER_PAN:
            {
                tsf_channel_midi_control(soundfont, event.channel, 10, value);
            }
            break;
            case MUS_CONTROLLER_EXPRESSION:
            {
                tsf_channel_midi_control(soundfont, event.channel, 11, value);
            }
            break;
            case MUS_CONTROLLER_REVERB_DEPTH:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_CHORUS_DEPTH:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_SUSTAIN_PEDAL:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_SOFT_PEDAL:
            {
                // Not supported
            }
            break;
            }
        }
        break;
        case MUS_CMD_END_OF_MEASURE:
        {
            // Not used
        }
        break;
        case MUS_CMD_FINISH:
        {
            if (loop)
            {
                mus_restart(mus);
            }
            else
            {
                memset(output, 0, remaining * 2 * sizeof(*output));
                return -1;
            }
        }
        break;
        case MUS_CMD_RENDER_SAMPLES:
        {
            int count = event.data.render_samples.samples_count;
            if (count > remaining)
            {
                left_over = count - remaining;
                count = remaining;
            }
            tsf_render_short(soundfont, output, count, 1);
            remaining -= count;
            output += count * 2;
        }
        break;
        }
    }
    return left_over;
}

int render_mus_opl(mus_t *mus, int left_over, int loop, APP_S16 *sample_pairs, int sample_pairs_count, opl_t *opl)
{
    int left_over_from_previous = left_over;
    int remaining = sample_pairs_count;
    APP_S16 *output = sample_pairs;
    left_over = 0;
    if (left_over_from_previous)
    {
        int count = left_over_from_previous;
        if (count > remaining)
        {
            left_over = count - remaining;
            count = remaining;
        }
        opl_render(opl, output, count, internals->audio.music_volume / 255.0f);
        remaining -= count;
        output += count * 2;
    }
    if (left_over)
    {
        return left_over;
    }

    while (remaining)
    {
        mus_event_t event;
        mus_next_event(mus, &event);
        if (event.channel == 15)
        {
            event.channel = 9;
        }
        else if (event.channel == 9)
        {
            event.channel = 15;
        }
        switch (event.cmd)
        {
        case MUS_CMD_RELEASE_NOTE:
        {
            opl_midi_noteoff(opl, event.channel, event.data.release_note.note);
        }
        break;
        case MUS_CMD_PLAY_NOTE:
        {
            opl_midi_noteon(opl, event.channel, event.data.play_note.note, event.data.play_note.volume);
        }
        break;
        case MUS_CMD_PITCH_BEND:
        {
            opl_midi_pitchwheel(opl, event.channel, event.data.pitch_bend.bend_amount - 0x80);
        }
        break;
        case MUS_CMD_SYSTEM_EVENT:
        {
            switch (event.data.system_event.event)
            {
            case MUS_SYSTEM_EVENT_ALL_SOUNDS_OFF:
            {
                opl_midi_controller(opl, event.channel, 120, 0);
            }
            break;
            case MUS_SYSTEM_EVENT_ALL_NOTES_OFF:
            {
                opl_midi_controller(opl, event.channel, 123, 0);
            }
            break;
            case MUS_SYSTEM_EVENT_MONO:
            {
                // Not supported
            }
            break;
            case MUS_SYSTEM_EVENT_POLY:
            {
                // Not supported
            }
            break;
            case MUS_SYSTEM_EVENT_RESET_ALL_CONTROLLERS:
            {
                // Not supported
            }
            break;
            }
        }
        break;
        case MUS_CMD_CONTROLLER:
        {
            int value = event.data.controller.value;
            switch (event.data.controller.controller)
            {
            case MUS_CONTROLLER_CHANGE_INSTRUMENT:
            {
                opl_midi_changeprog(opl, event.channel, value);
            }
            break;
            case MUS_CONTROLLER_BANK_SELECT:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_MODULATION:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_VOLUME:
            {
                opl_midi_controller(opl, event.channel, 11, value);
            }
            break;
            case MUS_CONTROLLER_PAN:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_EXPRESSION:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_REVERB_DEPTH:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_CHORUS_DEPTH:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_SUSTAIN_PEDAL:
            {
                // Not supported
            }
            break;
            case MUS_CONTROLLER_SOFT_PEDAL:
            {
                // Not supported
            }
            break;
            }
        }
        break;
        case MUS_CMD_END_OF_MEASURE:
        {
            // Not used
        }
        break;
        case MUS_CMD_FINISH:
        {
            if (loop)
            {
                mus_restart(mus);
            }
            else
            {
                memset(output, 0, remaining * 2 * sizeof(*output));
                return -1;
            }
        }
        break;
        case MUS_CMD_RENDER_SAMPLES:
        {
            int count = event.data.render_samples.samples_count;
            if (count > remaining)
            {
                left_over = count - remaining;
                count = remaining;
            }
            opl_render(opl, output, count, internals->audio.music_volume / 255.0f);
            remaining -= count;
            output += count * 2;
        }
        break;
        }
    }
    return left_over;
}

float mix_sound_channel(struct sound_t *sound, bool loop, float volume_left, float volume_right, float position, float *sample_pairs, int sample_pairs_count)
{
    float ratio = sound->samplerate / 44100.0f;
    int16_t *samples = (int16_t *)(sound + 1);
    if (sound->channels == 2)
    {
        for (int i = 0; i < sample_pairs_count; ++i)
        {
            int p = (int)position;
            if (p >= sound->framecount && loop)
            {
                position = 0.0f;
                p = 0;
            }
            float s0 = p < sound->framecount ? samples[p * 2 + 0] / 32768.0f : 0.0f;
            float s1 = p < sound->framecount ? samples[p * 2 + 1] / 32768.0f : 0.0f;
            sample_pairs[i * 2 + 0] += s0 * volume_left;
            sample_pairs[i * 2 + 1] += s1 * volume_right;
            position += ratio;
        }
    }
    else
    {
        for (int i = 0; i < sample_pairs_count; ++i)
        {
            int p = (int)position;
            if (p >= sound->framecount && loop)
            {
                position = 0.0f;
                p = 0;
            }
            float s = p < sound->framecount ? samples[p + 0] / 32768.0f : 0.0f;
            sample_pairs[i * 2 + 0] += s * volume_left;
            sample_pairs[i * 2 + 1] += s * volume_right;
            position += ratio;
        }
    }
    return position;
}

float soft_clipping(float s)
{
    return s < -1.0f ? -2.0f / 3.0f : s > 1.0f ? 2.0f / 3.0f
                                               : s - (s * s * s) / 3.0f;
}

#define SOUND_BUFFER_SIZE (735 * 3) /* Three frames worth of sound buffering */

struct sound_context_t
{
    thread_mutex_t mutex;
    tsf *soundfont;
    opl_t *opl;
    int commands_count;
    struct audio_command_t commands[512];
    struct music_t *current_music;
    bool loop_music;
    int music_volume;
    tml_message *music_next;
    int left_over;
    double music_msec;
    bool music_done;
    int music_play_counter;
    int sound_freq;
    bool sound_8bit;
    bool sound_mono;
    struct
    {
        struct sound_t *sound;
        bool loop;
        int volume_left;
        int volume_right;
        int play_counter;
        float position;
        bool done;
    } sound_channels[SOUND_CHANNELS];
};

static void app_sound_callback(APP_S16 *sample_pairs, int sample_pairs_count, void *user_data)
{
    struct sound_context_t *context = (struct sound_context_t *)user_data;
    static float mixbuffer[SOUND_BUFFER_SIZE * 10];
    static short modbuffer[SOUND_BUFFER_SIZE * 10];
    int in_count = sample_pairs_count;

    thread_mutex_lock(&context->mutex);

    if (!context->music_done && context->current_music && context->current_music->format == MUSIC_FORMAT_MOD)
    {
        memset(modbuffer, 0, sample_pairs_count * 2 * sizeof(short));
        jar_mod_context_t *modctx = (jar_mod_context_t *)(context->current_music + 1);
        jar_mod_fillbuffer(modctx, modbuffer, sample_pairs_count, NULL);
        for (int i = 0; i < sample_pairs_count * 2; ++i)
        {
            mixbuffer[i] = (modbuffer[i] / 32768.0f) * (context->music_volume / 255.0f);
        }
    }
    else
    {
        memset(mixbuffer, 0, sample_pairs_count * 2 * sizeof(float));
    }

    for (int i = 0; i < SOUND_CHANNELS; ++i)
    {
        if (context->sound_channels[i].sound && !context->sound_channels[i].done)
        {
            float result = mix_sound_channel(context->sound_channels[i].sound, context->sound_channels[i].loop,
                                             context->sound_channels[i].volume_left / 255.0f, context->sound_channels[i].volume_right / 255.0f,
                                             context->sound_channels[i].position,
                                             mixbuffer, sample_pairs_count);
            if (result >= context->sound_channels[i].sound->framecount)
            {
                context->sound_channels[i].done = true;
            }
            else
            {
                context->sound_channels[i].position = result;
            }
        }
    }

    int freq = context->sound_freq;
    int is8bit = context->sound_8bit;
    int ismono = context->sound_mono;

    static float freqbuffer[SOUND_BUFFER_SIZE * 10];
    float ratio = freq / 44100.0f;
    float outpos = 0.0f;
    for (int i = 0; i < in_count; ++i)
    {
        int o = (int)outpos;
        float s0 = mixbuffer[i * 2 + 0];
        float s1 = mixbuffer[i * 2 + 1];
        freqbuffer[o * 2 + 0] = s0;
        freqbuffer[o * 2 + 1] = s1;
        outpos += ratio;
    }

    float inpos = 0.0f;
    for (int i = 0; i < in_count; ++i)
    {
        int in = (int)inpos;
        float s0 = freqbuffer[in * 2 + 0];
        float s1 = freqbuffer[in * 2 + 1];
        if (ismono)
        {
            float s = (s0 + s1) / 2.0f;
            s0 = s;
            s1 = s;
        }
        if (is8bit)
        {
            s0 *= 127.0f;
            s1 *= 127.0f;
            s0 = ((int)s0) / 127.0f;
            s1 = ((int)s1) / 127.0f;
        }
        s0 = soft_clipping(s0) * 32700.0f;
        s1 = soft_clipping(s1) * 32700.0f;
        sample_pairs[i * 2 + 0] = (APP_S16)s0;
        sample_pairs[i * 2 + 1] = (APP_S16)s1;
        inpos += ratio;
    }

    if (!context->music_done && context->current_music && context->current_music->format == MUSIC_FORMAT_MUS)
    {
        int result = 0;
        if (context->soundfont)
        {
            result = render_mus_tsf((mus_t *)(context->current_music + 1), context->left_over,
                                    context->loop_music, sample_pairs, sample_pairs_count, context->soundfont);
        }
        else
        {
            result = render_mus_opl((mus_t *)(context->current_music + 1), context->left_over,
                                    context->loop_music, modbuffer, sample_pairs_count, context->opl);
            for (int i = 0; i < sample_pairs_count * 2; ++i)
            {
                int s = (modbuffer[i]);
                s += sample_pairs[i];
                if (s > 32700)
                    s = 32700;
                if (s < -32700)
                    s = -32700;
                sample_pairs[i] = (short)(s);
            }
        }
        if (result >= 0)
        {
            context->left_over = result;
        }
        else
        {
            context->music_done = true;
            context->left_over = 0;
            ;
        }
    }
    else if (!context->music_done && context->current_music && context->current_music->format == MUSIC_FORMAT_MID)
    {
        if (context->soundfont)
        {
            context->music_next = render_mid_tsf(context->current_music, context->music_next, &context->music_msec,
                                                 context->loop_music, sample_pairs, sample_pairs_count, context->soundfont);
        }
        else
        {
            context->music_next = render_mid_opl(context->current_music, context->music_next, &context->music_msec,
                                                 context->loop_music, modbuffer, sample_pairs_count, context->opl);
            for (int i = 0; i < sample_pairs_count * 2; ++i)
            {
                int s = (modbuffer[i]);
                s += sample_pairs[i];
                if (s > 32700)
                    s = 32700;
                if (s < -32700)
                    s = -32700;
                sample_pairs[i] = (short)(s);
            }
        }
        if (context->music_next == NULL)
        {
            context->music_done = true;
        }
    }
    else if (!context->music_done && context->current_music && context->current_music->format == MUSIC_FORMAT_OPB)
    {
        struct opb_t *opb = (struct opb_t *)(context->current_music + 1);
        double current_time = opb->accumulated_time;
        opb->accumulated_time += sample_pairs_count / 44100.0;
        short *outsamples = modbuffer;
        int samples_remaining = sample_pairs_count;
        int buffered_count = 0;
        uint16_t buffered_regs[256];
        uint8_t buffered_data[256];
        while (opb->position < opb->commands_count)
        {
            OPB_Command cmd = opb->commands[opb->position];
            if (cmd.Time >= opb->accumulated_time)
            {
                break;
            }
            if (cmd.Time > current_time)
            {
                int samples_to_render = (int)((cmd.Time - current_time) * 44100.0);
                if (samples_to_render > 0)
                {
                    if (samples_to_render > samples_remaining)
                    {
                        samples_to_render = samples_remaining;
                    }
                    opl_write(context->opl, buffered_count, buffered_regs, buffered_data);
                    buffered_count = 0;
                    opl_render(context->opl, outsamples, samples_to_render, context->music_volume / 255.0f);
                    outsamples += samples_to_render * 2;
                    samples_remaining -= samples_to_render;
                    if (samples_remaining <= 0)
                    {
                        break;
                    }
                    current_time = cmd.Time;
                }
            }
            buffered_regs[buffered_count] = cmd.Addr;
            buffered_data[buffered_count] = cmd.Data;
            ++buffered_count;
            if (buffered_count >= 256)
            {
                opl_write(context->opl, buffered_count, buffered_regs, buffered_data);
                buffered_count = 0;
            }
            ++opb->position;
        }
        opl_write(context->opl, buffered_count, buffered_regs, buffered_data);
        buffered_count = 0;
        if (samples_remaining > 0)
        {
            opl_render(context->opl, outsamples, samples_remaining, context->music_volume / 255.0f);
        }
        for (int i = 0; i < sample_pairs_count * 2; ++i)
        {
            int s = (modbuffer[i]);
            s += sample_pairs[i];
            if (s > 32700)
                s = 32700;
            if (s < -32700)
                s = -32700;
            sample_pairs[i] = (short)(s);
        }
    }
    else
    {
        if (context->soundfont)
        {
            if (context->commands_count > 0)
            {
                int current_stamp = context->commands[0].frame_stamp;
                for (int i = 0; i < context->commands_count; ++i)
                {
                    struct audio_command_t *cmd = &context->commands[i];
                    if (cmd->frame_stamp != current_stamp)
                    {
                        if (sample_pairs_count > 0)
                        {
                            tsf_render_short(context->soundfont, sample_pairs, 735, 1);
                        }
                        sample_pairs += 2 * 735;
                        sample_pairs_count -= 735;
                        current_stamp = cmd->frame_stamp;
                    }
                    switch (cmd->type)
                    {
                    case AUDIO_COMMAND_NOTE_ON:
                        tsf_channel_note_on(context->soundfont, cmd->channel, cmd->note, cmd->velocity / 127.0f);
                        break;
                    case AUDIO_COMMAND_NOTE_OFF:
                        tsf_channel_note_off(context->soundfont, cmd->channel, cmd->note);
                        break;
                    case AUDIO_COMMAND_NOTE_OFF_ALL:
                        tsf_channel_note_off_all(context->soundfont, cmd->channel);
                        break;
                    case AUDIO_COMMAND_SET_INSTRUMENT:
                        tsf_channel_set_presetnumber(context->soundfont, cmd->channel, cmd->instrument,
                                                     cmd->instrument == 128 ? 1 : 0);
                        break;
                    }
                }
            }
            if (sample_pairs_count > 0)
            {
                tsf_render_short(context->soundfont, sample_pairs, sample_pairs_count, 1);
            }
        }
        else
        {
            if (context->commands_count > 0)
            {
                int current_stamp = context->commands[0].frame_stamp;
                for (int j = 0; j < context->commands_count; ++j)
                {
                    struct audio_command_t *cmd = &context->commands[j];
                    if (cmd->frame_stamp != current_stamp)
                    {
                        if (sample_pairs_count > 0)
                        {
                            opl_render(context->opl, modbuffer, 735, 1.0f);
                            for (int i = 0; i < 735 * 2; ++i)
                            {
                                int s = (modbuffer[i]);
                                s += sample_pairs[i];
                                if (s > 32700)
                                    s = 32700;
                                if (s < -32700)
                                    s = -32700;
                                sample_pairs[i] = (short)(s);
                            }
                        }
                        sample_pairs += 2 * 735;
                        sample_pairs_count -= 735;
                        current_stamp = cmd->frame_stamp;
                    }
                    switch (cmd->type)
                    {
                    case AUDIO_COMMAND_NOTE_ON:
                        opl_midi_noteon(context->opl, cmd->channel, cmd->note, cmd->velocity);
                        break;
                    case AUDIO_COMMAND_NOTE_OFF:
                        opl_midi_noteoff(context->opl, cmd->channel, cmd->note);
                        break;
                    case AUDIO_COMMAND_NOTE_OFF_ALL:
                        opl_midi_controller(context->opl, cmd->channel, 123, 0);
                        break;
                    case AUDIO_COMMAND_SET_INSTRUMENT:
                        opl_midi_changeprog(context->opl, cmd->channel, cmd->instrument);
                        break;
                    }
                }
            }
            if (sample_pairs_count > 0)
            {
                opl_render(context->opl, modbuffer, sample_pairs_count, 1.0f);
                for (int i = 0; i < sample_pairs_count * 2; ++i)
                {
                    int s = (modbuffer[i]);
                    s += sample_pairs[i];
                    if (s > 32700)
                        s = 32700;
                    if (s < -32700)
                        s = -32700;
                    sample_pairs[i] = (short)(s);
                }
            }
        }
    }
    context->commands_count = 0;

    thread_mutex_unlock(&context->mutex);
}

static void load_crt_frame_col(void *data, struct GIF_WHDR *whdr)
{
    APP_U32 *pixels = (APP_U32 *)data;
    for (int i = 0; i < 1024 * 1024; ++i)
    {
        uint8_t v = whdr->bptr[i];
        pixels[i] = (whdr->cpal[v].B << 16) | (whdr->cpal[v].G << 8) | (whdr->cpal[v].R);
    }
}

static void load_crt_frame_alpha(void *data, struct GIF_WHDR *whdr)
{
    APP_U32 *pixels = (APP_U32 *)data;
    for (int i = 0; i < 1024 * 1024; ++i)
    {
        uint8_t v = whdr->bptr[i];
        pixels[i] = pixels[i] | (whdr->cpal[v].R << 24);
    }
}

static APP_U32 *load_crt_frame(void)
{
    APP_U32 *pixels = (APP_U32 *)malloc(1024 * 1024 * sizeof(APP_U32));
    memset(pixels, 0, 1024 * 1024 * sizeof(APP_U32));
    GIF_Load(crtframecol, (long)sizeof(crtframecol), load_crt_frame_col, NULL, (void *)pixels, 0L);
    GIF_Load(crtframealpha, (long)sizeof(crtframealpha), load_crt_frame_alpha, NULL, (void *)pixels, 0L);
    return pixels;
}

static int app_proc(app_t *app, void *user_data)
{
    struct app_context_t *app_context = (struct app_context_t *)user_data;

    app_title(app, app_filename(app));

#ifndef __wasm__
    bool fullscreen = true;
#else
    bool fullscreen = false;
#endif

    int modargc = 0;
    char *modargv[256];
    for (int i = 0; i < app_context->argc; ++i)
    {
        if (strcmp(app_context->argv[i], "--window") == 0)
        {
            fullscreen = false;
        }
        else if (strcmp(app_context->argv[i], "-w") == 0)
        {
            fullscreen = false;
        }
        else
        {
            if (modargc >= sizeof(modargv) / sizeof(*modargv))
            {
                break;
            }
            modargv[modargc++] = app_context->argv[i];
        }
    }
    app_context->argc = modargc;
    app_context->argv = modargv;

    int pointer_width = 0;
    int pointer_height = 0;
    int pointer_hotspot_x = 0;
    int pointer_hotspot_y = 0;
    static APP_U32 pointer_pixels[256 * 256];
    app_pointer_default(app, &pointer_width, &pointer_height, pointer_pixels, &pointer_hotspot_x, &pointer_hotspot_y);

    app_screenmode(app, fullscreen ? APP_SCREENMODE_FULLSCREEN : APP_SCREENMODE_WINDOW);
#ifdef DISABLE_SYSTEM_CURSOR
    APP_U32 blank = 0;
    app_pointer(app, 1, 1, &blank, 0, 0);
#else
    if (fullscreen)
    {
        APP_U32 blank = 0;
        app_pointer(app, 1, 1, &blank, 0, 0);
    }
    else
    {
        app_pointer(app, pointer_width, pointer_height, pointer_pixels, pointer_hotspot_x, pointer_hotspot_y);
    }
#endif

    app_displays_t displays = app_displays(app);
    if (displays.count > 0)
    {
        int disp = 0;
        for (int i = 0; i < displays.count; ++i)
        {
            if (displays.displays[i].x == 0 && displays.displays[i].y == 0)
            {
                disp = i;
                break;
            }
        }
        int scrwidth = displays.displays[disp].width - 80;
        int scrheight = displays.displays[disp].height - 80;
        int aspect_width = (int)((scrheight * 4.25f) / 3);
        int aspect_height = (int)((scrwidth * 3) / 4.25f);
        int target_width, target_height;
        if (aspect_height <= scrheight)
        {
            target_width = scrwidth;
            target_height = aspect_height;
        }
        else
        {
            target_width = aspect_width;
            target_height = scrheight;
        }

        int x = displays.displays[disp].x + (displays.displays[disp].width - target_width) / 2;
        int y = displays.displays[disp].y + (displays.displays[disp].height - target_height) / 2;
        int w = target_width;
        int h = target_height;
        app_window_pos(app, x, y);
        app_window_size(app, w, h);
    }

    struct user_thread_context_t user_thread_context;
    user_thread_context.app_context = app_context;
    user_thread_context.sound_buffer_size = SOUND_BUFFER_SIZE;
    thread_signal_init(&user_thread_context.user_thread_initialized);
    thread_atomic_int_store(&user_thread_context.user_thread_finished, 0);
    thread_signal_init(&user_thread_context.app_loop_finished);
    thread_signal_init(&user_thread_context.user_thread_terminated);

#ifndef __wasm__
    thread_ptr_t user_thread = thread_create(user_thread_proc, &user_thread_context,
                                             THREAD_STACK_SIZE_DEFAULT);

    if (!thread_signal_wait(&user_thread_context.user_thread_initialized, 5000))
    {
        thread_signal_term(&user_thread_context.user_thread_initialized);
        thread_signal_term(&user_thread_context.app_loop_finished);
        thread_signal_term(&user_thread_context.user_thread_terminated);
        return EXIT_FAILURE;
    }
#else
    // WebAssembly has no real threads so we use coroutines which can switch context between two
    // callstacks to simulate the behavior from native platforms
    WaCoro user_coro = WaCoroInitNew(user_thread_proc, "user_thread_proc", &user_thread_context, 0);
    WaCoroSwitch(user_coro);
    internals->wasm.user_coro = user_coro; // only now internals exists
#endif

#ifdef NULL_PLATFORM
    crtemu_pc_t *crt = NULL;
#else
    crtemu_pc_t *crt = crtemu_pc_create(NULL);
#ifndef DISABLE_SCREEN_FRAME
    APP_U32 *frame = load_crt_frame();
    crtemu_pc_frame(crt, frame, 1024, 1024);
    free(frame);
#endif
#endif

    // Create the frametimer instance, and set it to fixed 60hz update. This will ensure we never run faster than that,
    // even if the user have disabled vsync in their graphics card settings.
    frametimer_t *frametimer = frametimer_create(NULL);
    frametimer_lock_rate(frametimer, 60);

    // Start sound playback
    struct sound_context_t sound_context;
    memset(&sound_context, 0, sizeof(sound_context));
    thread_mutex_init(&sound_context.mutex);
    sound_context.opl = opl_create();
    sound_context.commands_count = 0;
    sound_context.current_music = NULL;
    sound_context.loop_music = false;
    sound_context.music_volume = 0;
    initsoundmode(internals->audio.soundmode, &sound_context.sound_freq, &sound_context.sound_8bit, &sound_context.sound_mono);
    app_sound(app, SOUND_BUFFER_SIZE * 2, app_sound_callback, &sound_context);
    int previous_soundbank = internals->audio.current_soundbank;

    signalvbl();

    struct
    {
        struct sound_t *sound;
        bool loop;
        int volume_left;
        int volume_right;
        int play_counter;
    } sound_channels[SOUND_CHANNELS] = {{NULL}};

    enum soundmode_t sound_mode = internals->audio.soundmode;
    int music_play_counter = 0;

    // Main loop
    static APP_U32 screen_xbgr[sizeof(internals->screen.buffer0)];
    int width = 0;
    int height = 0;
    int curs_vis = 0;
    int curs_x = 0;
    int curs_y = 0;
    bool keystate[KEYCOUNT] = {0};
    enum keycode_t keys[256] = {(enum keycode_t)0};
    char chars[256] = {0};
    APP_U64 crt_time_us = 0;
    APP_U64 prev_time = app_time_count(app);
    while (!thread_atomic_int_load(&user_thread_context.user_thread_finished))
    {
        app_state_t app_state = app_yield(app);
        frametimer_update(frametimer);

        int keys_index = 0;
        memset(keys, 0, sizeof(keys));
        int chars_index = 0;
        memset(chars, 0, sizeof(chars));
        float relx = 0;
        float rely = 0;
        app_input_t input = app_input(app);
        for (int i = 0; i < input.count; ++i)
        {
            app_input_event_t *event = &input.events[i];
            if (event->type == APP_INPUT_KEY_DOWN)
            {
                int index = (int)event->data.key;
                if (index > 0 && index < KEYCOUNT)
                {
                    keystate[index] = true;
                    if (keys_index < 255)
                    {
                        keys[keys_index++] = (enum keycode_t)event->data.key;
                    }
                }
                if (event->data.key == APP_KEY_F11)
                {
                    fullscreen = !fullscreen;
                    app_screenmode(app, fullscreen ? APP_SCREENMODE_FULLSCREEN : APP_SCREENMODE_WINDOW);
#ifdef DISABLE_SYSTEM_CURSOR
                    APP_U32 blank = 0;
                    app_pointer(app, 1, 1, &blank, 0, 0);
#else
                    if (fullscreen)
                    {
                        APP_U32 blank = 0;
                        app_pointer(app, 1, 1, &blank, 0, 0);
                    }
                    else
                    {
                        app_pointer(app, pointer_width, pointer_height, pointer_pixels, pointer_hotspot_x, pointer_hotspot_y);
                    }
#endif
                }
            }
            else if (event->type == APP_INPUT_KEY_UP)
            {
                int index = (int)event->data.key;
                if (index >= 0 && index < KEYCOUNT)
                {
                    keystate[index] = false;
                    if (keys_index < 255)
                    {
                        keys[keys_index++] = (enum keycode_t)(((uint32_t)event->data.key) | KEY_MODIFIER_RELEASED);
                    }
                }
            }
            else if (event->type == APP_INPUT_CHAR)
            {
                if (event->data.char_code > 0)
                {
                    if (chars_index < 255)
                    {
                        chars[chars_index++] = event->data.char_code;
                    }
                }
            }
            else if (event->type == APP_INPUT_MOUSE_DELTA)
            {
                relx += event->data.mouse_delta.x;
                rely += event->data.mouse_delta.y;
            }
        }
        internals->input.mouse_relx = (int)relx;
        internals->input.mouse_rely = (int)rely;

        // Check if the close button on the window was clicked (or Alt+F4 was pressed)
        if (app_state == APP_STATE_EXIT_REQUESTED)
        {
            // Signal that we need to force the user thread to exit
            thread_atomic_int_store(&internals->exit_flag, 1);
            signalvbl();
            break;
        }

        // Copy data from user thread
        thread_mutex_lock(&internals->mutex);

        width = internals->screen.width;
        height = internals->screen.height;
        uint8_t *internals_screen = internals->screen.buffer;
        uint32_t *font = internals->screen.font;
        if (internals->screen.doublebuffer)
        {
            if (internals->screen.buffer == internals->screen.buffer0)
            {
                internals_screen = internals->screen.buffer1;
            }
            else
            {
                internals_screen = internals->screen.buffer0;
            }
        }
        static uint8_t screen[sizeof(internals->screen.buffer0)];
        if (font)
        {
            memcpy(screen, internals_screen, width * height * 2);
        }
        else
        {
            memcpy(screen, internals_screen, width * height);
        }

        static uint32_t palette[256];
        memcpy(palette, internals->screen.palette, 1024);

        bool curs = internals->conio.curs;
        if (internals->conio.x != curs_x || internals->conio.y != curs_y)
        {
            curs_x = internals->conio.x;
            curs_y = internals->conio.y;
            curs_vis = 0;
        }

        int mouse_x = app_pointer_x(app);
        int mouse_y = app_pointer_y(app);
        if (crt)
        {
            crtemu_pc_coordinates_window_to_bitmap(crt, width * internals->screen.cellwidth,
                                                   height * internals->screen.cellheight, &mouse_x, &mouse_y);
        }
        internals->input.mouse_x = mouse_x / internals->screen.cellwidth;
        internals->input.mouse_y = mouse_y / internals->screen.cellheight;

        memcpy(internals->input.keystate, keystate, sizeof(internals->input.keystate));

        enum keycode_t *internals_keybuffer;
        if (internals->input.keybuffer == internals->input.keybuffer0)
        {
            internals_keybuffer = internals->input.keybuffer1;
        }
        else
        {
            internals_keybuffer = internals->input.keybuffer0;
        }
        enum keycode_t *keyin = keys;
        enum keycode_t *keyout = internals_keybuffer;
        enum keycode_t *keyend = internals_keybuffer + sizeof(internals->input.keybuffer0) / sizeof(*internals->input.keybuffer0) - 1;
        while (*keyout && keyout < keyend)
        {
            ++keyout;
        }
        while (*keyin)
        {
            if (keyout >= keyend)
            {
                memmove(internals_keybuffer + 1, internals_keybuffer, sizeof(internals->input.keybuffer0) / sizeof(*internals->input.keybuffer0) - 1);
                --keyout;
            }
            *keyout++ = *keyin++;
        }
        *keyout = KEY_INVALID;

        char *internals_charbuffer;
        if (internals->input.charbuffer == internals->input.charbuffer0)
        {
            internals_charbuffer = internals->input.charbuffer1;
        }
        else
        {
            internals_charbuffer = internals->input.charbuffer0;
        }
        char *charin = chars;
        char *charout = internals_charbuffer;
        char *charend = internals_charbuffer + sizeof(internals->input.charbuffer0) / sizeof(*internals->input.charbuffer0) - 1;
        while (*charout && charout < charend)
        {
            ++charout;
        }
        while (*charin)
        {
            if (charout >= charend)
            {
                memmove(internals_charbuffer + 1, internals_charbuffer, sizeof(internals->input.charbuffer0) / sizeof(*internals->input.charbuffer0) - 1);
                --charout;
            }
            *charout++ = *charin++;
        }
        *charout = '\0';

        int audio_commands_count = internals->audio.commands_count;
        internals->audio.commands_count = 0;
        struct audio_command_t audio_commands[256];
        memcpy(audio_commands, internals->audio.commands, audio_commands_count * sizeof(struct audio_command_t));
        ++internals->audio.frame_stamp;

        struct music_t *current_music = internals->audio.current_music;
        music_play_counter = internals->audio.music_play_counter;
        bool loop_music = internals->audio.loop_music;
        int music_volume = internals->audio.music_volume;

        for (int i = 0; i < SOUND_CHANNELS; ++i)
        {
            sound_channels[i].sound = internals->audio.channels[i].sound;
            sound_channels[i].loop = internals->audio.channels[i].loop;
            sound_channels[i].volume_left = internals->audio.channels[i].volume_left;
            sound_channels[i].volume_right = internals->audio.channels[i].volume_right;
            sound_channels[i].play_counter = internals->audio.channels[i].play_counter;
        }

        sound_mode = internals->audio.soundmode;

        int current_soundbank = internals->audio.current_soundbank;

        thread_mutex_unlock(&internals->mutex);

        // Signal to the game that the frame is completed, and that we are just starting the next one
        signalvbl();

        // Process audio commands
        thread_mutex_lock(&sound_context.mutex);
        if (previous_soundbank != current_soundbank)
        {
            enum soundbank_type_t type = internals->audio.soundbanks[current_soundbank].type;
            if (type == SOUNDBANK_TYPE_SF2)
            {
                sound_context.soundfont = internals->audio.soundbanks[current_soundbank].sf2;
                tsf_reset(sound_context.soundfont);
                for (int i = 0; i < MUSIC_CHANNELS; ++i)
                {
                    tsf_channel_set_presetnumber(sound_context.soundfont, i, 0, i == 9 ? 1 : 0);
                }
                //} else if( type == SOUNDBANK_TYPE_IBK ) {
                //    opl_loadbank_ibk( sound_context.opl, internals->audio.soundbanks[ current_soundbank ].data, internals->audio.soundbanks[ current_soundbank ].size );
                //    sound_context.soundfont = NULL;
            }
            else if (type == SOUNDBANK_TYPE_OP2)
            {
                opl_loadbank_op2(sound_context.opl, internals->audio.soundbanks[current_soundbank].data, (int)internals->audio.soundbanks[current_soundbank].size);
                sound_context.soundfont = NULL;
            }
            else if (type == SOUNDBANK_TYPE_NONE)
            {
                opl_destroy(sound_context.opl);
                sound_context.opl = opl_create();
                sound_context.soundfont = NULL;
            }
            sound_context.music_play_counter--;
            previous_soundbank = current_soundbank;
        }
        for (int i = 0; i < audio_commands_count; ++i)
        {
            if (sound_context.commands_count >= sizeof(sound_context.commands) / sizeof(*sound_context.commands))
            {
                break;
            }
            sound_context.commands[sound_context.commands_count++] = audio_commands[i];
        }

        sound_context.music_volume = music_volume;
        if (sound_context.soundfont)
        {
            tsf_set_volume(sound_context.soundfont, music_volume / 255.0f);
        }
        if (current_music && sound_context.music_play_counter != music_play_counter)
        {
            if (sound_context.soundfont)
            {
                tsf_reset(sound_context.soundfont);
                tsf_set_volume(sound_context.soundfont, music_volume / 255.0f);
            }
            else
            {
                opl_clear(sound_context.opl);
            }
            sound_context.current_music = current_music;
            sound_context.loop_music = loop_music;
            sound_context.music_volume = music_volume;
            if (current_music->format == MUSIC_FORMAT_MID)
            {
                sound_context.music_next = (tml_message *)(current_music + 1);
                if (sound_context.soundfont)
                {
                    tsf_reset(sound_context.soundfont);
                    for (int i = 0; i < MUSIC_CHANNELS; ++i)
                    {
                        tsf_channel_set_presetnumber(sound_context.soundfont, i, 0, i == 9 ? 1 : 0);
                    }
                }
                else
                {
                    opl_clear(sound_context.opl);
                }
            }
            else if (current_music->format == MUSIC_FORMAT_MUS)
            {
                sound_context.music_next = NULL;
                mus_t *mus = (mus_t *)(current_music + 1);
                mus_restart(mus);
            }
            else if (current_music->format == MUSIC_FORMAT_MOD)
            {
                jar_mod_context_t *modctx = (jar_mod_context_t *)(current_music + 1);
                jar_mod_seek_start(modctx);
            }
            else if (current_music->format == MUSIC_FORMAT_OPB)
            {
                struct opb_t *opb = (struct opb_t *)(current_music + 1);
                opb->position = 0;
                opb->accumulated_time = 0.0;
                opl_clear(sound_context.opl);
            }
            sound_context.music_msec = 0.0;
            sound_context.music_done = false;
            sound_context.left_over = 0;
            sound_context.music_play_counter = music_play_counter;
        }
        else if (current_music == NULL && sound_context.current_music != NULL)
        {
            sound_context.current_music = NULL;
            if (sound_context.soundfont)
            {
                tsf_reset(sound_context.soundfont);
                for (int i = 0; i < MUSIC_CHANNELS; ++i)
                {
                    tsf_channel_set_presetnumber(sound_context.soundfont, i, 0, i == 9 ? 1 : 0);
                }
            }
            else
            {
                opl_clear(sound_context.opl);
            }
        }
        else if (sound_context.music_done)
        {
            internals->audio.current_music = NULL;
            if (sound_context.soundfont)
            {
                tsf_reset(sound_context.soundfont);
                for (int i = 0; i < MUSIC_CHANNELS; ++i)
                {
                    tsf_channel_set_presetnumber(sound_context.soundfont, i, 0, i == 9 ? 1 : 0);
                }
            }
            else
            {
                opl_clear(sound_context.opl);
            }
        }
        initsoundmode(sound_mode, &sound_context.sound_freq, &sound_context.sound_8bit, &sound_context.sound_mono);
        for (int i = 0; i < SOUND_CHANNELS; ++i)
        {
            if (sound_channels[i].sound != sound_context.sound_channels[i].sound || sound_channels[i].play_counter != sound_context.sound_channels[i].play_counter)
            {
                sound_context.sound_channels[i].sound = sound_channels[i].sound;
                sound_context.sound_channels[i].loop = sound_channels[i].loop;
                sound_context.sound_channels[i].play_counter = sound_channels[i].play_counter;
                sound_context.sound_channels[i].position = 0.0f;
                sound_context.sound_channels[i].done = false;
            }
            else if (sound_context.sound_channels[i].done)
            {
                internals->audio.channels[i].sound = NULL;
            }
            sound_context.sound_channels[i].volume_left = sound_channels[i].volume_left;
            sound_context.sound_channels[i].volume_right = sound_channels[i].volume_right;
        }
        thread_mutex_unlock(&sound_context.mutex);

        // Render screen buffer
        if (font)
        {
            memset(screen_xbgr, 0, sizeof(screen_xbgr));
            uint32_t const *data = font;
            int chr_width = *data++;
            int chr_height = *data++;
            int chr_baseline = *data++;
            (void)chr_baseline;
            int chr_mod = 256 / chr_width;
            for (int y = 0; y < height; ++y)
            {
                for (int x = 0; x < width; ++x)
                {
                    uint8_t c = screen[(x + y * width) * 2 + 0];
                    uint8_t attr = screen[(x + y * width) * 2 + 1];
                    int fg = (attr & 0xf);
                    int bg = ((attr >> 4) & 0xf);
                    int sx = (c % chr_mod) * chr_width;
                    int sy = (c / chr_mod) * chr_height;
                    int dx = x * chr_width;
                    int dy = y * chr_height;
                    for (int iy = 0; iy < chr_height; ++iy)
                    {
                        for (int ix = 0; ix < chr_width; ++ix)
                        {
                            int v = (sx + ix) / 32;
                            int u = (sx + ix) - (v * 32);
                            uint32_t b = data[v + (sy + iy) * 8];
                            int xp = dx + ix;
                            int yp = dy + iy;
                            if (b & (1 << u))
                            {
                                screen_xbgr[xp + yp * (width * chr_width)] = palette[fg];
                            }
                            else
                            {
                                screen_xbgr[xp + yp * (width * chr_width)] = palette[bg];
                            }
                        }
                    }
                }
            }
            ++curs_vis;
            if (curs && curs_x >= 0 && curs_x < width && curs_y >= 0 && curs_y < height)
            {
                int vis = (curs_vis % 50) < 25;
                if (vis)
                {
                    int xp = curs_x * chr_width;
                    int yp = curs_y * chr_height;
                    int cs = chr_height == 16 ? 13 : 7;
                    int ce = chr_height == 16 ? 15 : 9;
                    APP_U32 col = palette[7];
                    for (int y = cs; y < ce; ++y)
                    {
                        for (int x = 0; x < chr_width; ++x)
                        {
                            screen_xbgr[(x + xp) + (y + yp) * width * chr_width] = col;
                        }
                    }
                }
            }
            width *= chr_width;
            height *= chr_height;
        }
        else
        {
            for (int y = 0; y < height; ++y)
            {
                for (int x = 0; x < width; ++x)
                {
                    screen_xbgr[x + y * width] = palette[screen[x + y * width]];
                }
            }
        }

        if (!app_has_focus(app))
        {
            continue;
        }
        APP_U64 time = app_time_count(app);
        APP_U64 freq = app_time_freq(app);
        APP_U64 delta_time_us = (time - prev_time) / ((freq > 1000000 ? freq / 1000000 : 1));
        prev_time = time;
        crt_time_us += delta_time_us;
        if (crt)
        {
#ifndef DISABLE_SCREEN_FRAME
            crtemu_pc_present(crt, crt_time_us, screen_xbgr, width, height, 0xffffff, 0xff1a1a1a);
#else
            crtemu_pc_present(crt, crt_time_us, screen_xbgr, width, height, 0xffffff, 0xff000000);
#endif
        }
        app_present(app, NULL, 1, 1, 0xffffff, 0xff1a1a1a);
    }

    app_sound(app, 0, NULL, NULL);

    thread_signal_raise(&user_thread_context.app_loop_finished);
    int user_exit = thread_signal_wait(&user_thread_context.user_thread_terminated, 170);
#ifdef __wasm__
    WaCoroSwitch(user_coro);
    user_exit = 0; // always show fade out animation
#endif
    if (!user_exit)
    {
        for (int i = 0; i < 60; ++i)
        {
            APP_U64 time = app_time_count(app);
            APP_U64 delta_time_us = (time - prev_time) / (app_time_freq(app) / 1000000);
            prev_time = time;
            crt_time_us += delta_time_us;
            int v = ((60 - i) * 255) / 60;
            uint32_t fade = (v << 16) | v << 8 | v;
            if (crt)
            {
                crtemu_pc_present(crt, crt_time_us, screen_xbgr, width, height, fade, 0xff1a1a1a);
            }
            app_present(app, NULL, 1, 1, 0xffffff, 0xff1a1a1a);
            frametimer_update(frametimer);
        }
        user_exit = thread_signal_wait(&user_thread_context.user_thread_terminated, 30);
        if (!user_exit)
        {
            exit(EXIT_FAILURE);
        }
    }
    thread_signal_term(&user_thread_context.user_thread_initialized);
    thread_signal_term(&user_thread_context.app_loop_finished);
    thread_signal_term(&user_thread_context.user_thread_terminated);
    frametimer_destroy(frametimer);
    opl_destroy(sound_context.opl);
    thread_mutex_term(&sound_context.mutex);
    if (crt)
    {
        crtemu_pc_destroy(crt);
    }
#ifndef __wasm__
    return thread_join(user_thread);
#else
    return 0;
#endif
}

#define APP_IMPLEMENTATION
#ifdef NULL_PLATFORM
#define APP_NULL
#elif defined(_WIN32)
#define APP_WINDOWS
#elif defined(__wasm__)
#define APP_WASM
#else
#define APP_SDL
#endif
#define APP_LOG(ctx, level, message)
#include "libs/app.h"

#define CRTEMU_PC_IMPLEMENTATION
#include "libs/crtemu_pc.h"

#define DR_WAV_IMPLEMENTATION
#define DRWAV_MALLOC(sz) wav_custom_malloc(sz)
#define DRWAV_REALLOC(p, sz) wav_custom_realloc(p, sz)
#define DRWAV_FREE(p) wav_custom_free(p);
#include "libs/dr_wav.h"

#define FRAMETIMER_IMPLEMENTATION
#include "libs/frametimer.h"

#define MUS_IMPLEMENTATION
#define MUS_MALLOC tml_mus_custom_malloc
#define MUS_FREE tml_mus_custom_free
#include "libs/mus.h"

#define OPBLIB_IMPLEMENTATION
#pragma warning(push)
#pragma warning(disable : 4189)
#pragma warning(disable : 4204)
#pragma warning(disable : 4244)
#pragma warning(disable : 4296)
#pragma warning(disable : 4388)
#pragma warning(disable : 4457)
#pragma warning(disable : 4706)
#include "libs/opblib.h"
#pragma warning(pop)

#define OPL_IMPLEMENTATION
#pragma warning(push)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4189)
#pragma warning(disable : 4242)
#pragma warning(disable : 4244)
#pragma warning(disable : 4245)
#include "libs/opl.h"
#pragma warning(pop)

#define PIXELFONT_IMPLEMENTATION
#define PIXELFONT_BUILDER_IMPLEMENTATION
#include "libs/pixelfont.h"

#define THREAD_IMPLEMENTATION
#include "libs/thread.h"

#define TSF_IMPLEMENTATION
#define TSF_POW pow
#define TSF_POWF (float)pow
#define TSF_EXPF (float)exp
#define TSF_LOG log
#define TSF_TAN tan
#define TSF_LOG10 log10
#define TSF_SQRT (float)sqrt
#define TSF_SQRTF (float)sqrt
#include <math.h>
#include "libs/tsf.h"

#define TML_IMPLEMENTATION
#ifdef _WIN32
#pragma warning(push)
#pragma warning(disable : 4201)
#endif
#define TML_MALLOC tml_mus_custom_malloc
#define TML_REALLOC tml_mus_custom_realloc
#define TML_FREE tml_mus_custom_free
#include "libs/tml.h"
#ifdef _WIN32
#pragma warning(pop)
#endif

bool app_has_focus(app_t *app)
{
#ifdef ALWAYS_UPDATE
    return true;
#else
#ifndef NULL_PLATFORM
    return app->has_focus;
#else
    return true;
#endif
#endif
}

#include <inttypes.h>

/*
void bin2arr( char const* src, char const* dst, char const* name ) {
    FILE* fp = fopen( src, "rb" );
    fseek( fp, 0, SEEK_END );
    size_t sz = ftell( fp );
    fseek( fp, 0, SEEK_SET );
    uint8_t* data = (uint8_t*) malloc( sz );
    fread( data, 1, sz, fp );
    fclose( fp );

    fp = fopen( dst, "w" );
    unsigned long long count = ( (unsigned long long) sz );
    fprintf( fp, "unsigned char %s[ %llu ] = {\n", name, count );
    for( size_t i = 0; i < sz; ++i ) {
        if( i > 0 && ( i % 400 ) == 0 ) fprintf( fp, "\n" );
        fprintf( fp, "%d,", data[ i ] );
    }
    fprintf( fp, "\n" );
    fprintf( fp, "};\n" );
    free( data );
    fclose( fp );
}
*/

//*** main ***

int main(int argc, char **argv)
{
    (void)argc, (void)argv;

    // bin2arr( "framecol.gif", "crtframecol.h", "crtframecol" );
    // bin2arr( "framealpha.gif", "crtframealpha.h", "crtframealpha" );
    // bin2arr( "aweromgm.sf2", "awe32rom.h", "awe32rom" );

    struct app_context_t app_context;
    app_context.argc = argc;
    app_context.argv = argv;
    return app_run(app_proc, &app_context, NULL, NULL, NULL);
}

#ifdef _WIN32
// pass-through so the program will build with either /SUBSYSTEM:WINDOWS or /SUBSYSTEM:CONSOLE
int WINAPI __stdcall WinMain(HINSTANCE a, HINSTANCE b, char *c, int d)
{
    (void)a, b, c, d;
    return main(__argc, __argv);
}
#endif

#endif /* DOS_IMPLEMENTATION */

#ifndef NO_MAIN_DEF
#define main dosmain
#endif

/*
------------------------------------------------------------------------------

This software is available under 2 licenses - you may choose the one you like.

------------------------------------------------------------------------------

ALTERNATIVE A - MIT License

Copyright (c) 2021 Mattias Gustavsson

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

------------------------------------------------------------------------------

ALTERNATIVE B - Public Domain (www.unlicense.org)

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
software, either in source code form or as a compiled binary, for any purpose,
commercial or non-commercial, and by any means.

In jurisdictions that recognize copyright laws, the author or authors of this
software dedicate any and all copyright interest in the software to the public
domain. We make this dedication for the benefit of the public at large and to
the detriment of our heirs and successors. We intend this dedication to be an
overt act of relinquishment in perpetuity of all present and future rights to
this software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

------------------------------------------------------------------------------
*/
