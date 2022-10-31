#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1441. 用栈操作构建数组
https://leetcode.cn/problems/build-an-array-with-stack-operations/
*/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int currentItem = 1;
        int dis = 0;
        for (auto tar : target) {
            if (currentItem != tar) {
                //题目保证了target 严格递增
                dis = tar - currentItem;
                result.insert(result.end(), dis, "Push");
                result.insert(result.end(), dis, "Pop");
                currentItem = tar;
            }
            result.push_back("Push");
            ++currentItem;
        }
        return result;
    }
};
