// https://www.coursera.org/learn/c-plus-plus-white/programming/Gi9dw/avtobusnyie-ostanovki-1

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


bool buses_for_stop(map<string, vector<string>>& schedule, const vector<string>& bus_order, string stop, string exclude_bus) {
    bool is_stop = false;
    for (const auto& bus : bus_order) {
        if (bus != exclude_bus) {
            int stops_count = count(schedule[bus].begin(), schedule[bus].end(), stop);
            if (stops_count > 0) {
                is_stop = true;
                cout << bus << ' ';
            }
        }
    }
    return is_stop;
}


int main() {
    int n;
    cin >> n;

    string command, bus, stop;
    int stop_count;
    map<string, vector<string>> schedule;
    vector<string> bus_order;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "NEW_BUS") {
            cin >> bus >> stop_count;
            bus_order.push_back(bus);
            for (int j = 0; j < stop_count; j++) {
                cin >> stop;
                schedule[bus].push_back(stop);
            }
        } else if (command == "BUSES_FOR_STOP") {
            cin >> stop;
            bool is_stop = buses_for_stop(schedule, bus_order, stop, "");
            if (!is_stop) {
                cout << "No stop";
            }

            cout << endl;
        } else if (command == "STOPS_FOR_BUS") {
            cin >> bus;

            if (schedule.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for (const auto& stop : schedule[bus]) {
                    cout << "Stop " << stop << ": ";
                    bool is_stop = buses_for_stop(schedule, bus_order, stop, bus);
                    if (!is_stop) {
                        cout << "no interchange"; 
                    }
                    cout << endl;
                }
            }
        } else if (command == "ALL_BUSES") {
            if (schedule.size() == 0) {
                cout << "No buses" << endl;
            } else {
                for (const auto& item : schedule) {
                    cout << "Bus " << item.first << ": ";
                    for (const auto& stop : item.second) {
                        cout << stop << ' ';
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}