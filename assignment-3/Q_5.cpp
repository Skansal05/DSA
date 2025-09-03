#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void init(Stack &S) {
    S.top = -1;
}

// Check empty
bool isEmpty(Stack S) {
    return (S.top == -1);
}

// Push element
void push(Stack &S, int x) {
    if (S.top < MAX - 1) {
        S.arr[++S.top] = x;
    } else {
        cout << "Stack Overflow!" << endl;
    }
}

// Pop element
int pop(Stack &S) {
    if (!isEmpty(S)) {
        return S.arr[S.top--];
    } else {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
}

// Evaluate postfix expression
int evaluatePostfix(string exp) {
    Stack S;
    init(S);

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // If operand (digit), push to stack
        if (c >= '0' && c <= '9') {
            push(S, c - '0');  // convert char to int
        }
        // If operator, pop two and apply
        else {
            int val2 = pop(S);
            int val1 = pop(S);

            switch (c) {
                case '+': push(S, val1 + val2); break;
                case '-': push(S, val1 - val2); break;
                case '*': push(S, val1 * val2); break;
                case '/': push(S, val1 / val2); break;
            }
        }
    }

    return pop(S); // Final result
}

int main() {
    string exp;
    cout << "Enter Postfix Expression: ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp) << endl;
    return 0;
}
