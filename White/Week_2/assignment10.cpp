// https://www.coursera.org/learn/c-plus-plus-white/programming/5NGSX/anaghrammy

#include <iostream>
#include <map>
using namespace std;

map<char, int> BuildCharCounters(const string& s) {
    map<char, int> counter;
    for (const auto& c : s) {
        ++counter[c];
    }
    return counter;
}

int main() {
    int n;
    cin >> n;

    string first_word;
    string second_word;
    for (int i = 0; i < n; i++) {
        cin >> first_word >> second_word;
        map<char, int> counter_first = BuildCharCounters(first_word);
        map<char, int> counter_second = BuildCharCounters(second_word);
        if (counter_first == counter_second) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}