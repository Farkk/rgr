#include "graphs.h"
#include "mainScreen.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <math.h>

using namespace std;

HANDLE graphsScreen = GetStdHandle(STD_OUTPUT_HANDLE);

float F1(float x) {
	return 2 - cos(x);
}

float F2(float x) {
	return sqrt(x + 4);
}

int graphs()
{
	system("cls");
	
	SetConsoleTextAttribute(graphsScreen, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	cout << ">> Графики\n";
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN pen1 = CreatePen(PS_SOLID, 2, RGB(226, 252, 70, 1));
	HPEN pen2 = CreatePen(PS_SOLID, 2, RGB(252, 70, 72, 1));

	for (float x = -3.14; x <= 3.14; x += 0.001)//отрисовка двух функций 
	{
		SelectObject(hDC, pen1);
		MoveToEx(hDC, 100 * x + 550, -100 * F1(x) + 300, NULL);//обновление текущей позиции указанной точки
		LineTo(hDC, 100 * x + 550, -100 * F1(x) + 300);//нарисовать в точку
		SelectObject(hDC, pen2);
		MoveToEx(hDC, 100 * x + 550, -100 * F2(x) + 300, NULL);
		LineTo(hDC, 100 * x + 550, -100 * F2(x) + 300);
	}

	HPEN pen3 = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, pen3);
	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, RGB(226, 252, 70, 1));

	TextOut(hDC, 610, 200,L"|2 - COS(x)|",12);
	SetTextColor(hDC, RGB(252, 70, 72, 1));
	TextOut(hDC, 225, 150, L"|SQRT(x + 4)|", 13);
	SetTextColor(hDC, RGB(252, 70, 72, 1));
	TextOut(hDC, 945, 315, L"X", 1);
	TextOut(hDC, 570, 20, L"Y", 1);
	TextOut(hDC, 555, 305, L"0", 1);
	MoveToEx(hDC, 960, 300, NULL);
	LineTo(hDC, 940, 290);
	MoveToEx(hDC, 960, 300, NULL);
	LineTo(hDC, 940, 310);
	MoveToEx(hDC, 550, 0, NULL);
	LineTo(hDC, 550, 600);
	MoveToEx(hDC, 0, 300, NULL);
	LineTo(hDC, 955, 300);
	MoveToEx(hDC, 550, 0, NULL);
	LineTo(hDC, 540, 20);
	MoveToEx(hDC, 550, 0, NULL);
	LineTo(hDC, 560, 20);
	setlocale(LC_ALL, "rus");

	goToBack();

	return 0;
}

    

