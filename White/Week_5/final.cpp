// https://www.coursera.org/learn/c-plus-plus-white/programming/sO7Vq/final-naia-zadacha-kursa

#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
using namespace std;

class Date {
    public:
        Date(){}
        Date(int new_year, int new_month, int new_day) {
            if (new_month < 1 || new_month > 12) {
                throw out_of_range("Month value is invalid: " + to_string(new_month));
            } else if (new_day < 1 || new_day > 31) {
                throw out_of_range("Day value is invalid: " + to_string(new_day));
            }
            year = new_year;
            month = new_month;
            day = new_day;
        }
        int GetYear() const {
            return year;
        }
        int GetMonth() const{
            return month;
        }
        int GetDay() const{
            return day;
        }
    private:
        int year;
        int month;
        int day;
};

class Database {
    public:
        void Add(const Date& date, const string& event) {
            if (!event.empty()) {
                db[date].insert(event);
            }
        }
        void Del(const Date& date, const string& event) {
            if (db.count(date) > 0) {
                if (db[date].erase(event)) {
                    cout << "Deleted successfully" << endl;
                } else {
                    cout << "Event not found" << endl;
                }
            } else {
                cout << "Event not found" << endl;
            }
        }
        void Wipe(const Date& date) {
            cout << "Deleted " << db[date].size() << " events" << endl;
            db.erase(date);
        }
        void Find(const Date& date)  {
            if (db.count(date) > 0) {
                for (const auto& event : db[date]) {
                    cout << event << endl;
                }
            }
        }
        void Print() const {
            for (const auto& row : db) {
                Date date = row.first;
                for (const auto& event : row.second) {
                    cout << setw(4) << setfill('0') << date.GetYear() << '-'
                        << setw(2) << setfill('0') << date.GetMonth() << '-'
                        << setw(2) << setfill('0') << date.GetDay();
                    cout << ' ' << event << endl;  //  << row.first
                }
            }
        }
    private:
        map<Date, set<string>> db;
};

ostream& operator<< (ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() << '-'
           << setw(2) << setfill('0') << date.GetMonth() << '-'
           << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

stringstream & operator>> (stringstream& stream, Date& date) {
    string date_str;
    stream >> date_str;
    int year, month, day;
    char c1, c2;
    string c3;

    stringstream s(date_str);
    s >> year >> c1 >> month >> c2 >> day;
    if (s && s.rdbuf()->in_avail() == 0 && c1 == '-' && c1 == '-') {
        date = Date(year, month, day);
    } else {
        string pass, wrong_date;
        s >> pass >> wrong_date;
        throw invalid_argument("Wrong date format: " + date_str);
    }
    return stream;
}

bool operator< (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear()) {
        if (lhs.GetMonth() == rhs.GetMonth()) {
            return lhs.GetDay() < rhs.GetDay();
        }
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetYear() < rhs.GetYear();
}


int main() {
  Database db;

  string command;
  while (getline(cin, command)) {
      if(command == "") continue;
      stringstream s(command);

      string command_line, event;
      Date date;
      s >> command_line;

      try {
          if (command_line == "Add") {
              s >> date >> event;
              db.Add(date, event);
          } else if (command_line == "Del") {
              s >> date >> event;
              if (event.size() > 0) {
                  db.Del(date, event);
              } else {
                  db.Wipe(date);
              }
          } else if (command_line == "Find") {
              s >> date;
              db.Find(date);
          } else if (command_line == "Print") {
              db.Print();
          } else {
              string err = "Unknown command: " + command_line;
              throw invalid_argument(err);
          }
      } catch (const exception& e) {
          cout << e.what() << endl;
      }
  }

  return 0;
}