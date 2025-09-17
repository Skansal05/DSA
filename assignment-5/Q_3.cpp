#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

Node* findMiddle(Node* head) {
    if (!head) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void displayList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    int arr[] = {1, 2, 3, 4, 5};
    for (int val : arr)
        insertAtEnd(head, val);

    cout << "Linked List: ";
    displayList(head);

    Node* mid = findMiddle(head);

    if (mid)
        cout << "Middle Node: " << mid->data << endl;
    else
        cout << "List is empty." << endl;

    return 0;
}
