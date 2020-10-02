// https://www.coursera.org/learn/c-plus-plus-white/programming/oOkT1/obratimaia-funktsiia-s-umnozhieniiem-i-dielieniiem

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class FunctionPart{
    public:
        FunctionPart(const char& new_operation, const double& new_value) {
            operation = new_operation;
            value = new_value;
        }
        double Apply(const double& new_value) const {
            if (operation == '+') {
                return new_value + value;
            } else if (operation == '-') {
                return new_value - value;
            } else if (operation == '*') {
                return new_value * value;
            } else if (operation == '/') {
                return new_value / value;
            }
        }
        void Invert() {
            if (operation == '+') {
                operation = '-';
            } else if (operation == '-') {
                operation = '+';
            } else if (operation == '*') {
                operation = '/';
            } else if (operation == '/') {
                operation = '*';
            }
        }
    private:
        char operation;
        double value;
};

class Function{
    public:
        void AddPart(char operation, double value) {
            parts.push_back({operation, value});
        };
        double Apply(double value) const {
            for (const auto& part : parts) {
                value = part.Apply(value);
            }
            return value;
        };
        void Invert() {
            for (auto& part : parts) {
                part.Invert();
            }
            reverse(begin(parts), end(parts));
        };
    private:
        vector<FunctionPart> parts;
};
