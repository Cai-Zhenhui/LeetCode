#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
779. ��K���﷨����
https://leetcode.cn/problems/k-th-symbol-in-grammar/
*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        //����һ 
        //n=1 �Գ���ͬ
        //  2     �෴
        //  3     ��ͬ
        //  4     �෴
        int temp;
        bool isNot = false;
        while (n > 1) {
            temp = 1 << (n - 1);
            if (k <= temp / 2) {
                //--n;
            }
            else {
                k = temp - k + 1;
                if(n % 2) {
                    //������ͬ
                    isNot;
                }
                else {
                    isNot = !isNot;
                }
            }
            --n;
        }
        return isNot;
    }
};
