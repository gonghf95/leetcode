#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int min = salary[0];
        int max = salary[0];
        int sum = 0;
        for (auto &s : salary)
        {
            sum += s;
            if (min > s)
                min = s;
            if (max < s)
                max = s;
        }

        sum -= (min + max);
        return (double)sum / (salary.size() - 2);
    }
};

int main(int argc, char *argv[])
{
    return 0;
}