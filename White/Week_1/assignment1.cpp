#include <iostream>
#include <string>
using namespace std;

string return_less(string x, string y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    a = return_less(a, b);
    a = return_less(a, c);
    cout << a;
    return 0;
}