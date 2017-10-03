#include <iostream>

using namespace std;

const int N = 3;

bool check(int* arr);

int main() {

	int arr[N];
	for(int i = 0 ; i < N ; i++) {
		cin >> arr[i];
	}
	if(check(arr)) {cout << "ano" << endl;} 
	else {cout << "nie" << endl;}
	return 0;
}

bool check(int* arr) {
	for(int i = 0 ; i < N-1 ; i++) {
		for(int j = i+1 ; j < N ; j++) {
			if(arr[i]==arr[j]) return true;
		}
	}
	return false;
}
