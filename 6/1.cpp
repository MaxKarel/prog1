#include <cstring>
#include <iostream>
using namespace std;

const int maxRiadok = 100;
const int maxN = 1000;

int main(void) {
    char *a[maxN];
    char riadok[maxRiadok];
    int n = 0;
     while (true) {
        /* nacitame jeden riadok */
        cin.getline(riadok, maxRiadok);
        /* ak je prazdny, koncime nacitavanie */
        if (strcmp(riadok, "") == 0) {
            break;
        }
        bool found = false;
        for(int i = 0 ; i < n ; i++) {
          //cout << a[n] << "vs" << riadok << endl;
          if(strcmp(riadok,a[i])==0) {
            //cout << "***" << endl;
            found = true;
            break;
          }
        }
        if(!found) {
          //cout << "--" << riadok << endl;
          a[n] = new char[strlen(riadok)+1];
          strcpy(a[n], riadok);
          n++;
        }
    }

    for(int i=0; i < n; i++) {
      cout << a[i] << endl;
    }
}
