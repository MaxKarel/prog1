#include <iostream>
#include <cassert>
#include <cstdio>

using namespace std;

int main() {
  char file_a [100];
  char file_b [100];
  char a,b;

  scanf("%s %s", file_b, file_a);
  FILE* fa = fopen(file_a, "r");
  FILE* fb = fopen(file_b, "r");
  assert(fa != NULL && fb != NULL);

  a = getc(fa);
  b = getc(fb);
  bool same = true;
  while((a!=EOF)&&(b!=EOF)) {
    if(a!=b) {
      same = false;
      printf("nezhoda '%c' '%c'\n", b, a);
      break;
    }
    a = getc(fa);
    b = getc(fb);
  }
  if(same&&(a==EOF)&&(b==EOF)){
    printf("%s\n", "rovnake");
  } else {
    if(a==EOF) printf("%s kratsi\n",file_a);
    if(b==EOF) printf("%s kratsi\n",file_b);
  }
  return 0;
}
