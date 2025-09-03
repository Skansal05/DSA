#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

Stack init() {
    Stack S;
    S.top = -1;
    return S;
}

bool isEmpty(Stack S) {
    return (S.top == -1);
}

Stack push(Stack S, char c) {
    if (S.top < MAX - 1) {
        S.arr[++S.top] = c;
    } else {
        cout << "Stack Overflow!" << endl;
    }
    return S;
}

char pop(Stack &S) {
    if (!isEmpty(S)) {
        return S.arr[S.top--];
    } else {
        return '\0';
    }
}

// Peek
char peek(Stack S) {
    if (!isEmpty(S)) return S.arr[S.top];
    return '\0';
}

// Precedence of operators
int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Convert infix to postfix
string infixToPostfix(string infix) {
    Stack S = init();
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If operand → add directly
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            postfix += c;
        }

        // If '(' → push
        else if (c == '(') {
            S = push(S, c);
        }
        // If ')' → pop until '('
        else if (c == ')') {
            while (!isEmpty(S) && peek(S) != '(') {
                postfix += pop(S);
            }
            pop(S);
        }
        // If operator → handle precedence
        else {
            while (!isEmpty(S) && precedence(peek(S)) >= precedence(c)) {
                postfix += pop(S);
            }
            S = push(S, c);
        }
    }

    // Pop all remaining operators
    while (!isEmpty(S)) {
        postfix += pop(S);
    }

    return postfix;
}

int main() {
    string infix = "(A+B)*C/D-E";
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    return 0;
}
