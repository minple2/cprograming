#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

// 키보드 값  
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4 // 선택(스페이스바)  
#define Quit 5

#endif

int exitGame();
int keyControl();
void titleDraw();
int menuDraw();
void gameRule();
void intro();
int changeNum();


