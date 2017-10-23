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
	int N, result=-1;
	int arr[100];
	cin >> N;
	for(int i = 0 ; i < N ; i++) {
		cin >> arr[i];
	}
	sort(arr,N);
	
	for(int i = 1 ; i < N ; i++) {
		if(arr[i] - arr[i-1] >= 2) {
			result = i;
			break;
		}
	}

	if(result == -1) {
		if(arr[0] == 1) { 
			cout << arr[N-1]+1 << endl;
		} else {cout << 1 << endl;}
	}
	else {cout << arr[result-1]+1 << endl;}

	
	return 0;
}
