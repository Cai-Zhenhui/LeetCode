#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
784. ��ĸ��Сдȫ����
https://leetcode.cn/problems/letter-case-permutation/
*/

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        int numLetter = 0;//��ĸ����
        vector<char> LI2CI;//��ĸ˳��ӳ�䵽�ַ�˳��
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
            
            //��ʼ���ɵ�ǰ�ַ���
            // n = 4
            // 0 1 2 3
            // a 1 b 2
            //       1<<3
            temp = i;//����i��ÿһλ i����numLetterλ
            for (j = 0; j < numLetter; ++j) {
                //j ����ĸ˳��
                if (temp & (1 << j)) {
                    //����
                    item[LI2CI[j]] ^= 0x20;
                }
            }
            ++i;
        }
        return result;
    }
};
