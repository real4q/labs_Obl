//lab8

#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    int N;

    do {
        cout << "\n\n������� 5-������� ����� �����:\n";
        cin >> N;
    } while (N > 9999 && N < 100000);

    int t;
    cout << "������� � ������? (0 - ���, 1 - ��)\n";
    cin >> t;
    if (t) {
        int k = N //������� �����, ������� � ������
            for (int i = 0; i < 5; i++) {
                cout << "\n" << k % 10;
                k /= 10;
            }
    }
    else {
        int k[5] // �����, ������� �� �������� �������
            k[5] = N; // ��������� ��������
        for (int i = 0; i < 5; i++) {
            k[i] = N % 5;
            N /= 10;
        }
        for (int i = 4; i > -1; i--) {
            cout << "\n" << k[i];
        }
    }

    // ������� � ������� �������
    char c;
    do {
        cout << "\n\n������� ��������� ����� � ������ ��������: \n";
        cin >> c;
    } while (c > 96 && c < 123);
    c -= 32;

    cout << "���� ����������� �����: " << c;
          
}

// ������� �������������� �������
double sred_ar_mas()
{
    int Mas_8[15];
    for (int i = 0; i < 15; i++)
    {
        Mas_8[i] = -2 + 3 * i; // �������� ������
    }
    double sum = 0;
    int schetchik = 0;
    for (int i = 0; i < 15; i++)
    {
        sum += Mas_8[i];
        schetchik++;
    }
    return sum / schetchik;
}