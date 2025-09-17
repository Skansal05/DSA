#include<iostream>
using namespace std;

class CircularQueue {
    int q[10];
    int front, rear;
    int size; // to track number of elements

public:
    CircularQueue() {
        front = rear = 0;
        size = 0;
    }

    bool isFull() {
        return size == 10; // when all slots are filled
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        q[rear] = x;
        rear = (rear + 1) % 10; // circular increment
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        front = (front + 1) % 10; // circular increment
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return q[front];
    }

    int peek() {
        return getFront();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        int count = size;
        int i = front;
        while (count--) {
            cout << q[i] << " ";
            i = (i + 1) % 10;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;
    do {
        cout << "\n=== Circular Queue Menu ===\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (Front element)\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 5:
                cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n");
                break;
            case 6:
                q.display();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}