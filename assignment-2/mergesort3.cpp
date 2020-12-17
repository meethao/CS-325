#include <iostream>
#include <fstream>

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

void printfArray(int array[], int n){
//      cout << "After 3 way merge sort:" << endl;
      for(int i = 0; i < n; i++){
            cout << array[i] << " ";
      }
      cout << endl;
}

void printOutfile_1(int array[], int arr_size){
	ofstream outfile;
	outfile.open("merge3.txt", ios::app);

	if(outfile.fail()){
		cout << "Failed to open merge.txt" << endl;
	}

	for(int i = 0; i < arr_size; i++){
		outfile << array[i] << " ";
	}
	outfile << endl;
	outfile.close();
}

void printOutfile_2(int array[], int arr_size){
	ofstream outfile;
	outfile.open("insert.txt", ios::app);

	if(outfile.fail()){
		cout << "Failed to open merge.txt" << endl;
	}

	for(int i = 0; i < arr_size; i++){
		outfile << array[i] << " ";
	}
	outfile << endl;
	outfile.close();
}

void pass_array(int array[], int n){
      cout << "The original array:\n";
	printfArray(array, n);

	mergeSort_3(array, n);

	cout << "Sorted array is:\n";
	printfArray(array, n);
	printOutfile_1(array, n);
      printOutfile_2(array, n);

	return;
}

int main(){
      ifstream infile;
      infile.open("data.txt");

      if(infile.fail()){
        cout << "Failed to read data.txt" << endl;
      }

    	int m  = 0, n = 0;
    	int array[m][n], arr[n];

      while(infile.good()){
            infile >> n;
            for(int i = 0; i < n; i++){
                  infile >> array[m][i];
            }

            for(int i = 0; i < n; i++){
                  arr[i] = array[m][i];
            }

    		pass_array(arr, n);

            cout << endl;
            m++;
      }

      infile.close();
}
