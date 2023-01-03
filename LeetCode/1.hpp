#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1. 两数之和
https://leetcode.cn/problems/two-sum/
*/

class Solution {
public:
#ifdef _MY_LOCAL_
	Solution() {

	}
#endif
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		int i = 0;
		auto it = m.end();
		for (auto& item : nums) {
			it = m.find(target - item);
			if (it != m.end()) {
				//存在 nums[i]+nums[j] = target
				return { (*it).second,i };
			}
			else {
				m[item] = i++;
			}
		}
		return { 0,0 };
	}
};
