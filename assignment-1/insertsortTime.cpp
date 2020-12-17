#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>
#include <fstream>

using namespace std;

void printfArray(int array[], int arr_size){
  for(int i = 0; i < arr_size; i++){
    cout << array[i] << " ";
  }
}

void insertionSort(int array[], int arr_size){
  int temp = 0, j = 0;
  for(int i = 1; i < arr_size; i++){
    temp = array[i];
    j = i -1;

    while (j >= 0 && array[j] > temp) {
      array[j+1] = array[j];
      j = j - 1;
    }
    array[j+1] = temp;
  }
}

int main(){
  const int n = 1000002;
  int array[n];
  float total = 0, average = 0;

  ofstream outfile;
	outfile.open("insertTime.txt", ios::app);

	if(outfile.fail()){
		cout << "Failed to open insertTime.txt" << endl;
	}

  for(int i = 0; i <= 100000; i = i+10000){
    outfile << i << " ";
    cout << i << " ";
    for(int k = 1; k <= 3; k++){
      srand(time(NULL));
      for(int j = 0; j <= i; j++){
        array[j] = rand() % 10000;
      }

      clock_t t1, t2;
      t1 = clock(); //start time

      insertionSort(array, i);

      t2 = clock(); //end time

      float diff((float) t2 - (float) t1);
      float seconds = diff / CLOCKS_PER_SEC;
      total = total + seconds;
      cout << "   " << seconds;
      outfile << "  " << seconds;
    }
    average = total / 3;
    cout << "   average  " << average << endl;
    outfile << "  " << average << endl;
  }
  outfile.close();
  return 0;
}
