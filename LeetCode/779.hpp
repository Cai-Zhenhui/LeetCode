#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
779. 第K个语法符号
https://leetcode.cn/problems/k-th-symbol-in-grammar/
*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        //方法一 
        //n=1 对称相同
        //  2     相反
        //  3     相同
        //  4     相反
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
                    //奇数相同
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
