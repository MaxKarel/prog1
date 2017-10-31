#include <iostream>
using namespace std;

void vypis(int a[], int k) {
  for (int i = 0; i < k; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << endl;
}

void generuj(int a[], int i, int k, int n, int sum, int s) {
  /* v poli a dlzky k mame prvych i cifier,
   * chceme vygenerovat vsetky moznosti
   * poslednych k-i cifier */
  if (i == k) {
    vypis(a, k);
  } else {
    for (int x = 0; x < n; x++) {
      if (s - sum - x > (k - i - 1) * (n - 1)) {
        continue;
      } else {
        a[i] = x;
        sum += x;
        generuj(a, i + 1, k, n, sum, s);
        sum -= x;
      }
    }
  }
}

int main(void) {
  const int maxK = 100;
  int a[maxK];
  int n, k, s;
  cin >> n >> k >> s;
  generuj(a, 0, k, n, 0, s);
}
