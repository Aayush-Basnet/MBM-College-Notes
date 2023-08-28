#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(const string& infix) {
    string postfix;
    stack<char> opStack;
    
    for (size_t i = 0; i < infix.size(); ++i) {
        char c = infix[i];
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            opStack.push(c);
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Pop the '('
        } else if (isOperator(c)) {
            while (!opStack.empty() && opStack.top() != '(' && precedence(c) <= precedence(opStack.top())) 
			{
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }
    while (!opStack.empty()) 
	{
        postfix += opStack.top();
        opStack.pop();
    }
    return postfix;
}
string infixToPrefix(const string& infix) {
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (size_t i = 0; i < reversedInfix.size(); ++i) {
        if (reversedInfix[i] == '(') {
            reversedInfix[i] = ')';
        } else if (reversedInfix[i] == ')') {
            reversedInfix[i] = '(';
        }
    }

    string reversedPostfix = infixToPostfix(reversedInfix);
    reverse(reversedPostfix.begin(), reversedPostfix.end());
    return reversedPostfix;
}

int main() {
    string infixExpression;
    cout << "Enter infix expression: ";
    cin>>infixExpression;
    string postfixExpression = infixToPostfix(infixExpression);
    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;
    cout << "Prefix expression: " << prefixExpression << endl;
    return 0;
}

