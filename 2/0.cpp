#include <iostream>
using namespace std;

/** Funkcia vráti počet cifier v desiatkovom zápise pre celé číslo
 * n>=0. Pozor, počet cifier pre n=0 by mal byť 1. */
int pocet_cifier(int n) {
	if(n / 10 > 0) {return pocet_cifier(n / 10) + 1;}
		else {return 1;}
}

/** Funkcia vypíše n medzier. */
void vypis_medzery(int n) {
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}

/** Funkcia vráti väčšie z čísel a, b. */
int max(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    // načítanie vstupu
    int a, b;
    cin >> a >> b;

    // TODO váš kód tu
    /* vytvorte premenné pocet_a, pocet_b
     * a pomocou funkcie pocet_cifier do nich spočítajte
     * počty cifier vstupných čísel. */
    int pocet_a, pocet_b;
    pocet_a = pocet_cifier(a);
    pocet_b = pocet_cifier(b);

    // výpis prvého riadku výstupu
    cout << "Pocty cifier: " << pocet_a << " " << pocet_b << endl;

    // spočítanie šírky stĺpca pre čísla a, b
    int sirka = max(pocet_a, pocet_b);

    // výpis čísla a do stĺpca šírky sirka
    vypis_medzery(sirka - pocet_a);
    cout << a << endl;
   
    vypis_medzery(sirka - pocet_b);
    cout << b << endl;

    // TODO váš kód tu
    /* vypíšte aj číslo b podobne ako číslo a */
}
