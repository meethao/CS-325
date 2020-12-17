#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
#include <cstdlib>

using namespace std;

void merge(int array[], int low, int mid_1, int mid_2, int high, int array_2[]){
      int i = low, j = mid_1, k = mid_2, l = low;

      while((i < mid_1) && (j < mid_2) && (k < high)){
            if(array[i] < array[j]){
                  if(array[i] < array[k])
                        array_2[l++] = array[i++];
                  else
                        array_2[l++] = array[k++];
            }
            else{
                  if(array[j] < array[k])
                        array_2[l++] = array[j++];
                  else
                        array_2[l++] = array[k++];

            }
      }

      while((i < mid_1) && (j < mid_2)){
            if(array[i] < array[j])
                  array_2[l++] = array[i++];
            else
                  array_2[l++] = array[j++];
      }

      while((k < high) && (j < mid_2)){
            if(array[j] < array[k])
                  array_2[l++] = array[j++];
            else
                  array_2[l++] = array[k++];
      }

      while((i < mid_1) && (k < high)){
            if(array[i] < array[k])
                  array_2[l++] = array[i++];
            else
                  array_2[l++] = array[k++];
      }

      while(i < mid_1){
            array_2[l++] = array[i++];
      }
      while (j < mid_2) {
            array_2[l++] = array[j++];
      }
      while (k < high) {
            array_2[l++] = array[k++];
      }
}


void mergeSort_3_recursion(int array[], int low, int high, int array_2[]){
      if(high - low < 2){
            return;
      }

      int mid_1 = low + ((high - low) / 3);
      int mid_2 = high - ((high - low) / 3) - 1;
//      int mid_2 = low + 2 * ((high - low) / 3) + 1;

      mergeSort_3_recursion(array_2, low, mid_1, array);
      mergeSort_3_recursion(array_2, mid_1, mid_2, array);
      mergeSort_3_recursion(array_2, mid_2, high, array);

      merge(array_2, low, mid_1, mid_2, high, array);
}


void mergeSort_3(int array[], int n){
      if(n == 0){
            return;
      }

      int array_2[n];

      for(int i = 0; i < n; i++){
            array_2[i] = array[i];
      }

      mergeSort_3_recursion(array_2, 0, n, array);

      for(int i = 0; i < n; i++){
            array[i] = array_2[i];
      }
}


int main(){
      const int n = 1000002;
      int array[n];
      float total = 0, average = 0;

      ofstream outfile;
	outfile.open("merge3Time.txt", ios::app);

	if(outfile.fail()){
		cout << "Failed to open mergeTime.txt" << endl;
	}

      for(int i = 0; i <= 1000000; i = i+100000){
            outfile << i << " ";
            cout << i << " ";
            for(int k = 1; k <= 3; k++){
                  srand(time(NULL));
                  for(int j = 0; j <= i; j++){
                        array[j] = rand() % 10000;
                  }

                  clock_t t1, t2;
                  t1 = clock(); //start time

                  mergeSort_3(array, i);

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
