#pragma once

#include <iostream>
#include <new>  
#include <stdexcept>
#include <vector>


template <typename T>
class MaxHeap {


public:
	MaxHeap(const std::vector<T>& data);

	void makeHeap();
	void insert(T x);
	T max() const;
	void del_max();



private:
	std::vector<T> heap;
	void heapify(int i);

};


template<typename T>
inline MaxHeap<T>::MaxHeap(const std::vector<T>& data)
{
	heap = data;
	makeHeap();
}

template<typename T>
inline void MaxHeap<T>::makeHeap()
{
	heapify(0);
}

template<typename T>
inline void MaxHeap<T>::insert(T x)
{
}

template<typename T>
inline T MaxHeap<T>::max() const
{
}

template<typename T>
inline void MaxHeap<T>::del_max()
{
}

template<typename T>
inline void MaxHeap<T>::heapify(int i)
{

}
