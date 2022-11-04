#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
754. 到达终点数字
https://leetcode.cn/problems/reach-a-number/
*/


class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) {
            target = -target;
        }
        int d = 0;
        int k = 0;
        int s = 0;
        while (s<target) {
            ++k;
            s += k;
        }
        d = s - target;
        if (d == 0 || d%2==0) {
            return k;
        }
        else {
            if ((d + k + 1) % 2 == 0) {
                return k + 1;
            }
            else {
                return k + 2;
            }
        }
    }
};
