#include "Lesson.h"

Lesson::Lesson()
{
    this->name = "";
    this->teacher = Teacher();
}

Lesson::Lesson(string n, Teacher t)
{
    this->name = n;
    this->teacher = t;
}

string Lesson::GetName()
{
    return this->name;
}

Teacher Lesson::GetTeacher()
{
    return this->teacher;
}

bool Lesson::GetStatus()
{
    return this->isBysy;
}

void Lesson::SetStatusBysy()
{
    this->isBysy = true;
}

bool Lesson::operator == (Lesson& l)
{
    return this->name == l.name && this->teacher == l.teacher;
}

Lesson& Lesson::operator = (Lesson l)
{
    this->name = l.name;
    this->teacher = l.teacher;
    this->isBysy = l.isBysy;
    return *this;
}
