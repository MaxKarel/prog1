#include <cassert>
#include <iostream>
using namespace std;

const int MAXN = 20; // maximalny pocet kamenov

struct tyc {
  int meno;         // meno tyce: 1, 2 alebo 3
  int pocet;        // pocet kamenov na tyci
  int kamene[MAXN]; // zoznam kamenov na tyci,
                    // kamene[0] je spodny kamen
                    // kamene[pocet-1] je vrchny kamen
};

/** Funkcia inicializuje tyc tak, aby na nej
 * bolo n kamenov, s kamenom velkosti n naspodku a velkosti 1 navrchu */
void initTyc(tyc &t, int meno, int n) {
  t.meno = meno;
  t.pocet = n;
  for (int i = 0; i < n; i++) {
    t.kamene[i] = n - i;
  }
}

/** Prelozi horny kamen z tyce odkial na tyc kam
 * a vypise o tom spravu */
void prelozKamen(tyc &odkial, tyc &kam) {
  assert(odkial.pocet > 0);
  cout << "Prelozim kamen " << odkial.kamene[odkial.pocet - 1] << " z "
       << odkial.meno << " na " << kam.meno << endl;
  kam.kamene[kam.pocet + 1 - 1] = odkial.kamene[odkial.pocet - 1];
  odkial.pocet -= 1;
  kam.pocet += 1;
}

/** Vypise obsah danej tyce */
void vypisTyc(tyc &tyc) {
  cout << "Tyc " << tyc.meno << ":";
  for (int i = 0; i < tyc.pocet; i++) {
    cout << " " << tyc.kamene[i];
  }
  cout << endl;
}

/** Vypise obsah vsetkych tyci, pricom najskor vypise tyc 1,
 * potom 2 a nakoniec 3. Nevieme ale, ktora z tyci tycA, tycB, tycC je ktorá */
void vypisHanoi(tyc &tycA, tyc &tycB, tyc &tycC) {

  // ideme cez vsetky mena tyci v spravnom poradi 1,2,3
  for (int ktoraTyc = 1; ktoraTyc <= 3; ktoraTyc++) {
    // najdeme a vypiseme tyc s menom ktoraTyc
    if (tycA.meno == ktoraTyc)
      vypisTyc(tycA);
    if (tycB.meno == ktoraTyc)
      vypisTyc(tycB);
    if (tycC.meno == ktoraTyc)
      vypisTyc(tycC);
  }
  cout << endl;
}

/* Rekurzívne presunie n horných kameňov z tyče odkial
 * na tyč kam pomocou pomocnej tyče cez. Ak n>1, tak na tyčiach
 * kam a cez sú len väčšie kamene ako horných n kameňov na odkial.
 * Ak n=1, na tyči kam sú len väčšie kamene, obsah tyče cez môže byť ľubovoľný.
 */
void presunHanoi(tyc &odkial, tyc &cez, tyc &kam, int n) {
  if (n == 1) {
    prelozKamen(odkial, kam);
    vypisHanoi(odkial, cez, kam);
  } else {
    presunHanoi(odkial, kam, cez, n - 1);
    presunHanoi(odkial, cez, kam, 1);
    presunHanoi(cez, odkial, kam, n - 1);
  }
}

int main(void) {
  tyc tycA, tycB, tycC;
  int n; // kolko kamenov
  cin >> n;
  initTyc(tycA, 1, n);
  initTyc(tycB, 2, 0);
  initTyc(tycC, 3, 0);

  presunHanoi(tycA, tycB, tycC, n);
}
