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
	void siftUp(int i);
	void siftDown(int i);
	
	void printHeap() const {
		for (int i : heap) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}

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
	int startIdx = (heap.size() / 2) - 1;
	for (int i = startIdx; i >= 0; i--) {
		siftDown(i);
	}
}

template<typename T>
inline void MaxHeap<T>::insert(T x)
{
	heap.push_back(x);
	siftUp(heap.size() - 1);
}

template<typename T>
inline T MaxHeap<T>::max() const
{
	if (heap.size() == 0) {
		throw std::out_of_range("Heap is empty");
	}
	return heap[0];
}

template<typename T>
inline void MaxHeap<T>::del_max()
{
	int size = heap.size();
	if (size == 0) {
		return;
	}
	if (size == 1) {
		heap.pop_back();
		return;
	}
	std::swap(heap[0], heap[size - 1]);
	heap.pop_back();
	siftDown(0);
}

template<typename T>
inline void MaxHeap<T>::siftUp(int i)
{
	while (i > 0) {
		int parentIndex = (i - 1) / 2;
		if (heap[i] > heap[parentIndex]) {
			std::swap(heap[i], heap[parentIndex]);
			i = parentIndex;
		}
		else {
			break;
		}
	}
}

template<typename T>
inline void MaxHeap<T>::siftDown(int i) {
	int size = heap.size();

	while (i < size) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < size && heap[left] > heap[largest]) {
			largest = left;
		}
		if (right < size && heap[right] > heap[largest]) {
			largest = right;
		}
		if (largest != i) {
			std::swap(heap[i], heap[largest]);
			i = largest;
		}
		else {
			break;
		}
	}
}
