#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1668. 最大重复子字符串
https://leetcode.cn/problems/maximum-repeating-substring/
*/

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if (sequence.size() < word.size()) {
            return 0;
        }
        int maxK = 0;
        int curK = 0;
        bool isNew = true;
        bool isEqu = true;
        int j = 0;
        int curI = 0;
        for (int i = 0; i < sequence.size();) {
            if (isNew) {
                j = i;
                isEqu = true;
                for (auto ch : word) {
                    if (ch != sequence[j++]) {
                        isEqu = false;
                        break;
                    }
                }
                if (isEqu) {
                    curI = i;
                    curK = 1;
                    i = j;
                    if (curK > maxK) {
                        maxK = curK;
                    }
                    isNew = false;
                }
                else {
                    ++i;
                }
            }
            else {
                //进入连续状态
                j = i;
                isEqu = true;
                for (auto ch : word) {
                    if (ch != sequence[j++]) {
                        isEqu = false;
                        break;
                    }
                }
                if (isEqu) {
                    ++curK;
                    i = j;
                    if (curK > maxK) {
                        maxK = curK;
                    }
                }
                else {
                    //退出连续状态
                    i = curI + 1;
                    curK = 0;
                    isNew = true;
                }
            }
        }
        return maxK;
    }
};
