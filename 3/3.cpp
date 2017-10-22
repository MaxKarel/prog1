#include <iostream>

using namespace std;

const int NMAX = 1000;
void sort(int *arr, int n);
void swap(int &x, int &y);

int main() {
  int arr[NMAX];
  int n, count = 1;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, n);

  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1]) {
      count++;
    } else {
      cout << arr[i-1] << " - " << count << endl;
      count = 1;
    }
  }
  cout << arr[n-1] << " - " << count << endl;
  return 0;
}

void swap(int &x, int &y) {
  /* Vymeň hodnoty premenných x a y. */
  int tmp = x;
  x = y;
  y = tmp;
}

void sort(int a[], int n) {
  /* usporiadaj prvky v poli a od najmenšieho po najväčší */
  bool hotovo = false;
  while (!hotovo) {
    bool vymenil = false;
    /* porovnávaj všetky dvojice susedov, vymeň ak menší za väčším */
    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) {
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
