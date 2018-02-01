#include <iostream>
#include <cstring>

using namespace std;

/** struktura reprezentujuca dvojrozmeny vektor */
struct vector2d {
    /** pocet pouzitych riadkov (n) a stlpcov (m) */
    int n, m;
    /** pocet alokovanych riadkov (maxN) a stlpcov (maxM) */
    int maxN, maxM;
    /** matica s maxN riadkami a maxM stlpcami */
    int **a;
};

/** funkcia vytvori maticu s n riadkami a m stlpcami a vrati na nu smernik */
int ** vytvorMaticu(int n, int m) {
    int **a;
    a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[m];
    }
    return a;
}

/** Funkcia skopiruje hodnoty n riadkov a m stlpcov z matice co do
 * matice kam. */
void skopirujMaticu(int **kam, int **co, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            kam[i][j] = co[i][j];
        }
    }
}

/** Funkcia v matici a vyplni obdlznik s riadkami od r1 po r2 (vratane)
 * a stlpcami od s1 po s2 (vratane) hodnotou x */
void vyplnMaticu(int **a, int r1, int r2, int s1, int s2, int x) {
    for (int i = r1; i <= r2; i++) {
        for (int j = s1; j <= s2; j++) {
            a[i][j] = x;
        }
    }
}

/** Funkcia odalokuje maticu a s n riadkami. */
void zmazMaticu(int **a, int n) {
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

/** Funkcia vytvori 2d vektor s n riadkami a m stlpcami a vyplni ho
 * hodnotu x */
void init(vector2d &a, int n, int m, int x) {
    a.n = n; //riadky
    a.m = m;
    a.maxN = n;
    a.maxM = m;
    a.a = vytvorMaticu(n, m);
    vyplnMaticu(a.a, 0, n - 1, 0, m - 1, x);
}

/* Funkcia vypise obsah 2d vektra a */
void print(vector2d &a) {
    cout << a.n << "x" << a.m
         << " (" << a.maxN << "x" << a.maxM << ")" << endl;
    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < a.m; j++) {
            if (j > 0) {
                cout << " ";
            }
            cout << a.a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

/** Funkcia uvolni pamat 2d vektora a */
void destroy(vector2d &a) {
    zmazMaticu(a.a, a.maxN);
}

/** Funkcia do policka v riadku i a stlpci j 2d vektora a priradi hodnotu x */
void set(vector2d &a, int i, int j, int x) {
    if((i < a.n)&&(j < a.m)) {
      a.a[i][j] = x;
    }
}

/** Funkcia do 2d vektora a prida novy stlpec vyplneny hodnotou x */
void addColumn(vector2d &a, int x) {
  if(a.m+1>a.maxM) {
    //cout << "INCREASING" << endl;
    int** tmp;
    tmp = vytvorMaticu(a.n, a.maxM*2);
    skopirujMaticu(tmp, a.a, a.n, a.m);
    zmazMaticu(a.a, a.maxN);
    a.a = tmp;
    a.maxM *= 2;


    /*a.a = vytvorMaticu(a.maxN, a.maxM);
    skopirujMaticu(a.a, tmp, a.n, a.m);*/
    //cout << "mazem druhy krat" << endl;
    //zmazMaticu(tmp, a.maxN);
    vyplnMaticu(a.a, 0, a.n-1, a.m, a.m, x);
    a.m++;
  } else {
    //cout << "ADDING" << endl;
    a.m++;
    vyplnMaticu(a.a, 0, a.n-1, a.m-1, a.m-1, x);
  }
}

/** Funkcia do 2d vektora a prida novy riadok vyplneny hodnotou x */
void addRow(vector2d &a, int x) {
  if(a.n+1>a.maxN) {
    //cout << "INCREASING_R" << endl;
    int** tmp;
    tmp = vytvorMaticu(a.n, a.m);
    skopirujMaticu(tmp, a.a, a.n, a.m);
    zmazMaticu(a.a, a.maxN);
    a.maxN *= 2;
    a.a = vytvorMaticu(a.maxN, a.maxM);
    skopirujMaticu(a.a, tmp, a.n, a.m);
    //cout << "mazem druhy krat" << endl;
    zmazMaticu(tmp, a.maxN/2);
    vyplnMaticu(a.a, a.n, a.n, 0, a.m-1, x);
    a.n++;
  } else {
    //cout << "ADDING_R" << endl;
    vyplnMaticu(a.a, a.n, a.n, 0, a.m-1, x);
    a.n++;
  }
}

int main() {
    const int MAX = 100;
    char prikaz[MAX];
    vector2d a;
    int i, j, n, m, x;
    while (true) {
        cin >> prikaz; // nacitaj prikaz
        if (strcmp(prikaz, "destroy") == 0) {
            destroy(a);
            break;
        }
        else if (strcmp(prikaz, "init") == 0) {
            cin >> n >> m >> x;
            init(a, n, m, x);
        }
        else if (strcmp(prikaz, "print") == 0) {
            print(a);
        }
        else if (strcmp(prikaz, "addColumn") == 0) {
            cin >> x;
            addColumn(a, x);
        }
        else if (strcmp(prikaz, "addRow") == 0) {
            cin >> x;
            addRow(a, x);
        }
        else if (strcmp(prikaz, "set") == 0) {
            cin >> i >> j >> x;
            set(a, i, j, x);
        }
    }
}
