#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        int ans = 0;
        queue<Employee *> que;
        map<int, Employee *> mie;

        for (auto &e : employees)
            mie[e->id] = e;

        que.push(mie[id]);

        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                Employee *emp = que.front();
                que.pop();

                ans += emp->importance;

                vector<int> sub = emp->subordinates;
                for (auto i : sub)
                    que.push(mie[i]);
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<Employee *> employees;
    int id = 1;

    Employee e1;
    e1.id = 1;
    e1.importance = 5;
    e1.subordinates = {2, 3};
    employees.push_back(&e1);

    Employee e2;
    e2.id = 2;
    e2.importance = 3;
    e2.subordinates = {};
    employees.push_back(&e2);

    Employee e3;
    e3.id = 3;
    e3.importance = 3;
    e3.subordinates = {};
    employees.push_back(&e3);

    cout << s.getImportance(employees, id) << endl;
    return 0;
}