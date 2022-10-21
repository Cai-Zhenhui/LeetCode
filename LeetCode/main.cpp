#include "common.h"

#include "4.hpp"

int main() {
	Solution solution;
	
	{
		vector<int> nums1{ 1,3 };
		vector<int> nums2{ 2 };
		cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
	}
	{
		vector<int> nums1{ 1,2 };
		vector<int> nums2{ 3,4 };
		cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
	}
	return 0;
}