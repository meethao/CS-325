#include <iostream>
#include <fstream>

using namespace std;

void printfArray(int array[], int arr_size){
  for(int i = 0; i < arr_size; i++){
    cout << array[i] << " ";
  }
  cout << endl;
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

void printOutfile(int array[], int arr_size){
	ofstream outfile;
	outfile.open("insertsort.txt", ios::app);

	if(outfile.fail()){
		cout << "Failed to open merge.txt" << endl;
	}

	for(int i = 0; i < arr_size; i++){
		outfile << array[i] << " ";
	}
	outfile << endl;
	outfile.close();
}

void pass_array(int array[], int arr_size){
  cout << "The original array:\n";
	printfArray(array, arr_size);

	insertionSort(array, arr_size);

	cout << "Sorted array is:\n";
	printfArray(array, arr_size);
	printOutfile(array, arr_size);

	return;
}

int main(){
  ifstream infile;
  infile.open("data.txt");

  if(infile.fail()){
    cout << "Failed to read data.txt" << endl;
  }

  int m = 0, n = 0;
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
  return 0;
}
