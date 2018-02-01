#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
  FILE *fr = fopen("vyrazy.txt", "r");
  FILE *fw = fopen("vysledky.txt", "w");

  assert(fr != NULL && fw != NULL); // skontrolujeme, ze sa podarilo

  double a, b;
  char c;
  while (!feof(fr)) {
    fscanf(fr, "%lf %c %lf \n", &a, &c, &b);
    // cout << a << c << b << endl;
    if (c == '+') {
      fprintf(fw, "%10g   +%10g   =%10g\n", a, b, a + b);
    }
    if (c == '*') {
      fprintf(fw, "%10g   *%10g   =%10g\n", a, b, a * b);
    }
    if (c == '-') {
      fprintf(fw, "%10g   -%10g   =%10g\n", a, b, a - b);
    }
    if (c == '/') {
      fprintf(fw, "%10g   /%10g   =%10g\n", a, b, a / b);
    }
  }

  fclose(fr);
  fclose(fw); // zavrieme vystupny subor
}
