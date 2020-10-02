// https://www.coursera.org/learn/c-plus-plus-white/programming/4X4vH/spisok-studientov

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student{
    string name;
    string last_name;
    int day;
    int month;
    int year;

    void Request(const string& request) const {
        if (request == "name") {
            cout << name << " " << last_name << endl;
        } else if (request == "date") {
            cout << day << "." << month << "." << year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<Student> students;
    string name, last_name;
    int day, month, year;
    for (int i = 0; i < n; i++) {
        cin >> name >> last_name >> day >> month >> year;
        students.push_back({name, last_name, day, month, year});
    }

    int m;
    cin >> m;
    string request;
    int student_idx;
    for (int i = 0; i < m; i++) {
        cin >> request >> student_idx;
        if (student_idx > 0 && student_idx <= n) {
            students[--student_idx].Request(request);
        } else {
            cout << "bad request" << endl;
        }
        
    }

    return 0;
}