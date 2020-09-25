#include <iostream>
using namespace std;


int main() {
    int a, b, z;
    cin >> a >> b;

    if (a > b) {
        swap(a, b);
    }

    while (a != 0) {
        z = b % a;
        b = a;
        a = z;
    }

    cout << b;

    return 0;
}