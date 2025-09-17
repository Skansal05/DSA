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

    void rotate() {
        int temp = getFront();
        dequeue();
        enqueue(temp);
    }
};

class Stack {
    Queue q;

public:
    void push(int x) {
        int n = q.size();
        q.enqueue(x);
        for (int i = 0; i < n; i++) {
            q.rotate();
        }
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << q.getFront() << endl;
        q.dequeue();
    }

    void top() {
        if (q.isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << q.getFront() << endl;
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