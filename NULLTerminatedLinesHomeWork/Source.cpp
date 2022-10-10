#include<iostream>
#include <Windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(const char str[]);
bool is_int_number(const char str[]);
int  to_int_number(char str[]);
bool is_bin_number(const char str[]);
int  bin_to_dec(char str[]);
bool is_hex_number(const char str[]);
int  hex_to_dec(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 256;
	char str[SIZE] = {}; //"Мишки   очень любят  мед.Почему и   кто поймет."
	SetConsoleCP(1251);
	/*cout << str << endl;
	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;*/
	cout << "Введите строку:";	cin.getline(str, SIZE);
	//cout << (is_palindrome(str) ? "" : "НЕ") << " является палиндромом"<<endl;
	cout << (is_int_number(str) ? "" : "НЕ") << " является десятичным числом"<<endl;
	if (is_int_number(str))cout << to_int_number(str)<< endl;
	cout << (is_bin_number(str) ? "" : "НЕ") << " является двоичным числом" << endl;
	if (is_bin_number(str))cout <<"При переводе из двоичной в десятичную="<< bin_to_dec(str) << endl;
	cout << (is_hex_number(str) ? "" : "НЕ") << " является шестнадцатиричным числом" << endl;
	if (is_hex_number(str))cout << "При переводе из шестнадцатиричной в десятичную=" << hex_to_dec(str) << endl;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		str[i] = tolower(str[i]);
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
		while (str[i] == ' ' && str[i + 1] == ' ')
			for (int j = i + 1; str[j]; j++)
				str[j] = str[j + 1];
}
void remove_symbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
		while (str[i] == symbol)
			for (int j = i; str[j]; j++)
				str[j] = str[j + 1];
}
bool is_palindrome(const char str[])
{
	char* buffer = new char[strlen(str) + 1]{};
	strcpy(buffer, str);
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	int size = strlen(buffer);
	for (int i = 0; i < size; i++)
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	delete[] buffer;
	return true;
}
bool is_int_number(const char str[])
{
	int size = strlen(str),counter=0;
	for (int i=0; str[i]; i++)
		if(str[i] >= '0' && str[i] <= '9')counter++;
	if (counter == size )return true;
	return false;
}
int  to_int_number(char str[])
{
	int number = 0;
	int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		int buffer = (int)str[i] - (int)'0';
		number = number * 10 + buffer;
	}
	return number;
}
bool is_bin_number(const char str[])
{
	int size = strlen(str), counter = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] == '0' || str[i] == '1')counter++;
	if (counter == size)return true;
	return false;
}
int  bin_to_dec(char str[])
{
	int number = 0,size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		number *= 2;
		number += str[i] - '0';
	}
	return number;
}
bool is_hex_number(const char str[])
{
	int size = strlen(str), counter = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] >= '0' && str[i] <= '9'||str[i]>='a'&&str[i]<='f' || str[i] >= 'A' && str[i] <= 'F')counter++;
	if (counter == size)return true;
	return false;
}
int  hex_to_dec(char str[])
{
	int number = 0, size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		int intermediate_result = 0,N=1;
		if (str[i] >= '0' && str[i] <= '9')intermediate_result += str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')intermediate_result += str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')intermediate_result += str[i] - 'A' + 10;
		for (int j = 1; j < size - i; j++)N *= 16;
		number += (intermediate_result * N);
	}
	return number;
}