// https://www.coursera.org/learn/c-plus-plus-white/programming/zqw0h/sortirovka-biez-uchiota-rieghistra

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char to_lower(char c) {
    return tolower(c);
}

bool is_less_lowercase(string a, string b) {
    transform(begin(a), end(a), begin(a), to_lower);
    transform(begin(b), end(b), begin(b), to_lower);
    return a < b;
}


int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    for (auto& i : v) {
        cin >> i;
    }

    sort(begin(v), end(v), is_less_lowercase);

    for (const auto& i : v) {
        cout << i << ' ';
    }

    return 0;
}