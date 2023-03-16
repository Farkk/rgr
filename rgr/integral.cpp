#include "integral.h"
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

double integralResult(double x) {
    return (cos(x) / (sin(x) + cos(x)));
}

double rectangleMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += h * integralResult(a + i * h);
    }
    return sum;
}

double trapezoidMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = integralResult(a) + integralResult(b);

    for (int i = 1; i < n; i++) {
        sum += 2 * integralResult(a + i * h);
    }

    sum *= h / 2;
    return sum;
}

int integral()
{
    system("cls");
    cout << ">> Заставка\n";
    float a;
    float b;
    int n;
    GoToXY(40, 7);
    cout << "Введите начало отрезка для расчётов: ";
    cin >> a;
    GoToXY(40, 8);
    cout << "Введите конец отрезка для расчётов: ";
    cin >> b;
    GoToXY(40, 9);
    cout << "Введите число иттераций: ";
    cin >> n;

    system("cls");

    int t = a;
    int u = b;
    float x = rectangleMethod(a, b, n), x2 = trapezoidMethod(a, b, n);

    string firstText = "Интеграл Cos(x) / (Sin(x) + Cos(x)) на отрезке[" + to_string(t) + ", " + to_string(u) + "]";
    string firstMarginLeft = "    ", firstRight = "    ";

    string secondText = "Методом прямоугольников: " + to_string(x);
    string secondMarginLeft = "            ", secondRight = "              ";

    string thirdText = "Методом Трапеции: " + to_string(x2);
    string thirdMarginLeft = "                ", thirdRight = "                 ";

    generateEquationInfo(1, false, firstText, firstMarginLeft, firstRight);
    generateEquationInfo(4, true, secondText, secondMarginLeft, secondRight);
    generateEquationInfo(8, true, thirdText, thirdMarginLeft, thirdRight);

    goToBack();

    return 0;
}
