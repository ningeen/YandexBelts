#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    double discr;
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            return 0;
        }

        double ans = - c / b;
        cout << ans;
        return 0;
    }

    discr = b * b - 4 * a * c;
    if (discr > 0) {
        double x1 = (-b + sqrt(discr)) / (2 * a);
        double x2 = (-b - sqrt(discr)) / (2 * a);
        cout << x1 << ' ' << x2;
    } else if (discr == 0) {
        double x1 = (-b + sqrt(discr)) / (2 * a);
        cout << x1;
    }

    return 0;
}