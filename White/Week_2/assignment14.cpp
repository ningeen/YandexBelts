// https://www.coursera.org/learn/c-plus-plus-white/programming/7rcDW/kolichiestvo-unikal-nykh-strok

#include <iostream>
#include <set>
using namespace std;


int main() {
    int n;
    cin >> n;

    string s;
    set<string> unique;
    for (int i = 0; i < n; i++) {
        cin >> s;
        unique.insert(s);
    }

    cout << unique.size();

    return 0;
}