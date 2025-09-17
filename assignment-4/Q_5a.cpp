#include <iostream>
using namespace std;

class Queue {
    int q[10];
    int front, rear;

public:
    Queue() { front = rear = -1; }

    void enqueue(int x) {
        if (rear == 9) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0;
        q[++rear] = x;
    }

    void dequeue() {
        if (front == -1 || front > rear) return;
        front++;
        if (front > rear) front = rear = -1;
    }

    int getFront() { return q[front]; }
    bool isEmpty() { return front == -1 || front > rear; }
    int size() { return isEmpty() ? 0 : rear - front + 1; }

    void transferTo(Queue &other) {
        while (!isEmpty()) {
            other.enqueue(getFront());
            dequeue();
        }
    }
};

class Stack {
    Queue q1, q2;

public:
    void push(int x) {
        q1.enqueue(x);
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        while (q1.size() > 1) {
            q2.enqueue(q1.getFront());
            q1.dequeue();
        }

        cout << "Popped: " << q1.getFront() << endl;
        q1.dequeue();

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void top() {
        if (q1.isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        while (q1.size() > 1) {
            q2.enqueue(q1.getFront());
            q1.dequeue();
        }
        cout << "Top element: " << q1.getFront() << endl;

        q2.enqueue(q1.getFront());
        q1.dequeue();

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }
};


int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.top();   
    s.pop();   
    s.top();   
    return 0;
}
