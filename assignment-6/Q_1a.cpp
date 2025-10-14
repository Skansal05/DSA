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
        if (head == nullptr) {
            head = tail = t;
            tail->next = head;
        }

        else{
            t->next = head;
            head = t;
            tail->next = head;
        }
        size++;
    }
    void insert_at_tail(int val){
        Node *t = new Node(val);
        if (head == nullptr) {
            head = tail = t;
            tail->next = head;
        }

        else{
            t->next = head;
            tail->next = t;
            tail = t;
        }
        size++;
    }
    void insert_at(int idx, int val){
        if (idx < 0 || idx > size) {
            cout << "Invalid index!\n";
            return;
        }

        if(idx == 0) insert_at_head(val);
        else if(idx == size) insert_at_tail(val);
        else{
            Node* t = new Node(val);
            Node* temp = head;
            
            for(int i=1; i<=idx-1;i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
        }
    }

    int get_at_idx(int idx){
        if (idx < 0 || idx >= size) {
            cout << "Invalid index!\n";
            return -1;
        }
        else if(idx == 0) return head->data;
        else if(idx == size-1) return tail->data;
        else{
            Node* temp = head;
            for(int i=1;i<=idx;i++){
                temp = temp->next;
            }
            return temp->data;
        }
    }
    int search(int value){
        if(head == nullptr) return -1;

        Node* temp = head;
        int idx = 0;
        do {
            if(temp->data == value) return idx;
            temp = temp->next;
            idx++;
        } while(temp != head);

        return -1; 
    }


    void delete_at_head(){
        if (head == tail)
        { 
            delete head;
            head = tail = nullptr;
        }
        else
        { 
            Node *temp = head;
            head = head->next;
            tail->next = head;

            temp->next = nullptr;
            delete temp;
        }
        size--;
    }
    void delete_at_tail() {
        if (head == nullptr) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* previous = head;
            while (previous->next != tail)
            previous = previous->next;

            delete tail;
            tail = previous;
            tail->next = head;
        }
        size--;
    }

    void delete_at_idx(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid index!\n";
            return;
        }

        if (idx == 0) {
            delete_at_head();
            return;
        }
        else if (idx == size - 1) {
            delete_at_tail();
            return;
        }
        else {
            Node* temp = head;
            for (int i = 0; i < idx - 1; i++) {
                temp = temp->next;
            }

            Node* delNode = temp->next;
            temp->next = delNode->next;
            delete delNode;  
            size--;
        }
    }

    void display()
    {
        if(!head) return;

        cout << head->data << " -> ";
        Node *temp = head->next;
        
        while (temp != head)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data<<"(back to head)" << endl;
    }
};
int main(){
    CircularList cl;
    cl.insert_at_head(60);
    cl.insert_at_tail(70);
    cl.insert_at_head(50);
    cl.insert_at(1, 55);
    cl.display();

    cout << "Index of 70 in CLL: " << cl.search(70) << endl;

    cl.delete_at_idx(1);
    cl.display();

    cl.delete_at_tail();
    cl.display();

    return 0;
}