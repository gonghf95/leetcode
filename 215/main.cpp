#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace hongfu01
{
    class Solution
    {
    public:
        int findKthLargest(vector<int> &nums, int k)
        {
            int *heap = new int[nums.size() + 1];
            int i = 1;
            for (auto val : nums)
                adjustUp(heap, i++, val);

            int ret;
            while (k--)
                ret = pop(heap, --i);
            delete[] heap;
            return ret;
        }

    private:
        int pop(int *heap, int size)
        {
            int top = heap[1];
            heap[1] = heap[size];
            for (int i = size - 1; i >= 1; i--)
                adjustUp(heap, i, heap[i]);
            return top;
        }

        void adjustUp(int *heap, int k, int val)
        {
            heap[k] = val;

            int i = k / 2;
            while (i > 0)
            {
                if (heap[i] < heap[k])
                {
                    swap(heap[i], heap[k]);
                    k = i;
                    i = k / 2;
                }
                else
                    break;
            }
        }
    };
} // namespace hongfu01

namespace hongfu02
{
    class Solution
    {
    public:
        int findKthLargest(vector<int> &nums, int k)
        {
            priority_queue<int, vector<int>, greater<int>> pq;
            for (auto &i : nums)
            {
                pq.push(i);
                if ((int)pq.size() > k)
                    pq.pop();
            }
            int ret = pq.top();
            return ret;
        }
    };
} // namespace hongfu02

int main(int argc, char *argv[])
{
    // vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    // vector<int> nums = {3, 2, 1, 5, 6, 4};
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    hongfu02::Solution s;
    cout << s.findKthLargest(nums, 4) << endl;
    return 0;
}