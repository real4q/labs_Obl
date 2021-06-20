//lab 7
//Среднее гармоническое
#include <iostream>
using namespace std;

double sr_g(double a, double b)
{
    if (a != 0 && b != 0)
        cout << "Результат: " << (2 * a * b) / (a + b) << endl;
    else
        cout << "На 0 нельзя делить, введите значения повторно\n";
    return (2 * a * b) / (a + b);
}


//Сортировка
void sort_7(double& a7, double& b7, double& c7)
{
    double aa, bb, cc;
    if (a7 == max(a7, max(b7, c7))) {   //В "а" максимум?
        aa = a7; if (b7 > c7) {
            bb = b7; cc = c7;
        }
        else {
            bb = c7; cc = b7;
        }
    }

    else if (b7 == max(a7, max(b7, c7))) {//В "b" максимум?
        aa = b7; if (a7 > c7) {
            bb = a7; cc = c7;
        }
        else {
            bb = c7; cc = a7;
        }
    }

    else if (c7 == max(a7, max(b7, c7))) {//В "c" максимум?
        aa = c7; if (b7 > a7) {
            bb = b7; cc = a7;
        }
        else {
            bb = a7; cc = b7;
        }
    }
    a7 = aa;    // Записываем по возрастанию
    b7 = bb;
    c7 = cc;
}

int main()
{
    setlocale(LC_ALL, "RU");
    double a, b, c;

    cout << "Введите 3 числа типа double:\n";
    cin >> a >> b >> c;
    //Сортировка
    sort_7(a, b, c);
    cout << "Результат сортировки: " << a << " " << b << " " << c;
    //Среднее гармоническое
    sr_g(a, c);
    return 0;
}