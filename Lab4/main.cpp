//Вариант 4.
//1. Ввести натуральные числа A, B и C. Если A+B кратно C и C кратно B, то вывести (A+B)/C-C/B, если A+B кратно C и C не кратно B, 
//то вывести (A+B)/С+B*C, в остальных случаях вывести A-B+C.
//2. Ввести число N, которое обозначает некоторую ошибку. При помощи оператора switch расшифровать значение ошибки.
//Список ошибок:
//0 – все хорошо, 1 – ошибка чтения файла, 2 – ошибка записи файла, 3 – не все поля определены.
//Предусмотреть обработку ошибочного ввода N.
//3. Переменная x может принимать 2 значения: -1 и 1. Если -1, то вывести в консоль “Negative number”, 
//если положительное - “Positive number”. Предложить вариант программы и объяснить свой выбор.


#include <iostream>

int main()
{
    int A, B, C;
    std::cout << "1. Input A, B, C (positive , int): "; //Введите натуральные числа А, В, С
    std::cin >> A >> B >> C;
    if ((A+B)%C == 0 && C%B == 0) std::cout << (A+B)/C-C/B << std::endl;
    else if ((A+B)%C == 0 && C%B != 0) std::cout << (A+B)/C-C*B << std::endl;
    else std::cout << A-B+C << std::endl;

    int N;
    std::cout << std::endl << "2. Input N = 0, 1, 2, 3: " << std::endl; //Введите N
    std::cin >> N;
    switch (N)
    {
        case 0:
            std::cout << "All good." << std::endl; //Всё хорошо
            break;
        case 1:
            std::cout << "File reading error." << std::endl; //Ошибка чтения файла
            break;
        case 2:
            std::cout << "File writing error." << std::endl; //Ошибка записи файла
            break;
        case 3:
            std::cout << "Not all fields are defined." << std::endl; //Не все поля определены
            break;
        default:
            std::cout << "N is incorrect." << std::endl; //Недопустимое N
    }

    int x;
    std::cout << std::endl << "3. Input x = -1, 1: " << std::endl; //Введите x
    std::cin >> x;
    switch (x)
    {
        case -1:
            std::cout << "Negative number." << std::endl;
            break;
        case 1:
            std::cout << "Positive numver." << std::endl;
            break;
        default:
            std::cout << "x is not -1 nor 1." << std::endl;
    }

    return 0;
}
