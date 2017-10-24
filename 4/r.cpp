#include <iostream>

using namespace std;

void print_binary(int n);

int main() {
  int n;
  cin >> n;
  print_binary(n);
  cout << endl;
  return 0;
}

void print_binary(int n) {
  if(n > 0) {
    print_binary(n / 2);
    cout << n % 2;
  }

}
