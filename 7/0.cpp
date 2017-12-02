#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  char menoVstup [100];
  char menoVystup [100];
  int dlzka;
  scanf("%s %s %d", menoVstup, menoVystup, &dlzka);

  FILE *fr = fopen(menoVstup, "r");
  FILE *fw = fopen(menoVystup, "w");
  assert(fr != NULL && fw != NULL); // skontrolujeme, ze sa podarilo

  char c = getc(fr);
  int n = 0;

  while (c!=EOF) {
    if(n==dlzka) {
      //cout << "+" << c;
      putc('\n',fw);
      n++;
    }
    if(n<dlzka) {
      //cout << "*" << c;
      putc(c, fw);
      n++;
    }
    if(c == '\n') {
      //cout << "=" << c;
      //if(n<5) {putc(c,fw);}
      n = 0;
    }
    c = getc (fr);
  }

  return 0;
}
