#include <bits/stdc++.h>
#include "SparseMatrix.cpp"

using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int r(int l, int r)
{
    return rnd() % (r - l + 1) + l;
}

int main()
{
    SparseMatrix matrix1, matrix2, matrix3;
    InitSparseMatrix(matrix1, 5, 5);
    InitSparseMatrix(matrix2, 5, 5);
    InitSparseMatrix(matrix3, 5, 5);
    for (int i = 0; i < 10; i++)
    {
        InsertSparseMatrix(matrix1, r(1, 5), r(1, 5), r(1, 100));
        InsertSparseMatrix(matrix2, r(1, 5), r(1, 5), r(1, 100));
    }
    PrintSparseMatrix(matrix1);
    PrintSparseMatrix(matrix2);
    matrix3 = AddSparseMatrix(matrix1, matrix2);
    PrintSparseMatrix(matrix3);
}