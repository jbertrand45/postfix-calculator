#include <iostream>
#include <string>
#include<stack>
#include<cc>
#include "linkedstack.h"
#include "Node.h"

using namespace std;

bool isOperator(char c){
    return(c == "+" || c == "-" || c == "*" || c == "/");

}

int evaluatePostfix(string postfix){
    linkedstack<int> operandStack;
    for(char c : postfix) {
        if(isdigit(c)) {
            operandStack.push(c - '0');
            
        }
        else if(isOperator(C))
        {
            int operand1 = operandStack.pop();
            int operand2 = operandStack.pop();
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

        return operandStack.pop();
    }
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
        else if(isOperator(C))
        {
            while(!operatorStack.isEmpty() && operatorStack.peek() != '(' &&
            ((c == '+' || c == '-') && (operatorStack.peek() == '*' || operatorStack.peek() == '/')))
            postfix += operatorStack.pop();

        
            operatorStack.push(C);
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if(c == ')')
        {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(')
            {
                postfix += operatorStack.pop();
            }
            if(!operatorStack.isEmpty() && operatorStack.peek() == '(')
            {
                operatorStack.pop();
            }
        }

    }
    while(!operatorStack.isEmpty())
    {
        postfix += operatorStack.pop();
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
