#include <iostream>
#include <string>
#include <cctype>
#include "linkedstack.h"
#include "Node.h"

using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');

}

int evaluatePostfix(string postfix){
    linkedstack<int> operandStack;
    for(char c : postfix) {
        if(isdigit(c)) {
            operandStack.push(c - '0');

        }
        else if(isOperator(c))
        {
            int operand2 = operandStack.peek();
            operandStack.pop();
            int operand1 = operandStack.peek();
            operandStack.pop();
            int result;
            switch (c)
            {
                case '+': result = operand1 + operand2;
                break;
                case '-': result = operand1 - operand2;
                break;
                case '*': result = operand1 * operand2;
                break;
                case '/': result = operand1 / operand2;
                break;
            

            }
            operandStack.push(result);
        }
    }
    int finalResult = operandStack.peek();
    operandStack.pop();
    return finalResult;
}

string infixTopostfix(string infix)
{
    linkedstack<char> operatorStack;
    string postfix;
    for(char c : infix)
    {
        if (isdigit(c))
        {
            postfix += c;

        }
        else if(isOperator(c))
        {
            while(!operatorStack.isEmpty() && operatorStack.peek() != '(' &&
            ((c == '+' || c == '-') && (operatorStack.peek() == '*' || operatorStack.peek() == '/')))
            {
                char top = operatorStack.peek();
                operatorStack.pop();
                postfix += top;
            }

            operatorStack.push(c);
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if(c == ')')
        {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(')
            {
                char op = operatorStack.peek();
                operatorStack.pop();
                postfix += op;
            }
            if(!operatorStack.isEmpty() && operatorStack.peek() == '(')
            {
                operatorStack.pop();
            }
        }

    }
    while(!operatorStack.isEmpty())
    {
        char op = operatorStack.peek();
        operatorStack.pop();
        postfix += op;
    }
    return postfix;
}

int main() 
{
    string infix;

    cout << "Enter an arithmetic expression: ";

    getline(cin, infix);

    string postfix = infixTopostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);

    cout << "Result: " << result << endl;

    return 0;
}
