#include "main.h"



int main() {
    init();
    while (1) {
        titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 0) {
            system("cls");
            intro();
            startGame();
        }
        else if (menuCode == 1) {
            system("cls");
            gameRule();
        }
        else if (menuCode == 2) {
            return 0;
        }

        system("cls");//콘솔창 모든 글자 깨끗하게 비움, 좌표도 (0,0)이 됨

    }

    return 0;
}


