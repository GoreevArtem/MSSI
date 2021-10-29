#include <Windows.h>
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;
typedef long long LL;

const LL MAX = SHRT_MAX;
const LL MIN = SHRT_MAX / 2 + 1;

LL p, q, n, e, d, f, mes;

//Поиск наибольшего общего делителя
int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

LL modPow(LL x, LL e, LL n)
{
    LL res = 1;
    while (e>0)
    {
        if (e % 2 == 1)
        {
            res = (res * x) % n;
        }
        e = e / 2;
        x = (x * x) % n;
    }
    return res;
}

//тест Миллера-Рабина
//Смотрим, является ли число простым или же составным

bool testMillerRabin(LL n)
{
    LL a, s = 0, d = 1, x, temp = n - 1;
    bool flag = false;
    if (n % 2 == 0)
    {
        return false;
    }

    while (temp % 2 !=1)
    {
        s++;
        temp /= 2;
    }
    for (int i = 0; i < 20; i++)
    {
        a = rand() % (n - 3) + 2;
        x = modPow(a, d, n);
        if (x == 1 || x == n - 1)
        {
            continue;
        }
        for (int r = 1; r < s; r++)
        {
            x = modPow(x, 2, n);
            if (x == 1)
            {
                return false;
            }
            if (x == n - 1)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        return false;
    }
    return true;
}

//Генерация ключа
void keyGen()
{
    do
    {
        p = rand() % MAX + MIN;
    } while (!testMillerRabin(p));

    do
    {
        q = rand() % MAX + MIN;
    } while (!testMillerRabin(q));

    n = p * q;

    f = (p - 1) * (q - 1);

    e = rand() % n;

    cout << "p=" << p << "\n"
        << "q=" << q << "\n"
        << "N=" << n << "\n"
        << "f=" << f << "\n"
        << "e=" << e << "\n";

    d = GCD(f, e);

    cout << "d=" << d << endl;

}

//Алгорим RSA
string RSA(string& str)
{
    keyGen();
    string crypted;
    string decrypted;
    for (int i = 0; i < str.size(); i++)
    {
        mes = str[i];
        crypted.push_back(modPow(mes, e, n));
        decrypted.push_back(mes);
    }
    cout << "Зашифрованное сообщение\n" << crypted << endl;
    cout << "Расшифрованное сообщение\n" << decrypted << endl;
    return str;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    string message = "";
    cout << "Введите сообщение, которое нужно зашифровать\n";
    getline(cin, message);

    RSA(message);
    
}
