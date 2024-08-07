
#ifndef LINKED_LIST_H
#define LINKED_LIST_H


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


#endif // LINKED_LIST_H


