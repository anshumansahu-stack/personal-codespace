#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <cmath> // For pow function
using namespace std;

// Function to get precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

// Function to handle parentheses and operators in infix to postfix conversion
string infixToPostfix(const string &infix)
{
    stack<char> s;
    string postfix;
    cout << setw(15) << "Token" << setw(15) << "Action" << setw(15) << "Stack" << setw(15) << "Postfix" << endl;

    for (size_t i = 0; i < infix.length(); ++i)
    {
        char token = infix[i];

        if (isdigit(token) || token == '.')
        { // Handle numbers and floating point
            postfix += token;
            if (i + 1 >= infix.length() || !isdigit(infix[i + 1]) && infix[i + 1] != '.')
            {
                postfix += ' '; // Space to separate operands
            }
        }
        else if (token == '(')
        {
            s.push(token);
        }
        else if (token == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.pop(); // pop the '('
        }
        else if (isOperator(token))
        {
            while (!s.empty() && precedence(s.top()) >= precedence(token))
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(token);
        }
        // Print current state
        stringstream stackState;
        stack<char> tempStack = s;
        while (!tempStack.empty())
        {
            stackState << tempStack.top();
            tempStack.pop();
        }
        cout << setw(15) << token << setw(15) << (token == '(' ? "Push" : (token == ')' ? "Pop" : "Process"))
             << setw(15) << (stackState.str().empty() ? "Empty" : stackState.str()) << setw(15) << postfix << endl;
    }

    // Pop all the operators from the stack
    while (!s.empty())
    {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
float evaluatePostfix(const string &postfix)
{
    stack<float> s;
    stringstream ss(postfix);
    string token;
    cout << setw(15) << "Token" << setw(15) << "Action" << setw(15) << "Stack" << setw(15) << "Result" << endl;

    while (ss >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1))
        { // Handle numbers
            s.push(stof(token));
        }
        else if (isOperator(token[0]))
        {
            float right = s.top();
            s.pop();
            float left = s.top();
            s.pop();
            float result;
            switch (token[0])
            {
            case '+':
                result = left + right;
                break;
            case '-':
                result = left - right;
                break;
            case '*':
                result = left * right;
                break;
            case '/':
                result = left / right;
                break;
            case '%':
                result = static_cast<int>(left) % static_cast<int>(right);
                break;
            case '^':
                result = pow(left, right);
                break;
            }
            s.push(result);
        }
        // Print current state
        stringstream stackState;
        stack<float> tempStack = s;
        while (!tempStack.empty())
        {
            stackState << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << setw(15) << token << setw(15) << (isOperator(token[0]) ? "Operate" : "Push")
             << setw(15) << (stackState.str().empty() ? "Empty" : stackState.str()) << setw(15) << (s.empty() ? "Empty" : to_string(s.top())) << endl;
    }

    return s.top();
}

int main()
{
    string infix;
    cout << "Enter the infix expression: ";
    getline(cin, infix);

    // Remove extra spaces from the infix expression
    stringstream ss(infix);
    string temp, cleanedInfix;
    while (ss >> temp)
    {
        cleanedInfix += temp + " ";
    }

    cout << "Infix Expression: " << cleanedInfix << endl;

    string postfix = infixToPostfix(cleanedInfix);
    cout << "Postfix Expression: " << postfix << endl;

    float result = evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << endl;

    return 0;
}
