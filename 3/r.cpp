#include <iostream>
#include <string>

using namespace std;

const int N = 1000;

int array_state(int* arr, int size);

int main() {
	int arr[N];
	int size;
	bool rising=true;
	
	cin >> size;
	for(int i = 0; i < size; i++) {
		cin >> arr[i];
	} 

	int result = array_state(arr, size);

	if(result==-1) {cout << "neutriedena" << endl;}
	if(result==1) {cout << "neklesajuca" << endl;}
	if(result==2) {cout << "nerastuca" << endl;}
	return 0;
}

int array_state(int* arr, int size) {
	bool rastuca = true;
	bool in_progress = false;
	if (size <= 1) { return -1;}
	if (arr[0]==arr[size-1]) {return -1;}
//	if (arr[0] > arr[1]) {rising=false;}

	for(int i = 0; i < size - 1; i++) {
		if(arr[i] < arr[i+1]){
			if(in_progress) {
				if(rastuca) {return -1;}
			} else {rastuca = false; in_progress=true;}
		} else if(arr[i]>arr[i+1]){
			if(in_progress) {
				if(!rastuca) {return -1;}
			} else{rastuca = true; in_progress=true;}
		}
	}

	if(rastuca) {return 2;}
	else {return 1;}
}
