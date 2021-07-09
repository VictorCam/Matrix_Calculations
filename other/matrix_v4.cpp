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

int main() {
  ifstream mat1; ifstream mat2; //used to open matrix1 and matrix2
  ifstream mat1_lines; ifstream mat2_lines; //used to open matrix1 nad matrix2 again
  ofstream results; //used to place the final results of the matrix multiplication
  char c; //used for getting each character in the file
  int rows1 = 0; int cols1 = 0; //rows and cols of first matrix file
  int rows2 = 0; int cols2 = 0; //rows and cols of second matrix file


  //opening the matrix files and results for storing
  mat1.open("./mat7"); //used 78 and 56
  mat2.open("./mat8");
  mat1_lines.open("./mat7");
  mat2_lines.open("./mat8");
  results.open("./results");

  //check if the files are open if not then quit the program
  if(!mat1 || !mat2 || !mat1_lines || !mat2_lines || !results) {
    cout << "unable to open files" << endl;
    exit(1);
  }
  else {
    cout << "opened all files" << endl;
  }


  //https://stackoverflow.com/questions/32940746/what-is-the-time-complexity-of-this-program (while eof should be linear)
  while(!mat1.eof()) { //this gets the rows and the columns for matrix1 O(N)
    mat1.get(c);
    if(c == '\n') {
      rows1++;
    }
    if(isspace(c) && rows1 == 0) {
      cols1++;
    }
  }

  while(!mat2.eof()) { //this gets the rows and the columns for matrix2 O(N)
    mat2.get(c);
    if(c == '\n') {
      rows2++;
    }
    if(isspace(c) && rows2 == 0) {
      cols2++;
    }
  }



  //http://www.cplusplus.com/reference/string/string/getline/ (should be linear)

  string s1; //used to store whole file of matrix1 into this string
  char* c1; //used for strtok below
  getline(mat1_lines, s1, '\0'); //stores contents of the file into a string called s1 (should generally be linear O(N))
  char raw_arr1[s1.size()+1]; //create an array size of the string
  strcpy(raw_arr1, s1.c_str()); //copy the string into the character array



  string s2; //used to store whole file of matrix2 into this string
  char* c2; //used for strtok below
  getline(mat2_lines, s2, '\0');
  char raw_arr2[s2.size()+1]; //create an array size of the string
  strcpy(raw_arr2, s2.c_str()); //copy the string into the character array



  int mat1_arr[10000]; //avoided using (rows1 * cols1) used hardcoded value
  int mat2_arr[10000]; //avoided using (rows2 * cols2) used hardcoded value


  //stoi http://www.cplusplus.com/reference/string/stoi/ (unknown but usually linear time)
  //strtok unknown on time complexity

  //STRTOK IS NOT RELIABLE FOR PARSING LARGE MATRICES

  int n1 = 0;
  int n2 = 0;

  c1 = strtok(raw_arr1, "\t\n ");
  int n = 0;
  while(c1 != NULL) {
    //cout << c1 << endl;
    mat1_arr[n] = stoi(c1);
    c1 = strtok(NULL, "\t\n ");
    n++; //we count the number of values that exist in matrix 1
  }

//  cout << "c1: " << c1 << " :c1" << endl;
  n1 = n; //this is the number of elements

  //stoi http://www.cplusplus.com/reference/string/stoi/ (unknown but usually linear time)
  //strtok unknown on time complexity

  c2 = strtok(raw_arr2, "\t\n ");
  n = 0;
  while(c2 != NULL) {
    mat2_arr[n] = stoi(c2);
    c2 = strtok(NULL, "\t\n ");
    n++; //we count the number of values that exist in matrix 2
  }
  rows1--; cols1++; rows2--; cols2++; //offset the position to the right spot


  n2 = n; //this is the number of elements

  int arr[(n1)+(n2)]; //allocate the right size of the array




  //MISSING A CASE FOR REVERSED ORDER
  //below if and else should be linear
  if(cols1 < cols2) {
    for (int y = 0; y < (n1)+(n2); y++) {
      arr[y] = mat1_arr[y];
    if(y >= n2) {
      arr[y] = mat2_arr[y-(n1)];
    }
  }
}
  else {
  for (int y = 0; y < (n1)+(n2); y++) {
    arr[y] = mat1_arr[y];
    if(y >= n2) {
    arr[y] = mat2_arr[y-(n1)];
  }
}

//assigns the values in different values so that the matrix multiplication calculation works
int tmp1 = rows1;
int tmp2 = rows2;
rows1 = cols1;
cols1 = tmp1;

rows2 = cols2;
cols2 = tmp2;
}



/*
THINGS TO NOTE
n1 = (cols1 * rows1) or (count ever single value in the file) or (let n1 = user input by dimension)

n2 = (cols2 * cols2) or (count ever single value in the file) or (let n2 = user input by dimension)

mat1_arr[] and mat2_arr[] = (filler linearly by user (rows and cols must be defined)) or (declared with a set size (rows and cols must be defined)) or (found by file)

rows1 rows2 cols1 cols2 = (declared by user) or (found by file)

arr[n1+n2] = (just store values from the two arrays  mat1_arr[] and mat2_arr[])

*/

//STARTING RUNTIME HERE
  chrono::time_point<chrono::system_clock> start, end;
  start = chrono::system_clock::now();


  //initializes these values below to 0 for now
  int inc6 = 0;
  int inc1 = 0;
  int inc4 = 0; //inc4 is in charge of newlines
  int inc5 = 0;
  int cut1 = 0;
  int cut2 = 0;
  int multiply = 0;
  int sum = 0;
  int index = 0;
  int stop = 0;
  int pos = 0;

  int counting1 = 1; //counting1 is in charge of position of array1
  int counting2 = n1 + 1; //counting2 is in charge of position of array2
  int inc3 = counting2;
  if(n1 == n2) { //for example of matrix is (25x25) x (25x25) it should be this stoping condition
    stop = n1; //stop is used to keep track on how many times the while loop needs to execute
  }
  else{
    stop = cols1 + rows2; //stop is used to keep track on how many times the while loop needs to execute
  }

//int a = 0;
    while(inc6 != stop) { //if running with a 20x20 * 20x20 matrix the number of executions will be 20x20x20 or (8000)
      //cout << "num of exe: " << a << endl;
      //a++;
      //finding the correct position using counting1 and counting2
      cut1 = arr[counting1-1];
      cut2 = arr[counting2-1];

      //incrementing for the next position on the single array
      counting1 += 1;
      counting2 += cols1;
      inc1 += 1;
      inc4 += 1;

      //cout << "cut1: " << cut1 << " * " << cut2 << "= " << cut1*cut2 << endl;
      //cout << "multiply" << endl;
      multiply = cut1 * cut2; //do the multiplication of the two matricies depending on their position
      sum += multiply; //add it to the sum for later printing once we finish a calculated matrix

      if (inc1 == rows1) {
        inc6 += 1; //we need these two incs and index so we don't land at a bad spot
        inc5 += 1;
        index = inc3 + inc6;
        if(inc5 == cols2) { //here we print the new number without a new line or tab.
          results << sum << " ";
          //cout << sum << endl;
          //cout << sum << " ";
          sum = 0; //reset sum
          inc1 = 0; //restart the counter again
          counting1 = counting1 - rows1; //go back to original spot again for cut1
          counting2 = index - pos; //go back to original spot +1 again for cut2
          inc5 = 0;
        }
        else {
          results << sum << " ";
          //cout << sum << endl;
          //cout << sum << " "; //adds a space
          sum = 0; //reset sum
          inc1 = 0; //restart the counter again
          counting1 = counting1 - rows1; //go back to original spot again for cut1
          counting2 = index - pos; //go back to original spot +1 again for cut2
        }
      if (inc4 == n2) { //check if inc4 is equal to the number of values in matrix2
        results << endl;
        //cout << endl; //adds a newline
        pos += cols1; //used for positioning to the right count
        inc4 = 0; //reseting inc4
        counting1 = counting1 + rows1; //go to the next position for cut1
        counting2 = index - pos; //go back to original spot +1 again for cut2
      }
    }
  }
  end = chrono::system_clock::now();
  chrono::duration<double>seconds = end - start;
  cout << endl << "total seconds: " << seconds.count() << endl;
  return 0;
}
