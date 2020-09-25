#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> temp(n);
    int temp_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
        temp_sum += temp[i];
    }

    int mean_temp = temp_sum / n;
    vector<int> high_temp;
    for (int i = 0; i < n; ++i) {
        if (temp[i] > mean_temp) {
            high_temp.push_back(i);
        }
    }

    cout << high_temp.size() << endl;
    for (int i = 0; i < high_temp.size(); ++i) {
        cout << high_temp[i] << ' ';
    }

    return 0;
}