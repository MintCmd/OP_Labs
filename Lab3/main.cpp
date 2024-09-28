//Вариант 4.
//Установить i-ый бит числа х (0<x<10^9) в 1.

#include <iostream>

int main() 
{
    int x, i;
    std::cout << "Input x and i (0<x<10^9, 0<i<31): "; //Введите x и i 
    std::cin >> x >> i; //Ввод
    if (0<x && x<1000000000) {
        std::cout << (x | (1 << i)) << std::endl;
    }
    else {
        std::cout << "Error! Incorrect x." << std::endl; //Ошибка! Некоректное число x.
    }
    return 0;
}
