//
//  main.cpp
//  AED2-MaxHeap
//
//  Created by Coelho on 29/08/16.
//  Copyright © 2016 Flavio Jose Mendes Coelho. All rights reserved.
//

#include <iostream>
#include <cstdlib> // srand(), rand()
#include <vector>
#include <cmath> // floor
#include <ctime> // para usar com srand()
using namespace std;

#define NIL -1


int parent(int i) {
    return static_cast<int>(floor(i/2));
}


int left(int i) {
    return 2*i;
}


int right(int i) {
    return 2*i + 1;
}


template <typename T>
void maxHeapfy(vector<T> &a, int i, int heapSize) {
    int largest = NIL;
    int l = left(i);
    int r = right(i);
    if (l <= heapSize and a[l] > a[i])
        largest = l;
    else
        largest = i;
    if (r <= heapSize and a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapfy(a, largest, heapSize);
    }
}


template <typename T>
void buildMaxHeap(vector<T> &a, int &heapSize) {
    heapSize = static_cast<int>(a.size() - 1);
    for (int i = static_cast<int>(floor(heapSize/2)); i >= 1; i--) {
        maxHeapfy(a, i, heapSize);
    }
}


template <typename T>
void heapsort(vector<T> &a) {
    int heapSize = 0;
    buildMaxHeap(a, heapSize);
    const int N = static_cast<int>(a.size() - 1);
    for (int i = N; i >= 2; i--) {
        swap(a[1], a[i]);
        heapSize--;
        maxHeapfy(a, 1, heapSize);
    }
}


template <typename T>
void printChar(const vector<T> v) {
    int N = static_cast<int>(v.size() - 1);
    for(int i = 1; i < N; i++){
        cout << static_cast<char>(v[i]) << " ";
    }
    cout << static_cast<char>(v[N]);
    std::cout << "\n";
}


template <typename T>
bool isSorted(vector<T> &a) {
    int N = static_cast<int>(a.size() - 1);
    for(int i = 1; i < N; i++){
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}


int main() {
    // Vetor vai de 1..n-1
    vector<char> v = {'?', 'E', 'H', 'I', 'B', 'D', 'C', 'F', 'G', 'A'};
    printChar(v);
    heapsort(v);
    printChar(v);
    cout << "ordenado?:" << (isSorted(v)?"sim":"não") << endl;
    
    std::cout << "\n";
    return 0;
}
