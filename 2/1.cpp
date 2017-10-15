#include <iostream>

using namespace std;

const int size = 100;

int main() {
  int arr[size];
  int n, min, sum;
  sum = 0;
  cin >> n;

  if (n > size) {
    return -1;
  }
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> min;
  for (int i = 0; i < n; i++) {
    if (arr[i] < min) {
      sum += arr[i];
    }
  }
  cout << sum << endl;
  return 0;
}
