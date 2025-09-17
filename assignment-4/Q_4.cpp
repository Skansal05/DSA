#include<iostream>
#include<string>
using namespace std;

class Queue{
    char q[26];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }
    
    void enqueue(char x){
        if(rear == 25){
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
        front++;
        if(front > rear) {  
        front = rear = -1; 
        }
    }
    
    char getFront(){
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
        return rear == 25;
    }
};

int main(){
    int count[26] = {0};
    Queue q;
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    for(char c : str){
        count[c - 'a']++; // increase frequency
        q.enqueue(c);

        // Remove all characters from front which have freq > 1
        while (!q.isEmpty() && count[q.getFront() - 'a'] > 1) {
            q.dequeue();
        }

        // Print result
        if (q.isEmpty())
            cout << -1 << " ";
        else
            cout << q.getFront() << " ";
    }
    return 0;
}