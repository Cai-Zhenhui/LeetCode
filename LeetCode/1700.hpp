#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1700. 无法吃午餐的学生数量
https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        ////方法一 最直接的想法
        //int remain = 0;
        //do {
        //    remain = students.size();
        //    for (int i = 0; i < remain; ++i) {
        //        if (students[0] == sandwiches[0]) {
        //            students.erase(students.begin());
        //            sandwiches.erase(sandwiches.begin());
        //        }
        //        else {
        //            students.push_back(students[0]);
        //            students.erase(students.begin());
        //        }
        //    }
        //} while (students.size() != 0 && students.size() < remain);
        //return students.size();
        
        //方法二
        int like[2] = { 0 };
        for (auto& _ : students) {
            ++like[_];
        }
        for (auto& _ : sandwiches) {
            if (like[_]--) {

            }
            else {
                return like[0] + like[1] + 1;
            }
        }
        return 0;
    }
};
