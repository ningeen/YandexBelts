// https://www.coursera.org/learn/c-plus-plus-white/programming/PnvtW/struktura-lecturetitle

#include <string>
using namespace std;

struct Specialization {
    string name;
    explicit Specialization(string s) {
        name = s;
    }
};

struct Course {
    string name;
    explicit Course(string s) {
        name = s;
    }
};

struct Week {
    string name;
    explicit Week(string s) {
        name = s;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;
    explicit LectureTitle(Specialization new_spec, Course new_course, Week new_week) {
        specialization = new_spec.name;
        course = new_course.name;
        week = new_week.name;
    }
};

int main() {
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );

    return 0;
}