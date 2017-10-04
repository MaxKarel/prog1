#include <iostream>
#define N 3
using namespace std;

void max_sort(int* arr, int);

int main() {
	
	//TODO:rewrite with binary tree or whatever 	

	int array[N];
	for(int i = 0 ; i < N ; i++) {
		cin >> array[i];		
	}
	
	//for(int i = 0 ; i < N ; i++) {cout << array[i] << " ";}
	//cout << endl;
	max_sort(array, N);
	//for(int i = 0 ; i < N ; i++) {cout << array[i] << " ";}
	//cout << endl;
	cout << array[N/2] << endl;
	return 0;
}

void max_sort(int* arr, int s) {
	int max;
	int tmp;
	for(int i = s-1 ; i >= 0 ; i-- ) {
		max = 0;
		for( int j = 0 ; j <= i ; j++) {
			if(arr[j]>arr[max]) {max=j;}
		}
		tmp = arr[i];
		arr[i] = arr[max];
		arr[max] = tmp;
	}
}
