//Переменная - проименованная область памяти, хранящая данные. 
//
//Типы данных
// 1. Целочисленные
// - char, 1 байт, -128..127
// - short, 2 байта, -32768..32767
// - int, 4 байта, -2^31 .. 2^31-1
// - long long, 8 байт, -2^63 .. 2^63-1
// - unsigned int, 4 байт, 0 .. 2^32-1
// 2. Символьные
// - char, 1 байт, -128..127
// 3. Вещественные типы
// - float, 4 байта, 6-7 цифр
// - double, 8 байтов, 15-16 цифр 
// 4. Логический тип
// - bool, 1 байт, true/false

#include <iostream>

int main() 
{
	std::cout << "Типы данных:" << std::endl; // Типы данных

	std::cout << std::endl << "Целочисленные:" << std::endl; // Целочисленные
	std::cout << "char - 1 байт, -128...127" << std::endl;
	std::cout << "unsigned char - 1 байт, 0...255" << std::endl;
	std::cout << "short - 2 байта, -32768...32767" << std::endl;
	std::cout << "unsigned short - 2 байта, 0...65535" << std::endl;
	std::cout << "int - 4 байта, -2^31...2^31-1" << std::endl;
	std::cout << "unsigned int - 4 байта, 0...2^32-1" << std::endl;
	std::cout << "long long - 8 байта, -2^63...2^63-1" << std::endl;
	std::cout << "unsigned long long - 8 байта, 0...2^64-1" << std::endl;

	std::cout << std::endl << "Символьные:" << std::endl; // Символьные
	std::cout << "char - 1 байт, -128...127" << std::endl;

	std::cout << std::endl << "Вещественные:" << std::endl; // Вещественные
	std::cout << "float - 4 байта, 6-7 цифр" << std::endl;
	std::cout << "double - 8 байта, 15-16 цифр" << std::endl;

	std::cout << std::endl << "Логический:" << std::endl; // Логический
	std::cout << "bool - 1 Байт, true/false" << std::endl;

	std::cout << std::endl <<"Арифметические операции:" << std::endl; // Арифметические операции

	char c = 10, h = 15;
	std::cout << c - h << std::endl; // -5

	char m = 'A', n = 'B';
	std::cout << m + n << std::endl; // 131
	
	short s = 500, o = 20;
	std::cout << s * o << std::endl; // 10000

	int a = 74572, b = 100;
	std::cout << a / b << std::endl; // 745

	float f = 155.55;
	std::cout << f/3.9f << std::endl; // 39.8846

	double d = -233.576;
	d += 50.556;
	std::cout << d << std::endl; // -183.02

	bool tr = true, fl = false;
	bool boolsum = tr + fl;
	std::cout << boolsum << std::endl; // 1

	return 0;
}
