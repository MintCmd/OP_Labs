/*
1. 	Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). Если в последовательности нет ни одного простого числа, 
упорядочить последовательность по невозрастанию.
 
2. 	Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). Упорядочить последовательность по неубыванию первой цифры числа, 
числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию наименьшей цифры числа, числа с одинаковыми первыми цифрами 
и  одинаковыми наименьшими цифрами дополнительно упорядочить по неубыванию самого числа.
 
3. 	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). Найти строку с наименьшей суммой элементов и заменнить 
все элементы этой строки этой суммой.

4. Сначала введите последовательность. Затем удалите и продублируйте элементы. Затем выведите полученную последовательность 
(каждый элемент по одному разу). Используйте в программе только один массив.

Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). Удалить из последовательности числа-палиндромы, 
а среди оставшихся продублировать простые числа.
*/


#include <iostream>

int main()
{
    //1.
    const int N_Max = 10000;
    int posl1[N_Max];
    bool hasPrime = false;
    int n;
    std::cout << "Task 1." << std::endl << "Input: n: ";
    std::cin >> n;
    std::cout << "Input: " << n << " values: ";
    for(int i=0; i<n; i++) //Цикл для ввода последовательности
        std::cin >> posl1[i];

    for(int i=0; i<n; i++) //Цикл для проверки, есть ли в последовательности промтое число
    {
        bool isPrime=true;
        for(int d=2; d<=sqrt(posl1[i])+1; d++)
        {
            if(posl1[i]%d == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            hasPrime=true;
            break;
        }
    }
    if(hasPrime)
    {
        std::cout << "It has a prime number." << std::endl;
    }
    else
    {
        for(int i=0; i<n-1; i++) //Двойной цикл для сортировки по невозрастанию
            for(int j=i+1; j<n; j++)
                if(posl1[i] < posl1[j])
                {
                    int tmp = posl1[i];
                    posl1[i] = posl1[j];
                    posl1[j] = tmp;
                }
        std::cout << "Sorted sequance: ";
        for(int i = 0; i<n; i++)
            std::cout << posl1[i] << " ";
    }

    //2.
    int posl2[N_Max];
    char firstDigit[N_Max];
    char minDigit[N_Max];
    int n2;
    std::cout << std::endl << "Task 2." << std::endl << "Input: n: ";
    std::cin >> n2;
    std::cout << "Input: " << n2 << " values: ";
    for(int i=0; i<n2; i++) //Цикл для ввода массива и поиска первой и минимальной цифр
    {
        std::cin >> posl2[i];
        firstDigit[i] = posl2[i];

        while(firstDigit[i] > 9) firstDigit[i] /= 10;
        int dif = posl2[i];
        minDigit[i] = 9;

        while(dif > 0)
        {
            char min = dif%10;
            if(minDigit[i] < min)
                minDigit[i] = min;
            dif /= 10;
        }
    }

    for(int i=0; i<n2-1; i++) //Двойной цикл для сортировки по неубыванию
            for(int j=i+1; j<n2; j++)
                if((firstDigit[i] > firstDigit[j]) ||
                    (firstDigit[i] == firstDigit[j] && minDigit[i] > minDigit[j]) ||
                        (firstDigit[i] == firstDigit[j] && minDigit[i] == minDigit[j] && posl2[i] > posl2[j]))
                {
                    int tmp = posl2[i];
                    posl2[i] = posl2[j];
                    posl2[j] = tmp;

                    tmp = firstDigit[i];
                    firstDigit[i] = firstDigit[j];
                    firstDigit[j] = tmp;

                    tmp = minDigit[i];
                    minDigit[i] = minDigit[j];
                    minDigit[j] = tmp;
                }

        std::cout << "Sorted sequance: ";
        for(int i = 0; i<n2; i++)
            std::cout << posl2[i] << " ";
    

    //3.
    const int N_Max3 = 100, M_Max3 = 100;
    int posl3[N_Max3][M_Max3];
    int n3, m3;
    int sumstr = INT_MAX;
    int istr;
    std::cout << std::endl << "Task 3." << std::endl << "Input: n and m: ";
    std::cin >> n3 >> m3;
    std::cout << "Input: " << n3 << "x" << m3 << " matrix values below." << std::endl;
    for(int i=0; i<n3; i++)
        for(int j=0; j<m3; j++) //Цикл для ввода последовательности
            std::cin >> posl3[i][j];

    for(int i=0; i<n3; i++) //Цикл для нахождения минимальной суммы строки и номера строки
    {
        int minsum = 0;
        for(int j=0; j<m3; j++)
        {
            minsum += posl3[i][j];
        }
        if(sumstr > minsum)
        {
            sumstr = minsum;
            istr = i;
        }    
    }
    for(int i=0; i<n3; i++) //Цикл для замены значений строки на сумму
    {   
        if(istr == i)
        {
            for(int j=0; j<m3; j++)
            posl3[i][j] = sumstr;
        }
    }
    std::cout << "Changed matrix:" << std::endl;
    for(int i=0; i<n3; i++) //Цикл для вывода изменённого массива
    {
        for(int j=0; j<m3; j++)
            std::cout << posl3[i][j] << " ";
        std::cout << std::endl;
    }

    //4.
    const int N_Max20k = 20000;
    int posl4[N_Max20k];
    int n4;
    std::cout << std::endl << "Task 4." << std::endl << "Input: n: ";
    std::cin >> n4;
    std::cout << "Input: " << n4 << " values: ";
    for(int i=0; i<n4; i++) //Цикл для ввода последовательности
        std::cin >> posl4[i];
    
    int j1 = 0; //Удаление
    for(int i=0;i<n4;i++)
    {
        int y = 0;
        int x = posl4[i];
        while(x>0) {
            int d = x % 10;
            y = y*10 + d;
            x = x/10;
        }
        if (posl4[i] == y)
            continue;
        posl4[j1] = posl4[i];
        j1++;
    }
    n4 = j1;
    std::cout << "Sequence with deleted palindromes: ";
    for(int i = 0; i<n4; i++)
        std::cout << posl4[i] << " ";   

    for(int i=0;i<n4;i++) //Дублирование простых чисел
    {    
        bool isPrime=true;
        for(int d=2; d<=sqrt(posl4[i])+1; d++)
        {
            if(posl4[i]%d == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            for(int j=n;j>1;j--)
            {
                posl4[j] = posl4[j-1];
            }
            i++;
            n4++;
        }
    }
    std::cout << std::endl << "Sequence with doubled prime numbers: ";
    for(int i = 0; i<n4; i++)
        std::cout << posl4[i] << " ";
    return 0;
}
