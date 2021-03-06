	//Lab1 - Nasledovanie

#include <iostream>
	using namespace std;

	const int COUNT = 3;

	class Harbinger	{
	private:
		string hName, catchPhrase;
		int hAge;

	public:
		Harbinger(string hName = "Предвестник", int hAge = 2000, string catchPhrase = "\"Пойманная фраза\"");

		string GethName() {return hName;}
		void SethName(string hNameValue) {hName = hNameValue;}
		int GethAge() {return hAge;}
		void SethAge(int hAgeValue) {hAge = hAgeValue;}
		string GetCatchPhrase() {return catchPhrase;}
		void SetCatchPhrase(string cPhraseValue) {catchPhrase = cPhraseValue;}
	};

	Harbinger::Harbinger(string hName, int hAge, string catchPhrase) {
		this->hName = hName;
		this->hAge = hAge;
		this->catchPhrase = catchPhrase;
	}

	class Prophet : public Harbinger
	{
	private:
		string phName, phCall, magnumOpus[COUNT];
		int phAge;

	public:
		Prophet(string hName = "Пророк", int hAge = 50, string catchPhrase = "\"Пойманная фраза\"", string phName = "Пророк", string phCall = "default phCall", string defaltMagnumOpusElementValue = "default", int phAge = 30);

		string GetphName() {
			return phName;
		}

		void SetphName(string pNameValue) {
			phName = pNameValue;
		}

		string GetphCall() {
			return phCall;
		}

		void SetphCall() {
			string longestString = magnumOpus[0];
			for (int i = 1; i < COUNT; i++)
			{
				if (magnumOpus[i].length() > longestString.length())
				{
					longestString = magnumOpus[i];
				}
			}
			phCall = longestString;
		}

		string* GetMagnumOpus() {
			return magnumOpus;
		}

		void SetMagnumOpus() {
			cout << "Ввод массива magnumOpus\n";
			for (int i = 0; i < COUNT; i++)
			{
				cout << "Введите " << i << "-й эл-т: ";
				do {
					cin >> magnumOpus[i];
					if (magnumOpus[i].length() > 25)
					{
						cout << "Строка слишком длинная! Повторите попытку: ";
					}
				} while (magnumOpus[i].length() > 25);	
			}
			SetphCall();
		}

		int GetphAge() {
			return phAge;
		}

		void SetphAge(int pAgeValue) {
			phAge = pAgeValue;
		}
	};

	Prophet::Prophet(string hName, int hAge, string catchPhrase, string phName, string phCall, string defaltMagnumOpusElementValue, int phAge)
		: Harbinger(hName, hAge, catchPhrase) {
		this->phName = phName;
		this->phCall = phCall;
		this->phAge = phAge;
		for (int i = 0; i < COUNT; i++)
		{
			magnumOpus[i] = defaltMagnumOpusElementValue;
		}
	}

	class DeusEx : public Prophet
	{
	private:
		string gdName;
		int gdYear;

	public:
		DeusEx(string hName = "default hName", int hAge = 50, string cPhrase = "default catchPhrase", string phName = "default phName", string phCall = "default phCall", string defaltMagnumOpusElementValue = "default", int phAge = 30, string gdName = "default gdName")
			: Prophet(hName, hAge, cPhrase, phName, phCall, defaltMagnumOpusElementValue, phAge) {
			this->gdName = gdName;

			srand(time(0));
			gdYear = rand() % 10000;
		}

		string GetGdName() {
			return gdName;
		}

		int GetGdYear() {
			return gdYear;
		}

		void ShowInfo() {
			SethName("Аллах");
			SethAge(10000);
			SetCatchPhrase("придет Моисей");
			SetphName("Моисей");
			SetMagnumOpus();

			cout << GethName() << " в возрасте " << GethAge() << " говорил, что " << GetCatchPhrase() << ".\n";
			int count = 0;
			for (int i = 0; i < COUNT; i++)
			{
				if (GetMagnumOpus()[i] == GetphCall())
				{
					continue;
				}
				else
				{
					count++;
					if (count == 1)
					{
						cout << "Первое ";
					}
					else if (count == 2)
					{
						cout << "Второе ";
					}
					cout << "пророчество: " << GetMagnumOpus()[i] << "\n";
				}
			}
			cout << "Главное пророчество: " << GetphCall() << ".\n";
			cout << "Так говорил " << GetphName() << ".\n\n";
			cout << "В год " << gdYear << " пришел " << gdName << ", которого предрекали " << GethName() << " и " << GetphName() << ".\n\n";
		}
	};

	class Believer : private DeusEx
	{
	private:
		string bvName;
		int bvAge;

	public:
		Believer(string, int);

		string GetBelieverName() {
			return bvName;
		}

		void SetBelieverName(string bvName) {
			this->bvName = bvName;
		}

		int GetBelieverAge() {
			return bvAge;
		}

		void SetBelieverAge(int bvAge) {
			this->bvAge = bvAge;
		}

		void ShowMessage() {
			cout << "Верующий " << bvName << " молится " << GetGdName() << " именем " << GetphName() << "\n\n";
		}
	};

	Believer::Believer(string bvName, int bvAge)
	{
		this->bvName = bvName;
		this->bvAge = bvAge;
	}

	int main()
	{
		setlocale(LC_ALL, "ru");
		Prophet prophet;
		prophet.SetMagnumOpus();
		cout << "phCall: " << prophet.GetphCall() << "\n\n";

		DeusEx god;
		god.ShowInfo();

		Believer believer("христианин", 50);
		believer.ShowMessage();

		system("pause");
		return 0;
	}