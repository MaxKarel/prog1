#include <iostream>

using namespace std;

void swap(int &x, int &y) {
	    /* Vymeň hodnoty premenných x a y. */
	    int tmp = x;
	        x = y;
		    y = tmp;
}

void sort(int a[], int n) {
	    /* usporiadaj prvky v poli a od najmenšieho po najväčší */

	    bool hotovo = false;
	        while (!hotovo) {
			        bool vymenil = false;
				        /* porovnávaj všetky dvojice susedov, vymeň ak menší za väčším */
				        for (int i = 1; i < n; i++) {
					            if (a[i] < a[i - 1]) {
								                    swap(a[i - 1], a[i]);
										                    vymenil = true;
												                }
							            }
					        /* ak sme žiadnu dvojicu nevymenili, môžeme skončiť. */
					        if (!vymenil) {
							            hotovo = true;
								            }
						    }
}

int main() {
	int N;
	int arr[100];
	cin >> N;
	for(int i = 0 ; i < N ; i++) {
		cin >> arr[i];
	}
	sort(arr,N);
	int ptr = 1;
	for(int i = 0 ; i < N ; i ++) {
		if(arr[i] != ptr) {
			if(arr[i-1] == arr[i]) {ptr--;}
			else {break;}
		}
		ptr ++;
	}	
	
	cout << ptr << endl;
	return 0;
}
