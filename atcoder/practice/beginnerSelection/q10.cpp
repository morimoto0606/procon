#include <iostream>
#include <vector>
using namespace std;
const vector<string> list = {
    "dream","dreamer","erase","eraser"
};

bool checkTail(std::string& s) {
    if (s.length() == 0) {
        return true;
    }
    for (string l : list) {
        if (s.length() < l.length()) {continue;}
        if (s.substr(s.length() - l.length()) == l) {
            s.erase(s.length() - l.length());
            return checkTail(s);
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (checkTail(s)) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}