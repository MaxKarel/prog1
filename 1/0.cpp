#include <iostream>

using namespace std;

int main() {
	int min, a;
	cin >> min;
	
	for(int i = 0 ; i < 2 ; i++) {
		cin >> a;
		if (a < min) min = a;
	}
	cout << min << endl;
	return 0;
}
