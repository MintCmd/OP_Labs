//Вариант 4
//1. Дана последовательность натуральных чисел {Aj}. Найти сумму чисел, оканчивающихся цифрой 0 или 7, 
//наибольшее из таких чисел и номер этого числа в последовательности.
//2. Дано натуральное число N (N<10^9). Найти сумму нечетных цифр числа N.


#include <iostream>

int main()
{
    const int N_Max = 10;
    int sum = 0;
    int max = 0;
    int posl[N_Max] = {43, 642, 64, 12, 89, 423, 111, 1671, 234, 771};
    for (int i=0; i<10;i++)
    {
        if (posl[i]%10==0 || posl[i]%10==7)
        {
            sum+=posl[i];
            if (max<posl[i]) max=posl[i];
            std::cout << "Number " << posl[i] << " has number " << i+1 << " in the sequance." << std::endl;
        }

    }
    if (max!=0) std::cout << "Max number: " << max << std::endl;
    else std::cout << "There is no such a number." << std::endl;
    std::cout << "Sum of numbers: " << sum << std::endl;
    
    

    int N;
    int nsum = 0;
    std::cin >> N;
    if (0<N && N<1000000000) 
    {
        while (N>0)
        {
            int digit = N%10;
            if (digit%2==1) nsum+=digit;
            N/=10;
        }
        std::cout << "Sum of odd digits: " << nsum << std::endl;
    }
    else 
    {
        std::cout << "Incorrect N.";
    }

    return 0;
}
