#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Linkedlist{
    Node* head;
    public:
    Linkedlist(){
        head = nullptr;
    }
    void insert_at_head(int val) {
        Node* temp = new Node(val);
        if (!head){ 
            head = temp;
            temp->next = head;
        }
        else {
            Node* temp1 = head;
            while(temp1->next!=head){
                temp1 = temp1->next;
            }
            temp->next = head;
            temp1->next = temp;
            head = temp;
        }
    }
    void insert_at_tail(int val) {
        Node* temp = new Node(val);
        if (!head){ 
            head = temp;
            temp->next = head;
        } else{
            Node* temp1 = head;
            while(temp1->next!=head){
                temp1 = temp1->next;
            }
            temp1->next=temp;
            temp->next=head;
        }
    }
    void display(){
        if(head == NULL) return;

        cout << head->data << " -> ";
        Node *temp = head->next;
        
        while (temp != head)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data<<"(back to head)" << endl;
    }
    bool cll(){
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main(){
    Linkedlist ll;
    ll.insert_at_head(2);
    ll.insert_at_tail(4);
    ll.insert_at_tail(6);
    ll.insert_at_tail(7);
    ll.insert_at_tail(5);
    ll.display();
    if(ll.cll()) cout<<"True"<<endl;
    else cout<<"false"<<endl;
    return 0;
}