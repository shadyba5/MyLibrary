#include <iostream>
#include <vector>
#include <cassert>
#include "max_heap.h"

void testHeapConstruction() {
    std::vector<int> data = { 3, 1, 6, 5, 2, 4 };
    MaxHeap<int> heap(data);

    assert(heap.max() == 6);  // Root should be the largest element
    std::cout << "testHeapConstruction passed!" << std::endl;
}

void testInsertion() {
    std::vector<int> data = { 3, 1, 6, 5, 2, 4 };
    MaxHeap<int> heap(data);

    heap.insert(10);
    assert(heap.max() == 10);  // New max after inserting a larger element

    heap.insert(7);
    assert(heap.max() == 10);  // Max should remain 10 after inserting a smaller element

    std::cout << "testInsertion passed!" << std::endl;
}

void testDeletion() {
    std::vector<int> data = { 3, 1, 6, 5, 2, 4 };
    MaxHeap<int> heap(data);

    heap.del_max();
    assert(heap.max() == 5);  // Max should be the next largest element

    heap.del_max();
    assert(heap.max() == 4);  // Continue deleting max elements

    heap.del_max();
    assert(heap.max() == 3);  // Continue until the heap is almost empty

    std::cout << "testDeletion passed!" << std::endl;
}

void testEmptyHeap() {
    std::vector<int> data = {};
    MaxHeap<int> heap(data);

    try {
        heap.max();
        assert(false);  // Should not reach here; exception expected
    }
    catch (const std::out_of_range&) {
        assert(true);  // Exception successfully caught
    }

    std::cout << "testEmptyHeap passed!" << std::endl;
}

void testSingleElementHeap() {
    std::vector<int> data = { 42 };
    MaxHeap<int> heap(data);

    assert(heap.max() == 42);  // Single element should be the max

    heap.del_max();
    try {
        heap.max();
        assert(false);  // Should not reach here; exception expected
    }
    catch (const std::out_of_range&) {
        assert(true);  // Exception successfully caught
    }

    std::cout << "testSingleElementHeap passed!" << std::endl;
}

void testDuplicateElements() {
    std::vector<int> data = { 7, 7, 7, 7, 7 };
    MaxHeap<int> heap(data);

    assert(heap.max() == 7);  // Max should be 7

    heap.del_max();
    assert(heap.max() == 7);  // Max should remain 7

    std::cout << "testDuplicateElements passed!" << std::endl;
}

void testAll() {
    testHeapConstruction();
    testInsertion();
    testDeletion();
    testEmptyHeap();
    testSingleElementHeap();
    testDuplicateElements();
}

int main() {
    testAll();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
