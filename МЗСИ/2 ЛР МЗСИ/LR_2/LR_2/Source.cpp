#include <iostream>
#include <string>
using namespace std;

//�������������� ������, � ������� ������������ ���
//parameter_1, parameter_2 ������� ��������.parameter_1 ��������� (����������� ���, ��� � ��������) parameter_2 ��� �����
string conversion_XOR(string parameter_1, string parameter_2)
{
	//�������� ��������
	string parameter_3;
	int j = 0;
	for (auto i = 0; i < parameter_1.length(); i++)
	{
		//�������������� �������� ��������� � ��������, � ������� ������������ ���
		parameter_3 += (int)parameter_1[i] ^ (int)parameter_2[j];
		j++;
		//���� ����� ��������� ������ �����
		if (j >= parameter_2.length()) j = 0;
	}
	return parameter_3;
}

int main()
{
	string message;
	string gamma;

	cout << "Enter the message you want to encrypt : ";
	getline(cin, message);

	cout << "Enter the key : ";
	getline(cin, gamma);

	cout << "\n\t\tEncrypted text " << endl;
	cout << conversion_XOR(message, gamma) << endl;
	cout << "\n\t\tDecrypted text " << endl;
	cout << conversion_XOR(conversion_XOR(message, gamma), gamma) << endl;

	system("pause");
	return 0;
}


/*
	//cout << "Encrypted text : " << endl;
	//cout << encryptionText(message,gamma)<<endl;
	//cout << "Decrypted text : " << endl;
	//cout << decryptionText(encryptionText(message, gamma), gamma) << endl;

//������� �������������� ������ � �������� 
string encryptionText(string message, string gamma)
{
	//�������� ���
	string binCode;
	int j = 0;

	for (int i = 0; i < message.length(); i++)
	{
		if (j >= gamma.length()) j = 0;
		binCode += (int)message[i] ^ (int)gamma[j];
		j++;
	}
	return binCode;
}

string decryptionText(string binCode, string gamma)
{
	string message;
	int j = 0;

	for (int i = 0; i < binCode.length(); i++)
	{
		if (j >= gamma.length()) j = 0;
		message += (int)binCode[i] ^ (int)gamma[j];
		j++;
	}
	return message;
}
*/