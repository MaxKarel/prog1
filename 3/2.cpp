#include <cassert>
#include <iostream>
using namespace std;

/** Maximálny počet cifier v čísle. Súčet dvoch 1000-ciferných čísel
 *  môže mať najviac 1001 cifier. */
const int MAXN = 1001;

struct bignum {
  /** Reprezentácia veľkého čísla s najviac MAXN ciframi */
  /** počet cifier čísla */
  int pocet_cifier;
  /** Pole cifier, najmenej významná cifra je na indexe 0. */
  int cifry[MAXN];
};
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
void nacitaj_cislo(bignum &a) {
  /* Táto funkcia načíta číslo a uloží ho do structu bignum.
   * Využíva typ char, ktorý sme ešte nebrali, ale nemusíte jej rozumieť. */
  a.pocet_cifier = 0;
  char c;
  cin >> noskipws >> c;
  while (c >= '0' && c <= '9') {
    a.cifry[a.pocet_cifier] = c - '0';
    a.pocet_cifier++;
    assert(a.pocet_cifier <= MAXN);
    cin >> noskipws >> c;
  }
  assert(c == '\n');
  for (int i = 0; i < a.pocet_cifier - i - 1; i++) {
    swap(a.cifry[i], a.cifry[a.pocet_cifier - i - 1]);
  }
}
void vypis(bignum &a) {
  /* Táto funkcia vypíše počet cifier a samotné zadané číslo. */
  cout << "pocet cifier suctu: " << a.pocet_cifier << endl;
  cout << "sucet: ";
  /* TODO: Doprogramujte túto funkciu tak, aby dávala rovnaký výstup
   * ako ukážkový vstup. */
  for (int i = a.pocet_cifier - 1; i >= 0; i--) {
    cout << a.cifry[i];
  }
  cout << endl;
}

/* TODO: Naprogramujte funkciu scitaj, ktorá bude mať tri parametre -- dve
 * čísla, ktoré chceme sčítať a premennú, do ktorej zapíšeme výsledný súčet.
 * Všetky tieto tri premenné by mali byť typu bignum.
 * Odovzdajte ich tejto funkcii REFERENCIOU! */
void scitaj(bignum &a, bignum &b, bignum &c) {
  int size, tmp = 0; //maximal size
  a.pocet_cifier > b.pocet_cifier ? size = a.pocet_cifier
                                  : size = b.pocet_cifier;
  c.pocet_cifier = size;
  for (int i = 0; i < size; i++) {
    tmp = tmp / 10;
    tmp += a.cifry[i] + b.cifry[i];
    c.cifry[i] = tmp % 10;
  }
  if(tmp / 10 > 0) {c.cifry[c.pocet_cifier++]=1;}
}

int main() {
  bignum a, b, sucet;
  for (int i = 0; i < MAXN; i++) {
    a.cifry[i] = 0;
    b.cifry[i] = 0;
  }
  /* Načítame dve veľké čísla na vstupe. */
  nacitaj_cislo(a);
  nacitaj_cislo(b);

  /* Zavoláme funkciu scitaj(), ktorá sčíta zadané čísla a, b
   * a vysledok ulozi do premennej sucet. */
  scitaj(a, b, sucet);
  /* Výsledný súčet následne vypíšeme. */
  vypis(sucet);
}
