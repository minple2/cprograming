﻿#include <stdio.h>
#include <windows.h>
#include <conio.h>

// 키보드 값
#define UP 0
#define DOWN 1
#define SUBMIT 2

int keyControl();
void init();
void titleDraw();
int menuDraw();
void gotoxy(int, int);

void startGame() {
    printf("게임을 시작합니다!\n");

    // 게임 시작하는 코드를 작성하세요.
}

void exitGame() {
    printf("게임을 종료합니다.\n");
    return 0;
    // 게임 종료하는 코드를 작성하세요.
}

void gameRule() {
    system("cls");//화면모두 지우기
    printf("\n\n");

    printf("┌----------------[게임 룰]--------------------┐\n");
    printf("|  1. 5*4로 이루어진 호텔 방 중 하나를 선택한다.|\n");
    printf("|  2. 탈출구를 찾을 때까지 신중하게 선택한다.   |\n");
    printf("|  3. 살인마가 있는 방을 선택하면 게임오버!     |\n");
    printf("|                                               |\n");
    printf("|  \033[0;35m스페이스바를 누르면 메인 화면으로 이동합니다.\033[0m|\n");
    printf("└----------------------------------------------┘\n");

    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }

}

void handleMenuSelection(int selection) {
    switch (selection) {
    case 0:
        startGame();
        break;
    case 1:
        gameRule();
    case 2:
        exitGame();
        break;;
    }
}

int main() {
    init();
    while (1) {
        titleDraw();
        int menuCode= menuDraw();
        if (menuCode == 0) {
            startGame();
        }
        else if (menuCode == 1) {
            gameRule();
        }
        else if (menuCode == 2) {
            return 0;
        }

        system("cls")//콘솔창 모든 글자 깨끗하게 비움, 좌표도 (0,0)이 됨

    }
    
    return 0;
}

int keyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }

    return -1; // 잘못된 키 입력인 경우
}

void init() {
    system("mode con cols=56 lines=20 | title 게임 제목");
}

void titleDraw() {
    printf(".    _                  __  __         .            .  \n");
    printf(" _/_   /        ___      |   |    __.  _/_     ___   |  \n");
    printf(" |    |,---. .'   `      |___|  .'   \\  |    .'   `  |  \n");
    printf(" |    |'   ` |----'      |   |  |    |  |    |----'  |  \n");
    printf(" \\__/ /    | `.___,     /   /   `._.'  \\__/ `.___, /\\__\n");
    printf("                   //  ~escape~   //                                        \n");

    printf("                   ┎(HOTEL)┒\n");
    printf("                   ┃┏┓┏┓┏┓┃       \n");
    printf("         人人人人人┃┗┛┗┛┗┛┃人人人人人\n");
    printf("    　   l l l l l ┃┏┓┏┓┏┓┃| l | | |\n");


}

int menuDraw() {
    int x= 12;
    int y = 12;

    gotoxy(x, y);
    printf("┌--------------------------┐");
    gotoxy(x , y+1);
    printf("│    >◇ 게임시작           │");
    gotoxy(x, y + 2);
    printf("│     ◇ 게임정보           │");
    gotoxy(x, y + 3);
    printf("│     ◇ 게임종료           │");
    gotoxy(x, y+4);
    printf("└--------------------------┘");
    while (1) {
        int n = keyControl();
        switch (n) {
            case UP: {
                if (y > 13) {
                    gotoxy(x +5,y);
                    printf(" ");
                    gotoxy(x +5, --y);
                    printf(">");

                }
                break;
            }
            case DOWN: {
                if (y < 15) {
                    gotoxy(x +5, y);
                    printf(" ");
                    gotoxy(x+5, ++y);
                    printf(">");
                }
                break;
            }
            case SUBMIT: {
                return y - 13;
            }
         
        }
    }

}

void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}