#include <iostream>

using namespace std;

const int MAXN = 20;

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
  void add_item(int item, int item_weight) {
    items[count] = item_weight;
    weight += item_weight;
    count++;
  }
  void remove_item(int item, int item_weight) {
    int item_position = -1;
    for(int i = 0 ; i < count; i++) {
      if(item == items[i]) {
        item_position = i;
        break;
      }
    }
    for(int i = item_position ; i < count -1; i++) {
      items[i] = items[i+1];
    }
    weight -= item_weight;
    count--;
  }
  void remove_item2() {
    count--;
    weight -= items[count];
  }
};
bool pack(box* boxes, int* items, int n, int k, int unpacked, int j);
void pack2(box* boxes, int* items, int n, int k, int unpacked, int j);
void sort(int* a, int n);
void swap(int &x, int &y);

int main() {
  box boxes[MAXN];
  int items[MAXN];
  int n,k;

  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >>items[i];
  }
  for(int i = 0 ; i < n; i++) { cout << items[i] << " ";}
  cout << endl;
  sort(items, n);
  for(int i = 0 ; i < n; i++) { cout << items[i] << " ";}
  cout << endl;
  for(int i = 0; i < k; i++) {
    boxes[i].weight = 0;
    boxes[i].count = 0;
    boxes[i].pos = i;
  }
  for(int i = n-1; i >=0; i--) {
    boxes[0].add_item(i, items[i]);
    cout << boxes[0].weight << endl;
    if(pack(boxes, items, n, k, n-i-1, 1)){
      break;
    }
    for(int ii = 1; ii < k; ii++) {
      boxes[i].weight = 0;
      boxes[i].count = 0;
    }
  }
  //pack2(boxes, items, n, k, n, 0);
  cout << boxes[0].weight << endl;
  for(int i = 0;i< k;i++){
    boxes[i].print_contents();
  }
  return 0;
}

void pack2(box* boxes, int* items, int n, int k, int unpacked, int j) {
  if(unpacked > 0) {
    for(int i = 0; i < n; i++) {

    }
  }
}

bool pack(box* boxes, int* items,int n, int k, int unpacked, int j) {
  if(unpacked!=0) {
    if(j<k) {
      int packed = 0;
      for(int i = n - unpacked; i < n; i++) {
        boxes[j].add_item(i, items[i]);
        if(boxes[j].weight > boxes[0].weight) {
          boxes[j].remove_item2();
        } else {
          packed++;
        }
      }
      if(pack(boxes, items, n, k, unpacked-packed, j+1)) {return true;}
    } else{return false;}
  } else {
    return true;
  }
}
void swap(int &x, int &y) {
    /* Vymeň hodnoty premenných x a y. */
    int tmp = x;
    x = y;
    y = tmp;
}
void sort(int* a, int n) {

    bool hotovo = false;
    while (!hotovo) {
        bool vymenil = false;
        /* porovnávaj všetky dvojice susedov, vymeň ak menší za väčším */
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
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
