#include <cstring>
#include <iostream>
using namespace std;

/* maximalna hodnota n */
const int MAXN = 20;

/* Funkcia dostane mnozinu reprezentovanu v poli logickych hodnot
 * dlzky n a vypise jej prvky oddelene medzerami. */
void vypisBool(bool a[], int n) {
  bool bolo = false;
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      if (bolo) {
        cout << " ";
      }
      bolo = true;
      cout << i;
    }
  }
  cout << endl;
}

/* V poli a uz mame na poziciach 0..i-1 nastavene hodnoty na true
 * alebo false podla toho, ci prvok ma byt v mnozine. Zostava
 * vygenerovat a vypisat vsetky moznosti, ako nastavit hodnoty na
 * poziciach i..n-1 tak, aby sme nastavili estePrvkov poloziek na
 * true. */
void generujPodmnoziny(bool a[], int i, int n, int estePrvkov) {
  if(estePrvkov!=0) {
    for(int j = i ; j <= n ; j++) {
      a[j]=true;
      //cout << i << "|" << estePrvkov << endl << '\t';
      for(int k = 0 ; k < n ; k ++) {
        //cout << a[k] << " ";
      }
      //cout << endl;
      generujPodmnoziny(a, i+1, n, estePrvkov-1);
      a[j]= false;
    }
  } else {
    vypisBool(a, n);
    //cout << "VYPIS" << i << endl;
  }
}

int main(void) {
  /* nacitanie vstupu */
  int n, k;
  cin >> n >> k;
  /* vytvorenie a inicializacia pola */
  bool a[MAXN];
  for (int i = 0; i < n; i++) {
    a[i] = false;
  }

  /* volanie rekurzivnej funkcie, zmente podla potreby */
  generujPodmnoziny(a, 0, n, k);
}
