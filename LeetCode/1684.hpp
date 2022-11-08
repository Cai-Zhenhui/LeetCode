#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1684. Count the Number of Consistent Strings
https://leetcode.cn/problems/count-the-number-of-consistent-strings/
*/



class Solution {
public:
#ifdef _MY_LOCAL_
    Solution() {
        vector<string> words{
            "ab",
            "ad"
        };
        this->countConsistentStrings("ab", words);
    }
#endif
    int countConsistentStrings(string allowed, vector<string>& words) {
        ////方法一 set
        //int result = 0;
        //bool isAllowed = true;
        //set<char>s;
        //for (auto& c : allowed) {
        //    s.insert(c);
        //}
        //for (auto& word : words) {
        //    isAllowed = true;
        //    for (auto& c : word) {
        //        auto it = s.find(c);
        //        if (it == s.end()) {
        //            isAllowed = false;
        //            break;
        //        }
        //    }
        //    result += isAllowed;
        //}
        //return result;
        
        //方法二 
        int result = 0;
        bool isAllowed = true;
        int s = 0;
        int temp;
        for (auto& c : allowed) {
            //s.insert(c);
            s |= 1 << (c - 'a');
        }
        for (auto& word : words) {
            isAllowed = true;
            for (auto& c : word) {
                temp = s & (1 << (c - 'a'));
                if (!temp) {
                    isAllowed = false;
                    break;
                }
            }
            result += isAllowed;
        }
        return result;
    }
};
