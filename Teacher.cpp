#include "Teacher.h"

Teacher::Teacher()
{
    this->name = "";
    this->surname = "";
    this->patronymic = "";
}

Teacher::Teacher(string n, string s, string p)
{
    this->name = n;
    this->surname = s;
    this->patronymic = p;
}

void Teacher::SetBysyLesson(int day, int number)
{
    this->bysySchedule[day][number] = true;
}

bool Teacher::operator == (Teacher& t)
{
    return this->name == t.name && this->surname == t.surname && this->patronymic == t.patronymic;
}