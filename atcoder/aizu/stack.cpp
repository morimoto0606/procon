#include <bits/stdc++.h>
using namespace std;


int operation(int x, int y, const string& op) {
    if (op == "+") {
        return x + y;
    }
    else if (op == "-"){
        return x - y;
    }
    else if (op == "*"){
        return x * y;
    }
    else {
        return x / y;
    }
}

bool isOperator(const string& c) {
    if (c == "+") {
        return true;
    }
    if (c == "-") {
        return true;
    }
    if (c == "*") {
        return true;
    }
    if (c == "/") {
        return true;
    }
    return false;
}

int main() {
    string porland;
    getline(cin, porland);
    vector<string> vec;
    string tmp;
    for (auto it = porland.begin(); it != porland.end(); ++it) {
        if (*it == ' ') {
            vec.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += *it;
        }
    }
    vec.push_back(tmp);

    stack<int> stack;
    for (const auto& s : vec) {
        porland.erase(porland.begin());
        if (isOperator(s)) {
            const int y = stack.top();
            stack.pop();
            const int x = stack.top();
            stack.pop();
            const int z = operation(x, y, s);
            stack.push(z);
        }
        else {
            const int z = atoi(s.c_str());
            stack.push(z);
        }
    }
    assert(stack.size()==1);
    cout << stack.top() << endl;

}