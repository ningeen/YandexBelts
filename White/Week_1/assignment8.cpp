#include <iostream>
#include <string>
using namespace std;


int main() {
    int n;
    string number;
    char aChar;

    cin >> n;

    do {
        aChar = '0' + n % 2;
        number += aChar;
        n /= 2;
    }
    while (n != 0);
    
    for (int i = number.size() - 1; i >= 0; --i) {
        cout << number[i];
    }
    return 0;
}