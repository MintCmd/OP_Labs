#pragma once

const int N_Max = 100;
const int M_Max = 100;

void Read(int matrix[N_Max][M_Max], int& n, int& m);
bool hasSecMin(int matrix[N_Max][M_Max], int n, int m);
int f_abs(int x);
bool hasTwoPrimes(int matrix[N_Max][M_Max], int n, int m);
int productOfRow(int row[], int m);
void Sort(int matrix[N_Max][M_Max], int n, int m);
void Write(int matrix[N_Max][M_Max], int n, int m);
