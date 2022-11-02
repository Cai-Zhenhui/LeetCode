#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1620. 网络信号最好的坐标
https://leetcode.cn/problems/coordinate-with-maximum-network-quality/
*/

//char m[51][51];

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        ////方法一 有问题
        //memset(m, 0, sizeof(m));
        //int i = 0;
        //int j = 0;
        //int x, y, q;
        //int d2;
        //int maxX = 0, maxY = 0, maxQ = 0;
        //int r2 = radius * radius;
        //for (auto& tower : towers) {
        //    x = tower[0];
        //    y = tower[1];
        //    q = tower[2];
        //    for (i = 0; i <= 50; ++i) {
        //        for (j = 0; j <= 50; ++j) {
        //            d2 = (x - i) * (x - i) + (y - j) * (y - j);
        //            if (d2 > r2) {
        //                continue;
        //            }
        //            m[i][j] += int(q / (1 + sqrt(d2)));
        //            if (m[i][j] > maxQ) {
        //                maxX = i;
        //                maxY = j;
        //                maxQ = m[i][j];
        //            }
        //        }
        //    }
        //}
        //return { maxX,maxY };

        //方法二
        int i = 0;
        int j = 0;
        int x, y, q;
        int d2;
        int maxX = 0, maxY = 0, maxQ = 0;
        int r2 = radius * radius;
        int _;
        for (i = 0; i <= 50; ++i) {
            for (j = 0; j <= 50; ++j) {
                _ = 0;
                for (auto& tower : towers) {
                    x = tower[0];
                    y = tower[1];
                    q = tower[2];
                    d2 = (x - i) * (x - i) + (y - j) * (y - j);
                    if (d2 > r2) {
                        continue;
                    }
                    _ += int(q / (1 + sqrt(d2)));
                }
                if (_ > maxQ) {
                    maxX = i;
                    maxY = j;
                    maxQ = _;
                }
            }
        }
        return { maxX,maxY };
    }
};
