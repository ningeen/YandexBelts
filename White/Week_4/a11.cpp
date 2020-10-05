// https://www.coursera.org/learn/c-plus-plus-white/programming/NXqA9/rabota-s-siervierom-vriemieni

#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <system_error>
using namespace std;

string AskTimeServer() {
    // throw runtime_error("AAA");
    // throw system_error();
    return "00:00:71";
}

class TimeServer {
public:
    string GetCurrentTime() {
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
        try {
            last_fetched_time = AskTimeServer();
        } catch (const system_error& e) {}
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
