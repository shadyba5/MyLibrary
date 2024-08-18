#pragma once

#include <iostream>
#include <new>  
#include <stdexcept>


template<typename T>
class Node {
public:
	T data;
	Node* prev;
	Node() {}
	Node(const T& value) : data(value), prev(nullptr) {}
};

template<typename T>
class Stack {
public:
	Stack(); // Default constructor
	~Stack(); // Destructor

	Stack(const Stack& other); // Copy constructor
	Stack& operator=(const Stack& other); // Copy assignment operator

	void push(T item);
	T pop();
	T& peak();
	bool is_empty();
	int size();
	void copyFrom(const Stack<T>& other);
	void clear();

private:
	Node<T>* top;
	int length;
};

template<typename T>
inline Stack<T>::Stack() : top(nullptr), length(0){}

template<typename T>
inline Stack<T>::~Stack() {
	clear();
}

template <typename T>
Stack<T>::Stack(const Stack& other) {
	copyFrom(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
	if (this != &other) {
		clear();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline void Stack<T>::push(T item)
{	
	try {
		Node<T>* newNode = new Node<T>(item);
		if (top == nullptr) {
			top = newNode;
		}
		else {
			newNode->prev = top;
			top = newNode;	
		}
		length++;
	}
	catch (const std::bad_alloc& e) {
		throw std::runtime_error("stack push failed to allocate a new node!" + std::string(e.what()));
	}
}

template<typename T>
inline T Stack<T>::pop()
{
	if (top == nullptr) {
		throw std::runtime_error("Stack is empty");
	}

	T data = top->data;
	Node<T>* toDelete = top;
	top = toDelete->prev;
	delete toDelete;
	length--;

	if (length == 0){
		top = nullptr;
	}

	return data;
}

template<typename T>
inline T& Stack<T>::peak()
{
	if (top == nullptr) {
		throw std::runtime_error("Stack is empty");
	}

	return top->data;
}

template<typename T>
inline bool Stack<T>::is_empty()
{
	return length == 0;
}

template<typename T>
inline int Stack<T>::size()
{
	return length;
}

template<typename T>
inline void Stack<T>::clear()
{
	if (top == nullptr) {
		return;
	}
	else {
		while (this->length != 0) {
			pop();
		}
	}
}

template<typename T>
inline void Stack<T>::copyFrom(const Stack<T>& other)
{	
	clear();

	if (other.top == nullptr) {
		top = nullptr;
		length = 0;
		return;
	}

	Node<T>* newTop = new Node<T>(other.top->data);
	Node<T>* otherItr = other.top->prev;
	Node<T>* sourceItr = newTop;

	while (otherItr != nullptr) {
		Node<T>* newElem = new Node<T>(otherItr->data);
		sourceItr->prev = newElem;
		sourceItr = newElem;
		otherItr = otherItr->prev;
	}

	top = newTop;
	length = other.length;
}
