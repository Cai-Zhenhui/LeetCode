#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
901. ��Ʊ�۸���
https://leetcode.cn/problems/online-stock-span/
*/

class StockSpanner {
public:
    vector< unsigned short> data;
    StockSpanner() {
    }

    int next(int price) {
        //����һ ����
        data.push_back(price);
        auto it = data.rbegin();
        for (++it; it != data.rend() && (*it) <= price; ++it);
        return it - data.rbegin();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
