#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
    int tmp;
    for (int i = 0; i < v.size() / 2; ++i) {
        tmp = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = tmp;
    }
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    numbers = {1, 5, 4, 2};
    Reverse(numbers);
    return 0;
}