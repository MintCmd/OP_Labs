#include <iostream>
#include <iomanip>


int main()
{
    double R;
    double pi = acos(-1);
    std::cout << "Input R - circle radius (0 < R < 100): ";
    std::cin >> R;
    if (R > 0 && R < 100) 
    {
        double S = pi * pow(R, 2);
        std::cout << std::fixed << std::setprecision(9);
        std::cout << "Area of the circle is equal to " << S << std::endl;
    } 
    else 
    {
        std::cout << "R must be 0 < R < 100" << std::endl;
        return 1;
    }

    return 0;
}