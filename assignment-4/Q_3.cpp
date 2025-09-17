#include<iostream>
using namespace std;

class Queue{
    int q[15];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }
    
    void enqueue(int x){
        if(rear == 14){
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
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);
    q.display();

    //interleave the first half of the queue with second half.
    Queue temp;
    for(int i=0; i<3; i++){
        temp.enqueue(q.peek());
        q.dequeue();
    }
    while(!temp.isEmpty()){
        int val = temp.peek();
        temp.dequeue();
        q.enqueue(val);
        val = q.peek();
        q.dequeue();
        q.enqueue(val);
    }
    q.display();
    return 0;
}