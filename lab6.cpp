//lab 6
// возвращение максимального значения
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>


using namespace std;

int max_zn(int a, int b, int c) {
    cout << "Введите 3 аргумента";
    cin >> a >> b >> c;
    cout << "Максимальное из введеных вами чисел - " << max(a, max(b, c));
    return max(a, max(b, c));
}


int predel(int left, int right) {

    double z;
    cin >> z; //считываем число
    if (z<left || z>right || z == (long)z) Menu(&left, &right, &z);
    else return z;
}

// часть А
int Menu(int* left, int* right, double* z) {
    cout << "\nДоступные действия:\n\n";

    cout << "1: Ввод верхнего предела\t";
    cout << "2: Ввод нижнего предела\n";
    cout << "3: Повторный ввод числа\t";
    cout << "Ввод любого иного варианта для выхода из программы";
    int k;
    cin >> k;
    switch (k) {
    case 1: cin >> *left;
    case 2: cin >> *right;
    case 3: cin >> *z;
    default: exit(1);
    };
};

//массив вставками уже был во 2й лабораторной, копирую сюда же

const int NN = 10;
void sort() {
    int Mas_6[NN];
    srand(10);
    for (int i = 1; i < NN; i++) Mas_6[i] = rand() % 144;   // Заполняем Mas_6
    int tmp;
    for (int i = 1; i < NN; i++)
        for (int j = i; j > 0 && Mas_6[j - 1] > Mas_6[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
        {                   // меняем местами элементы j и j-1
            tmp = Mas_6[j - 1];
            Mas_6[j - 1] = Mas_6[j];
            Mas_6[j] = tmp;
        };
}
