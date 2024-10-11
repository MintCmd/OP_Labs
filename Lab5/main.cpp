//Вариант 4
//1. Дана последовательность натуральных чисел {Aj}. Найти сумму чисел, оканчивающихся цифрой 0 или 7, 
//наибольшее из таких чисел и номер этого числа в последовательности.
//2. Дано натуральное число N (N<10^9). Найти сумму нечетных цифр числа N.


#include <iostream>

int main()
{   
    //Задание 1
    const int N_Max = 1000; 
    int sum = 0;
    int max = 0;
    int n;
    int seq[N_Max];
    std::cout << "Input n: ";
    std::cin >> n;
    std::cout << "Input values of sequence: ";
    for(int i=0;i<n;i++)
        std::cin >> seq[i];
    for (int i=0; i<n;i++)
    {
        if (seq[i]%10==0 || seq[i]%10==7)
        {
            sum+=seq[i];
            if (max<seq[i]) max=seq[i];
            std::cout << "Number " << seq[i] << " is №" << i+1 << " in the sequence." << std::endl;
        }

    }
    if (max!=0) std::cout << "Max number: " << max << std::endl;
    else std::cout << "There is no such a number." << std::endl;
    std::cout << "Sum of numbers: " << sum << std::endl;
    /* Пример:
    Ввод: 10
    45 57 110 229 80 77 555 234 10 6
    
    Вывод:
    Number 57 is №2 in the sequence.
    Number 110 is №3 in the sequence.
    Number 80 is №5 in the sequence.
    Number 77 is №6 in the sequence.
    Number 10 is №9 in the sequence.
    Max number: 110
    Sum of numbers: 334
    */
    
    //Задание 2
    int N;
    int nsum = 0;
    std::cout <<std::endl << "Input N (0<N<10^9): ";
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
    //Пример
    //Ввод: 54326780 
    //Вывод: 15
    return 0;
}
