#include <iostream>
#include <iomanip>

int main()
{
    double R; //Радиус
    double pi = acos(-1); //Число Пи
    std::cout << "Введите радиус круга R (0 < R < 100): ";
    std::cin >> R;
    if (R > 0 && R < 100) 
    {
        double S = pi * pow(R, 2); //Формула площади круга
        std::cout << std::fixed << std::setprecision(9); //С точностью до 10^-9
        std::cout << "Площадь круга равна " << S << std::endl; //Вывод площади
    } 
    else 
    {
        std::cout << "Ошибка: Радиус должен быть в пределах 0 < R < 100" << std::endl; //Сообщение об ошибке
    }

    return 0;
}