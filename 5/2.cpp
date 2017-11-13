#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAXN = 100;

/* TODO: naprogramujte funkciu zdvoj podla zadania */

int main() {
    char riadok[MAXN];
    char najkratsi[MAXN];
    cin.getline(najkratsi, MAXN);
    if (strlen(najkratsi) == 0) {  // prazdny riadok ukonci vstup
        return -1;
    }

    while (true) {
        cin.getline(riadok, MAXN);  // nacitaj riadok
        if (strlen(riadok) == 0) {  // prazdny riadok ukonci vstup
            //cout << "breaK" << endl;
            break;
        }
        if(strcmp(riadok, najkratsi) < 0) {
          //cout << "+" << riadok << endl;
          strcpy(najkratsi, riadok);
        }
    }
    cout << najkratsi << endl;
}
