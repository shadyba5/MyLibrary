#pragma once

/* QUICK EXPLAINATION ON HOW O(1) amortized  IS ACHIEVED
	assume we have n insertions and intial size of 1, each insertion takes O(1) time so for total we have O(n).
	but every time the array is full we have to resize by doubling the size, so on each resize we have O(1)+O(2)+O(4)+...+O(n).
	since we double the size by 2 untill we reach n capacity, we do the resize K times where 2^k=n.
	this means that k = logn.
	so O(1)+O(2)+O(4)+...+O(n) is the sum of a finite geomtric series where a1 is 1 q is 2 and k is logn.
	the sum is then a1*(q^k-1)/q-1  = 1*(2^logn-1)/2-1 = n-1.
	so the total sum of time for resizing on the n insertions is O(n-1), and the total sum for the insertion it self is O(n).
	O(n-1)+O(n) = O(n).
	since we have total of n insertions with total of O(n) time, On average each insertion takes O(1) time amortized .
*/

/* same explaination goes for remove and append.*/

#include <iostream>
#include <new>  
#include <stdexcept>


#define STARTING_CAPACITY 16


template <typename T>
class Vector{
public:
	Vector();
	~Vector();

	Vector(const Vector& other);
	Vector<T>& operator=(const Vector& other);

	void append(T item);
	void insert(int index, T item);
	void remove(int index);
	bool exists(T item) const;
	const T& get(int index) const;
	int size() const;
	void resize(int newSize);

	void clear();
	void copyFrom(const Vector& other);

private:
	T* data;
	int length;
	int capacity;
};


template<typename T>
inline Vector<T>::Vector()
{
	length = 0;
	data = new T[STARTING_CAPACITY];
	capacity = STARTING_CAPACITY;
}


template<typename T>
inline Vector<T>::~Vector()
{
	delete[] data;
}


template<typename T>
inline Vector<T>::Vector(const Vector& other)
{
	copyFrom(other);
}


template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector& other)
{
	if (this != &other) {
		clear();
		copyFrom(other);
	}
	return *this;
}


template<typename T>
inline void Vector<T>::append(T item)
{
	if (length < capacity) {
		data[length] = item;
	}
	else {
		capacity *= 2;
		T* newData = new T[capacity];
		for (int i = 0; i < length; i++) {
			newData[i] = data[i];
		}
		delete data;
		data = newData;
	}
	length++;
}


template<typename T>
inline void Vector<T>::insert(int index, T item)
{
	if (index >= length) {
		throw std::runtime_error("index out of bound!");
	}
	if (length < capacity) {
		for (int i = length - 1; i >= index; i--) {
			data[i + 1] = data[i];
		}
		data[index] = item;
	}
	else {
		capacity *= 2;
		T* newData = new T[capacity];
		for (int i = 0; i < length+1; i++) {
			if (i < index) {
				newData[i] = data[i];
				continue;
			}
			if (i == index) {
				newData[i] = item;
				continue;
			}
			if (i > index) {
				newData[i + 1] = data[i];
			}
		}
		delete data;
		data = newData;
	}
	length++;
}


template<typename T>
inline void Vector<T>::remove(int index)
{
	if (index >= length) {
		throw std::runtime_error("index out of bound!");
	}
	for (int i = index; i < length; i++) {
		data[i] = data[i + 1];
	}
	length--;
	if (length <= capacity / 4) {
		capacity /= 2;
		T* newData = new T[capacity];
		for (size_t i = 0; i < length; i++)
		{
			newData[i] = data[i];
		}
		delete data;
		data = newData;
	}
}

template<typename T>
inline bool Vector<T>::exists(T item) const
{
	for (int i = 0; i < length; i++) {
		if (data[i] == item) {
			return true;
		}
	}
	return false;
}


template<typename T>
inline const T& Vector<T>::get(int index) const
{
	if (index < length) {
		return data[index];
	}
	else {
		throw std::runtime_error("index out of bound!");
	}
}


template<typename T>
inline int Vector<T>::size() const
{
	return length;
}


template<typename T>
inline void Vector<T>::resize(int newSize)
{

}


template<typename T>
inline void Vector<T>::clear()
{

}


template<typename T>
inline void Vector<T>::copyFrom(const Vector<T>&  other)
{

}
