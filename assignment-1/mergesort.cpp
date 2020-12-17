#include <iostream>
#include <fstream>

using namespace std;

void merge(int array[], int left, int m, int right){
	int i, j, k;
	int n1 = m - left + 1;
	int n2 = right - m;

	int L[n1], R[n2];

	for(int i = 0; i < n1; i++){
		L[i] = array[left + i];
	}
	for(int j = 0; j < n2; j++){
		R[j] = array[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			array[k] = L[i];
			i++;
		}
		else{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		array[k] = L[i];
		i++;
		k++;
	}

	while (j < n2){
		array[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int array[], int left, int right){
	if (left < right){
		int m = (left + right) / 2;

		mergeSort(array, left, m);
		mergeSort(array, m + 1, right);

		merge(array, left, m, right);
	}
}

void printfArray(int array[], int size){
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

void printOutfile(int array[], int arr_size){
	ofstream outfile;
	outfile.open("mergesort.txt", ios::app);

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

	mergeSort(array, 0, arr_size-1);

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

  return 0;
}
