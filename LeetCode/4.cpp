#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
4. 寻找两个正序数组的中位数
https://leetcode.cn/problems/median-of-two-sorted-arrays/
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ////方法一 最直接的想法
        //int length = nums1.size() + nums2.size();
        //int midIndex = (nums1.size() + nums2.size()) / 2;
        //int i1 = 0;
        //int i2 = 0;
        //vector<int>* pNum = NULL;
        //vector<int>* pNum2 = NULL;
        //int ii = 0;
        //int ii2 = 0;
        //if (nums1.size() == 0) {
        //    if (length % 2) {
        //        return nums2[midIndex];
        //    }
        //    else {
        //        return double(nums2[midIndex - 1] + nums2[midIndex]) / 2;
        //    }
        //}
        //if (nums2.size() == 0) {
        //    if (length % 2) {
        //        return nums1[midIndex];
        //    }
        //    else {
        //        return double(nums1[midIndex - 1] + nums1[midIndex]) / 2;
        //    }
        //}

        //for (int i = 0; i <= midIndex; ++i) {
        //    if (i1 >= nums1.size()) {
        //        //num1 结束
        //        ii2 = ii;
        //        ii = i2;
        //        pNum2 = pNum;
        //        pNum = &nums2;

        //        ++i2;
        //        continue;
        //    }
        //    if (i2 >= nums2.size()) {
        //        ii2 = ii;
        //        ii = i1;
        //        pNum2 = pNum;
        //        pNum = &nums1;

        //        ++i1;
        //        continue;
        //    }
        //    if (nums1[i1] <= nums2[i2]) {
        //        ii2 = ii;
        //        ii = i1;
        //        pNum2 = pNum;
        //        pNum = &nums1;

        //        ++i1;
        //    }
        //    else {
        //        ii2 = ii;
        //        ii = i2;
        //        pNum2 = pNum;
        //        pNum = &nums2;

        //        ++i2;
        //    }
        //}
        //if (length % 2) {
        //    //奇数
        //    return pNum->operator[](ii);
        //}
        //else {
        //    return double(pNum2->operator[](ii2) +pNum->operator[](ii))/2;
        //}
        
        //方法二 
        if (nums1.size() == 0) {
            if (nums2.size() % 2) {
                return nums2[nums2.size() / 2];
            }
            else {
                return double(nums2[nums2.size() / 2 - 1] + nums2[nums2.size() / 2]) / 2;
            }
        }
        if (nums2.size() == 0) {
            if (nums1.size() % 2) {
                return nums1[nums1.size() / 2];
            }
            else {
                return double(nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) / 2;
            }
        }

        vector<int>* _nums1 = &nums1;
        vector<int>* _nums2 = &nums2;
        if (_nums1->size() > _nums2->size()) {
            auto temp = _nums1;
            _nums1 = _nums2;
            _nums2 = temp;
        }
        int left = 0;
    }
};
