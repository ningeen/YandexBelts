// https://www.coursera.org/learn/c-plus-plus-white/programming/7p79I/iskliuchieniia-v-klassie-rational

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        int delimiter = __gcd(numerator, denominator);
        p = numerator / delimiter;
        q = denominator / delimiter;

        if (q == 0) {
            throw invalid_argument("denominator");
        } else if (p == 0) {
            q = 1;
        } else if (q < 0) {
            p = -p;
            q = -q;
        }
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p;
    int q;
};


Rational operator/(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Numerator();
    if (denominator == 0) {
        throw domain_error("denominator == 0");
    }
    return {numerator, denominator};
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
