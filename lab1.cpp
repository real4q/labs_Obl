// lab1

#include <iostream>


int main()
{
	setlocale(LC_ALL, "ru");
	using namespace std;

	int mas[10];	// создаем и заполняем массив
	for (int i = 0; i < 10; i++) {
		mas[i] = i;
	}

	// Меняем четные на 0
	for (int i = 0; i < 10; i++) {
		if (mas[i] % 2 == 0) mas[i] = 0;
	}

	// Ввод символа и строки с проверкой
	char c;
	do {
		cin >> c;
	} while (isalpha(c));

	string str = "";
	do {
		cin >> str;
	} while (str.empty() ? 0 : 1);

	// Поиск позиции символа в строке
	int flag = -1;
	for (int i = 0; i < str.length(); i++) {
		if (c == str[i]) flag = i; cout << flag; break;
	}
	if (flag = -1) cout << "Символа в строке нет";

	// Определитель
	int Opr[3][3];
	int det = 0;

	// Ввод построчно
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> Opr[i][j];
		}
	}
	// Расчет определителя 
	det = Opr[0][0] * Opr[1][1] * Opr[2][2] + Opr[0][1] * Opr[1][2] * Opr[2][0] + Opr[0][2] * Opr[1][0] * Opr[2][1];		//для удобства перенес
	det = det - Opr[0][2] * Opr[1][1] * Opr[2][0] - Opr[0][0] * Opr[1][2] * Opr[2][1] - Opr[0][1] * Opr[1][0] * Opr[2][2];  //вычитаемое на строку
	cout << det;
	system("p");
}
