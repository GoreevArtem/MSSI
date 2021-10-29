#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

//Преобразование в двоичный код

void decToBin(int a, int** fin, int m)
{
	int count = 0;
	int j = 0;
	for (int i = 0; i < 8; i++)
	{
		int b = a % 2;
		int c = a / 2;
		a = c;
		fin[m][7 - i] = b;
	}
}

//операция XOR
void XOR(int** strFin, int** gammaFin, int** fin, int strLength, int gammaLength)
{
	int m = 0;                         //счетчик букв в гамме
	for (int i = 0; i < strLength; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((strFin[i][j] == 1 && gammaFin[m][j] == 1) ||
				(strFin[i][j] == 0 && gammaFin[m][j] == 0))
			{
				fin[i][j] = 0;
				m++;
			}
			else
			{
				fin[i][j] = 1;
				m++;
			}
			if (m == gammaLength)
				m = 0;              //идем по гамме снова
		}
	}
}

//преобразование двоичного кода в десятичный
void binToDec(int** fin, int strLength, int* strAscii)
{
	for (int i = 0; i < strLength; i++)
	{
		int power = 0;           //степень, в которую возводим 2
		strAscii[i] = 0;         //обнуляем данные массива
		for (int j = 0; j < 8; j++)
		{
			strAscii[i] += fin[i][7 - j] * pow(2, power);
			power++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите строку: ";
	string str;
	getline(cin, str);
	cout << "Введите гамму: ";
	string gamma;
	getline(cin, gamma);
	int strLen = str.length();
	int gamLen = gamma.length();
	int** strFin = new int* [100];    //двоичный код строки
	int** gammaFin = new int* [100];  //двоичный код гаммы
	int** finEnc = new int* [100]; //XOR зашифрованного сообщения
	int** finDecr = new int* [100]; //XOR расшифрованного сообщения
	for (int i = 0; i < 100; i++)
	{
		strFin[i] = new int[100];
		gammaFin[i] = new int[100];
		finEnc[i] = new int[100];
		finDecr[i] = new int[100];
	}
	char* strCh = new char[100];      //массив char строки
	char* gammaCh = new char[100];    //массив char гаммы
	int* strAscii = new int[100];     //ascii-код строки
	int* gammaAscii = new int[100];   //ascii-код гаммы
	char* encrypted = new char[100];  //зашифрованная строка
	char* decrypted = new char[100];  //расшифрованная строка

	for (int i = 0; i < gamma.length(); i++)
	{
		gammaCh[i] = gamma[i];        //преобразуем string в char
		gammaAscii[i] = (int)gammaCh[i];//преобразуем char в int
		//преобразуем гамму в двоичный код
		decToBin(gammaAscii[i], gammaFin, i);
	}
	for (int i = 0; i < str.length(); i++)
	{
		strCh[i] = str[i];
		strAscii[i] = (int)strCh[i];
		//преобразуем десятичный в двоичный код
		decToBin(strAscii[i], strFin, i);
	}
	//операция XOR для строки и гаммы
	XOR(strFin, gammaFin, finEnc, strLen, gamLen);

	//преобразуем двоичный код в десятичный
	binToDec(finEnc, strLen, strAscii);
	cout << endl;

	cout << "Зашифрованное сообщение: ";
	for (int i = 0; i < str.length(); i++)
	{
		encrypted[i] = (char)strAscii[i];
		cout << encrypted[i];
	}
	cout << endl;

	//операция XOR для строки и гаммы
	XOR(finEnc, gammaFin, finDecr, strLen, gamLen);

	//преобразуем двоичный код в десятичный 
	binToDec(finDecr, strLen, gammaAscii);

	cout << "Расшифрованное сообщение: ";
	for (int i = 0; i < str.length(); i++)
	{
		decrypted[i] = (char)gammaAscii[i];
		cout << decrypted[i];
	}
	return 0;
}
