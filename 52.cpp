#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int evaluate(string expression) {
    stack<int> stack;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            stack.push(stoi(token));
        } else {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            switch (token[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
            }
        }
    }

    return stack.top();
}

int main() {
    string expression;
    getline(cin, expression);
    cout << evaluate(expression) << endl;
    return 0;
}
