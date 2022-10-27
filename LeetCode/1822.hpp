#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1822. 数组元素积的符号
https://leetcode.cn/problems/sign-of-the-product-of-an-array/
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int result = 0;
        // 0 0 0
        // 0 1 1
        // 1 0 1
        // 1 1 0
        for (auto& i : nums) {
            if (i == 0) {
                return 0;
            }
            result ^= i;
        }
        return result >> 31 ? -1 : 1;
    }
};
