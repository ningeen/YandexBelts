// https://www.coursera.org/learn/c-plus-plus-white/programming/ZUCo1/spravochnik-stolits

#include <iostream>
#include <map>
using namespace std;


int main() {
    int n;
    cin >> n;

    map<string, string> dict;
    string command, capital, new_capital, country, new_country;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "CHANGE_CAPITAL") {
            cin >> country >> new_capital;

            if (dict.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            } else if (dict[country] == new_capital) {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            } else {
                cout << "Country " << country << " has changed its capital from " << dict[country] << " to " << new_capital << endl;
            }

            dict[country] = new_capital;
        } else if (command == "RENAME") {
            cin >> country >> new_country;

            if (country == new_country || dict.count(country) == 0 || dict.count(new_country) > 0) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << country << " with capital " << dict[country] << " has been renamed to " << new_country << endl;
                dict[new_country] = dict[country];
                dict.erase(country);
            }


        } else if (command == "ABOUT") {
            cin >> country;

            if (dict.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << dict[country] << endl;
            }
        } else if (command == "DUMP") {
            if (dict.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto& item : dict) {
                    cout << item.first << '/' << item.second << ' ';
                }
                cout << endl;
            }


        }
    }

    return 0;
}