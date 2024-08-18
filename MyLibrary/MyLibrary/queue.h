#pragma once

#include <iostream>
#include <new>  
#include <stdexcept>


template <typename T>
class Node {
public:
	T data;
	Node* next;
	Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class Queue {
public:
	Queue();
	~Queue();

	Queue(const Queue& other);
	Queue& operator=(const Queue& other);

	void enqueue(T item);
	T dequeue();
	const T& peek() const;
	bool isEmpty() const;
	int size() const;
	void copyFrom(const Queue<T>& other);
	void clear();

private:
	Node<T>* head;
	Node<T>* tail;
	int length;

};

template<typename T>
inline Queue<T>::Queue() : head(nullptr), tail(nullptr), length(0){}

template<typename T>
inline Queue<T>::~Queue(){
	clear();
}


template<typename T>
inline Queue<T>::Queue(const Queue& other){
	clear();
	copyFrom(other);
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != &other) {
		clear();
		copyFrom(other);
	}
	return *this;
}



template<typename T>
inline void Queue<T>::enqueue(T item)
{	
	try {
		Node<T>* newItem = new Node<T>(item);
		if (length == 0) {
			head = newItem;
			tail = newItem;
		}
		else {
			tail->next = newItem;
			tail = newItem;
		}
		length++;
	}
	catch (const std::bad_alloc& e) {
		throw std::runtime_error("enqueue failed to allocate a new node!" + std::string(e.what()));
	}

}

template<typename T>
inline T Queue<T>::dequeue()
{
	if (length == 0) {
		throw std::runtime_error("Queue is empty");
	}
	T data = head->data;
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	length--;
	if (length == 0) {
		tail = nullptr;
	}
	return data;
}

template<typename T>
inline const T& Queue<T>::peek() const
{
	if (length == 0) {
		throw std::runtime_error("Queue is empty");
	}
	return head->data;
}

template<typename T>
inline bool Queue<T>::isEmpty() const
{
	return length == 0;
}

template<typename T>
inline int Queue<T>::size() const
{
	return length;
}

template<typename T>
inline void Queue<T>::copyFrom(const Queue<T>& other)
{
	if (other.isEmpty()) {
		head = nullptr;
		tail = nullptr;
		length = 0;
		return;
	}
	
	try {
		head = new Node<T>(other.head->data);
		Node<T>* itr = head;
		Node<T>* otherItr = other.head->next;
		while (otherItr != nullptr) {
			Node<T>* newNode = new Node<T>(otherItr->data);
			itr->next = newNode;
			itr = newNode;
			otherItr = otherItr->next;
		}

		tail = itr;
		length = other.length;
	}
	catch (const std::bad_alloc& e) {
		throw std::runtime_error("Copy constructor failed! " + std::string(e.what()));
	}
	
}

template<typename T>
inline void Queue<T>::clear()
{	
	Node<T>* itr = head;
	while (itr != nullptr) {
		Node<T>* temp = itr;
		itr = itr->next;
		delete temp;
	}

	head = nullptr;
	tail = nullptr;
	length = 0;
}
