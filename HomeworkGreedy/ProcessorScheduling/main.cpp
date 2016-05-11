#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

namespace CPU {

    struct Task {
        Task(int id):Id(id)
        {}
        int Id;
        int Value;
        int Deadline;
    };

    bool operator <(const Task &lhs, const Task &rhs)
    {
        return lhs.Value > rhs.Value;
    }

    vector<Task> AvailableTasks;
    vector<Task*> Tasks;
    int TotalSteps;
    int TotalValue;

    void InputTasks()
    {
        int NumTasks;
        cout << "Tasks: ";
        cin >> NumTasks;

        AvailableTasks = vector<Task>();
        AvailableTasks.reserve(NumTasks);
        for( int id=0; id<NumTasks; id++ ) {
            auto task = Task(id+1);
            cin >> task.Value;
            cin.ignore(numeric_limits<streamsize>::max(), '-');
            cin >> task.Deadline;
            AvailableTasks.push_back(task);
            TotalSteps = max(TotalSteps, task.Deadline);
        }
        Tasks = vector<Task*>(TotalSteps, nullptr);

        sort(AvailableTasks.begin(), AvailableTasks.end());

    }

    void TryInsertTask(Task *task)
    {
        auto index = task->Deadline-1;
        while(Tasks[index] != nullptr && --index >= 0);
        if( index >= 0 ) {
            Tasks[index] = task;
            TotalValue += task->Value;
        }
    }

    void Exec()
    {
        TotalValue = 0;
        auto task_it = AvailableTasks.begin();
        for(auto step=1; step <= TotalSteps; step++) {
            if( task_it == AvailableTasks.end() ) {
                break;
            }
            TryInsertTask(&(*task_it));
            task_it++;
        }
    }


    void Print()
    {
        cout << "Optimal schedule: ";
        for( auto it = Tasks.begin(); it != Tasks.end(); it++ ) {
            if( *it == nullptr ) {
                continue;
            }
            cout << (*it)->Id << "->";
        }
        cout << endl;
        cout << "Total value: " << TotalValue << endl;
    }
}

int main()
{
    CPU::InputTasks();
    CPU::Exec();
    CPU::Print();
    return 0;
}

