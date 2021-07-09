// C++ program to multiply
// two square matrices.
#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;

#define N 300

// This function multiplies
// mat1[][] and mat2[][], and
// stores the result in res[][]
void multiply(int mat1[][N],
			int mat2[][N],
			int res[][N])
{
	int i, j, k;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			res[i][j] = 0;
			for (k = 0; k < N; k++)
				res[i][j] += mat1[i][k] *
							mat2[k][j];
		}
	}
}

// Driver Code
int main()
{
	int i, j;
	int res[N][N]; // To store result
  int mat1[N][N];
  int mat2[N][N];

  int x = 0;

  for (int a = 0; a < N; a++) {
    for (int b = 0; b < N; b++) {
      x++;
      if(a < N) {
        mat1[a][b] = x;
        mat2[a][b] = x;
        //cout << x << " ";
      }
      else {
        mat1[a][b] = x;
        mat2[a][b] = x;
        //cout << x << " ";
      }
    }
  }

	// int mat1[N][N] = {{1, 1, 1, 1, 1},8
	// 				{2, 2, 2, 2 , 2},
	// 				{3, 3, 3, 3, 3},
	// 				{4, 4, 4, 4, 4}};
  //
	// int mat2[N][N] = {{1, 1, 1, 1, 1},
	// 				{2, 2, 2, 2, 2},
	// 				{3, 3, 3, 3, 3},
	// 				{4, 4, 4, 4, 4}};

  ofstream results_trad;
  results_trad.open("./results_t");

  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();
	multiply(mat1, mat2, res);

	cout << "Result matrix is \n";
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		results_trad << res[i][j] << " ";
		results_trad << "\n";
	}

  end = chrono::system_clock::now();
  chrono::duration<double>seconds = end - start;
  cout << endl << "[SUCCESS] total seconds: " << seconds.count() << endl;
	return 0;
}

// This code is contributed
// by Soumik Mondal
