#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
784. 字母大小写全排列
https://leetcode.cn/problems/letter-case-permutation/
*/

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        int numLetter = 0;//字母数量
        vector<char> LI2CI;//字母顺序映射到字符顺序
        int i = 0;
        int j = 0;
        for (auto ch : s) {
            if (ch >= '0' && ch <= '9') {
                ;
            }
            else {
                //LI2CI[i++] = j;
                LI2CI.push_back(j);
                ++numLetter;
            }
            ++j;
        }
        int count = 1 << numLetter;
        vector<string> result(count, s);
        int temp;
        i = 0;
        for (auto& item : result) {
            if (i == 0) {
                ++i;
                continue;
            }
            
            //开始生成当前字符串
            // n = 4
            // 0 1 2 3
            // a 1 b 2
            //       1<<3
            temp = i;//遍历i的每一位 i共有numLetter位
            for (j = 0; j < numLetter; ++j) {
                //j 是字母顺序
                if (temp & (1 << j)) {
                    //交换
                    item[LI2CI[j]] ^= 0x20;
                }
            }
            ++i;
        }
        return result;
    }
};
