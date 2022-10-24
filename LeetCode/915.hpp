#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
915. 分割数组
https://leetcode.cn/problems/partition-array-into-disjoint-intervals/
*/

class Solution {
public:
	int partitionDisjoint(vector<int>& nums) {
		////方法一  超时
		//for (int i = 1; i < nums.size(); ++i) {
		//	//0 - 1 
		//	int lmax = 0;
		//	for (int j = 0; j < i; ++j) {
		//		if (nums[j] > lmax) {
		//			lmax = nums[j];
		//		}
		//	}
		//	//1 - n
		//	int rmin = 0x7fffffff;
		//	for (int j = i; j < nums.size(); ++j) {
		//		if (nums[j] < rmin) {
		//			rmin = nums[j];
		//		}
		//	}
		//	if (lmax <= rmin) {
		//		return i;
		//	}
		//}

		//方法二
		int result = 1;
		int lmax = nums[0];
		int rmin = 0x7fffffff;
		int rmini = 0;

		for (result = 1; result < nums.size();) {
			if (lmax > nums[result]) {
				//左边要尽可能短，所以这里要严格大于
				//分割线右移
				++result;
				continue;
			}
			//找到最小值
			rmin = 0x7fffffff;
			rmini = 0;
			for (int i = result; i < nums.size(); ++i) {
				if (nums[i] < rmin) {
					rmin = nums[i];
					rmini = i;
				}
			}
			if (lmax <= rmin) {
				return result;
			}
			//检查是否需要更新最大值
			for (int i = result; i < rmini; ++i) {
				if (nums[i] > lmax) {
					lmax = nums[i];
				}
			}
			//移动分割线
			result = rmini;
		}
		return 1;
	}
};
