#include "Group.h"
using namespace std;


void Group::InitializeRealSchedule()
{
    vector <Lesson> t(8);
    for (int i = 0; i < 5; ++i)
    {
        this->realSchedule.push_back(t);
    }
}


Group::Group()
{
    this->grade = 0;
    this->liter = 0;
    InitializeRealSchedule();
}


Group::Group(int g, int l)
{
    this->grade = g;
    this->liter = l;
    InitializeRealSchedule();
}


void Group::SetLesson(int day, int number, Lesson& lesson)
{
    this->realSchedule[day][number] = lesson;
    this->priority[day][number] = -1;
}


void Group::ChangePriority(int day, int number, int value)
{
    priority[day][number] = priority[day][number] + value;
}


void Group::ClearPriority()
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (priority[i][j] != -1)
                priority[i][j] = 0;
        }
    }
}


void Group::AddLesson(Lesson& lsn)
{
    this->lessons.push_back(lsn);
}


void Group::DeleteUsedLesson()
{
    for (int i = lessons.size() - 1; i >= 0; --i)
    {
        if (lessons[i].GetStatus() == true)
        {
            lessons.erase(lessons.begin() + i);
        }
    }
}


void Group::SetMinPriorities(Lesson& lesson)
{
    vector <vector<bool>> teachersLessons = lesson.teacher.bysySchedule;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (this->priority[i][j] != -1 && teachersLessons[i][j] == 1)
            {
                this->priority[i][j] = -2;
            }
        }
    }
}


void Group::SetMaxPriorities(Lesson& lesson) //better Fix(or not)
{
    //this->SetMinPriorities(lesson);
    //close all windows possible; if there are already lessons in the day; farest position from the end; amount of lessons in day;
    //            3                                    2                             1                               1


    //farest position from the end
    for (int i = 0; i < 5; ++i)
    {
        int mnInd = 8;
        for (int j = 7; j >= 0; --j)
        {
            if (this->priority[i][j] != -1 && this->priority[i][j] != -2)
            {
                mnInd = j;
            }
        }
        if (mnInd != 8)
        {
            this->priority[i][mnInd] += 1;
        }
    }


    //if there are already lessons in the day
    vector <bool> dayPrioritiesByLessons = { 0, 0, 0, 0, 0 };
    for (int i = 0; i < 5; ++i)
    {
        bool isLessonInDay = false;
        for (int j = 0; j < 8; ++j)
        {
            if (this->realSchedule[i][j] == lesson)
            {
                isLessonInDay = true;
            }
        }
        if (!isLessonInDay)
        {
            dayPrioritiesByLessons[i] = true;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (dayPrioritiesByLessons[i])
        {
            for (int j = 0; j < 8; ++j)
            {
                if (this->priority[i][j] != -1 && this->priority[i][j] != -2)
                {
                    this->priority[i][j] += 2;
                }
            }
        }
    }


    //close all windows possible
    for (int i = 0; i < 5; ++i)
    {
        bool isFound = false;
        for (int j = 7; j >= 0; --j)
        {
            if (this->priority[i][j] == -1)
            {
                isFound = true;
            }
            if (isFound && this->priority[i][j] != -1 && this->priority[i][j] != -2)
            {
                this->priority[i][j] += 3;
            }
        }
    }


    //amount of lessons in a day

    vector <int> amountOfLessonsInDay(5, 0);
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 7; j >= 0; --j)
        {
            if (this->priority[i][j] == -1)
            {
                amountOfLessonsInDay[i] = j;
                break;
            }
        }
    }

    int minLessonsInDay = amountOfLessonsInDay[0];
    int indOfMinLessons = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (minLessonsInDay > amountOfLessonsInDay[i])
        {
            minLessonsInDay = amountOfLessonsInDay[i];
            indOfMinLessons = i;
        }
    }

    for (int i = 0; i < 8; ++i)
    {
        if (this->priority[indOfMinLessons][i] != -1 && this->priority[indOfMinLessons][i] != -2)
        {
            this->priority[indOfMinLessons][i] += 1;
        }
    }
}


pair<int, int> Group::FindMaxPrioritisedLesson()
{
    int mxVal = -3;
    int indI = 0;
    int indJ = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (this->priority[i][j] > mxVal)
            {
                mxVal = priority[i][j];
                indI = i;
                indJ = j;
            }
        }
    }
    if (mxVal < 0) return { -1, -1 };
    return { indI, indJ };
}

Lesson Group::GetRandomLesson()
{
    srand(time(NULL));
    int ind = rand() % (this->lessons.size());
    this->lessons[ind].SetStatusBysy();
    this->lessons.erase(this->lessons.begin() + ind);
    return lessons[ind];
}

void Group::Result()
{
    while (this->lessons.size() != 0)
    {
        Lesson tempLesson = this->GetRandomLesson();
        this->SetMinPriorities(tempLesson);
        this->SetMaxPriorities(tempLesson);
        pair<int, int> rsp = FindMaxPrioritisedLesson();
        if (rsp.first == rsp.second == -1)
            break;
        this->SetLesson(rsp.first, rsp.second, tempLesson);
        this->ClearPriority();
    }
    //if (this->lessons.size() != 0)
        //Fix ASAP
}

vector<vector<Lesson>> Group::GetRealSchedule()
{
    return this->realSchedule;
}