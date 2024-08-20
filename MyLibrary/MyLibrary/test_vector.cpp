#include <cassert>
#include <iostream>
#include "vector.h"

void testAppend() {
    Vector<int> vec;

    // Test basic append
    vec.append(10);
    assert(vec.size() == 1);
    assert(vec.get(0) == 10);

    // Test multiple appends and resizing
    for (int i = 1; i < 20; ++i) {
        vec.append(i);
    }
    assert(vec.size() == 20);
    assert(vec.get(19) == 19);

    std::cout << "testAppend passed!" << std::endl;
}

void testInsert() {
    Vector<int> vec;

    // Test insert at the beginning
    vec.insert(0, 10);
    assert(vec.size() == 1);
    assert(vec.get(0) == 10);

    // Test insert at the end
    vec.append(20);
    vec.insert(1, 15);
    assert(vec.size() == 3);
    assert(vec.get(1) == 15);
    assert(vec.get(2) == 20);

    // Test insert in the middle
    vec.insert(1, 12);
    assert(vec.size() == 4);
    assert(vec.get(1) == 12);
    assert(vec.get(2) == 15);

    // Test insert at invalid index (should throw an exception)
    try {
        vec.insert(-1, 5);
        assert(false);  // Should not reach this line
    }
    catch (const std::runtime_error&) {
        // Expected exception
    }

    try {
        vec.insert(10, 5);
        assert(false);  // Should not reach this line
    }
    catch (const std::runtime_error&) {
        // Expected exception
    }

    std::cout << "testInsert passed!" << std::endl;
}

void testRemove() {
    Vector<int> vec;

    // Fill vector
    for (int i = 0; i < 10; ++i) {
        vec.append(i);
    }

    // Test remove from the end
    vec.remove(9);
    assert(vec.size() == 9);

    // Test remove from the beginning
    vec.remove(0);
    assert(vec.size() == 8);
    assert(vec.get(0) == 1);

    // Test remove from the middle
    vec.remove(4);
    assert(vec.size() == 7);
    assert(vec.get(4) == 6);

    // Test remove at invalid index (should throw an exception)
    try {
        vec.remove(-1);
        assert(false);  // Should not reach this line
    }
    catch (const std::runtime_error&) {
        // Expected exception
    }

    try {
        vec.remove(10);
        assert(false);  // Should not reach this line
    }
    catch (const std::runtime_error&) {
        // Expected exception
    }

    std::cout << "testRemove passed!" << std::endl;
}

void testExists() {
    Vector<int> vec;

    vec.append(10);
    vec.append(20);
    vec.append(30);

    // Test existing elements
    assert(vec.exists(10) == true);
    assert(vec.exists(20) == true);
    assert(vec.exists(30) == true);

    // Test non-existing elements
    assert(vec.exists(40) == false);

    std::cout << "testExists passed!" << std::endl;
}

void testGet() {
    Vector<int> vec;

    vec.append(10);
    vec.append(20);
    vec.append(30);

    // Test get elements
    assert(vec.get(0) == 10);
    assert(vec.get(1) == 20);
    assert(vec.get(2) == 30);

    // Test get at invalid index (should throw an exception)
    try {
        vec.get(-1);
        assert(false);  // Should not reach this line
    }
    catch (const std::runtime_error&) {
        // Expected exception
    }

    try {
        vec.get(3);
        assert(false);  // Should not reach this line
    }
    catch (const std::runtime_error&) {
        // Expected exception
    }

    std::cout << "testGet passed!" << std::endl;
}

void testResize() {
    Vector<int> vec;

    // Fill vector
    for (int i = 0; i < 10; ++i) {
        vec.append(i);
    }

    // Test resize to larger
    vec.resize(20);
    assert(vec.size() == 20);

    // Test resize to smaller
    vec.resize(5);
    assert(vec.size() == 5);

    std::cout << "testResize passed!" << std::endl;
}

void testClear() {
    Vector<int> vec;

    // Fill vector
    for (int i = 0; i < 10; ++i) {
        vec.append(i);
    }

    // Test clear
    vec.clear();
    assert(vec.size() == 0);

    std::cout << "testClear passed!" << std::endl;
}

void testCopyFrom() {
    Vector<int> vec1;

    // Fill vector
    for (int i = 0; i < 10; ++i) {
        vec1.append(i);
    }

    // Test copyFrom
    Vector<int> vec2(vec1);
    assert(vec2.size() == 10);
    for (int i = 0; i < 10; ++i) {
        assert(vec2.get(i) == i);
    }

    std::cout << "testCopyFrom passed!" << std::endl;
}

int main() {
    testAppend();
    testInsert();
    testRemove();
    testExists();
    testGet();
    testResize();
    testClear();
    testCopyFrom();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
