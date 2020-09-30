// https://www.coursera.org/learn/c-plus-plus-white/programming/c3YTB/otsortirovannyie-stroki

#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class SortedStrings {
    public:
        void AddString(const string& s) {
            v.push_back(s);
        }

        vector<string> GetSortedStrings() {
            sort(begin(v), end(v));
            return v;
        }

    private:
        vector<string> v;
};

