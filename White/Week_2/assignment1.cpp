#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        } 
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    if (IsPalindrom(s)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}