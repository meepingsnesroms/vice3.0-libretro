#ifndef LIBRETRO_CORE_H
#define LIBRETRO_CORE_H 1

#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>

#define MATRIX(a,b) (((a) << 3) | (b))

// DEVICE VICE
#define RETRO_DEVICE_VICE_KEYBOARD RETRO_DEVICE_SUBCLASS(RETRO_DEVICE_KEYBOARD, 0)
#define RETRO_DEVICE_VICE_JOYSTICK RETRO_DEVICE_SUBCLASS(RETRO_DEVICE_JOYPAD, 1)

extern unsigned vice_devices[ 2 ];

#define TEX_WIDTH 384
#define TEX_HEIGHT 272

//LOG
#if  defined(__ANDROID__) || defined(ANDROID)
#include <android/log.h>
#define LOG_TAG "RetroArch.vice"
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#else
#define LOGI printf
#endif

//TYPES

#define UINT16 uint16_t
#define UINT32 uint32_t
#define uint32 uint32_t
#define uint8 uint8_t

#if defined(__CBM2__)
#define WINDOW_WIDTH 704
#define WINDOW_HEIGHT 266
#define WINDOW_SIZE (704*266)
#elif defined(__CBM5X__)
#define WINDOW_WIDTH 448
#define WINDOW_HEIGHT 284
#define WINDOW_SIZE (448*284)
#else
#define WINDOW_WIDTH 384
#define WINDOW_HEIGHT 272
#define WINDOW_SIZE (384*272)
#endif

//#define RENDER16B
//#undef RENDER16B
#ifdef RENDER16B
#define M16B
#endif
#ifdef  RENDER16B
	extern uint16_t *Retro_Screen;
	extern uint16_t bmp[WINDOW_SIZE];
	#define PIXEL_BYTES 1
	#define PIXEL_TYPE UINT16
	#define PITCH 2	
#else
	extern unsigned int *Retro_Screen;
	extern unsigned int bmp[WINDOW_SIZE];
	#define PIXEL_BYTES 2
	#define PIXEL_TYPE UINT32
	#define PITCH 4	
#endif 


//VKBD
#define NPLGN 10
#define NLIGN 5
#define NLETT 5

typedef struct {
	char norml[NLETT];
	char shift[NLETT];
	int val;	
} Mvk;

extern Mvk MVk[NPLGN*NLIGN*2];

//STRUCTURES
typedef struct{
     signed short x, y;
     unsigned short w, h;
} retro_Rect;

typedef struct{
     unsigned char *pixels;
     unsigned short w, h,pitch;
} retro_Surface;

typedef struct{
     unsigned char r,g,b;
} retro_pal;

//VARIABLES
extern int pauseg; 
extern int CROP_WIDTH;
extern int CROP_HEIGHT;
extern int VIRTUAL_WIDTH;
extern int retrow ; 
extern int retroh ;
extern int cpuloop;
extern int vice_statusbar;

//FUNCS
extern void maincpu_mainloop_retro(void);
extern long GetTicks(void);
#endif
