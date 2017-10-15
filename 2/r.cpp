#include<iostream>
using namespace std;

/* Funkcia dostane n a vráti n! Mala by fungovať 
   aj pre n=0, pričom 0! = 1 */
int faktorial(int n) {
    if (n>0) { return n*faktorial(n-1);}
    	else {return 1;}
}

// TODO naprogramujte funkciu komb, ktora spocita kombinacne cislo
// pomocou funkcie faktorial

int komb(int n, int k) {
	return faktorial(n) / ( faktorial(k)*faktorial(n-k));
}


int main() {
    int n;
    cin >> n;
    for (int k = 0; k <= n; k++) {
        cout << " " << komb(n, k);
    }
    cout << endl;
}
