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
#include <limits>
#include <typeinfo>

template<typename T>
void printTypeInfo()
{
	if (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value) {
		std::cout << typeid(T).name() << ", " << sizeof(T) << " byte, " << static_cast<int>(std::numeric_limits<T>::min()) << "..." << static_cast<int>(std::numeric_limits<T>::max()) << std::endl;
	}
	else {
		std::cout << typeid(T).name() << ", " << sizeof(T) << " bytes, " << std::numeric_limits<T>::min() << "..." << std::numeric_limits<T>::max() << std::endl;
	}
}

int main() 
{
	std::cout << "Data types:" << std::endl; // Типы данных

	std::cout << std::endl << "Integer types:" << std::endl; // Целочисленные
	printTypeInfo<char>();
	printTypeInfo<unsigned char>();
	printTypeInfo<short>();
	printTypeInfo<unsigned short>();
	printTypeInfo<int>();
	printTypeInfo<unsigned int>();
	printTypeInfo<long long>();
	printTypeInfo<unsigned long long>();
	std::cout << "__int64 is long long" << std::endl;

	std::cout << std::endl << "Character types:" << std::endl; // Символьные
	printTypeInfo<char>();

	std::cout << std::endl << "Real types:" << std::endl; // Вещественные
	printTypeInfo<float>();
	printTypeInfo<double>();

	std::cout << std::endl << "Logical type:" << std::endl; // Логический
	printTypeInfo<bool>();

	std::cout << std::endl <<"Arithmetic operations:" << std::endl; // Арифметические операции

	char c = 10, h = 15;
	std::cout << c - h << std::endl; // -5
	
	short s = 500, o = 20;
	std::cout << s * o << std::endl; // 10000

	int a = 74572, b = 100;
	std::cout << a / b << std::endl; // 745

	char m = 'A', n = 'B';
	std::cout << m + n << std::endl; // 131

	float f = 155.55;
	std::cout << f/3.9f << std::endl; // 39.8846

	double d = -233.576;
	d += 50.5566;
	std::cout << d << std::endl; // -183.019

	bool tr = true, fl = false;
	std::cout << tr + fl << std::endl; // 1

	return 0;
}
