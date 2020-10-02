// https://www.coursera.org/learn/c-plus-plus-white/programming/uyK0H/chtieniie-i-vyvod-tablitsy

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");

    int n, m, val;
    input >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            input >> val;
            input.ignore(1);

            cout << setw(10) << val;
            if (j != m - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}