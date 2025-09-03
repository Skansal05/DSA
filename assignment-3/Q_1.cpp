#include <iostream>
using namespace std;

#define MAX 5  // Maximum size of the stack

struct Stack{
    int arr[MAX];
    int top;
};

Stack init() {
    Stack S;
    S.top = -1; // Initialize top to -1 indicating an empty stack
    return S;
}

int isEmpty(Stack S) {
    if (S.top == -1)
        return 1;
    else
        return 0;
}
int isFull(Stack S) {
    if (S.top == MAX - 1)
        return 1;
    else
        return 0;
}
int top(Stack S) {
    if (!isEmpty(S))
        return S.arr[S.top];
    else
        return -1; // Indicating stack is empty
}
Stack push(Stack S, int x) {
    if (!isFull(S)) {
        S.arr[++S.top] = x;
    } else {
        cout << "Stack Overflow! Cannot push " << x << endl;
    }
    return S;
}
Stack pop(Stack S) {
    if (!isEmpty(S)) {
        cout << "Popped element: " << S.arr[S.top--] << endl;
    } else {
        cout << "Stack Underflow! Cannot pop from empty stack." << endl;
    }
    return S;
}
void display(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements: ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.arr[i] << " ";
    }
    cout << endl;
}
int peek(Stack S, int pos) {
    // pos = 1 means top element
    int index = S.top - pos + 1;
    if (index < 0 || index > S.top) {
        cout << "Invalid position!" << endl;
        return -1; // Indicating error
    }
    return S.arr[index];
}

int main() {
    Stack S = init();
    S = push(S, 10);
    S = push(S, 20);
    S = push(S, 30);
    display(S);
     cout << "Top element is: " << top(S) << endl;
    
    cout << "Peek at position 1: " << peek(S, 1) << endl;
    cout << "Peek at position 2: " << peek(S, 2) << endl;
    cout << "Peek at position 3: " << peek(S, 3) << endl;
    
    S = pop(S);
    display(S);
    S = pop(S);
    S = pop(S);
    S = pop(S); // Attempt to pop from empty stack
    display(S);     

    return 0;
}