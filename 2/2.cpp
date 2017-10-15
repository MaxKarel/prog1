#include <iostream>

using namespace std;

int main() {
  int min, size, in, count;
  cin >> size;
  if (size == 0) {
    return -1;
  }

  count = 1;
  cin >> min;

  for (int i = 0; i < size - 1; i++) {
    cin >> in;
    if (in == min) {
      count++;
    } else if (in < min) {
      min = in;
      count = 1;
    }
  }
  cout << count << endl;
  return 0;
}
