// https://www.coursera.org/learn/c-plus-plus-white/programming/NZTXy/rabota-s-failami

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("input.txt");

    if (input.is_open()) {
        string line;
        while (getline(input, line)) {
            cout << line << '\n';
        }
    }

    return 0;
}