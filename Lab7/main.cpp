//Вариант 4
//
//Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если в матрице есть еще один элемент, 
//равный ее минимальному элементу, и не менее 2-х элементов, абсолютные величины которых - простые числа, 
//упорядочить строки матрицы по невозрастанию произведений элементов. 

#include "func.hpp"
#include <iostream>

int main() {
    int n, m;
    int matrix[N_Max][M_Max];
    Read(matrix, n, m);
    if(hasSecMin(matrix, n, m) && hasTwoPrimes(matrix, n, m)) {
        Sort(matrix, n, m);
    }
    Write(matrix, n, m);
    return 0;
}
