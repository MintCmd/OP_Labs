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
    //Задание 1.
    const int N_Max = 10000;
    int seq1[N_Max];
    bool hasPrime = false;
    int n;
    std::cout << "Task 1." << std::endl << "Input: n: ";
    std::cin >> n;
    std::cout << "Input: " << n << " values: ";
    for(int i=0; i<n; i++) //Цикл для ввода последовательности
    {
        std::cin >> seq1[i];
    }
        
    for(int i=0; i<n; i++) //Цикл для проверки, есть ли в последовательности проcтое число
    {
        bool isPrime=true;
        for(int d=2; d<=sqrt(seq1[i]); d++)
        {
            if(seq1[i]%d == 0)
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
        for(int i=0; i<n-1; i++) //Двойной цикл для сортировки по невозрастанию SWAP SORT
        {
            for(int j=i+1; j<n; j++)
            {
                if(seq1[i] < seq1[j])
                {
                    int tmp = seq1[i];
                    seq1[i] = seq1[j];
                    seq1[j] = tmp;
                }
            }
        }
        std::cout << "Sorted sequance: ";
        for(int i = 0; i<n; i++)
        {
            std::cout << seq1[i] << " ";
        }
    }

    //Задание 2.
    int seq2[N_Max];
    int firstDigit[N_Max];
    int minDigit[N_Max];
    int n2;
    std::cout << std::endl << "Task 2." << std::endl << "Input: n: ";
    std::cin >> n2;
    std::cout << "Input: " << n2 << " values: ";
    for(int i=0; i<n2; i++) //Цикл для ввода массива и поиска первой и минимальной цифр
    {
        std::cin >> seq2[i];
        firstDigit[i] = seq2[i];

        while(firstDigit[i] > 9)
        {
            firstDigit[i] /= 10;
        } 
        int dif = seq2[i];
        minDigit[i] = 9;

        while(dif > 0)
        {
            int min = dif%10;
            if(minDigit[i] < min)
            {
                minDigit[i] = min;
            }
            dif /= 10;
        }
    }

    for(int i=0; i<n2-1; i++) //Двойной цикл для сортировки по неубыванию
    {
        for(int j=i+1; j<n2; j++)
        {
            if((firstDigit[i] > firstDigit[j]) || 
                ((firstDigit[i] == firstDigit[j]) && (minDigit[i] > minDigit[ j])) || 
                    ((firstDigit[i] == firstDigit[j]) && (minDigit[i] == minDigit[j]) && (seq2[i] > seq2[j])))
            {
                int tmp = seq2[i];
                seq2[i] = seq2[j];
                seq2[j] = tmp;

                tmp = firstDigit[i];
                firstDigit[i] = firstDigit[j];
                firstDigit[j] = tmp;

                tmp = minDigit[i];
                minDigit[i] = minDigit[j];
                minDigit[j] = tmp;
            }
        }        
    } 
            
    std::cout << "Sorted sequance: ";
    for(int i = 0; i<n2; i++)
    {
        std::cout << seq2[i] << " ";
    }
    

    //Задание 3.
    const int N_Max3 = 100, M_Max3 = 100;
    int matrix[N_Max3][M_Max3];
    int n3, m3;
    int sumstr = INT_MAX;
    int istr;
    std::cout << std::endl << "Task 3." << std::endl << "Input: n and m: ";
    std::cin >> n3;
    std::cin >> m3;
    std::cout << "Input: " << n3 << "x" << m3 << " matrix values below." << std::endl;
    for(int i=0; i<n3; i++) //Цикл для ввода последовательности
    {
        for(int j=0; j<m3; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    for(int i=0; i<n3; i++) //Цикл для нахождения минимальной суммы строки и номера строки
    {
        int minsum = 0;
        for(int j=0; j<m3; j++)
        {
            minsum += matrix[i][j];
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
            {
                matrix[i][j] = sumstr;
            }
        }
    }
    std::cout << "Changed matrix:" << std::endl;
    for(int i=0; i<n3; i++) //Цикл для вывода изменённого массива
    {
        for(int j=0; j<m3; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    //Задание 4.
    const int N_Max20k = 20000;
    int seq4[N_Max20k];
    int n4;
    std::cout << std::endl << "Task 4." << std::endl << "Input: n: ";
    std::cin >> n4;
    std::cout << "Input: " << n4 << " values: ";
    for(int i=0; i<n4; i++) //Цикл для ввода последовательности
    {
        std::cin >> seq4[i];
    }
        
    int j1 = 0; //Удаление
    for(int i=0;i<n4;i++)
    {
        int y = 0;
        int x = seq4[i];
        while(x>0) 
        {
            int d = x % 10;
            y = y*10 + d;
            x = x/10;
        }
        if (seq4[i] == y)
        {
            continue;
        }
        seq4[j1] = seq4[i];
        j1++;
    }
    n4 = j1;
    std::cout << "Sequence with deleted palindromes: ";
    for(int i = 0; i<n4; i++)
    {
        std::cout << seq4[i] << " ";  
    }     

    for(int i=0;i<n4;i++) //Дублирование простых чисел
    {    
        bool isPrime=true;
        for(int d=2; d<=sqrt(seq4[i]); d++)
        {
            if(seq4[i]%d == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            for(int j=n;j>1;j--)
            {
                seq4[j] = seq4[j-1];
            }
            i++;
            n4++;
        }
    }
    std::cout << std::endl << "Sequence with doubled prime numbers: ";
    for(int i = 0; i<n4; i++)
    {
        std::cout << seq4[i] << " ";
    }
    return 0;
}
