﻿#include "game.h"

//방향키(키보드입력)을 입력받고 숫자를 반환하는 함수
int keyControl() {
    char temp = _getch();
    //위 방향키 아스키코드 72
    if (temp == 'w' || temp == 'W'|| temp==72) {
        return UP;
    }
    //아래방향키 80
    else if (temp == 's' || temp == 'S'||temp==80) {
        return DOWN;
    }
    //13 아스키코드로 엔터
    else if (temp == 13|| temp==' ') {
        return SUBMIT;
    }
    else if (temp == 'q' || temp == 'Q') {
        return Quit;
    }

    return -1; // 잘못된 키 입력인 경우
}

//타이틀 출력 함수
void titleDraw() {
    printf("\033[0;31m.    _                  __  __         .            .  \n");
    printf(" _/_   /        ___      |   |    __.  _/_     ___   |  \n");
    printf(" |    |,---. .'   `      |___|  .'   \\  |    .'   `  |  \n");
    printf(" |    |'   ` |----'      |   |  |    |  |    |----'  |  \n");
    printf(" \\__/ /    | `.___,     /   /   `._.'  \\__/ `.___, /\\__\n");
    printf("                 //  ~escape~   //                                        \n\n");

    printf("                     ┎(HOTEL)┒\n");
    printf("                     ┃┏┓┏┓┏┓┃       \n");
    printf("           人人人人人┃┗┛┗┛┗┛┃人人人人人\n");
    printf("    　     l l l l l ┃┏┓┏┓┏┓┃| l | | |\033[0m\n");


}

//메뉴 출력 함수
int menuDraw() {
    int x = 12;
    int y = 12;

    gotoxy(x, y-1);//좌표이동
    printf("┌--------------------------┐");
    gotoxy(x, y);
    printf("│    >◇ 게임시작           │");
    gotoxy(x, y + 1);
    printf("│     ◇ 게임정보           │");
    gotoxy(x, y + 2);
    printf("│     ◇ 게임종료           │");
    gotoxy(x, y + 3);
    printf("└--------------------------┘");
    gotoxy(x-2, y + 5);
    printf("\033[0;31m (방향키로도 가능합니다)w:위 s:아래 엔터 : 선택\033[0m");

    while (1) {
        int n = keyControl();//키보드 이벤트 키값으로 받아오기
        switch (n) {
        case UP: {//입력받은 키값이 UP인 경우
            if (y > 12) {//y는 12~14까지 이동
                gotoxy(x + 5, y);
                printf(" ");//현재위치의 >를 지우고
                gotoxy(x + 5, --y);
                printf(">");//이동한 위치에 새로 >를 그림

            }
            break;
        }
        case DOWN: {//입력받은 키값이 DOWN인 경우
            if (y < 14) {
                gotoxy(x + 5, y);
                printf(" ");
                gotoxy(x + 5, ++y);
                printf(">");
            }
            break;
        }
        case SUBMIT: {
            return y - 12;//y-12를 반환(메뉴 선택값),main()함수에 있는 menucode로 반환 
        }

        }
    }

}


//게임 방법 설명 함수
void gameRule() {
    system("cls");//화면모두 지우기
    printf("\n\n");

    printf("┌----------------[게임 룰]----------------------┐\n");
    printf("|  1. 호텔 방(20개) 중 하나를 선택한다.         |\n");
    printf("|  2. 열쇠를 찾을 때까지 신중하게 선택한다.     |\n");
    printf("|  3. 금고의 비밀번호를 맞춰 열쇠를 획득한다.   |\n");
    printf("|  4. 살인마가 있는 방을 선택하면 게임오버!     |\n");
    printf("|                                               |\n");
    printf("|  \033[0;35m엔터를 누르면 메인 화면으로 이동합니다.\033[0m      |\n");
    printf("└-----------------------------------------------┘\n");

    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }

}

//입력받은 숫자를 배열 인덱스 번호로 바꿔주는 함수
int changeNum(int x) {
    if ((401 <= x) && (x <= 405)) {
        return x - 385;
    }
    if ((301 <= x) && (x <= 305)) {
        return x - 290;
    }
    if ((201 <= x) && (x <= 205)) {
        return x - 195;
    }
    if ((101 <= x) && (x <= 105)) {
        return x - 100;
    }
    else
    {
        return -1;
    }
}

//인트로 출력 함수
void intro() {
    char sentences[][1024] = {
        "당신은 등산을 하다가 길을 잃어버렸습니다.",
        "밤이 될때까지 길을 찾지못해 어둡고 낯선 숲속을 끝없이 헤맸습니다. ",
        "지쳐쓰러지기 직전,",
        "다행스럽게도 호텔을 발견합니다.",
        "                     ┎(HOTEL)┒\n                     ┃┏┓┏┓┏┓┃       \n           人人人人人┃┗┛┗┛┗┛┃人人人人人\n    　     l l l l l ┃┏┓┏┓┏┓┃| l | | |\033[0m\n",
        "외진곳에 있는 호텔이라 그런지 조금 으스스한 느낌이 듭니다.",
        "심지어 투숙객도 당신을 포함해 2명밖에 없습니다.",
        "당신은 호텔로 들어가 방을 구하고 잠을 청합니다.",
        "눈을 딱 감는 순간...",
        "_ _ _ \n| | | | | |\n| |__ ___ | | _ __ | |\n| '_ \ / _ \| || '_ \ | |\n| | | || __/| || |_) ||_|\n|_| |_| \___||_|| .__/ (_)\n | |\n |_|\n",
        "으아아아아악!!!!!",
        "옆방에서 비명소리가 들립니다.",
        "복도로 나가 확인해보니, 옆 방문 틈사이로 피가 흘러나오고 있습니다.",
        "소름끼치는 누군가의 웃음이 방 안에 들립니다.",
        "뭔가 심상치 않음을 느낀 당신은 이곳을 벗어나고자 합니다.",
        "입구로 달려가봤지만 문은 자물쇠로 잠겨있습니다.",
        "일단 급한대로 다른 호텔 방을 조사해봅시다.",
        "살인마를 마주치지 않도록 조심해야겠습니다."
    };
    //총 문장 수
    int sentenceCount = sizeof(sentences) / sizeof(sentences[0]);
    int currentIndex = 0;
    char ch;
    int count = 0;

    printf("스페이스 바를 누를 때마다 다음 문장이 출력됩니다. 종료하려면 'q'를 입력하세요.\n");

    while (true) {
        ch = _getch();

        if (ch == ' ') {
            if (currentIndex >= sentenceCount) {
                break;
            }
            //5줄 출력시 화면 지우기
            if (count>=5) {
                system("cls");
                count = 0;
            }
                
            printf("%s\n", sentences[currentIndex]);
            currentIndex++;
            count++;
        }
        else if (ch == 'q') {
            break;
        }
    }
}



//게임 플레이 함수
void startGame() {

    int rooms[20] = { 101,102,103,104,105,201,202,203,204,205,301,302,303,304,305,401,402,403,404,405 };
    char Xrooms[20][32] = { "101","102","103","104","105","201","202","203","204","205","301","302","303","304","305","401","402","403","404","405" };
    int selectedRoom = 0;
    int gameOver = 0;
    int remain = 20;
    int killerRoom = 0;
    int exitRoom = 0;
    system("cls");
    //방 출력하기
    printf("==================HOTEL==================\n");
    printf("=========================================\n");
    printf("4층| %6s| %6s| %6s| %6s| %6s|\n", Xrooms[15], Xrooms[16], Xrooms[17], Xrooms[18], Xrooms[19]);
    printf("3층| %6s| %6s| %6s| %6s| %6s|\n", Xrooms[10], Xrooms[11], Xrooms[12], Xrooms[13], Xrooms[14]);
    printf("2층| %6s| %6s| %6s| %6s| %6s|\n", Xrooms[5], Xrooms[6], Xrooms[7], Xrooms[8], Xrooms[9]);
    printf("1층| %6s| %6s| %6s| %6s| %6s|\n", Xrooms[0], Xrooms[1], Xrooms[2], Xrooms[3], Xrooms[4]);
    printf("남은 방 : %d\n", remain);
    printf("========================================\n");

    //살인마 방과 탈출구 랜덤으로 고르기
    srand(time(NULL));
    killerRoom = rand() % 20;
    rooms[killerRoom] = 1;
    exitRoom = rand() % 20;

    //살인마 방과 탈출구가 같은 방이면 탈출구를 다시 선택함
    while (exitRoom == killerRoom) {
        exitRoom = rand() % 20;
    }
    rooms[exitRoom] = 1;

    // 방 선택 여부를 나타내는 배열
    bool selected[20] = { false };

    while (1) {
        int selectedRoom;
        int number;
        int result;
        int p_result;

        printf("(빠른 진행을 위해 넣은 줄입니다.)  %d %d\n",killerRoom, exitRoom);

        printf("들어갈 방을 선택하세요: ");

        scanf_s("%d", &number);

        selectedRoom = changeNum(number);

        if (selectedRoom < 1 || selectedRoom > 20) {
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
            while (getchar() != '\n');//문자 입력이 실패했을 때, 입력 버퍼에 문자가 남지 않도록 해 무한 루프에 빠지지 않도록 함
            continue;
        }

        if (selected[selectedRoom - 1]) { // 이미 선택한 방인지 확인
            printf("이미 선택한 방입니다. 다른 방을 선택하세요.\n");
            continue;
        }



        selected[selectedRoom - 1] = true; // 선택한 방을 방문한 것으로 표시

        //선택한 방이 살인마 방 주변에 있을 경우 나오는 힌트
        if (selectedRoom - 7 == killerRoom || selectedRoom - 6 == killerRoom || selectedRoom - 5 == killerRoom || selectedRoom - 2 == killerRoom || selectedRoom == killerRoom || selectedRoom + 4 == killerRoom || selectedRoom + 3 == killerRoom || selectedRoom + 5 == killerRoom) {
            printf("평범한 방이지만 어디선가에서 강한 피냄새가 납니다..\n");
            printf("[스페이스바를 눌러 계속...]");
            while (1) {
                if (keyControl() == SUBMIT) {
                    break;
                }
            }
                

        }

        if (selectedRoom - 1 == killerRoom) {
            system("cls");
            
            printf("\033[0;31m      #;                      \n");
            printf("     #@.                      \n");
            printf("    $@,        .~:;:-         \n");
            printf("   @@=        -@@@@@@#.       \n");
            printf("  *@@~       .#@:#@;@@*       \n");
            printf(" ~@@$        .#@~$@:$@=       \n");
            printf(" .!@~         !@@@@@@@-       \n");
            printf(":;=$      ,;*=;~!=$!;~!;      \n");
            printf("@@@@~    ~@@@@@@#!:*#@@@:     \n");
            printf(";@@@@=. =@@@@@@@@@@@@@@@@*    \n");
            printf(".=@@@@@#@@@@@@@@@@@@@@@@@@~   \n");
            printf("  -@@@@@@@@@@@@@@@@@@@@@@@@   \n");
            printf("    ;@@@@!;@@@@@@@@@@@@@@@@$  \n");
            printf("     .**~ ~@@@@@@@@@@@@@@#@@# \n");
            printf("          ~@@@@@@@@@@@@@@ #@@-\n");
            printf("          ~@@@@@@@@@@@@@@ .@@#\n");
            printf("          ~@@@@@@@@@@@@@@. ;@@\n");
            printf("          ~@@@@@@@@@@@@@@.  @@\n");
            printf("    선택한 방에는 살인마가 있습니다.\033[0m\n");
            printf("[스페이스 바를 누르면 메인화면으로 돌아갑니다.]");

            while (1) {
                if (keyControl() == SUBMIT) {
                    return;
                }
            }

        }

        else if (selectedRoom - 1 == exitRoom) {
            system("cls");

            printf("금고가 있는 방안입니다.\n");
            printf("아마 여기에 열쇠가 있는 듯합니다.\n");
            printf("일단 아무거나 눌러볼까요?\n");

            p_result = passward();
            if (p_result == 0) {
                system("cls");
                printf("\033[1;32m@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
                printf("@@@@$$$$$$$$$$$$$$$$$$$$#@@@@@\n");
                printf("@@@@      .             ~@@@@@\n");
                printf("@@@@   .=@@@@.          ~@@@@@\n");
                printf("@@@@   -@@@@@:          ~@@@@@\n");
                printf("@@@@    ;@@@@.          ~@@@@@\n");
                printf("@@@@     .!*=======*;-  ~@@@@@\n");
                printf("@@@@    -$@@@@@@@@@@@#, ~@@@@@\n");
                printf("@@@@   :@@@@@@@@@. :@@; ~@@@@@\n");
                printf("@@@@!!!@@@;$@@@@@!  ;@@!~@@@@@\n");
                printf("@@@@@@@@@- ;@@@@@@:  ;@.~@@@@@\n");
                printf("@@@@@;;;-    =@@@@@*     ~@@@@@\n");
                printf("@@@@@        =@@@@@@.    ~@@@@@\n");
                printf("@@@@@       :@@@*@@@,    ~@@@@@\n");
                printf("@@@@@      .=@@#,@@@,    ~@@@@@\n");
                printf("@@@@@      $@@@, @@@,    ,*@@@@\n");
                printf("@@@@@     !@@@*  #@@@@@@@@@@;@@\n");
                printf("@@@@@    ~@@@!   ~$@@@@@@@@@$=@\n");
                printf("축하합니다! 열쇠를 찾아 탈출에 성공했습니다.\033[0m\n");
                printf("[스페이스 바를 누르면 메인화면으로 돌아갑니다.]");
                while (1) {
                    if (keyControl() == SUBMIT) {
                        return;
                    }
                }
            }
            else if (p_result == -1) {
                system("cls");

                printf("\033[0;31m삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-\n삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-\n삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-\n삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-\n삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-\n삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-\n삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-\n삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-\n삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-삐- 삐- 삐-\033[0m\n");
              
                printf("금고의 보안 경고가 울려퍼집니다.\n");
                printf("(스페이스 바를 눌러 다음으로 넘어가세요)");
                
                while (1) {
                    if (keyControl() == SUBMIT) {
                        break;
                    }
                }

                system("cls");

                printf("\033[0;31m      #;                      \n");
                printf("     #@.                      \n");
                printf("    $@,        .~:;:-         \n");
                printf("   @@=        -@@@@@@#.       \n");
                printf("  *@@~       .#@:#@;@@*       \n");
                printf(" ~@@$        .#@~$@:$@=       \n");
                printf(" .!@~         !@@@@@@@-       \n");
                printf(":;=$      ,;*=;~!=$!;~!;      \n");
                printf("@@@@~    ~@@@@@@#!:*#@@@:     \n");
                printf(";@@@@=. =@@@@@@@@@@@@@@@@*    \n");
                printf(".=@@@@@#@@@@@@@@@@@@@@@@@@~   \n");
                printf("  -@@@@@@@@@@@@@@@@@@@@@@@@   \n");
                printf("    ;@@@@!;@@@@@@@@@@@@@@@@$  \n");
                printf("     .**~ ~@@@@@@@@@@@@@@#@@# \n");
                printf("          ~@@@@@@@@@@@@@@ #@@-\n");
                printf("          ~@@@@@@@@@@@@@@ .@@#\n");
                printf("          ~@@@@@@@@@@@@@@. ;@@\n");
                printf("          ~@@@@@@@@@@@@@@.  @@\n");
                printf("    당신의 방에 살인마가 찾아왔습니다.\033[0m\n");
                printf("[스페이스 바를 누르면 메인화면으로 돌아갑니다.]");

                while (1) {
                    if (keyControl() == SUBMIT) {
                        return;
                    }
                }
            }
        }

        else {
            rooms[selectedRoom - 1] = 1;
            remain--;

            system("cls");

            strcpy(Xrooms[selectedRoom - 1], "X");

            printf("==================HOTEL==================\n");
            printf("=========================================\n");
            printf("4층| %6s| %6s| %6s| %6s| %6s|\n", Xrooms[15], Xrooms[16], Xrooms[17], Xrooms[18], Xrooms[19]);
            printf("3층| %6s| %6s| %6s| %6s| %6s|\n", Xrooms[10], Xrooms[11], Xrooms[12], Xrooms[13], Xrooms[14]);
            printf("2층| %6s| %6s| %6s| %6s| %6s|\n", Xrooms[5], Xrooms[6], Xrooms[7], Xrooms[8], Xrooms[9]);
            printf("1층| %6s| %6s| %6s| %6s| %6s|\n", Xrooms[0], Xrooms[1], Xrooms[2], Xrooms[3], Xrooms[4]);



            printf("남은 방 : %d\n", remain);
            printf("========================================\n");
        }
    }
}

int passward() {
    //프로그램 시작할떄마다 다른 비밀번호가 나오게함
    srand(time(NULL));
    // 비밀번호 5가지 중 랜덤 선택
    int passwords[5] = { 1492, 1969, 1776, 1945, 2521 };
    int passwordIndex = rand() % 5;
    int selectedPassword = passwords[passwordIndex];

    int maxAttempts = 3;
    int attempt = 1;

    while (attempt <= maxAttempts)
    {
        int input;
        printf("비밀번호를 입력하세요 (남은 시도 횟수: %d): ", maxAttempts - attempt + 1);
        scanf("%d", &input);

        if (input == selectedPassword)
        {
            return 0;
        }
        else
        {
            printf("비밀번호가 틀렸습니다.\n");
            //처음에 틀렸을 때만 힌트가 나옴
            if (attempt == 1)
            {
                if (passwordIndex == 0)
                    printf("힌트: 해당 년도에는 세계적으로 알려진 사건으로서, 새로운 대륙의 발견과 관련이 있습니다.\n");
                else if (passwordIndex == 1)
                    printf("힌트: 해당년도에는 아폴로 11호가 발사되었으며 우주 탐사와 관련이 있습니다.\n");
                else if (passwordIndex == 2)
                    printf("힌트: 해당 년도에는 독립을 선언하는 행위와 관련이 있으며, 미국의 독립선언서가 발표된 해입니다.\n");
                else if (passwordIndex == 3)
                    printf("힌트: 해당 년도에는 제2차 세계 대전의 종료와 관련이 있으며, 대한민국이 광복한 날입니다\n");
                else if (passwordIndex == 4)
                    printf("힌트: 자우림의 노래 스OO섯, 스OO나\n");
            }
            attempt++;
        }
    }
    return -1;
}