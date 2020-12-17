#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>
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

int main(){
	const int n = 1000002;
  	int array[n];
  	float total = 0, average = 0;

  	ofstream outfile;
	outfile.open("mergeTime.txt", ios::app);

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

      		mergeSort(array, 0, i);

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
