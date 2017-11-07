#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAXN = 101;

void reverse(char a[]);

int main() {
	char riadok[MAXN];
	while (true) {
		cin.getline(riadok, MAXN);  // nacitaj riadok
		if (strlen(riadok) == 0) {  // prazdny riadok ukonci vstup
			break;
		}
		char def[MAXN]; //string in default order
		for(int i = 0 ; i < strlen(riadok); i++) {
			//cout << riadok << "++";
			if(riadok[i]==' '){
				for(int j = i; j < strlen(riadok); j++){
					riadok[j] = riadok[j+1];
				}
				i--;
			}
			riadok[i] = toupper(riadok[i]);
			//cout << riadok << endl;
		}
		strcpy(def,riadok);
		reverse(riadok);
		if(!strcmp(def,riadok)) {
			cout << "ANO" << endl;
		} else {
			//cout << def << "||" << riadok << endl;
			cout << "NIE" << endl;
		}
	}
	return 0;
}

void reverse(char a[]) {
    int n = strlen(a);
    int i = 0;
    int j = n - 1;
    while (i < j) {
        char tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        i++; j--;
    }
}
