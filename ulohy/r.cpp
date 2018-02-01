#include <iostream>
#include <cassert>
using namespace std;

/** štruktúra pre uzol jednosmerného zoznamu */
struct node {
    int data;    // dáta v uzle
    node* next;  // ďalší uzol v zozname
};

/** štruktúra pre jednosmerný spájaný zoznam */
struct linkedList {
    node* first;  // smerník na prvý uzol
};

/* inicializácia prázdneho zoznamu */
void init(linkedList &z) {
    z.first = NULL;
}
/* výpis zoznamu */
void print(const linkedList &z) {
    node * x = z.first;
    const char * separator = "";
    while (x != NULL) {
        cout << separator <<  x->data;
        separator = " ";
        x = x->next;
    }
    cout << endl;
}
/* načítanie zoznamu zo vstupu */
void read(linkedList &z) {
    assert(z.first == NULL);
    int x;
    cin >> x;
    node **v = &(z.first);  // v je smerník na posledný smernik v zozname
    while (x != -1) {       // kým užívateľ nezadá -1
        (*v) = new node;
        (*v)->data = x;
        (*v)->next = NULL;
        v = &((*v)->next);
        cin >> x;
    }
}
/* uvoľnenie pamäti pre zoznam */
void destroy(linkedList &z) {
    while (z.first != NULL) {
        node* p = z.first;
        z.first = z.first->next;
        delete p;
    }
}

/* funkcia zo zoznamu vyhodí všetky záznamy, v ktorých je data==0 */
void vyhod(linkedList &z) {
  cout << "start" << endl;
  node* list_ptr = z.first;
  while(list_ptr != NULL){
    if(list_ptr->next->data == 0) {
      cout << "found 0" << endl;
      list_ptr->next = list_ptr->next->next;
    } else {cout << "found" << list_ptr->next->data << endl;}
    list_ptr = list_ptr->next;
  }
}


int main(void) {
    linkedList z1;
    init(z1);
    read(z1);
    vyhod(z1);
    print(z1);
    destroy(z1);
}
