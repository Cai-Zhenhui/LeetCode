#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
2042. �������е������Ƿ����
https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence/
*/

class Solution {
public:
#ifdef _MY_LOCAL_
	Solution() {
		this->areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles");
	}
#endif
	bool areNumbersAscending(string s) {
		int process = 0;
		int n = s.size();
		int num = 0;

		for (int i = 0; i < n;++i) {
			if ('0' <= s[i] && s[i] <= '9') {
				if (i < n - 1) {
					if ('0' <= s[i+1] && s[i+1] <= '9') {
						//��λ
						num = (s[i] - '0') * 10 + (s[i+1] - '0');
						++i;
					}
					else {
						//һλ
						num = s[i] - '0';
					}
				}
				else {
					//���һ�� һλ
					num = s[i] - '0';
				}
				if (num <= process) {
					return false;
				}
				process = num;
			}
		}
		
		return true;
	}
};
