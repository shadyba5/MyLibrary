#include <iostream>
#include <cassert>
#include "Queue.h" // Include your header file here

void testQueue() {
    // Basic Test Case 1: Enqueue and Dequeue
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    assert(q.size() == 3);
    assert(q.peek() == 1);

    int val = q.dequeue();
    assert(val == 1);
    assert(q.size() == 2);
    assert(q.peek() == 2);

    val = q.dequeue();
    assert(val == 2);
    assert(q.size() == 1);
    assert(q.peek() == 3);

    val = q.dequeue();
    assert(val == 3);
    assert(q.size() == 0);
    assert(q.isEmpty());

    // Edge Case 1: Dequeue from an empty queue
    try {
        q.dequeue();
        assert(false); // Should not reach here
    }
    catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Queue is empty");
    }

    // Edge Case 2: Peek into an empty queue
    try {
        q.peek();
        assert(false); // Should not reach here
    }
    catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Queue is empty");
    }

    // Edge Case 3: Copy constructor
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    Queue<int> q2(q1); // Copy constructor
    assert(q2.size() == 3);
    assert(q2.peek() == 10);

    q1.dequeue(); // Modify q1
    assert(q1.size() == 2);
    assert(q2.size() == 3); // q2 should remain unaffected

    // Edge Case 4: Assignment operator
    Queue<int> q3;
    q3.enqueue(100);
    q3.enqueue(200);

    q2 = q3; // Assignment operator
    assert(q2.size() == 2);
    assert(q2.peek() == 100);

    q3.enqueue(300);
    assert(q3.size() == 3);
    assert(q2.size() == 2); // q2 should remain unaffected

    // Edge Case 5: Clear the queue
    q2.clear();
    assert(q2.size() == 0);
    assert(q2.isEmpty());

    q2.enqueue(1);
    q2.enqueue(2);
    q2.clear();
    assert(q2.size() == 0);
    assert(q2.isEmpty());
}

/*
int main() {
    testQueue();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
*/