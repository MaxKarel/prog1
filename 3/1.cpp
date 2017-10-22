#include <cassert>
#include <iostream>
using namespace std;

int umocni(int x, int n) {
  if (n == 0) {
    // TODO: dopiste aby funkcia vratila x na n-tu
    return 1;

  } else {
    // TODO: spocitajte rekurzivne x na (n-1) funkciou umocni
    // potom pouzite vysledok pri vypocte x na n
    return x * umocni(x, n - 1);
  }
}

int main(void) {
  while (true) {
    int x, n;
    cin >> x >> n;
    if (x <= 0)
      break;
    cout << x << " na " << n << " je " << umocni(x, n) << endl;
  }
}
