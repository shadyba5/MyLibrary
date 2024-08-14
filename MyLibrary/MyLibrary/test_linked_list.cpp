#include <iostream>
#include "F:\F-Downloads\github\MyLibrary\MyLibrary\MyLibrary\linked_list.h"

void testInsertFirst() {
    LinkedList<int> list;
    list.insertFirst(1);
    list.insertFirst(2);
    list.insertFirst(3);
    list.display(); // Expected output: 3 2 1
}

void testInsertLast() {
    LinkedList<int> list;
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    list.display(); // Expected output: 1 2 3
}

void testDeleteFirst() {
    LinkedList<int> list;
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    list.deleteFirst();
    list.display(); // Expected output: 2 3
}

void testDeleteLast() {
    LinkedList<int> list;
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    list.deleteLast();
    list.display(); // Expected output: 1 2
}

void testDeleteData() {
    LinkedList<int> list;
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    list.deleteData(2);
    list.display(); // Expected output: 1 3
}

void testExist() {
    LinkedList<int> list;
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    std::cout << list.exist(2) << std::endl; // Expected output: 1 (true)
    std::cout << list.exist(4) << std::endl; // Expected output: 0 (false)
}

void testSize() {
    LinkedList<int> list;
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    std::cout << list.size() << std::endl; // Expected output: 3
}

void testIsEmpty() {
    LinkedList<int> list;
    std::cout << list.isEmpty() << std::endl; // Expected output: 1 (true)
    list.insertLast(1);
    std::cout << list.isEmpty() << std::endl; // Expected output: 0 (false)
}
/*
int main() {
    // Existing tests
    testInsertFirst();
    testInsertLast();
    testDeleteFirst();
    testDeleteLast();
    testDeleteData();
    testExist();
    testSize();
    testIsEmpty();

    // Additional test cases
    LinkedList<int> emptyList;
    emptyList.deleteFirst(); // Should not crash
    emptyList.deleteLast();  // Should not crash
    emptyList.deleteData(1); // Should not crash
    std::cout << "Size of empty list: " << emptyList.size() << std::endl; // Expected output: 0
    std::cout << "Is empty list empty: " << emptyList.isEmpty() << std::endl; // Expected output: 1

    LinkedList<int> singleElementList;
    singleElementList.insertLast(10);
    singleElementList.deleteFirst(); // Should empty the list
    std::cout << "Size after deleting single element: " << singleElementList.size() << std::endl; // Expected output: 0
    std::cout << "Is single element list empty: " << singleElementList.isEmpty() << std::endl; // Expected output: 1

    LinkedList<int> multipleElementList;
    for (int i = 0; i < 1000; ++i) {
        multipleElementList.insertLast(i);
    }
    std::cout << "Size with 1000 elements: " << multipleElementList.size() << std::endl; // Expected output: 1000

    LinkedList<int> copiedList(multipleElementList);
    std::cout << "Size of copied list: " << copiedList.size() << std::endl; // Expected output: 1000

    LinkedList<int> assignedList;
    assignedList = multipleElementList;
    std::cout << "Size of assigned list: " << assignedList.size() << std::endl; // Expected output: 1000

    // Test deletion of non-existent element
    multipleElementList.deleteData(1001); // Should not change list

    return 0;
}

*/