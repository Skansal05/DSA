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
    public:
    DLL(){
        head = nullptr;
    }
    void insert_at_tail(int val){
        Node* temp = new Node(val);
        if(!head) head = temp;
        else{
            Node* temp1 = head;
            while(temp1->next){
                temp1 = temp1->next;
            }
            temp1->next = temp;
            temp->prev = temp1;
        }
    }
    void insert_at_head(int val){
        Node* temp = new Node(val);
        if(!head) head = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    bool palindrome() {
        if (!head || !head->next)
            return true;

        Node* left = head;
        Node* right = head;

        while (right->next)
            right = right->next;

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main(){
    DLL list;
    list.insert_at_head(1);
    list.insert_at_tail(2);
    list.insert_at_tail(3);
    list.insert_at_tail(3);
    list.insert_at_tail(2);
    list.insert_at_tail(1);

    if (list.palindrome())
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}