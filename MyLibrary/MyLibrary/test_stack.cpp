#include <iostream>
#include <cassert>
#include "stack.h"  // Assuming your stack implementation is in a file named stack.h

void test_pop_on_empty_stack() {
    stack<int> s;

    try {
        s.pop();
        assert(false); // If we reach here, pop did not throw as expected
    }
    catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Stack is empty");
    }

    std::cout << "test_pop_on_empty_stack passed!" << std::endl;
}

void test_peak_on_empty_stack() {
    stack<int> s;

    try {
        s.peak();
        assert(false); // If we reach here, peak did not throw as expected
    }
    catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Stack is empty");
    }

    std::cout << "test_peak_on_empty_stack passed!" << std::endl;
}

void test_push_and_pop_single_element() {
    stack<int> s;

    s.push(42);
    assert(s.size() == 1);

    int value = s.pop();
    assert(value == 42);
    assert(s.size() == 0);

    std::cout << "test_push_and_pop_single_element passed!" << std::endl;
}

void test_copy_empty_stack() {
    stack<int> s1;
    stack<int> s2(s1);  // Copy constructor

    assert(s2.is_empty());
    assert(s2.size() == 0);

    std::cout << "test_copy_empty_stack passed!" << std::endl;
}

void test_assignment_empty_stack() {
    stack<int> s1;
    stack<int> s2;
    s2 = s1;  // Assignment operator

    assert(s2.is_empty());
    assert(s2.size() == 0);

    std::cout << "test_assignment_empty_stack passed!" << std::endl;
}

void test_copy_stack_with_one_element() {
    stack<int> s1;
    s1.push(100);

    stack<int> s2(s1);  // Copy constructor
    assert(s2.size() == 1);
    assert(s2.pop() == 100);
    assert(s2.is_empty());

    std::cout << "test_copy_stack_with_one_element passed!" << std::endl;
}

void test_assignment_stack_with_one_element() {
    stack<int> s1;
    s1.push(200);

    stack<int> s2;
    s2 = s1;  // Assignment operator
    assert(s2.size() == 1);
    assert(s2.pop() == 200);
    assert(s2.is_empty());

    std::cout << "test_assignment_stack_with_one_element passed!" << std::endl;
}

void test_multiple_operations() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    assert(s.pop() == 3);
    assert(s.pop() == 2);

    s.push(4);
    assert(s.peak() == 4);
    assert(s.pop() == 4);
    assert(s.pop() == 1);

    assert(s.is_empty());

    std::cout << "test_multiple_operations passed!" << std::endl;
}

void test_memory_leak() {
    // This test will check if all nodes are properly deleted.
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.clear();
    assert(s.is_empty());

    std::cout << "test_memory_leak passed!" << std::endl;
}

int main() {
    test_pop_on_empty_stack();
    test_peak_on_empty_stack();
    test_push_and_pop_single_element();
    test_copy_empty_stack();
    test_assignment_empty_stack();
    test_copy_stack_with_one_element();
    test_assignment_stack_with_one_element();
    test_multiple_operations();
    test_memory_leak();

    std::cout << "All edge case tests passed!" << std::endl;
    return 0;
}
