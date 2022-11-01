#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1662. 检查两个字符串数组是否相等
https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent/
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0;
        int j = 0;
        for (auto& s : word2) {
            for (auto c : s) {
                if (j >= word1[i].size()) {
                    ++i;
                    j = 0;
                    if (i >= word1.size()) {
                        return false;
                    }
                }
                if (word1[i][j++] != c) {
                    return false;
                }
            }
        }
        return word1[i].size() == j;
    }
};
