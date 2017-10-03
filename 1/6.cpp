#include <iostream>

using namespace std;

int main() {
	int xin, ain, bin;
	int x, a, b;
	cin >> xin >> ain >> bin;
	for(int i = ain ; i <= bin ; i++) {
		b = xin;
		a = i;
		while(b != 0) {
        		int x = a % b;
	        	a = b;
        		b = x;
    		}
		cout << "gcd(" << xin << "," << i <<")=" << a << endl;

	}
}
