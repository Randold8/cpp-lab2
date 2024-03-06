#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string str) {
    stack<char> s;
    for (char c : str) {
        switch (c) {
            case '(':
            case '[':
            case '{':
                s.push(c);
                break;
            case ')':
                if (s.empty() || s.top() != '(')
                    return false;
                s.pop();
                break;
            case ']':
                if (s.empty() || s.top() != '[')
                    return false;
                s.pop();
                break;
            case '}':
                if (s.empty() || s.top() != '{')
                    return false;
                s.pop();
                break;
        }
    }
    return s.empty();
}

int main() {
    string str;
    getline(cin, str);
    cout << (isBalanced(str) ? "yes" : "no") << endl;
    return 0;
}