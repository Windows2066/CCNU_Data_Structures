#include <bits/stdc++.h>

#ifndef SPARSE_MATRIX_CPP
#define SPARSE_MATRIX_CPP

using namespace std;

typedef int ElemType;

struct point
{
    int row, col;
    ElemType value;
};

struct SparseMatrix
{
    vector<point> data;
    int rows, cols;
};

void InitSparseMatrix(SparseMatrix &matrix, int rows, int cols)
{
    matrix.rows = rows;
    matrix.cols = cols;
}

bool InsertSparseMatrix(SparseMatrix &matrix, int row, int col, ElemType value)
{
    point p;
    if (row > matrix.rows || col > matrix.cols)
    {
        return false;
    }
    p.row = row;
    p.col = col;
    p.value = value;
    for (auto it = matrix.data.begin(); it != matrix.data.end(); it++)
    {
        if (it->row == row && it->col == col)
        {
            it->value += value;
            return true;
        }
    }
    matrix.data.push_back(p);
    return true;
}

bool FindElem(SparseMatrix &matrix, int row, int col, ElemType value)
{
    for (auto it = matrix.data.begin(); it != matrix.data.end(); it++)
    {
        if (it->row == row && it->col == col && it->value == value)
        {
            return true;
        }
    }
    return false;
}

SparseMatrix AddSparseMatrix(SparseMatrix &matrix1, SparseMatrix &matrix2)
{
    SparseMatrix matrix = matrix1;
    for (auto it = matrix2.data.begin(); it != matrix2.data.end(); it++)
    {
        bool flag = false;
        for (auto it1 = matrix.data.begin(); it1 != matrix.data.end(); it1++)
        {
            if (it->row == it1->row && it->col == it1->col)
            {
                flag = true;
                it1->value += it->value;
                break;
            }
        }
        if (!flag)
        {
            InsertSparseMatrix(matrix, it->row, it->col, it->value);
        }
    }
    return matrix;
}

void PrintSparseMatrix(SparseMatrix &matrix)
{
    cout << "size: " << matrix.data.size() << endl;
    for (auto it = matrix.data.begin(); it != matrix.data.end(); it++)
    {
        cout << "row: " << it->row << " col: " << it->col << " value: " << it->value << endl;
    }
    cout << endl;
}

#endif // SPARSE_MATRIX_CPP