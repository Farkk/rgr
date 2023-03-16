#include <iostream>
#include <iomanip>
#include "table.h"
#include "mainScreen.h"
#include <conio.h>
#include <Windows.h>

#define a -3.14
#define b 3.14

HANDLE tableToScreen = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

float maxAndMin(float dx, float* maxF2, float* minF1, float* minF2) {
    float max = -111111, max2 = -1111111;
    float min = 111111, min2 = 1111111;
    float f1, f2;
    float y = a;
    for (int i = 0; i < 16; i++) {
        f1 = 2 - cos(y);
        f2 = sqrt(y + 4);
        if (f1 > max) {
            max = f1;
        }
        if (f1 < min) {
            min = f1;
        }
        if (f2 > max2) {
            max2 = f2;
        }
        if (f2 < min2) {
            min2 = f2;
        }
        y += dx;
    }
    *maxF2 = max2;
    *minF1 = min;
    *minF2 = min2;

    return max;
}

int generateTable() {
    int xPoint = 30, y = 0;

    char ch1(201);//╔
    char ch2(205);//═
    char ch3(187);//╗
    char ch4(200);//╚
    char ch5(188);//╝
    char ch8(186);//║

    float n = 16;
    float dx;
    float f1[16], f2[16], x[16];
    float maxF2, minF1, minF2;

    dx = fabs(b - a) / (n - 1);
    x[0] = a;

    float maxF1 = maxAndMin(dx, &maxF2, &minF1, &minF2);

    setlocale(LC_ALL, "C");

    GoToXY(xPoint, y);
    for (int i = 0; i < 58; i++) {
        if (i == 0) {
            cout << ch1;
        }
        if (i == 57) {
            cout << ch3 << endl;
        }
        else {
            cout << ch2;
        }
    }

    GoToXY(xPoint, y += 1);
    cout << ch8 << "\t   I    " << ch8 << "\tX[i]    " << ch8 << "\tF1[i]   " << ch8 << "\tF2[i]   " << ch8 << endl;
    GoToXY(xPoint, y += 1);
    cout << ch8;

    for (int i = 0; i < 54; i++) {
        cout << ch2;
        if (i == 38 || i == 8 || i == 23) {
            cout << ch8;
        }
        if (i == 53) {
            cout << ch8;
        }
    }

    // Вывод таблички с числами
    for (int i = 0; i < n; i++) {
        f1[i] = 2 - cos(x[i]);
        f2[i] = sqrt(x[i] + 4);

        GoToXY(xPoint, y += 1);
        cout << setprecision(3) << ch8 << "    " << (i + 1) << "\t" << ch8 << "\t" << x[i] << "\t" << ch8 << "\t";

        if (maxF1 == f1[i]) {
            SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << f1[i];
            SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else {
            if (minF1 == f1[i]) {
                SetConsoleTextAttribute(tableToScreen, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                cout << f1[i];
                SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else {
                cout << f1[i];
            }
        }
        SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\t" << ch8 << "\t";

        if (maxF2 == f2[i]) {
            SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << f2[i];
            SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        else {
            if (minF2 == f2[i]) {
                SetConsoleTextAttribute(tableToScreen, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                cout << f2[i];
                SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else {
                cout << f2[i];
            }
        }

        SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "\t" << ch8 << endl;

        if (i == n - 1) {
            x[i] += dx;
        }
        else {
            x[i + 1] = x[i] + dx;
        }
    }
    
    SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    GoToXY(xPoint, y += 1);
    for (int i = 0; i < 58; i++) {
        if (i == 0) {
            cout << ch4;
        }
        if (i == 57) {
            cout << ch5 << endl;
        }
        else {
            cout << ch2;
        }
    }
    cout << "\n\n";

    setlocale(LC_ALL, "ru");

    SetConsoleTextAttribute(tableToScreen, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << setprecision(10) << "Минимальный элемент первой функции: " << minF1 << endl;
    SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << "Максимальный элемент первой функции: " << maxF1 << endl;

    SetConsoleTextAttribute(tableToScreen, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout  << "Минимальный элемент второй функции: " << minF2 << endl;
    SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED| FOREGROUND_INTENSITY);
    cout << "Максимальный элемент второй функции: " << maxF2 << endl;

    cout << "\n\n\nНажмите ESC для выхода....";

    return 0;
}

int table()
{
    system("cls");

    SetConsoleTextAttribute(tableToScreen, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    cout << ">> Таблица\n";
    
    generateTable();

    goToBack();

    return 0;
}
