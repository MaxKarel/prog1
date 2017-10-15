#include <iostream>

#define N 1000

using namespace std;
bool bubble_sort(int *arr, int size);
/** Funkcia vráti počet cifier v desiatkovom zápise pre celé číslo
 * n>=0. Pozor, počet cifier pre n=0 by mal byť 1. */
int pocet_cifier(int n) {
  if (n / 10 > 0) {
    return pocet_cifier(n / 10) + 1;
  } else {
    return 1;
  }
}

/** Funkcia vypíše n medzier. */
void vypis_medzery(int n) {
  for (int i = 0; i < n; i++) {
    cout << " ";
  }
}

/** Funkcia vráti väčšie z čísel a, b. */
int max(int* arr, int size) {
  int index = 0;
  int max = arr[0];
  for(int i = 0 ; i < size ; i++) {
    if(arr[i] > max) {
      max = arr[i];
      index = i;
    }
  }
  return arr[index];
}

int main() {
  // načítanie vstupu
  int count[N];
  int arr[N];
  int size = 0;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (arr[i] < 0) {
      size = i;
      break;
    }
    count[i] = pocet_cifier(arr[i]);
  }

  // výpis prvého riadku výstupu
  cout << "Pocty cifier:";
  for (int i = 0; i < size; i++) {
    cout << " " << count[i];
  }
  cout << endl;

  int sirka = max(count, size);

  for(int i = 0; i < size; i++) {
    vypis_medzery(sirka - count[i]);
    cout << arr[i] << endl;
  }
}

bool bubble_sort(int *arr, int size) {
  int help;
  bool unsorted = true;
  while (unsorted) {
    unsorted = false;
    for (int i = 0; i < size - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        help = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = help;
        unsorted = true;
      }
    }
    size--;
    if (size < 0)
      return false;
  }
  return true;
}
