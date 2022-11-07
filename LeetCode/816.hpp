#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
816. 模糊坐标
https://leetcode.cn/problems/ambiguous-coordinates/
*/

class Solution {
public:
#ifdef _MY_LOCAL_
    Solution() {
        vector<string> TestCases{
            "(01234)",
            "(100)",
            "(00011)",
            "(0123)"
        };
        for (auto& tc : TestCases) {
            for (auto& i : ambiguousCoordinates(tc)) {
                cout << i << endl;
            }
        }
    }
#endif
    inline int FSM(int state, char in) {
        //保证 in 属于 {'.','0'...'9'}
        switch (state) {
        case -2: {
            if (in == '.') {
                return -1;
            }
            else if (in == '0') {
                return -2;
            }
            else {
                return 4;
            }
        }
        case -1: {
            //终结状态
            return -1;
        }
        case 0: {
            //初始状态
            if (in == '.') {
                return -1;
            }
            else if (in == '0') {
                return 1;
            }
            else {
                return 2;
            }
        }
        case 1: {
            if (in == '.') {
                return -3;
            }
            else {
                return -1;
            }
        }
        case 2: {
            if (in == '.') {
                return -3;
            }
            else {
                return 2;
            }
        }
        case -3: {
            if (in == '.') {
                return -1;
            }
            else if (in == '0') {
                return -3;
            }
            else {
                return 4;
            }
        }
        case 4: {
            if (in == '.') {
                return -1;
            }
            else if (in == '0') {
                return -2;
            }
            else {
                return 4;
            }
        }
        default:
            return -1;
        }
    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string> result;
        int n = s.size();
        string _;
        string __;
        string numleft;
        string numright;
        string _numleft;
        string _numright;
        int temp;
        //
        //0123...i...     n
        //(123..., ...456) 
        // 
        //left  [1,i)
        //right [i+2,n+1)
        for (int i = 2; i < n - 1; ++i) {
            _ = s;
            _.insert(i, ", ");
            //left  [1,i)
            numleft = _.substr(1, i - 1);
            //right [i+2,n+1)
            numright = _.substr(i + 2, n + 1 - (i + 2));

            //[1,i) [i+2,n+1)
            //[0,rightn)

            //for left
            //01234
            //1234
            for (int ileft = 0; ileft < numleft.size(); ++ileft) {
                _numleft = numleft;
                if (ileft > 0) {
                    _numleft.insert(ileft, 1, '.');
                }
                //check number
                temp = 0;
                for (auto& c : _numleft) {
                    temp = FSM(temp, c);
                }
                if (temp <= 0) {
                    continue;
                }

                //generate right
                //right [i+2,n+1)
                for (int iright = 0; iright < numright.size(); ++iright) {
                    _numright = numright;
                    if (iright > 0) {
                        _numright.insert(iright, 1, '.');
                    }
                    //check number
                    temp = 0;
                    for (auto& c : _numright) {
                        temp = FSM(temp, c);
                    }
                    if (temp > 0) {
                        __ = _;
                        if (ileft > 0) {
                            __.insert(1 + ileft, 1, '.');
                            if (iright > 0) {
                                __.insert(i + 2 + 1 + iright, 1, '.');
                            }
                        }
                        else {
                            if (iright > 0) {
                                __.insert(i + 2 + iright, 1, '.');
                            }
                        }
                        
                        result.push_back(__);
                        //cout << __ << endl;
                    }
                }
            }
        }
        return result;
    }
};
