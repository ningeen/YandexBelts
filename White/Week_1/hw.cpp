#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

struct Person {
    string name;
    string surname;
    int age;
};

int main() {
    cout << "Hello World!" << endl;
    vector<int> vec = {10, 5, 4, 1, 2, 3};
    cout << vec.size() << endl;
    map<string, int> ntv;
    ntv["one"] = 1;
    cout << ntv["one"] << endl;
    
    vector<Person> stuff;
    stuff.push_back({"Ivan", "Ivanov", 25});
    cout << stuff[0].surname << endl;

    string str = "HADOOOOOOOKEN";
    for (auto c : str) {
        cout << c << '-';
    }

    int count_O = count(begin(str), end(str), 'O');
    cout << count_O << endl;

    sort(begin(str), end(str));
    for (auto c : str) {
        cout << c << '-';
    }

    vector<string> vs = {"", "", ""};
    
    return 0;
}