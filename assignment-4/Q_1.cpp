#include<iostream>
using namespace std;

class Queue{
    int q[10];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }
    
    void enqueue(int x){
        if(rear == 9){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(front == -1) 
            front = 0;
        q[++rear] = x; 
    }
    
    void dequeue(){
        if(front == -1 || front > rear){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        cout << "Removed: " << q[front] << endl;  
        front++;
        if(front > rear) {  
            front = rear = -1; 
        }
    }   

    
    void display(){
        if(front == -1 || front > rear){
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i = front; i <= rear; i++){
            cout<<q[i]<<" ";
        }
        cout<<endl;
    }
    
    int peek(){
        if(front == -1 || front > rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return q[front];
    }
    
    bool isEmpty(){
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == 9;
    }
};

int main(){
    Queue q;
    int choice, value;

    do {
        cout << "\n=== Queue Menu ===\n";
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
                value = q.peek();
                if (value == -1)
                    cout << "Queue is empty\n";
                else
                    cout << "Front element: " << value << endl;
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