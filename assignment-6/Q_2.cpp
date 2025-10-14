#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

class CircularList{
    Node *head;
    Node *tail;

public:
    int size;
    CircularList(){
        head = tail = NULL;
        size=0;
    }

    void insert_at_head(int val){
        Node *t = new Node(val);
        if (head == nullptr)
            head = tail = t;
        else{
            t->next = head;
            head = t;
            tail->next = head;
        }
        size++;
    }
    void insert_at_tail(int val){
        Node *t = new Node(val);
        if (head == nullptr)
            head = tail = t;
        else{
            t->next = head;
            tail->next = t;
            tail = t;
        }
        size++;
    }
    void display()
    {
        if(head == NULL) return;

        cout << head->data << " ";
        Node *temp = head->next;
        
        while (temp != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data <<"(back to head)" << endl;
    }
};
int main(){
    CircularList cl;
    cl.insert_at_head(20);
    cl.insert_at_tail(100);
    cl.insert_at_tail(40);
    cl.insert_at_tail(80);
    cl.insert_at_tail(60);
    cl.display();

    return 0;
}