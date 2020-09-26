// https://www.coursera.org/learn/c-plus-plus-white/programming/1mOPD/avtobusnyie-ostanovki-2

#include <iostream>
#include <vector>
#include <map>
using namespace std;


int main() {
    int n;
    cin >> n;

    int stops_count;
    string stop;
    vector<string> path;
    map<vector<string>, int> schedule;
    for (int i = 0; i < n; i++) {
        cin >> stops_count;
        path.clear();
        for (int j = 0; j < stops_count; j++) {
            cin >> stop;
            path.push_back(stop);
        }
        if (schedule.count(path) > 0) {
            cout << "Already exists for " << schedule[path] << endl;
        } else {
            int index = schedule.size() + 1;
            schedule[path] = index;
            cout << "New bus " << index << endl;
        }
    }

    return 0;
}