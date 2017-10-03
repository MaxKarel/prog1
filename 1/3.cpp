#include <iostream>

using namespace std;

int main() {
	int r,s;
	cin >> r >> s;
	
	for(int i = 0 ; i < r ; i++) {
		for(int j = 0 ; j < s ; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
