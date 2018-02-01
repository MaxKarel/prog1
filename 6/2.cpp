#include <iostream>
#include <cassert>
using namespace std;

/** Funkcia alokuje maticu s n riadkami a m stlpcami */
bool ** vytvorMaticu(int n, int m) {
    bool **a;
    a = new bool *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new bool[m];
    }
    return a;
}

/** Funkcia uvolni pamat matice s n riadkami a m stlpcami */
void zmazMaticu(int n, int m, bool **a) {
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

/** Funkcia do uz alokovanej matice s n riadkami a m stlpcami nacita
 * hodnoty zo vstupu */
void nacitajMaticu(int n, int m, bool **a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;  // nacitaj znak, preskoc biele znaky, ak nejake su
            assert(c == '0' || c == '1');
            a[i][j] = (c == '1');
        }
    }
}


/** Funkcia otoc poradie riadkov matice tym, ze bude prehadzovat
 * smerniky na jednotlive riadky. V premennej n je pocet riadkov,
 * pocet stlpcov nie je vo funkcii potrebny. */
void otocRiadky(int n, bool **a) {
  bool* tmp;
  int range = n/2;
  for(int i = 0; i < range; i++) {
    tmp = a[i];
    a[i] = a[n-i-1];
    a[n-i-1] = tmp;
  }
}

/** Funkcia vypise maticu na vystup */
void vypisMaticu(int n, int m, bool **a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }
}

int main(void) {
    /* nacitaj rozmery matice */
    int n, m;
    cin >> n >> m;

    /* vytvor a nacitaj maticu */
    bool **a = vytvorMaticu(n, m);
    nacitajMaticu(n, m, a);

    /* otoc poradie riadkov matice */
    otocRiadky(n, a);

    /* vypis maticu */
    vypisMaticu(n, m, a);

    /* uvolni pamat matice */
    zmazMaticu(n, m, a);
}
