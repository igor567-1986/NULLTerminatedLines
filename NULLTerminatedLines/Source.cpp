#include<iostream>
#include<Windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;


//#define EXAMPLE_1
#define EXAMPLE_2

int StringLength(const char str[]);
void upper_case( char str[]);
void lower_case(char str[]);
void shrink(char str[]);
// void remove_symbol(char str[], const char symbol);
bool is_palindrome(char str[]);

void main()
{
   setlocale(LC_ALL, "");
#ifdef EXAMPLE_1
	
	//char str[] = { 'H','e','l','l','o',0 };
	char str[] = "Hello";
	//str - строковая переменная
	//"Hello" - строковая константа
	cout << str << endl;
	cout << typeid (str).name() << endl;
	cout << typeid ("Hello").name() << endl;
#endif // EXAMPLE_1
	const int SIZE = 256;
	char str[SIZE] = {};
	/*cout << "Введите строку:";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	cout << str << endl;
	cout << "Длина строки: " << StringLength(str) <<" символов " << endl;
	cout << "Длина строки: " << strlen(str) <<" символов " << endl;
	cout << "Длина строки в байтах: " << sizeof(str)  << endl;
	upper_case(str);
	cout << str << endl;
	lower_case(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;*/
	cout << (is_palindrome(str) ? "" : "НЕ") << " является палиндромом";

}
int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void upper_case(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z') str[i] -= ' ';
		if (str[i]>= 'а'&& str[i] <='я') str[i] -= ' ';
		if (str[i] == 'ё')str[i] = 'Ё';*/
		str[i] = toupper(str[i]);
    }
}
void lower_case(char str[])
{
	for (int i = 0; str[i]; i++)
		str[i] = tolower(str[i]);
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
bool is_palindrome(char str[])
{
	char* buffer = new char[strlen(str) + 1]{};
	strcpy(buffer, str);
	lower_case(buffer);
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