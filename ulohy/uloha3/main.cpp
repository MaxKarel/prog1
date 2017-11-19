#include <iostream>

using namespace std;

const int MAXN = 20;

bool pack();
void sort(int* a, int n);
int maxIndex(int* a, int n);

struct box{
  int items[MAXN];
  int weight;
  int count;
  int pos;
  void print_contents() {
    cout << "Krabica " << pos << ":";
    for(int i = 0 ; i < count ; i++) {
      cout << " " << items[i];
    }
    cout << endl;
  }
};

int main() {
  box boxes[MAXN];
  int items[MAXN];
  int n,k;

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >>items[i];
  }
  sort(items, n);
  for(int i = 0; i < k; i++) {
    boxes[i].weight = 0;
    boxes[i].count = 0;
    boxes[i].pos = i;
  }

  pack(boxes, items, n, k);
  cout << boxes[0].weight;
  for(int i = 0;i< n;i++){
    boxes[i].print_contents();
  }
  return 0;
}

bool pack(boxes, items, n, k, unpacked) {
  if(unpacked != 0){

  } else {
    return ;
  }
}
int maxIndex(int* a, int n) {
    /* vráť index, na ktorom je najväčší prvok z prvkov a[0]...a[n-1] */
    int index = 0;
    for(int i=1; i<n; i++) {
        if(a[i]>a[index]) {
            index = i;
        }
        /* invariant: a[j]<=a[index] pre vsetky j=0,...,i*/
    }
    return index;
}
void sort(int* a, int n) {
    /* usporiadaj prvky v poli a od najmenšieho po najväčší */

    for(int kam=n-1; kam>=1; kam--) {
        /* invariant: a[kam+1]...a[n-1] sú utriedené
         * a pre každé i,j také že 0<=i<=kam, kam<j<n platí a[i]<=a[j] */
        int index = maxIndex(a, kam+1);
        swap(a[index], a[kam]);
    }
}
