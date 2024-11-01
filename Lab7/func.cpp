#include "func.hpp"
#include <iostream>

void Read(int matrix[N_Max][M_Max], int& n, int& m) {
    std::cout << "Input n, m: ";
    std::cin >> n;
    std::cin >> m;
    std::cout << "Input matrix values:" << std::endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

bool hasSecMin(int matrix[N_Max][M_Max], int n, int m) {
    int min=INT_MAX;
    int sum=0;    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(min>matrix[i][j]) {
                min=matrix[i][j];
                sum=1;
            }
            else if(min==matrix[i][j]) {
                sum++;
            }
        }
    }
    if(sum>=2) {
        return true;
    }
    else {
        return false;
    }
}

int f_abs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

bool hasTwoPrimes(int matrix[N_Max][M_Max], int n, int m) {
    int sum=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            bool isPrime = true;
            int x=f_abs(matrix[i][j]);
            for(int d=2; d<=sqrt(x); d++) {
                if(x%d == 0) {
                    isPrime=false;
                    break;
                }
            }
            if(isPrime) {
                sum++;
            }
            if(sum>=2) {
                return true;
            }
        }
    }
    return false;
}

int productOfRow(int row[], int m) {
    int product = 1;
    for(int i=0; i<m; i++) {
        product *= row[i];
    }
    return product;
}

void swapRows(int a[], int b[], int m) {
    for(int i=0; i<m; i++) {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

void Sort(int matrix[N_Max][M_Max], int n, int m) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(productOfRow(matrix[j], m) < productOfRow(matrix[j+1], m)) {
                swapRows(matrix[j], matrix[j+1], m);
            }
        }
    }
}

void Write(int matrix[N_Max][M_Max], int n, int m) {
    std::cout << "Output is:" << std::endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            std::cout << matrix[i][j] << " ";
        }
    std::cout << std::endl;
    }
}
