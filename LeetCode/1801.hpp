#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1801. 积压订单中的订单总数
https://leetcode.cn/problems/number-of-orders-in-the-backlog/
*/

class Solution {
public:
#ifdef _MY_LOCAL_
	Solution() {
		/*vector<vector<int>> orders{
			{10,5,0},
			{15,2,1},
			{25,1,1},
			{30,4,0}
		};*/
		/*vector<vector<int>> orders{
			{7,1000000000,1},
			{15,3,0},
			{5,999999995,0},
			{5,1,1}
		};*/
		vector<vector<int>> orders{
			{1,29,1},{22,7,1},{24,1,0},{25,15,1},{18,8,1},{8,22,0},{25,15,1},{30,1,1},{27,30,0}
		};
		getNumberOfBacklogOrders(orders);
	}
#endif
	int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
		map<int, int, less<int>> sellOrders;
		map<int, int, greater<int>> buyOrders;
		for (auto& order : orders) {
			if (order[2] == 0) {
				//buy
				while (order[1] > 0 && !sellOrders.empty()) {
					//printf("SO %dx%d\n", (*sellOrders.begin()).first, (*sellOrders.begin()).second);
					//printf("NO %dx%d\n", order[0], order[1]);
					if ((*sellOrders.begin()).first <= order[0]) {
						//printf("Sell\n\n");
						if (order[1] < (*sellOrders.begin()).second) {
							(*sellOrders.begin()).second -= order[1];
							order[1] = 0;
						}
						else {
							//
							order[1] -= (*sellOrders.begin()).second;
							sellOrders.erase(sellOrders.begin());
						}
					}
					else {
						break;
					}
				}
				if (order[1] > 0) {
					buyOrders[order[0]] += order[1];
				}
			}
			else {
				//sell
				while (order[1] > 0 && !buyOrders.empty()) {
					if ((*buyOrders.begin()).first >= order[0]) {
						if (order[1] < (*buyOrders.begin()).second) {
							(*buyOrders.begin()).second -= order[1];
							order[1] = 0;
						}
						else {
							//
							order[1] -= (*buyOrders.begin()).second;
							buyOrders.erase(buyOrders.begin());
						}
					}
					else {
						break;
					}
				}
				if (order[1] > 0) {
					sellOrders[order[0]] += order[1];
				}
			}
		}
		int result = 0;
		for (auto& order : sellOrders) {
			result += order.second;
			result %= 1000000007;
		}
		for (auto& order : buyOrders) {
			result += order.second;
			result %= 1000000007;
		}
		return result;
	}
};
