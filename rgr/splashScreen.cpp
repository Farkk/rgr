#include "splashScreen.h"
#include <iostream>
#include <iomanip>
#include "mainScreen.h"
#include <conio.h>
#include <Windows.h>
#include "string"

using namespace std;
#define ESC 27

HDC hDC = GetDC(GetConsoleWindow());

int splashScreen() {
    system("cls");
    srand(time(NULL));

    HBRUSH brush1 = CreateSolidBrush(RGB(0, 0, 0));
    HBRUSH brush2 = CreateSolidBrush(RGB(51, 0, 98, 255));
    HBRUSH brush3 = CreateSolidBrush(RGB(132, 148, 206, 255));
    HBRUSH brush4 = CreateSolidBrush(RGB(71, 17, 102, 255));
    HBRUSH brush5 = CreateSolidBrush(RGB(28, 28, 28, 255));
    HBRUSH brush6 = CreateSolidBrush(RGB(2, 206, 226, 255));
    HBRUSH brush7 = CreateSolidBrush(RGB(16, 16, 16, 255));


    cursorInvisible(hDC);

    bool spriteGenerate = true;

    int i = 0, coord = 0;

    do
    {
        SelectObject(hDC, brush3);
        Rectangle(hDC, 0, 0, 1000, 1000);

        if (coord == 50) {
            i--;
        }

        SelectObject(hDC, brush1);
        Rectangle(hDC, 550, 70 - i, 590, 90 - i);

        Rectangle(hDC, 510, 90 - i, 550, 110 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 550, 90 - i, 590, 110 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 90 - i, 610, 110 - i);

        Rectangle(hDC, 370, 110 - i, 510, 130 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 510, 110 - i, 550, 130 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 550, 110 - i, 590, 130 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 110 - i, 610, 130 - i);

        Rectangle(hDC, 330, 130 - i, 370, 150 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 370, 130 - i, 450, 150 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 450, 130 - i, 490, 150 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 490, 130 - i, 570, 150 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 570, 130 - i, 590, 150 - i);

        Rectangle(hDC, 310, 150 - i, 330, 170 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 330, 150 - i, 430, 170 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 430, 150 - i, 450, 170 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 450, 150 - i, 490, 170 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 490, 150 - i, 550, 170 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 550, 150 - i, 570, 170 - i);

        Rectangle(hDC, 290, 170 - i, 310, 190 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 310, 170 - i, 370, 190 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 370, 170 - i, 430, 190 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 430, 170 - i, 450, 190 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 450, 170 - i, 510, 190 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 510, 170 - i, 550, 190 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 550, 170 - i, 570, 190 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 570, 170 - i, 590, 190 - i);

        Rectangle(hDC, 270, 190 - i, 290, 210 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 290, 190 - i, 350, 210 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 350, 190 - i, 370, 210 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 370, 190 - i, 510, 210 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 510, 190 - i, 530, 210 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 530, 190 - i, 570, 210 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 570, 190 - i, 590, 210 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 190 - i, 610, 210 - i);

        Rectangle(hDC, 270, 210 - i, 290, 230 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 290, 210 - i, 330, 230 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 330, 210 - i, 350, 230 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 350, 210 - i, 530, 230 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 530, 210 - i, 550, 230 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 550, 210 - i, 570, 230 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 570, 210 - i, 590, 230 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 210 - i, 610, 230 - i);

        Rectangle(hDC, 270, 230 - i, 290, 250 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 290, 230 - i, 310, 250 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 310, 230 - i, 330, 250 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 330, 230 - i, 550, 250 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 550, 230 - i, 570, 250 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 570, 230 - i, 590, 250 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 230 - i, 610, 250 - i);

        Rectangle(hDC, 270, 250 - i, 290, 270 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 290, 250 - i, 310, 270 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 310, 250 - i, 330, 270 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 330, 250 - i, 370, 270 - i);
        SelectObject(hDC, brush6);
        Rectangle(hDC, 370, 250 - i, 390, 270 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 390, 250 - i, 490, 270 - i);
        SelectObject(hDC, brush6);
        Rectangle(hDC, 490, 250 - i, 510, 270 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 510, 250 - i, 530, 270 - i);
        SelectObject(hDC, brush7);
        Rectangle(hDC, 530, 250 - i, 550, 270 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 550, 250 - i, 570, 270 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 570, 250 - i, 590, 270 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 250 - i, 610, 270 - i);

        Rectangle(hDC, 270, 270 - i, 290, 290 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 290, 270 - i, 310, 290 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 310, 270 - i, 330, 290 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 330, 270 - i, 370, 290 - i);
        SelectObject(hDC, brush6);
        Rectangle(hDC, 370, 270 - i, 390, 290 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 390, 270 - i, 490, 290 - i);
        SelectObject(hDC, brush6);
        Rectangle(hDC, 490, 270 - i, 510, 290 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 510, 270 - i, 530, 290 - i);
        SelectObject(hDC, brush7);
        Rectangle(hDC, 530, 270 - i, 550, 290 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 550, 270 - i, 570, 290 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 570, 270 - i, 590, 290 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 270 - i, 610, 290 - i);

        Rectangle(hDC, 270, 290 - i, 290, 310 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 290, 290 - i, 310, 310 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 310, 290 - i, 330, 310 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 330, 290 - i, 370, 310 - i);
        SelectObject(hDC, brush6);
        Rectangle(hDC, 370, 290 - i, 390, 310 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 390, 290 - i, 490, 310 - i);
        SelectObject(hDC, brush6);
        Rectangle(hDC, 490, 290 - i, 510, 310 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 510, 290 - i, 530, 310 - i);
        SelectObject(hDC, brush7);
        Rectangle(hDC, 530, 290 - i, 550, 310 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 550, 290 - i, 570, 310 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 570, 290 - i, 590, 310 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 290 - i, 610, 310 - i);

        Rectangle(hDC, 270, 310 - i, 290, 330 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 290, 310 - i, 310, 330 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 310, 310 - i, 330, 330 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 330, 310 - i, 510, 330 - i);
        SelectObject(hDC, brush7);
        Rectangle(hDC, 510, 310 - i, 550, 330 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 550, 310 - i, 570, 330 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 570, 310 - i, 590, 330 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 310 - i, 610, 330 - i);

        Rectangle(hDC, 270, 330 - i, 290, 350 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 290, 330 - i, 330, 350 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 330, 330 - i, 350, 350 - i);
        SelectObject(hDC, brush5);
        Rectangle(hDC, 350, 330 - i, 370, 350 - i);
        SelectObject(hDC, brush7);
        Rectangle(hDC, 370, 330 - i, 530, 350 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 530, 330 - i, 550, 350 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 550, 330 - i, 570, 350 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 570, 330 - i, 590, 350 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 330 - i, 610, 350 - i);

        Rectangle(hDC, 270, 350 - i, 290, 370 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 290, 350 - i, 350, 370 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 350, 350 - i, 370, 370 - i);
        Rectangle(hDC, 370, 350 - i, 530, 370 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 530, 350 - i, 570, 370 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 570, 350 - i, 590, 370 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 590, 350 - i, 610, 370 - i);

        Rectangle(hDC, 290, 370 - i, 310, 390 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 310, 370 - i, 510, 390 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 510, 370 - i, 570, 390 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 570, 370 - i, 590, 390 - i);

        Rectangle(hDC, 310, 390 - i, 330, 410 - i);
        SelectObject(hDC, brush7);
        Rectangle(hDC, 330, 390 - i, 370, 410 - i);
        SelectObject(hDC, brush4);
        Rectangle(hDC, 370, 390 - i, 490, 410 - i);
        SelectObject(hDC, brush2);
        Rectangle(hDC, 490, 390 - i, 510, 410 - i);
        SelectObject(hDC, brush7);
        Rectangle(hDC, 510, 390 - i, 550, 410 - i);
        SelectObject(hDC, brush1);
        Rectangle(hDC, 550, 390 - i, 570, 410 - i);

        if (coord == 100) {
            coord = 0;
            i = 0;
            continue;
        }
        if (i < 50 && coord < 50) {
            i++;
            Sleep(5);
        }
        if (coord >= 50 && i > -50) {
            i--;
            Sleep(5);
        }

        if (_kbhit()) {
            int key = _getch();
            if (key == ESC)
            {
                mainScreen(); break;
            }
        }
        coord++;
        } while (true);

    return 0;
}