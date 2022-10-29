#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1773. 统计匹配检索规则的物品数量
https://leetcode.cn/problems/count-items-matching-a-rule/
*/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int result = 0;
        int index = 0;
        switch (ruleKey[0])
        {
        //case 't': {
        //    //type
        //    index = 0;
        //    break;
        //}
        case 'c': {
            //color
            index = 1;
            break;
        }
        case 'n': {
            //name
            index = 2;
            break;
        }
        }
        for (auto& item : items) {
            result += item[index] == ruleValue;
        }
        return result;
    }
};
