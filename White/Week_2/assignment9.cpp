#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 0;

    int q;
    cin >> q;

    int day;
    string command, action;
    vector<vector<string>> todo(days_in_month[current_month]);
    for (int i = 0; i < q; i++) {
        cin >> command;
        if (command == "ADD") {
            cin >> day >> action;
            todo[day - 1].push_back(action);
        } else if (command == "DUMP") {
            cin >> day;
            cout << todo[day - 1].size() << ' ';
            for (string act : todo[day - 1]) {
                cout << act << ' ';
            }
            cout << endl;
        } else if (command == "NEXT") {
            int next_month = (current_month + 1) % 12;
            if (days_in_month[next_month] > days_in_month[current_month]) {
                todo.resize(days_in_month[next_month]);
            } else if (days_in_month[next_month] < days_in_month[current_month]) {
                vector<vector<string>> next_todo(days_in_month[next_month]);
                int next_day = 0;
                for (auto actions : todo) {
                    next_todo[next_day].insert(end(next_todo[next_day]), begin(actions), end(actions));
                    if (next_day < days_in_month[next_month] - 1) {
                        next_day++;
                    }
                }
                todo = next_todo;
            }
            current_month = next_month;
        }
    }

    return 0;
}