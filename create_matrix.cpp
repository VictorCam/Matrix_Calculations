#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream matrix1; ofstream matrix2;
  matrix1.open("./m3"); matrix2.open("./m4");

  int rows = 1000;
  int cols = rows;
  int count = 1;
  int x = 0;

  //purpose of this program is to make a quick way to create matricies for m3 and m4

  // cout << "enter number of rows: ";
  // cin >> rows;
  // cout << "enter number of columns: ";
  // cin >> cols;
  for (int i = 0; i < rows*cols; i++) {
    x++;
    if(x == cols) {
      x = 0;
      matrix1 << count; matrix2 << count;
      matrix1 << endl; matrix2 << endl;
      count = 0;
    }
    else {
      matrix1 << count << " "; matrix2 << count << " ";
    }
    count++;
  }
  matrix1.close();
  matrix2.close();
  cout << "matrix completed" << endl;
  return 0;
}
