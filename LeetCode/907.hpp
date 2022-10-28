#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
907. 子数组的最小值之和
https://leetcode.cn/problems/sum-of-subarray-minimums/
*/

class Solution {
public:
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        int result = 0;
        int i = 0;

        {
            stack<int> d;
            for (auto item : arr) {
                while (!d.empty() && arr[d.top()] > item) {
                    d.pop();
                }
                if (!d.empty()) {
                    left[i] = d.top();
                }
                d.push(i++);
            }
        }
        {
            stack<int> d;
            for (i = n - 1; i >= 0;--i) {
                while (!d.empty() && arr[d.top()] >= arr[i]) {
                    d.pop();
                }
                if (!d.empty()) {
                    right[i] = d.top();
                }
                d.push(i);
            }
        }
        long long temp;
        for (i = 0; i < n; ++i) {
            temp = (static_cast<long long>(i) - left[i]) * (right[i] - static_cast<long long>(i)) * arr[i];
            temp %= 1000000007;
            result += temp;
            if (result >= 1000000007) {
                result -= 1000000007;
            }
        }
        return result;
    }
};
