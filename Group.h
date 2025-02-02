#ifndef GROUP_HEADER
#define GROUP_HEADER

#include <ctime>
#include "Teacher.h"
#include "Lesson.h"
#include <vector>

class Group
{
private:
    int grade;
    char liter;

    vector <Lesson> lessons;

    vector<vector<Lesson>> realSchedule;

    vector<vector<int>> priority =
    { {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    void InitializeRealSchedule();

public:
    Group();

    Group(int g, int l);

    void SetLesson(int day, int number, Lesson& lesson);

    void ChangePriority(int day, int number, int value);

    void ClearPriority();

    void AddLesson(Lesson& lsn);

    void DeleteUsedLesson();

    void SetMinPriorities(Lesson& lesson);

    void SetMaxPriorities(Lesson& lesson);

    pair<int, int> FindMaxPrioritisedLesson();

    Lesson GetRandomLesson();

    void Result();

    vector<vector<Lesson>> GetRealSchedule();
};

#endif // !GROUP_HEADER