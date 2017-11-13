#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAXN = 100;

/** Funkcia vypise pole A s n prvkami a pole B, v ktorom je m prvkov
 * urcujucich hranice jednotlivych utriedenych oblasti v poli
 * A. Vsetky cisla v poli B maju byt od 0 po n-1, tvorit rastucu
 * postupnost a posledny prvok ma byt n-1. Funkcia pole A vypise tak, ze
 * za kazdou utriedenou postupnostou da ako oddelovac znak '|' */
void vypisPole(int A[], int n, int B[], int m) {
  int j = 0; // pozicia v poli B
  for (int i = 0; i < n; i++) {
    // vypiseme medzeru a A[i]
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
    // ak treba, vypiseme oddelovac | a posunieme sa v poli B
    if (j >= m) {
      cout << "Chyba: pole B je prilis kratke";
      //exit(1);
    }
    if (B[j] == i) {
      cout << " |";
      j++;
    }
  }
  cout << endl;
  // na konci by sme mali mat minute pole B
  if (j != m) {
    cout << "Chyba, nepouzila sa cele pole B" << endl;
    cout << "Nepouzite prvky:";
    for (int jj = j; jj < m; jj++) {
      cout << " " << B[jj];
    }
    exit(1);
  }
}

/** Funkcia dostane pole A, v ktorom su utriedene useky A[low..mid] a
 * A[mid+1..high] a zluci ich do utriedeneho useku A[low..high]. */
void merge(int A[], int low, int mid, int high) {

  int C[MAXN];                    // pomocne pole
  int i = low;                    // poloha v prvej catsi pola
  int j = mid + 1;                // poloha v druhej casti pola
  int k = 0;                      // poloha v zlucenom poli
  while (i <= mid && j <= high) { // kym v oboch poliach zostavaju prvky
    if (A[i] <= A[j]) {           // pouzi prvok z lavej casti
      C[k] = A[i];
      i++;
      k++;
    } else { // pouzi prvok z pravej casti
      C[k] = A[j];
      j++;
      k++;
    }
  }

  while (i <= mid) { // ak skoncila prava cast, prekopirujeme zvysok lavej
    C[k] = A[i];
    i++;
    k++;
  }

  while (j <= high) { // ak skoncila lava cast, prekoprujeme zvysok pravej
    C[k] = A[j];
    j++;
    k++;
  }

  for (int k = low; k <= high; k++) {
    A[k] = C[k - low];
  }
}

/** Funkcia dostane pole A s n prvkami a do pola B ulozi konce
 * utriedenych oblasti v poli A. Do premennej m ulozi pocet tychto
 * oblasti. V poli B ma byt teda rastuca postupnost celych nezapornych
 * cisel konciaca cislom n-1.
 */

void najdiHotove(int A[], int n, int B[], int &m) {
  m = 0;
  for (int i = 1; i < n; i++) {
    if (A[i] < A[i - 1]) {
      B[m] = i - 1;
      m++;
    }
  }
  B[m++] = n-1;
}

/** Funkcia dostane pole A s n prvkami a utriedi ho. */
void tried(int A[], int n) {
  int B[MAXN];
  int m;
  while (true) {
    // najdi konce uz utriedenych oblasti
    najdiHotove(A, n, B, m);
    // vypise tieto oblatsi na vystup
    vypisPole(A, n, B, m);
    // ak mame iba jendu oblast, sme hotovi
    if (m == 1)
      break;
    //for(int i = 0 ; i < m ; i++){cout << B[i] <<" ";}
    //cout << "|" << m << endl;
    int low = 0;
    int high = B[1];
    int mid = B[0];
    //cout << "::"<< low << "|" << mid << "|" << high << endl;
    merge(A, low, mid, high);
    for (int i = 1; i < m -1 ; i+=2) {
      low = B[i]+1;
      high = B[i+2];
      mid = B[i+1];

      //cout <<  ":"<<low << "|" << mid << "|" << high << endl;
      merge(A, low, mid, high);
    }
    //vypisPole(A, n, B, m);
    /* TODO: vas kod tu. Zlucovanim znizte pocet oblasti zhruba na
     * polovicu. Zlucute prve dve oblasti, druhe dve oblasti atd,
     * az kym neprejdete cez vsetky oblasti alebo kym nezostane
     * nanajvys jedna, ktoru uz nie je s cim zlucit. Pouzite funkciu
     * merge, ktora je hotova vyssie. */
  }
}

int main() {
  // nacitanie vstupu
  int n;
  cin >> n;
  int A[MAXN];
  assert(n <= MAXN);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  // triedenie pola
  tried(A, n);
}
