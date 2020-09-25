#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> reversed_v;
    for (int i = 0; i < v.size(); ++i) {
        reversed_v.push_back(v[v.size() - 1 - i]);
    }
    return reversed_v;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    vector<int> rnumbers = Reversed(numbers);
    numbers = {1, 5, 4, 2};
    rnumbers = Reversed(numbers);
    return 0;
}