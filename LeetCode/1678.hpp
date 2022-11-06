#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
1678. Éè¼Æ Goal ½âÎöÆ÷
https://leetcode.cn/problems/goal-parser-interpretation/
*/

char buffer[101];
class Solution {
public:
    string interpret(string command) {
        int n = command.size() - 1;
        int j = 0;
        int i = 0;
        for (; i < n; ++i) {
            switch (command[i]) {
            case '(': {
                if (command[i + 1] == ')') {
                    buffer[j++] = 'o';
                }
                else {
                    buffer[j++] = 'a';
                    buffer[j++] = 'l';
                }
                break;
            }
            case 'G': {
                buffer[j++] = 'G';
                break;
            }
            }
        }
        if (command[i] == 'G') {
            buffer[j++] = 'G';
        }
        buffer[j] = 0;
        return buffer;
    }
};
