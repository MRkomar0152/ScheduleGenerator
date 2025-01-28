#ifndef LESSON_HEADER
#define LESSON_HEADER

#include <string>
#include <vector>
#include "Teacher.h"
using namespace std;


class Lesson
{
private:
    string name;
    Teacher teacher;
    bool isBysy = false;
    friend class Group;

public:
    Lesson();

    Lesson(string n, Teacher t);

    string GetName();

    Teacher GetTeacher();

    bool GetStatus();

    void SetStatusBysy();

    bool operator == (Lesson& l);

    Lesson& operator = (Lesson l);
};

#endif // !LESSON_HEADER