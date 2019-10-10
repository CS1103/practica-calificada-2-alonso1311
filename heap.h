//
// Created by rudri on 10/10/2019.
//

#ifndef CS1103_PC2_201902_HEAP_H
#define CS1103_PC2_201902_HEAP_H

#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class heap {
private:
    vector<T> v;
    T valores;

public:
    heap() {}

    T get_max() {
        return *begin(v);
    }

    void insert(T item) {
        v.push_back(item);
        sort(begin(v), end(v), greater<T>());
    }

    template <typename... T1>
    auto insert(T1 ... items) {
        for(auto& i : {items...}) {
            v.push_back(i);
        }
        sort(begin(v), end(v), greater<T>());
    }

    void clean() {
        v.clear();
    }

    friend ostream& operator<< (ostream& out, const heap<T> heap) {
        for(auto& i : heap.v)
            out << i << " ";

        return out;
    }

    friend istream& operator>> (istream& in, heap<T>& heap) {
        cout << "\nIngrese elemento: ";
        in >> heap.valores;
        heap.insert(heap.valores);

        return in;
    }
};

template <typename T>
void load_from(const string& nombreArchivo, heap<T>& h) {
    h.clean();

    fstream file;
    file.open(nombreArchivo, ios::in);
    string fila;

    if (file.is_open()) {
        while (getline(file, fila)) {
            stringstream ss(fila);
            string dato;
            getline(ss, dato);
            h.insert(stoi(dato));
        }
        file.close();
    }
    else
        cout << "No se abrio el archivo" << endl;
}

template <typename T, typename... T1>
void insert (heap<T>& hp, T first, T1... items) {
    hp.insert(first);
    for(auto& i : {items...}) {
        hp.insert(i);
    }
}



#endif //CS1103_PC2_201902_HEAP_H
