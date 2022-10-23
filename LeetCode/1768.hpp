#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1768. ½»ÌæºÏ²¢×Ö·û´®
https://leetcode.cn/problems/merge-strings-alternately/
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result(word1.size() + word2.size(), 'a');
        int k = 0;
        int i[2] = { 0 };
        string* refs[2] = { &word1,&word2 };
        for (auto& ch : result) {
            if (i[k % 2] < refs[k % 2]->size()) {
                ch = refs[k % 2]->operator[](i[k % 2]++);
            }
            else {
                ch = refs[(k + 1) % 2]->operator[](i[(k + 1) % 2]++);
            }
            ++k;
        }
        return result;
    }
};
