#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DLL {
    DNode* head;
public:
    DLL() { head = NULL; }

    void insert_at_tail(int val) {
        DNode* temp = new DNode(val);
        if (!head) head = temp;
        else {
            DNode* t = head;
            while (t->next)
                t = t->next;
            t->next = temp;
            temp->prev = t;
        }
    }

    int size() {
        int count = 0;
        DNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

struct CNode {
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    CNode* head;
public:
    CircularList() { head = NULL; }

    void insert_at_tail(int val) {
        CNode* temp = new CNode(val);
        if (!head) {
            head = temp;
            temp->next = head; 
        } else {
            CNode* t = head;
            while (t->next != head)
                t = t->next;
            t->next = temp;
            temp->next = head;
        }
    }

    int size() {
        if (!head) return 0;
        int count = 0;
        CNode* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void display() {
        if (!head) return;
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << temp->data;
        cout << endl;
    }
};

int main() {
    DLL dll;
    dll.insert_at_tail(10);
    dll.insert_at_tail(20);
    dll.insert_at_tail(30);

    cout << "Doubly Linked List: ";
    dll.display();
    cout << "Size of DLL = " << dll.size() << endl;

    CircularList cll;
    cll.insert_at_tail(1);
    cll.insert_at_tail(2);
    cll.insert_at_tail(3);
    cll.insert_at_tail(4);

    cout << "\nCircular Linked List: ";
    cll.display();
    cout << "Size of CLL = " << cll.size() << endl;

    return 0;
}
