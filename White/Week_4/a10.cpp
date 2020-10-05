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
            throw invalid_argument("Invalid argument");
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

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Denominator();
    return {numerator, denominator};
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Denominator();
    return {numerator, denominator};
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Numerator();
    int denominator = lhs.Denominator() * rhs.Denominator();
    return {numerator, denominator};
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Numerator();
    if (denominator == 0) {
        throw domain_error("Division by zero");
    }
    return {numerator, denominator};
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
	int p, q;
    char c;

    stream >> p >> c >> q;
    if (stream && c == '/') {
        rational = Rational(p, q);
    } else {
        throw invalid_argument("Invalid argument");
    }

    return stream;
}

int main() {
    Rational a, b;
    char oper;

    try {
        cin >> a >> oper >> b;
        if (oper == '+') {
            cout << a + b;
        } else if (oper == '-') {
            cout << a - b;
        } else if (oper == '*') {
            cout << a * b;
        } else if (oper == '/') {
            cout << a / b;
        } else {
            throw invalid_argument("Invalid argument");
        }
    } catch (const exception& e) {
        cout << e.what();
    }
    return 0;
}
