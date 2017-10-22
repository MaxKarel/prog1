#include <cassert>
#include <iostream>
using namespace std;

const int MAXN = 100;

void printArray(int a[], int n) {
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << endl;
}
void swap(int &x, int &y) {
  /* Vymeň hodnoty premenných x a y. */
  int tmp = x;
  x = y;
  y = tmp;
}

void bubbleSort(int a[], int n) {
  /* usporiadaj prvky v poli a od najmenšieho po najväčší */
  int size = n; //TODO remove size
  int k=1;
  while (k>0) {
    printArray(a, n);
    k=0;
    /* porovnávaj všetky dvojice susedov, vymeň ak menší za väčším */
    for (int i = 0; i < size - 1; i++) {
      cout << a[i] << " " << a[i + 1];
      if (a[i] > a[i + 1]) {
        swap(a[i + 1], a[i]);
        cout << " swap " << endl;
        k = i;
      } else {
        cout << " ok" << endl;
      }
    }
    //cout << "K****=" << k << endl;
    size = k+1;
  }
}

int main(void) {
  int n;
  cin >> n;
  int a[MAXN];
  assert(n <= MAXN);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  bubbleSort(a, n);
  printArray(a, n);
}
