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

// Все задачи расположены в разных зонах видимости, поэтому можно использовать одинаковые имена переменнных
// и ошибки переопределения не будет и можно не создавать n, n2, n3, seq1[], seq2[], seq3[] и т.д.
#include <iostream>

int main() {
    //Задание 1.
    {
        const int N_Max = 10000;
        int seq[N_Max];
        bool hasPrime = false;
        int n;
        std::cout << "Task 1." << std::endl << "Input: n: ";
        std::cin >> n;
        std::cout << "Input: " << n << " values: ";
        for(int i=0; i<n; i++) { //Цикл для ввода последовательности
            std::cin >> seq[i];
        }
            
        for(int i=0; i<n; i++) { //Цикл для проверки, есть ли в последовательности проcтое число
            bool isPrime=true;
            for(int d=2; d<=sqrt(seq[i]); d++) {
                if(seq[i]%d == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) {
                hasPrime=true;
                break;
            }
        }
        if(hasPrime) {
            std::cout << "It has a prime number." << std::endl;
        }
        else {
            for(int i=0; i<n-1; i++) { //Двойной цикл для сортировки по невозрастанию SWAP SORT
                for(int j=i+1; j<n; j++) {
                    if(seq[i] < seq[j]) {
                        int tmp = seq[i];
                        seq[i] = seq[j];
                        seq[j] = tmp;
                    }
                }
            }
            std::cout << "Sorted sequance: ";
            for(int i = 0; i<n; i++) {
                std::cout << seq[i] << " ";
            }
        }
    }
    

    //Задание 2.
    {
        const int N_Max = 10000;
        int seq[N_Max];
        int firstDigit[N_Max];
        int minDigit[N_Max];
        int n;
        std::cout << std::endl << "Task 2." << std::endl << "Input: n: ";
        std::cin >> n;
        std::cout << "Input: " << n << " values: ";
        for(int i=0; i<n; i++) { //Цикл для ввода массива и поиска первой и минимальной цифр
            std::cin >> seq[i];
            firstDigit[i] = seq[i];

            while(firstDigit[i] > 9) {
                firstDigit[i] /= 10;
            } 
            int dif = seq[i];
            minDigit[i] = 9;

            while(dif > 0) {
                int min = dif%10;
                if(minDigit[i] < min) {
                    minDigit[i] = min;
                }
                dif /= 10;
            }
        }

        for(int i=0; i<n-1; i++) { //Двойной цикл для сортировки по неубыванию 
            for(int j=i+1; j<n; j++) {
                if((firstDigit[i] > firstDigit[j]) || 
                    ((firstDigit[i] == firstDigit[j]) && (minDigit[i] > minDigit[ j])) || 
                        ((firstDigit[i] == firstDigit[j]) && (minDigit[i] == minDigit[j]) && (seq[i] > seq[j]))) {
                    int tmp = seq[i];
                    seq[i] = seq[j];
                    seq[j] = tmp;

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
        for(int i = 0; i<n; i++) {
            std::cout << seq[i] << " ";
        }
    }

    //Задание 3.
    {
        const int N_Max = 100, M_Max = 100;
        int matrix[N_Max][M_Max];
        int n, m;
        int sumstr = INT_MAX;
        int istr;
        std::cout << std::endl << "Task 3." << std::endl << "Input: n and m: ";
        std::cin >> n;
        std::cin >> m;
        std::cout << "Input: " << n << "x" << m << " matrix values below." << std::endl;
        for(int i=0; i<n; i++) { //Цикл для ввода последовательности 
            for(int j=0; j<m; j++) {
                std::cin >> matrix[i][j];
            }
        }

        for(int i=0; i<n; i++) { //Цикл для нахождения минимальной суммы строки и номера строки
            int minsum = 0;
            for(int j=0; j<m; j++) {
                minsum += matrix[i][j];
            }
            if(sumstr > minsum) {
                sumstr = minsum;
                istr = i;
            }    
        }
        for(int i=0; i<n; i++) { //Цикл для замены значений строки на сумму
            if(istr == i) {
                for(int j=0; j<m; j++) {
                    matrix[i][j] = sumstr;
                }
            }
        }
        std::cout << "Changed matrix:" << std::endl;
        for(int i=0; i<n; i++) { //Цикл для вывода изменённого массива
            for(int j=0; j<m; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    //Задание 4.
    {
        const int N_Max = 20000;
        int seq[N_Max];
        int n;
        std::cout << std::endl << "Task 4." << std::endl << "Input: n: ";
        std::cin >> n;
        std::cout << "Input: " << n << " values: ";
        for(int i=0; i<n; i++) { //Цикл для ввода последовательности
            std::cin >> seq[i];
        }
            
        int j1 = 0; //Удаление
        for(int i=0;i<n;i++) {
            int y = 0;
            int x = seq[i];
            while(x>0) {
                int d = x % 10;
                y = y*10 + d;
                x = x/10;
            }
            if (seq[i] == y) {
                continue;
            }
            seq[j1] = seq[i];
            j1++;
        }
        n = j1;
        std::cout << "Sequence with deleted palindromes: ";
        for(int i = 0; i<n; i++) {
            std::cout << seq[i] << " ";  
        }     

        for(int i=0;i<n;i++) { //Дублирование простых чисел
            bool isPrime=true;
            for(int d=2; d<=sqrt(seq[i]); d++) {
                if(seq[i]%d == 0) {
                    isPrime = false;
                    break;
                }
            }
            if(isPrime) {
                for(int j=n;j>1;j--) {
                    seq[j] = seq[j-1];
                }
                i++;
                n++;
            }
        }
        std::cout << std::endl << "Sequence with doubled prime numbers: ";
        for(int i = 0; i<n; i++) {
            std::cout << seq[i] << " ";
        }
    }
    return 0;
}
