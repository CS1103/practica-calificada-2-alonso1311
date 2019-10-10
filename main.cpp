#include <iostream>
#include <string>
#include "heap.h"

using namespace std;

int main()
{
    heap<int> h;
    load_from(string("data.txt"), h);
    cout << "heap con lectura" << endl;
    cout << h;
    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(50);
    h.insert(10);
    cout << "\nheap insert 1 elementos:" << endl;
    cout << h;
    h.insert(20, 30, 40);
    cout << "\nheap insert n elementos:" << endl;
    cout << h;

    cout << "\nMax:" << h.get_max();

    cin >> h;
    cout << "\nheap cin:" << endl;
    cout << h;

    insert(h, 100, 200);
    cout << "\nheap insert fuera de la clase" << endl;
    cout << h;

    h.clean();
    cout << "\nheap clean" << endl;
    cout << h;
    load_from("data.txt", h);
    cout << "heap con lectura 2" << endl;
    cout << h;
    return 0;
}


