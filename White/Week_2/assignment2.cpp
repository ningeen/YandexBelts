#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        } 
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> result;
    for (auto word : words) {
        if (word.size() >= minLength) {
            if (IsPalindrom(word)) {
                result.push_back(word);
            }
        }
    }
    return result;
}

int main() {
    vector<string> words, words_filtered;
    words = {"weew", "bro", "code", "www", "qwq", "aa", "weew", "wewew"};
    words_filtered = PalindromFilter(words, 4);
    words_filtered = PalindromFilter(words, 3);
    words_filtered = PalindromFilter(words, 2);
    return 0;
}