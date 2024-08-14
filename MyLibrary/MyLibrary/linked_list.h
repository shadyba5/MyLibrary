
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include <iostream>

template<typename T>
class Node {
public:
	T data;
	Node* next;
	Node() {}
	Node(const T& value) : data(value), next(nullptr){}
};


template<typename T>
class LinkedList
{

public:
	LinkedList(); // Default constructor
	~LinkedList(); // Destructor

	LinkedList(const LinkedList& other); // Copy constructor
	LinkedList& operator=(const LinkedList& other); // Copy assignment operator

	void insertFirst(const T& data);
	void insertLast(const T& data);
	void deleteFirst();
	void deleteLast();
	void deleteData(const T& data);//deletes first occurance
	bool exist(const T& data) const;
	void display() const;
	bool isEmpty() const;
	int size() const;

private:
	Node<T>* head;
	int length;

	void pushFront(const T& data);
	void pushBack(const T& data);
	void popFront();
	void popBack();
	void clear();
	void copy_from(const LinkedList& other);
};

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), length(0) {}

template <typename T>
LinkedList<T>::~LinkedList() {
	clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other){
	copy_from(other);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
	if (this != &other) {
		clear();
		copy_from(other);
	}
	return *this;
}

template<typename T>
inline void LinkedList<T>::insertFirst(const T& data)
{
	pushFront(data);
	
}

template<typename T>
inline void LinkedList<T>::insertLast(const T& data)
{
	pushBack(data);
	
}

template<typename T>
inline void LinkedList<T>::deleteFirst()
{
	popFront();
	
}

template<typename T>
inline void LinkedList<T>::deleteLast()
{
	popBack();
	
}

template<typename T>
inline void LinkedList<T>::deleteData(const T& data)
{
	if (!exist(data)) {
		return;
	}
	if (head->data == data) {
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		length--;
	}
	else {
		Node<T>* itr = head;
		while (itr != nullptr && itr->next != nullptr ) {
			if (itr->next->data == data) {
				Node<T>* temp = itr->next;
				itr->next = temp->next;
				delete temp;
				length--;
				return;
			}
			itr = itr->next;
		}
	}
}

template<typename T>
bool LinkedList<T>::exist(const T& data) const
{
	Node<T>* itr = head;
	while (itr != nullptr) {
		if (itr->data == data) {
			return true;
		}
		itr = itr->next;
	}
	return false;
}

template<typename T>
void LinkedList<T>::display() const
{
	Node<T>* itr = head;
	while (itr != nullptr) {
		cout << itr->data;
		if (itr->next == nullptr) {
			cout << endl;
		}
		else {
			cout << " ";
		}
		itr = itr->next;
	}
}

template<typename T>
inline bool LinkedList<T>::isEmpty() const
{
	return (length == 0 && head == nullptr);
}

template<typename T>
inline int LinkedList<T>::size() const
{
	return length;
}

template<typename T>
void LinkedList<T>::pushFront(const T& data)
{
	Node<T>* newNode = new Node<T>(data);
	newNode->next = head;
	head = newNode;       
	length++;             
}

template<typename T>
void LinkedList<T>::pushBack(const T& data)
{
	Node<T>* newNode = new Node<T>(data);
	
	if (head == nullptr) {
		head = newNode;
		newNode->next = nullptr;
		length++;
	}
	else {
		Node<T>* itr = head;
		while (itr->next != nullptr) {
			itr = itr->next;
		}
		itr->next = newNode;
		newNode->next = nullptr;
		length++;
	}
}

template<typename T>
void LinkedList<T>::popFront()
{
	if (length == 0) {
		return;
	}
	if (length == 1) {
		delete head;
		head = nullptr;
		length--;
	}
	else {
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
void LinkedList<T>::popBack()
{
	if (length == 0) {
		return;
	}

	if (length == 1) {
		delete head;
		head = nullptr;
		length--;
		return;
	}

	Node<T>* itr = head;
	while (itr->next->next != nullptr) {
		itr = itr->next;
	}

	delete itr->next;
	itr->next = nullptr;
	length--;
}

template<typename T>
void LinkedList<T>::clear()
{
	Node<T>* itr = head;
	while (itr != nullptr) {
		Node<T>* temp = itr;
		itr = itr->next;
		delete temp;
	}
	head = nullptr;
	length = 0;
}

template<typename T>
void LinkedList<T>::copy_from(const LinkedList<T>& other)
{
	if (other.head == nullptr) {
		head = nullptr;
		length = 0;
		return;
	}

	Node<T>* otherItr = other.head;

	// Copy the first node
	head = new Node<T>(otherItr->data);
	Node<T>* thisItr = head;
	otherItr = otherItr->next;

	// Copy the remaining nodes
	while (otherItr != nullptr) {
		thisItr->next = new Node<T>(otherItr->data);
		thisItr = thisItr->next;
		otherItr = otherItr->next;
	}

	// Ensure the last node's next pointer is null
	thisItr->next = nullptr;

	// Set the length
	length = other.length;
}


#endif // LINKED_LIST_H


