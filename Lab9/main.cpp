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

    unsigned short* p = &x; //Указывает на переменную x в стеке

    std::cout <<  "x has value " << *p << " and it's adress in stack is " << p << std::endl; //Вывод значения и адреса переменной x

    unsigned char* c = reinterpret_cast<unsigned char*>(p); //Указатель на первый байт

    for(int i=0;i<sizeof(unsigned short);i++) {
        std::cout <<  "Byte " << i+1 << " value is " << static_cast<int>(*(c+i)) << " or ";
        BinaryFormat(c[i]);
    }
    //Пример ввода и вывода
    //Input x - 0 ... 65,535: 45678

    //x has value 45678 and it's adress in stack is 00000033F74FFB74 (адрес после каждого выполнения будет меняться, потому что указатель стека возвращается в начало после завершения программы)
    //Byte 1 value is 110 or 01101110
    //Byte 2 value is 178 or 10110010
    return 0;
}
