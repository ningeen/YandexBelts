#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int count = -2;
    int idx;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'f') {
            count++;
            if (count == 0) {
                cout << i;
                return 0;
            }
        }
    }
    cout << count;
    return 0;
}