#include "mainScreen.h"
#include "aboutTheAuthor.h"
#include "table.h"
#include "graphs.h"
#include "equation.h"
#include "integral.h"
#include "splashScreen.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <math.h>

#define UP 72
#define DOWN 80
#define ENTER 13
#define ESC 27

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void goToBack() {
	while (true) {
		int ch = _getch();
		switch (ch)
		{
		case ESC: mainScreen(); break;
		default: continue;
		}
	}
}

int GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
	return 0;
}

int cursorInvisible(HANDLE hStdOut) {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	return 0;
}

void ganerateMenu(int activeMenu) {
	string menu[] = { "Таблица", "Графики", "Уравнения", "Интегралы", "Заставка", "Об Авторе", "Выход" };
	int x = 55, y = 5;
	GoToXY(x, y);

	for (int i = 0; i < size(menu); i++) {
		GoToXY(x, y += 2);
		if (activeMenu == i) {
			SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
			;
		}
		else {
			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
		}
		cout << menu[i];
	}
}

int controlMenu(int key, int activeMenu) {
	switch (key)
	{
	case UP:
		if (activeMenu == 0) {
			activeMenu = 6;
			break;
		}
		else {
			activeMenu--;
			break;
		}
	case DOWN:
		if (activeMenu == 6) {
			activeMenu = 0;
			break;
		}
		else {
			activeMenu++;
			break;
		}
	case ENTER:
		switch (activeMenu)
		{
		case 0: table(); break;
		case 1: graphs(); break;
		case 2: equation(); break;
		case 3: integral(); break;
		case 4: splashScreen(); break;
		case 5: aboutTheAuthor(); break;
		case 6: exit(0); break;
		}
	case ESC: exit(0); break;
	}

	return activeMenu;
}

int mainScreen()
{	
	system("cls");

	setlocale(LC_ALL, "Rus");

	SetConsoleTitle(L"Ргр");

	cursorInvisible(hStdOut);

	bool inMenu = true;

	int activeMenu = 0;

	while (inMenu) {

		ganerateMenu(activeMenu);

		int key = _getch();

		activeMenu = controlMenu(key, activeMenu);

	}
	return 0;
}
