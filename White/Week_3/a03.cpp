// https://www.coursera.org/learn/c-plus-plus-white/programming/4FQn4/imiena-i-familii-1

#include <string>
#include <map>
#include <iostream>
using namespace std;

class Person {
    public:
        void ChangeFirstName(int year, const string& first_name) {
            names[year] = first_name;
        }
        void ChangeLastName(int year, const string& last_name) {
            last_names[year] = last_name;
        }
        string GetFullName(int year) {
            string current_name = GetName(year, names);
            string current_last_name = GetName(year, last_names);

            if (current_name.size() > 0 && current_last_name.size() > 0) {
                return current_name + ' ' + current_last_name;
            } else if (current_name.size() == 0 && current_last_name.size() > 0) {
                return current_last_name + " with unknown first name";
            } else if (current_name.size() > 0 && current_last_name.size() == 0) {
                return current_name + " with unknown last name";
            } else {
                return "Incognito";
            }
        }
    
    private:
        string GetName(int year, map<int, string>& name_map) {
            string current_name = "";
            for (const auto& name : name_map) {
                if (year >= name.first) {
                    current_name = name.second;
                }
            }
            return current_name;
        }

        map<int, string> names;
        map<int, string> last_names;
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
