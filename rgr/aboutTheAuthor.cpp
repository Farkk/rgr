#include <iostream>
#include "aboutTheAuthor.h"
#include "mainScreen.h"
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void generateInfo(int n, bool table, string text, string margin) {
    setlocale(LC_ALL, "C");

    char ch1(201);//╔
    char ch2(205);//═
    char ch3(187);//╗
    char ch4(200);//╚
    char ch5(188);//╝
    char ch6(185);//╣
    char ch7(204);//╠
    char ch8(186);//║

    int x = 40, y = 7;
    if (table) {
        GoToXY(x, y + n);
    }
    else {
        GoToXY(x, y);
    }
    
    for (int i = 0; i < 85; i++) {
        if (i == 0) {
            cout << ch1;
        }
        else {
            if (i > 0 && i <= 40) {
                cout << ch2;
            }
            if (i == 41) {
                cout << ch3 << endl;
            }
            if (i > 41 && i < 44) {
                if (i == 42) {
                    if (table) {
                        GoToXY(x, y + n + 1);
                    }
                    else {
                        GoToXY(x, y + n);
                    }
                    cout << ch8 << "\t" << "\t" << "\t" << "\t" << "\t" << " " << ch8 << endl;
                }
                else {
                    if (table) {
                        GoToXY(x, y + n + 1);
                    }
                    else {
                        GoToXY(x, y + n);
                    }
                    cout << ch8;
                    setlocale(LC_ALL, "ru");
                    cout << "\t" << margin << text << "\t" << "\t" << " ";
                    setlocale(LC_ALL, "C");
                    cout << endl;
                }
            }
            if (i == 44) {
                if (table) {
                    GoToXY(x, y + n + 2);
                }
                else {
                    GoToXY(x, y + n + 1);
                }
                cout << ch4;
            }
            if (i > 44 && i < 85) {
                cout << ch2;
                if (i == 84) {
                    cout << ch5;
                }
            }
        }
    }
}


int aboutTheAuthor() {
    system("cls");

    cursorInvisible(h);
    int nFirstTable = 1, nSecondTable = 4, nThirdTable = 8;
    
    string firstText = ">>Студент ОмГТУ<<", secondText = ">>Группы ИВТ-222<<", thirdText = ">>Латышев Павел Романович<<";
    string firstMargin = "     ", secondMarging = " ";
    
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
    generateInfo(nFirstTable, false, firstText, firstMargin);
    SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    generateInfo(nSecondTable, true, secondText, firstMargin);
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    generateInfo(nThirdTable, true, thirdText, secondMarging);

    goToBack();

    return 0;
}
