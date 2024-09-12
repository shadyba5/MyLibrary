#pragma once

#include <iostream>
#include <new>  
#include <stdexcept>
#include <vector>
#include <list>
#include <functional>
#include <cmath>

template <typename T1, typename T2>
class HashTable {
public:
    HashTable(int initialSize = 16);

    void insert(T1 key, T2 value);
    T2 get(T1 key);
    void remove(T1 key);
    bool contains(T1 key);

private:
    std::vector<std::list<std::pair<T1, T2>>> table; // Array of lists for handling collisions
    std::vector<std::function<int(T1)>> hashFunctions; // Array of hash functions

    int size;
    int numElements;

    int hash(T1 key);
    void resize(int newSize);
    void addHashFunction(std::function<int(T1)> operation);

    static int defaultHashFunction(T1 key); // Default hash function
};