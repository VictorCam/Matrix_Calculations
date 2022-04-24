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

int main(int argc, char const *argv[]) {
  ifstream mat1; //open matrix1 file and matrix2 file
  ifstream mat2;

  ifstream mat1_lines;
  ifstream mat2_lines;

  ofstream results;

  string lines; //used to loop through files
  char c; //used for checking if things are a space
  char* ch; //used for strtok
  int rows1 = 0; //used for having the rows and columns for both matrix1 file and matrix2 file
  int cols1 = 0;
  int rows2 = 0;
  int cols2 = 0;

  mat1.open("./m1"); //width must be longer
  mat2.open("./m2"); //length must be longer
  mat1_lines.open("./m1");
  mat2_lines.open("./m2");
  results.open("./results");
  if(!mat1 || !mat2 || !mat1_lines || !mat2_lines || !results) {
    cout << "unable to open mat file(s)" << endl;
    exit(1);
  }
  else
  {
    cout << "opened all mat file" << endl;
  }


  while(!mat1.eof()) { //this gets the rows and the columns for mat1
    mat1.get(c);
    if(c == '\n') {
      rows1++;
    }
    if(isspace(c) && rows1 == 0) {
      cols1++;
    }
  }

  while(!mat2.eof()) { //this gets the rows and the columns for mat2
    mat2.get(c);
    if(c == '\n') {
      rows2++;
    }
    if(isspace(c) && rows2 == 0) {
      cols2++;
    }
  }

  int mat1_arr[rows1 * cols1];
  int mat2_arr[rows2 * cols2];
  int i = 0, j = 0;

  while(getline(mat1_lines, lines)) { //this deliminates the spaces and puts it into a new file for mat1
    char raw_arr[lines.size()+1];
    strcpy(raw_arr, lines.c_str());
    ch = strtok(raw_arr, "\t ");
    while(ch != NULL) {
      //cout << "ch1: " << ch << endl;
      mat1_arr[i] = atoi(ch);
      i++;
      //mat1_temp << ch << endl;
      ch = strtok(NULL, "\t ");
    }
  }

  while(getline(mat2_lines, lines)) { //this deliminates the spaces and puts it into a new file for mat2
    char raw_arr[lines.size()+1];
    strcpy(raw_arr, lines.c_str());
    ch = strtok(raw_arr, "\t ");
    while(ch != NULL) {
      //cout << "ch2: " << ch << endl;
      mat2_arr[j] = atoi(ch);
      j++;
      //mat2_temp << ch << endl;
      ch = strtok(NULL, "\t ");
    }
  }

  rows1--;
  cols1++;
  rows2--;
  cols2++;

  /////////////CODE ABOVE IS NOT THE ALGORITHM MATRIX ALGORITHM////////////////
  //ABOVE CODE GETS THE ROWS AND COLUMNS OF BOTH FILES WHICH SHOULD BE O(N)
  //ABOVE CODE USES STRTOK TO GET NUMBERS FROM FILE WHICH SHOULD BE O(n log n)
  //ABOVE CODE COULD BE CHANGED IN A WAY WHERE EVERYTHING IS O(N)

  int arr[(rows1*cols1)+(rows2*cols2)];

  if(cols1 < cols2) {

  for (int y = 0; y < (rows1*cols1)+(rows2*cols2); y++) {
    arr[y] = mat1_arr[y];
    if(y >= rows2*cols2) {
      //cout << "entered" << endl;
      arr[y] = mat2_arr[y-(rows1*cols1)];
    }
  }
}
else { //MISSING A CASE FOR REVERSED ORDER
  for (int y = 0; y < (rows1*cols1)+(rows2*cols2); y++) {
    arr[y] = mat1_arr[y];
    if(y >= rows2*cols2) {
    //cout << "entered" << endl;
    arr[y] = mat2_arr[y-(rows1*cols1)];
  }
}
int tmp1 = rows1; //siwtch the for proper calculation
int tmp2 = rows2;
rows1 = cols1;
cols1 = tmp1;

rows2 = cols2;
cols2 = tmp2;
}

  ///////////////CODE BELOW IS THE MATRIX MULTIPLICATION ALGORITHM////////////////////

  /*STARTING RUNTIME HERE*/
    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
  //new
  int increment6 = 0;
  int increment1 = 0;
  int increment4 = 0;
  int increment5 = 0;
  int cut1 = 0;
  int cut2 = 0;
  int multiply = 0;
  int sum = 0;
  int index = 0;
  //


  //increment4 is in charge of newlines
  //counting1 is in charge of position of array1
  //counting2 is in charge of position of array2

  int counting1 = 1; //good
  int counting2 = (( rows1 * cols1 ) + 1); //MUTLIPLICATION
  int increment3 = counting2; //good
  int inc = 0; //good
  int stop = 0;
  //int stop =  cols2 * rows1; //OLD SOLUTION but almost
  if((cols1+rows2) == (cols2+rows1)) { //for example of matrix is 25 x 25 it should be this stoping condition
    stop =  cols2 * rows1;
  }
  else{
    stop = cols1 + rows2; //fixed
  }


int a = 0;
while(true) {
  a++;
          if(increment6 == stop){ //will eventually reach break once it reaches it suffice number of executions
              //cat multfile;
              //rm newfile2 multfile;
              cout << endl << "quiting program" << endl;
              break;
          }

          //cout << "c1: " << counting1 << endl;
          //cout << "c2: " << counting2 << endl;
          cut1 = arr[counting1-1];
          cut2 = arr[counting2-1];
          //cout << "cut1: " << cut1 << endl;
          //cout << "cut2: " << cut2 << endl;

          counting1 += 1;
          counting2 += cols1; //5
          increment1 += 1;
          increment4 += 1;

          multiply = cut1 * cut2;
          sum += multiply;

          if (increment1 == rows1) {
              //we need these two increments and index so we don't land at a bad spot
              increment6 += 1;
              increment5 += 1;
              index = increment3 + increment6;
              if(increment5 == cols2) { //here we print the new number without a new line or tab.
                  //echo -e -n "$sum" >> multfile

                  results << sum << " "; //NEW
                  //cout << sum << " ";

                  sum -= sum; //reset sum
                  increment1 -= increment1; //restart the counter again
                  counting1 = counting1 - rows1; //go back to original spot again for cut1
                  counting2 = index - cols1  * inc; //go back to original spot +1 again for cut2
                  increment5 -= increment5;
                }
              else {
                  results << sum << " "; // NEW
                  //cout << sum << " ";
                  sum -= sum; //reset sum
                  increment1 -= increment1; //restart the counter again
                  counting1 = counting1 - rows1; //go back to original spot again for cut1
                  counting2 = index - cols1  * inc; //go back to original spot +1 again for cut2
                }
            if (increment4 == (rows2 * cols2)) { //15 //rows * cols or rows2 * cols2
                inc += 1;
                results << endl; // NEW

                increment4 -= increment4; //reseting increment4
                counting1 = counting1 + rows1; //offsetting cut1
                counting2 = index - cols1  * inc; //go back to original spot +1 again for cut2
              }
            }
          }
          end = chrono::system_clock::now();
          chrono::duration<double>seconds = end - start;
          cout << endl << "total seconds: " << seconds.count() << endl;
  return 0;
}
