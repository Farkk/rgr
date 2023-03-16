#pragma once
#include <Windows.h>
int mainScreen();
int cursorInvisible(HANDLE hStdOut);
int GoToXY(short x, short y);
void goToBack();