#ifndef TEACHER_HEADER
#define TEACHER_HEADER

#include <string>
#include <vector>
using namespace std;

class Teacher
{
private:
    friend class Group;
    string name;
    string surname;
    string patronymic;
    vector<vector<bool>> bysySchedule =
    { {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

public:
    Teacher();

    Teacher(string n, string s, string p);

    void SetBysyLesson(int day, int number);

    bool operator == (Teacher& t);
};

#endif // !TEACHER_HEADER