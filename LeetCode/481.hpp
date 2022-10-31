#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
481. ÉñÆæ×Ö·û´®
https://leetcode.cn/problems/magical-string/
*/

char s[100004];
char cs[100004];
bool isFirst = true;

class Solution {
public:
    int magicalString(int n) {
        if (isFirst) {
            //generate
            int sn = 1;
            int csn = 1;
            int temp = 0;
            
            //   0 | 1 2 3
            //s  2 |
            //cs   | 1

            s[0] = 2;
            cs[1] = 1;
            while(sn<= 100001) {
                //   0 |    1   2 3
                //s  2 |(sn)    
                //cs   | 1(csn)    
                temp = 3 - s[sn - 1];
                if (cs[csn++] == 1) {
                    s[sn++] = temp;
                }
                else {
                    s[sn++] = temp;
                    s[sn++] = temp;
                }
                if (sn > csn) {
                    //   0 | 1  2   3
                    //s  2 | 1  2   2   (sn)
                    //cs   | 1  2   (csn)
                    cs[csn] = s[csn];
                }
                else {
                    //   0 | 1  2   3
                    //s  2 | 1  (sn)
                    //cs   | 1  (csn)
                    cs[csn] = 3 - s[csn - 1];
                }
            }
            isFirst = false;
        }

        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result += s[i] == 1;
        }
        return result;
    }
};
