
// C++ program to multiply two
// rectangular matrices
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <time.h>
#include <ctime>
#include <chrono>
#include <array>
using namespace std;

// Multiplies two matrices mat1[][]
// and mat2[][] and prints result.
// (m1) x (m2) and (n1) x (n2) are
// dimensions of given matrices.
void multiply(int m1, int m2, int mat1[][2],
              int n1, int n2, int mat2[][2])
{
    int x, i, j;
    int res[m1][n2];
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            res[i][j] = 0;
            for (x = 0; x < m2; x++)
            {
                *(*(res + i) + j) += *(*(mat1 + i) + x) *
                                     *(*(mat2 + x) + j);
            }
        }
    }
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            cout << *(*(res + i) + j) << " ";
        }
        cout << "\n";
    }
}

// Driver code
int main()
{
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();
    int mat1[][2] = { { 2, 4 }, { 3, 4 } };
    int mat2[][2] = { { 1, 2 }, { 1, 3 } };
    int m1 = 2, m2 = 2, n1 = 2, n2 = 2;
    multiply(m1, m2, mat1, n1, n2, mat2);
    end = chrono::system_clock::now();
    chrono::duration<double>seconds = end - start;
    cout << endl << "total seconds: " << seconds.count() << endl;
    return 0;
}

// This code is contributed
// by Akanksha Rai(Abby_akku)
