#include <cassert>
#include <iostream>
using namespace std;

/** Maximálny počet zlomkov */
const int MAXN = 100;

struct zlomok {
  int citatel;
  int menovatel;
};
void swap(zlomok &x, zlomok &y);
bool jeMensi(zlomok &x, zlomok &y);
void sort(zlomok a[], int n);

int main(void) {
  zlomok zlomky[MAXN];
  int n;
  cin >> n;
  assert(n <= MAXN);
  for (int i = 0; i < n; i++) {
    cin >> zlomky[i].citatel >> zlomky[i].menovatel;
  }

  sort(zlomky, n);

  for (int i = 0; i < n; i++) {
    cout << zlomky[i].citatel << "/" << zlomky[i].menovatel << endl;
  }
}
void swap(zlomok &x, zlomok &y) {
  /* Vymeň hodnoty premenných x a y. */
  zlomok tmp = x;
  x = y;
  y = tmp;
}
bool jeMensi(zlomok &x, zlomok &y) {
  /** Vráti true, ak zlomok x je menší ako zlomok y */
  return x.citatel * y.menovatel < y.citatel * x.menovatel;
}
void sort(zlomok a[], int n) {
  /** usporiadaj prvky v poli a od najmenšieho po najväčší */
  bool hotovo = false;
  while (!hotovo) {
    bool vymenil = false;
    /* porovnávaj všetky dvojice susedov, vymeň ak menší za väčším */
    for (int i = 1; i < n; i++) {
      if (jeMensi(a[i], a[i - 1])) {
        swap(a[i - 1], a[i]);
        vymenil = true;
      }
    }
    /* ak sme žiadnu dvojicu nevymenili, môžeme skončiť. */
    if (!vymenil) {
      hotovo = true;
    }
  }
}
