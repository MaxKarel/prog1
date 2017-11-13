#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAXN = 100;

/* TODO: naprogramujte funkciu zdvoj podla zadania */
void zdvoj(char r[], char z[]) {
  //int i = 0;
  //while(r[i] != '\0') {
  // while(!iscntrl(r[i]) && (strlen(r)>i) ) {
  //   //cout << r[i] << endl;
  //   z[2*i] = r[i];
  //   z[2*i+1] = r[i];
  //   //cout << i << endl;
  //   i++;
  // }
  //r[2*i] = '\0';
  for(int i = 0 ; i < strlen(r)+1; i++){
    if(r[i] == '\0') {
      z[2*i] = '\0';
      break;
    }
    z[2*i] = r[i];
    z[2*i+1] = r[i];
  }
}

int main() {
    char riadok[MAXN];
    char zdvojeny[2 * MAXN];
    while (true) {
        cin.getline(riadok, MAXN);  // nacitaj riadok
        if (strlen(riadok) == 0) {  // prazdny riadok ukonci vstup
            break;
        }
        //cout << riadok[0] << riadok[1] << 0;
        zdvoj(riadok, zdvojeny);
        cout << zdvojeny << endl;
    }
}
