#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1704. ÅÐ¶Ï×Ö·û´®µÄÁ½°ëÊÇ·ñÏàËÆ
https://leetcode.cn/problems/determine-if-string-halves-are-alike/
*/

class Solution {
public:
#ifdef _MY_LOCAL_
    Solution() {
    }
#endif
    bool halvesAreAlike(string s) {
        int cnt = 0;
        int i = 0;
        int n = s.size() >> 1;
        for (auto c : s) {
            switch (c & 0xDF) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U': {
                if (i < n) {
                    ++cnt;
                }
                else {
                    if (--cnt < 0) {
                        return false;
                    }
                }
                break;
            }
            default:
                break;
            }
            ++i;
        }
        return cnt == 0;
    }
};
