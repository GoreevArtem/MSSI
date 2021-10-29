#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;


/*
class Solution
{
public:
    vector<int> MaxPooling(const vector<int>& a, const int k)
    {
        queue<int> q;
        vector<int> output_A;
        int i = 0;
        int c = 0;

        while (q.size() != k)
        {
            q.push(a[i]);
            i++;
        }

        output_A.push_back(maxq(q));
        c++;
        i--;

        while (i != a.size() - 1)
        {
            q.pop();
            q.push(a[i+1]);

            if (a[i + 1] > output_A[c - 1])
            {
                output_A.push_back(a[i + 1]);
            }
            else
            {
                output_A.push_back(maxq(q));
            }
            c++;
            i++;
        }
        return output_A;
    }


    int maxq(queue<int> q)
    {
        int max = INT_MIN;
        while (!q.empty())
        {
            if (q.front() > max)
            {
                max = q.front();
            }

            q.pop();
        }
        return max;
    }
};

int main()
{
    srand(time(0));
    vector<int> a = { 2, 1, 5 };
    vector<int> b;
    Solution p;
    b = p.MaxPooling(a,1);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    cout <<"\n"<< clock() << endl;
}

*/


/*
class Solution
{
public:
    vector<int> solve(const std::vector<int>& array)
    {

        vector<int> index;
        vector<int> temp;

        temp.push_back(array.front() + 1);

        for (int i = 0; i < array.size(); i++)
        {
            temp.push_back(array[i]);
        }

        temp.push_back(array.back() - 1);


        for (auto i = 1; i < temp.size() - 1; i++)
        {
            if (temp[i] < temp[i - 1] && temp[i] > temp[i + 1])
            {
                index.push_back(i - 1);
            }
        }

        return index;
    }
};



int main()
{
    vector<int> arr;
    arr = { 14,15,14,16,13,11,12 };

    Solution p;
    vector<int> index=p.solve(arr);

    for (int i = 0; i < index.size(); i++)
    {
        cout << index[i] << " ";
    }
}

*/


/*

class Solution
{
public:
    int solve(const vector<int>& a)
    {
        int result = a[a.size() - 1];
        for (int i = a.size() - 2; i >= 0; i--)
        {

            if (a[i] > 0 && (i - 1) < 0)
            {
                result += a[i];
                break;
            }

            if (a[i] <= 0 && (i - 1) < 0)
            {
                break;
            }


            if (a[i] < 0 && a[i - 1] < 0)
            {
                if (a[i] > a[i - 1])
                {
                    result += a[i];
                    continue;
                }
                else
                {
                    result += a[i - 1];
                    i--;
                    continue;
                }
            }

            if ((a[i] >= 0 && a[i - 1] < 0) || (a[i] < 0 && a[i - 1] >= 0))
            {
                if (a[i] > a[i - 1])
                {
                    result += a[i];
                    continue;
                }
                else {
                    result += a[i - 1];
                    i--;
                    continue;
                }
            }

            if (a[i] >= 0 && a[i - 1] >= 0)
            {
                result += a[i];
                continue;
            }

        }

        return result;

    }
};


int main()
{
    vector<int> a = { -1,2,1 };

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    Solution p;
    cout << p.solve(a) << endl;

}

*/


/*

class Solution {
public:
    void sortExperiments(vector<int>& nums)
    {
        int a = 0, b = 0, c = 0, i=0;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                a++;
            if (nums[i] == 1)
                b++;
            if (nums[i] == 2)
                c++;
        }

        for (i = 0; i < a; i++)
        {
            nums[i] = 0;
        }

        for (i=a; i < a+b; i++)
        {
            nums[i] = 1;
        }

        for (i=a+b; i < a+b+c; i++)
        {
            nums[i] = 2;
        }

    }
};

int main()
{
    vector<int> a = { 2,2,2,0,1,0,1,1,0 };

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    Solution p;
    p.sortExperiments(a);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}


*/


#include <iostream>
#include <string>
#include <windows.h>
#include <cctype>
#include <istream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Массив для хранения 16 сгенерированных ключей
string round_keys[16];
// строка для шифрования блока текста, длиной 64 бита
string pt;

// Функция перевода чисел из двоичной системы счисления в десятичную
int convertBinaryToDecimal(string binary)
{
    int decimal = 0;
    int counter = 0;
    int size = binary.length();
    for (int i = size - 1; i >= 0; i--)
    {
        if (binary[i] == '1') {
            decimal += pow(2, counter);
        }
        counter++;
    }
    return decimal;
}

// функция перевода строки в двоичную систему (английские символы)
string str2bin(string s)
{
    int n = s.length();

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        // преобразуем каждый символ в числовое значение из ASCII  
        int val = int(s[i]);
        // Перевод из десятичного значения в двоичное 
        string bin = "";
        while (val > 0)
        {
            (val % 2) ? bin.push_back('1') :
                bin.push_back('0');
            val /= 2;
        }
        while (bin.size() < 8) {
            bin += '0';
        }
        reverse(bin.begin(), bin.end());
        ans += bin;
    }
    return ans;
}

// функция перевода строки в двоичную систему (русские символы)
string str2binRU(string s)
{
    int n = s.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        int val = int(s[i]);

        string bin = "";
        if (val < 0)
        {
            val = val * (-1);
        }
        while (val > 0)
        {
            (val % 2) ? bin.push_back('1') :
                bin.push_back('0');
            val /= 2;
        }
        while (bin.size() < 8) {
            bin += '0';
        }
        reverse(bin.begin(), bin.end());
        ans += bin;
    }
    return ans;
}

// Функция перевода текста из двоичной системы в символьную
string bin2str(string s)
{
    string result = "";
    string block = "";
    int counter = 0;
    int n = s.length() / 8;
    for (int i = 0; i < n; i++)
    {
        block = "";
        for (int j = 0; j < 8; j++)
        {
            block += s[counter];
            counter++;
        }
        int dec = convertBinaryToDecimal(block);
        result += dec;
    }
    return result;
}
// Функция перевода текста из двоичной системы в символьную (для русского алфавита)
string bin2strRU(string s)
{
    string result = "";
    string block = "";
    int counter = 0;
    int n = s.length() / 8;
    for (int i = 0; i < n; i++)
    {
        block = "";
        for (int j = 0; j < 8; j++)
        {
            block += s[counter];
            counter++;
        }
        int dec = convertBinaryToDecimal(block);
        if (dec != 32)
        {
            dec = dec * (-1);
        }
        result += dec;
    }
    return result;
}

// Функция перевода числа из десятичной в двоичную систему счисления
string convertDecimalToBinary(int decimal)
{
    // строка для записи двоичного числа
    string binary;
    // алгоритм перевода
    while (decimal != 0) {
        binary = (decimal % 2 == 0 ? "0" : "1") + binary;
        decimal = decimal / 2;
    }
    while (binary.length() < 4) {
        binary = "0" + binary;
    }
    return binary;
}

// Функция для выполнения кругового сдвига влево на 1 (сдвиг уже разделенной части ключа)
string shift_left_once(string key_chunk) {
    string shifted = "";
    for (int i = 1; i < 28; i++) {
        shifted += key_chunk[i];
    }
    shifted += key_chunk[0];
    return shifted;
}

// Функция для выполнения кругового сдвига влево на 2 (сдвиг уже разделенной части ключа)
string shift_left_twice(string key_chunk) {
    string shifted = "";
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < 28; j++) {
            shifted += key_chunk[j];
        }
        shifted += key_chunk[0];
        key_chunk = shifted;
        shifted = "";
    }
    return key_chunk;
}
// Функция XOR (Исключающее ИЛИ)
string Xor(string a, string b) {
    string result = "";
    int size = b.size();
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            result += "1";
        }
        else {
            result += "0";
        }
    }
    return result;
}
//Функция для генерации 16 ключей
void generate_keys(string key) {
    // 1-я таблица перестановок для преобразования 64 бит в 56
    int pc1[56] = {
    57,49,41,33,25,17,9,
    1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,
    19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,
    7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,
    21,13,5,28,20,12,4
    };
    // 2-я таблица перестановок для преобразования 56 в 48 бит при переходе со стороны ключа на сторону открытого текста
    int pc2[48] = {
    14,17,11,24,1,5,
    3,28,15,6,21,10,
    23,19,12,4,26,8,
    16,7,27,20,13,2,
    41,52,31,37,47,55,
    30,40,51,45,33,48,
    44,49,39,56,34,53,
    46,42,50,36,29,32
    };

    // Сжатие ключа с помощью 1-й таблицы перестановок
    string perm_key = "";
    for (int i = 0; i < 56; i++) {
        perm_key += key[pc1[i] - 1];
    }
    // Деление ключа на две равные части по 28 бит с помощью преобразованной ранее строки perm_key 
    string left = perm_key.substr(0, 28);
    string right = perm_key.substr(28, 28);
    for (int i = 0; i < 16; i++) {
        // Для циклов 1, 2, 9, 16 сдвиг на единицу
        if (i == 0 || i == 1 || i == 8 || i == 15) {
            left = shift_left_once(left);
            right = shift_left_once(right);
        }
        // Для всех остальных циклов сдвиг на 2
        else {
            left = shift_left_twice(left);
            right = shift_left_twice(right);
        }
        // Объединение 2 частей
        string combined_key = left + right;
        string round_key = "";
        // Используем 2-ю таблицу перестановок для транспонирования битов ключа
        for (int i = 0; i < 48; i++) {
            round_key += combined_key[pc2[i] - 1];
        }
        round_keys[i] = round_key;
    }
}

// Реализация основного алгоритма DES
string DES() {
    // Начальная таблица перестановок для текста
    int initial_permutation[64] = {
    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7
    };
    // Таблица функции расширения E
    int expansion_table[48] = {
    32,1,2,3,4,5,4,5,
    6,7,8,9,8,9,10,11,
    12,13,12,13,14,15,16,17,
    16,17,18,19,20,21,20,21,
    22,23,24,25,24,25,26,27,
    28,29,28,29,30,31,32,1
    };

    // Функции преобразования S(i)
    // 48 бит делится на подблоки по 6 бит (S-box). Функция S преобразует 6 бит в 4 бита.
    int substition_boxes[8][4][16] =
    { {
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    },
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    },
    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    },
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    },
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    },
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    },
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    },
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    } };
    // Таблица перестановок P
    int permutation_tab[32] = {
    16,7,20,21,29,12,28,17,
    1,15,23,26,5,18,31,10,
    2,8,24,14,32,27,3,9,
    19,13,30,6,22,11,4,25
    };

    // Обратная таблица перестановок
    int inverse_permutation[64] = {
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25
    };

    //Используем начальную перестановку
    string perm = "";
    for (int i = 0; i < 64; i++) {
        perm += pt[initial_permutation[i] - 1];
    }
    // Деление результата на две равные половины
    string left = perm.substr(0, 32);
    string right = perm.substr(32, 32);

    // Шифруем текст 16 раз 
    string ciphertext = "";   // переменная для хранения зашифрованного текста
    for (int i = 0; i < 16; i++) {
        string right_expanded = "";
        // Правая половина текста расширяется
        for (int i = 0; i < 48; i++) {
            right_expanded += right[expansion_table[i] - 1];
        };
        // Применяем операцию "Исключающее ИЛИ"
        string xored = Xor(round_keys[i], right_expanded);
        string res = "";
        // Результат делится на 8 равных частей и пропускается через 8 S-блоков. 
        //После прохождения каждый блок уменьшается с 6 до 4 бит.
        for (int i = 0; i < 8; i++) {
            // Поиск индексов строк и столбцов для  S-преобразований
            string row1 = xored.substr(i * 6, 1) + xored.substr(i * 6 + 5, 1);
            int row = convertBinaryToDecimal(row1);
            string col1 = xored.substr(i * 6 + 1, 1) + xored.substr(i * 6 + 2, 1) + xored.substr(i * 6 + 3, 1) + xored.substr(i * 6 + 4, 1);;
            int col = convertBinaryToDecimal(col1);
            int val = substition_boxes[i][row][col];
            res += convertDecimalToBinary(val);
        }
        //  P преобразования с помощью таблицы перестановок P
        string perm2 = "";
        for (int i = 0; i < 32; i++) {
            perm2 += res[permutation_tab[i] - 1];
        }
        // Результат сравнивается с левой половиной с помощью XOR (исключающее ИЛИ)
        xored = Xor(perm2, left);
        //левая и правая части тектса меняются местами
        left = xored;
        if (i < 15) {
            string temp = right;
            right = xored;
            left = temp;
        }
        // объединение обеих сторон для создания полного зашифрованного текста
        string combined_text = left + right;
        ciphertext = "";
        // Применяется обратная перестановка
        for (int i = 0; i < 64; i++) {
            ciphertext += combined_text[inverse_permutation[i] - 1];
        }

    }
    //Возвращение зашифрованного текста
    return ciphertext;
}


bool checkKeyWord(string word)    // проверка ключевого слова на наличие посторонних символов
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] >= 'А' && word[i] <= 'Я' || word[i] >= 'а' && word[i] <= 'я')
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

string key_wordInput()    // функция проверки ввода ключа от пользователя
{
    bool rightInput = false;
    string key_word = "";
    while (rightInput == false)
    {
        cout << "Длина слова должна быть равна 8! : " << endl;
        cin >> key_word;
        std::cin.ignore();
        if (checkKeyWord(key_word) == true && key_word.length() == 8)
        {
            rightInput = true;
        }
    }
    return key_word;
}

string word_HighRegisterRU(string word)   // функция перевода в верхний регистр (RU)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] >= 'а' && word[i] <= 'я')
        {
            word[i] = word[i] - 32;
        }
    }
    return word;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string key;  // переменная, хранящая ключ

    cout << "Введите ключ:" << endl;
    key = key_wordInput();
    key = str2binRU(key);
    cout << "Ключ в 64 бит: " << key << endl << endl;

    string message = "";  // переменная, хранящая сообщение
    cout << "Введите сообщение, которое нужно зашифровать:" << endl;
    std::getline(std::cin, message);
    cout << endl;
    message = word_HighRegisterRU(message);
    int excess_symbols = 0;
    // Если исходный текст не делится на блоки по 64 бита, то он дополнится символами с конца
    for (int i = 0; i < (message.length() % 8); i++)
    {
        message += "_";
        excess_symbols++;
    }
    string crypted = "";  // переменная для записи зашифрованного сообщения
    int counter = 0;
    string ct;  // строка для хранения результата шифрования блока текста
    // Шифрование сообщения
    for (int i = 0; i < (message.length() / 8); i++)
    {
        string block = "";
        for (int j = 0; j < 8; j++)
        {
            block += message[counter];
            counter++;
        }
        pt = str2binRU(block);

        // Вызов функции для генерации ключей
        generate_keys(key);
        // Вызов самого алгоритма шифрования
        ct = DES();
        crypted += ct;
    }

    cout << "Зашифрованное сообщение: " << crypted << endl << endl;
    int i = 15;
    int j = 0;
    while (i > j)
    {
        string temp = round_keys[i];
        round_keys[i] = round_keys[j];
        round_keys[j] = temp;
        i--;
        j++;
    }
    string binBlock;
    string res;
    counter = 0;
    string decrypted;  // строка для хранения расшифрованного сообщения
    //Расшифровка сообщения
    for (int k = 0; k < (message.length() / 8); k++)
    {
        binBlock = "";
        for (int m = 0; m < 64; m++)
        {
            binBlock += crypted[counter];
            counter++;
        }
        pt = binBlock;
        //При расшифровке данных все действия выполняются в обратном порядке
        res = DES();
        decrypted += res;
    }

    cout << "Расшифрованное сообщение: " << decrypted << endl << endl;
    // Перевод расшифрованного сообщения из двоичного в символьный вид
    decrypted = bin2strRU(decrypted);
    // Стирание символов, которые были вставлены, если исходный текст не делился на блоки по 64 бита
    decrypted.erase(decrypted.length() - excess_symbols);
    cout << "Расшифрованное сообщение в символьном виде:   " << decrypted << endl;

    system("pause");
    return 0;
}
