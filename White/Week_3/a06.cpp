// https://www.coursera.org/learn/c-plus-plus-white/programming/6rEoc/imiena-i-familii-3

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
    public:
        Person(const string& first_name, const string& last_name, int year) {
            birth_year = year;
            names[year] = first_name;
            last_names[year] = last_name;
        }

        void ChangeFirstName(int year, const string& first_name) {
            if (birth_year <= year) {
                names[year] = first_name;
            }
        }
        void ChangeLastName(int year, const string& last_name) {
            if (birth_year <= year) {
                last_names[year] = last_name;
            }
        }
        string GetFullName(int year) const {
            if (year < birth_year) {
                return "No person";
            }
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
        string GetFullNameWithHistory(int year) const {
            if (year < birth_year) {
                return "No person";
            }
            string all_names = GetNames(year, names);
            string all_last_names = GetNames(year, last_names);

            if (all_names.empty() && all_last_names.empty()) {
                return "Incognito";
            } else if (all_names.empty()) {
                return all_last_names + " with unknown first name";
            } else if (all_last_names.empty()) {
                return all_names + " with unknown last name";
            } else {
                return all_names + ' ' + all_last_names; 
            }
        }
    private:
        string GetName(int year, const map<int, string>& name_map) const {
            string current_name = "";
            for (const auto& name : name_map) {
                if (year >= name.first) {
                    current_name = name.second;
                }
            }
            return current_name;
        }

        string GetNames(int year, const map<int, string>& name_map) const {
            vector<string> current_names;
            for (const auto& name : name_map) {
                if (year >= name.first) {
                    int nsize = current_names.size();
                    if (nsize == 0) {
                        current_names.push_back(name.second);
                    } else {
                        if (current_names[nsize - 1] != name.second) {
                            current_names.push_back(name.second);
                        }
                    }
                } else {
                    break;
                }
            }

            reverse(begin(current_names), end(current_names));

            string current_names_str = "";
            if (!current_names.empty()) {
                current_names_str += current_names[0];
                if (current_names.size() > 1) {
                    current_names_str += " (";
                    for (int i = 1; i < current_names.size(); i++) {
                        current_names_str += current_names[i];
                        if (i < current_names.size() - 1) {
                            current_names_str += ", ";
                        }
                    } 
                    current_names_str += ")";
                }
            }

            return current_names_str;
        }

        map<int, string> names;
        map<int, string> last_names;
        int birth_year;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1960, "Appol");
    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
