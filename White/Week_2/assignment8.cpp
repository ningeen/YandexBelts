#include <iostream>
#include <vector>
using namespace std;

void operate(vector<bool>& queue, string command, int number) {
    if (command == "WORRY") {
        queue[number] = true;
    } else if (command == "QUIET") {
        queue[number] = false;
    } else if (command == "COME") {
        queue.resize(queue.size() + number, false);
    } else if (command == "WORRY_COUNT") {
        int sum = 0;
        for (bool val : queue) {
            if (val) {
                sum ++;
            }
        }
        cout << sum << endl;
    }
}

int main() {
    int q;
    cin >> q;

    vector<bool> queue;
    string command;
    for (int i = 0; i < q; i++) {
        int number = 0;
        cin >> command;
        if (command != "WORRY_COUNT") {
            cin >> number;
        }
        operate(queue, command, number);
    }

    return 0;
}