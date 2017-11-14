#include <iostream>
#include <cassert>
using namespace std;

bool ** vytvorMaticu(int n, int m) {
    /* vytvor maticu s n riadkami a m stlpcami */
    bool **a;
    a = new bool *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new bool[m];
    }
    return a;
}

void zmazMaticu(int n, int m, bool **a) {
    /* uvolni pamat matice s n riadkami a m stlpcami */
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

void nacitajMaticu(int n, int m, bool **a) {
    /* matica je vytvorena, velkosti n, m, vyplnime ju cislami zo vstupu */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;  // nacitaj znak, preskoc biele znaky, ak nejake su
            assert(c == '0' || c == '1');
            a[i][j] = (c == '1');
        }
    }
}

int main(void) {
    /* nacitaj rozmery matice */
    int n, m;
    cin >> n >> m;

    /* vytvor a nacitaj maticu */
    bool **a = vytvorMaticu(n, m);
    nacitajMaticu(n, m, a);
	bool empty;
	int count = 0;
    for(int i = 0 ; i < n ; i++) {
		empty = true;
		for(int j = 0 ; j < m ; j++) {
			if(a[i][j]) {
				empty = false;
				break;
			}
		}
		if(empty) {
			count++;
		}
	}
	cout << count << endl;
    /* uvolni pamat matice */
    zmazMaticu(n, m, a);
}
