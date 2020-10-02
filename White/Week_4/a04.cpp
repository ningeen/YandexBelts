// https://www.coursera.org/learn/c-plus-plus-white/programming/ndSVY/vyvod-s-tochnost-iu

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");

    cout << fixed << setprecision(3);
    if (input.is_open()) {
        double val;
        while (input >> val) {
            cout << val << endl;
        }
    }

    return 0;
}