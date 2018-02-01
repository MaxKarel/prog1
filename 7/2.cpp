#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

int main() {
  char* file_read = "vstup.txt";
  char* file_write = "vystup.txt";
  char c;

  int n;
  int arr[100];
  cin >> n;
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
  }
  FILE* fr = fopen(file_read, "r");
  FILE* fw = fopen(file_write, "w");
  assert(fr != NULL && fw != NULL);

  int tmp[n];
  int i = 0;
  int a = getc(fr);

  while(a!=EOF) {
    tmp[i] = a;
    //cout << (char)tmp[i] << "  ";
    if(i==n-1) {
      for(int j = 0; j < n ; j++) {
        putc(tmp[arr[i]],fw);
        cout << (char)tmp[arr[i]];
      }
      i=0;
    }
    i++;
    a = getc(fr);
  }

  return 0;
}
