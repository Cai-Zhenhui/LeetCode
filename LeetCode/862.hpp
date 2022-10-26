#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
862. 和至少为 K 的最短子数组
https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/
*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> preSumArr(nums.size()+1, 0);
        int i = 1;
        for (auto& _ : nums) {
            preSumArr[i] = preSumArr[i - 1] + _;
            ++i;
        }
        
        deque<long long> q;
        int result = nums.size() + 1;
        for (i = 0; i <= nums.size(); ++i) {
            while (!q.empty() && preSumArr[i] - preSumArr[q.front()] >= k) {
                if (i - q.front() < result) {
                    result = i - q.front();
                }
                q.pop_front();
            }
            while (!q.empty() && preSumArr[i] <= preSumArr[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        return result < (nums.size()+1) ? result : -1;
    }
};
