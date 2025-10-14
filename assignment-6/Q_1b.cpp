#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DLL{
    Node* head;
    Node* tail;
public:
    int size;
    DLL(){
        head = tail = nullptr;
        size = 0;
    }

    void insert_at_tail(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void insert_at_head(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

    void insert_at_idx(int idx, int val){
        if(idx < 0 || idx > size) {
            cout << "invalid index" << endl;
            return;
        }
        if(idx == 0) insert_at_head(val);
        else if(idx == size) insert_at_tail(val);
        else{
            Node* t = new Node(val);
            Node* temp = head;
            for(int i = 1; i <= idx - 1; i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next->prev = t;
            temp->next = t;
            t->prev = temp;
            size++;
        }
    }

    int get_at_idx(int idx){
        if(idx < 0 || idx >= size){
            cout << "Invalid index!\n";
            return -1;
        }
        Node* temp = head;
        for(int i = 0; i < idx; i++){
            temp = temp->next;
        }
        return temp->data;
    }
    int search(int value){
        Node* temp = head;
        int idx = 0;
        while(temp != nullptr){
            if(temp->data == value) return idx;
            temp = temp->next;
            idx++;
        }
        return -1; 
    }


    void delete_at_tail(){
        if(tail == nullptr){
            cout << "DLL is empty\n";
            return;
        }

        Node* temp = tail;
        if(head == tail){ 
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        temp = nullptr;
        size--;
    }

    void delete_at_head(){
        if(head == nullptr){
            cout << "DLL is empty\n";
            return;
        }

        Node* temp = head;
        if(head == tail){ 
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        temp = nullptr;
        size--;
    }

    void delete_at_index(int idx){
        if(idx < 0 || idx >= size){
            cout << "Invalid index\n";
            return;
        }
        if(idx == 0) delete_at_head();
        else if(idx == size - 1) delete_at_tail();
        else{
            Node* temp = head;
            for(int i = 0; i < idx; i++){
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            temp = nullptr;
            size--;
        }
    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main(){
    DLL list;
    list.insert_at_tail(10);
    list.insert_at_tail(20);
    list.insert_at_tail(30);
    list.insert_at_tail(40);
    list.insert_at_tail(50);
    list.display();

    cout << "Index of 30 in DLL: " << list.search(30) << endl;

    list.insert_at_idx(2, 25);
    list.display();

    list.delete_at_index(2);
    list.display();

    list.delete_at_head();
    list.display();

    list.delete_at_tail();
    list.display();

    cout << "Element at index 1: " << list.get_at_idx(1) << endl;

    return 0;
}
