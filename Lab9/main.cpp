//Вариант 4.
//Дано целое число типа unsigned short, выведите на экран содержимое каждого из его байтов, 
//используя знания по указателям. Дайте обоснование полученному результату.

#include <iostream>

//Функция выводит значение байта в двоичном виде
void BinaryFormat(unsigned char byte) {
    for(int i=7;i>=0;i--) {
        if(byte & (1<<i)) {
        std::cout << '1';
        }
        else {
            std::cout << '0';
        }
    }
    std:: cout << std::endl;
}

int main() {

    unsigned short x;
    std::cout << "Input x - 0 ... 65,535: ";
    std::cin >> x;
    if(x<0 || x>65535) {
        std::cerr << "Number is not unsigned short type." << std::endl;
        return -1;
    }

    unsigned short* p = &x; //Указатель p указывает на адрес переменной x в стеке

    std::cout <<  "x has value " << *p << " and its' adress in stack is " << p << std::endl; //Вывод значения и адреса переменной x

    unsigned char* c = reinterpret_cast<unsigned char*>(p); //Указатель на первый байт

    for(int i=0;i<sizeof(unsigned short);i++) {
        std::cout <<  "Byte " << i+1 << " value is " << static_cast<unsigned short>(*(c+i)) << " or ";
        BinaryFormat(c[i]);
    }

    return 0;
}
