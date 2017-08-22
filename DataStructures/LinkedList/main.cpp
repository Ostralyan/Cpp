#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int>* ll = new LinkedList<int>();
    ll->insertLast(1000);
    ll->insertLast(99);
    ll->insertLast(5980);
    ll->print();
    ll->clear();

    /* ll->removeFirst(); */
    /* ll->print(); */
    return 0;
}
