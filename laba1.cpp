//Программа определяет с заданной точностью сумму членов бесконечного степенного ряда
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    setlocale(LC_ALL, "RUSSIAN");
    //Инициализация переменных
    double Eps = 0;//Погрешность
    cout << "Допустимая погрешность: ";
    cin >> Eps; //Ввод погрешности
    if (Eps <= 0) {//Входной контроль
        cout << "Погрешность должна быть положительной.";
        return 1;
    }//if
    const double PI = 3.141592653589793;//Пи
    const double TSum = PI * PI * PI / 32;//Точная сумма бесконечного ряда
    double Sum = 1;//Сумма искомого ряда
    double Diff = Sum - TSum;//Погрешность искомой суммы
    double Slag = 0;//Слагаемое
    int ArgN = 0;//Знаменатель
    int N = 1;//Количество переменных
    int Znak = 1;//Знак переменной
    while (Diff > Eps) {//Вычисление суммы ряда
        Znak *= -1;
        N += 1;
        ArgN = (2 * N - 1) * (2 * N - 1) * (2 * N - 1);
        Slag = Znak / double(ArgN);//Вычисление слагаемого
        Sum += Slag;
        Diff = fabs(Sum - TSum);
    }//while
    //Печать результатов
    cout << "Кол-во переменных: " << N << endl;
    cout << "Сумма: " << Sum << endl;
    cout << "Разность суммы и точного значения: " << Diff << endl;
    return 0;
}
