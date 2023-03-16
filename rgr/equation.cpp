#include <iostream>
#include <iomanip>
#include "table.h"
#include "mainScreen.h"
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include "aboutTheAuthor.h"
#include "string"
#include "mainScreen.h"
#include "equation.h"

using namespace std;

float equationResult(float x) {
	return (pow(x, 3)- 2 * pow(x, 2) - 4);
}

float dEquationResult(float x) {
    return (3 * pow(x, 2) - 4 * x);
}

float halfDivisionMethod(float a, float b, float e) {
	float c = 0;
	while ((b - a) >= e) {
		c = (a + b) / 2;
		if ((equationResult(a) * equationResult(c)) < 0) {
			b = c;
		}
		else {
			a = c;
		}
	}
	return c;
}

float chordMethod(float x, float e) {
    float c = x;
    float h = equationResult(c) / dEquationResult(c);
    while (abs(h) >= e) {
        h = equationResult(c) / dEquationResult(c);
        c = c - h;
    }
    return c;
}

void generateEquationInfo(int n, bool table, string text, string marginLeft, string marginRight) {
    setlocale(LC_ALL, "C");

    char ch1(201);//╔
    char ch2(205);//═
    char ch3(187);//╗
    char ch4(200);//╚
    char ch5(188);//╝
    char ch6(185);//╣
    char ch7(204);//╠
    char ch8(186);//║

    int x = 31, y = 7;
    if (table) {
        GoToXY(x, y + n);
    }
    else {
        GoToXY(x, y);
    }

    for (int i = 0; i < 125; i++) {
        if (i == 0) {
            cout << ch1;
        }
        else {
            if (i > 0 && i <= 60) {
                cout << ch2;
            }
            if (i == 61) {
                cout << ch3 << endl;
            }
            if (i > 61 && i < 64) {
                if (i == 62) {
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
                    cout << marginLeft << text  << marginRight;
                    setlocale(LC_ALL, "C");
                    cout  << ch8 << endl;
                }
            }
            if (i == 64) {
                if (table) {
                    GoToXY(x, y + n + 2);
                }
                else {
                    GoToXY(x, y + n + 1);
                }
                cout << ch4;
            }
            if (i > 64 && i < 125) {
                cout << ch2;
                if (i == 124) {
                    cout << ch5;
                }
            }
        }
    }
}

int equation()
{
	system("cls");
    cout << ">> Уравнения\n";
    float a;
    float b;
    GoToXY(40, 7);
    cout << "Введите начало отрезка для расчётов: ";
    cin >> a;
    GoToXY(40, 8);
    cout << "Введите конец отрезка для расчётов: ";
    cin >> b;

    system("cls");

	float e = 0.001;
	int t = a;
	int u = b;
    float x = halfDivisionMethod(a, b, e);
    float x2 = chordMethod(x, e);

	string firstText = "Решение уравнения x^3 - 2x^2 - 4 = 0 на промежутке [" + to_string(t) + "," + to_string(u) + "]";
    string firstMarginLeft = "  ", firstMarginRight = "  ";

    string secondText = "Методом половинного деления: x = " + to_string(x);
    string secondMarginLeft = "         ", secondMarginRight = "          ";

    string thirdText = "Методом хорд: x = " + to_string(x2);
    string thirdMarginLeft = "                 ", thirdMarginRight = "                 ";

    string fourthText = "Точность: " + to_string(e);
    string fourthMarginLeft = "                     ", fourthMarginRight = "                     ";

    generateEquationInfo(1, false, firstText, firstMarginLeft, firstMarginRight);
    generateEquationInfo(4, true, secondText, secondMarginLeft, secondMarginRight);
    generateEquationInfo(8, true, thirdText, thirdMarginLeft, thirdMarginRight);
    generateEquationInfo(12, true, fourthText, fourthMarginLeft, fourthMarginRight);

    goToBack();
	return 0;
}
