#include <iostream>

using namespace std;
const int N = 100;
bool bubble_sort(int *arr, int size);
int check(int *arr, int size, int diff);

int main() {
  int arr[N];
  int size, diff, count = 0;
  // Load
  cin >> size;
  cin >> diff;
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }
  // Sort
  if (!bubble_sort(arr, size))
    return -1;
  // Calculate results
  count = check(arr, size, diff);
  cout << count << endl;

  return 0;
}

bool bubble_sort(int *arr, int size) {
  int help;
  bool unsorted = true;
  int n = size;
  while (unsorted) {
    unsorted = false;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        help = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = help;
        unsorted = true;
      }
    }
    n--;
    if (n < 0)
      return false;
  }
  return true;
}
int check(int *arr, int size, int diff) {
  if (size != 0) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
      if (arr[0] == arr[i + 1] - diff) {
        count++;
        //cout << size << i << count << endl;
      }
    }

    count += check(arr + 1, size - 1, diff);
    return count;
  } else
    return 0;
}
