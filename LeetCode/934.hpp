#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
934. 最短的桥
https://leetcode.cn/problems/shortest-bridge/
*/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>>buffer;
        list<pair<int, int>>currentBuffer;
        list<pair<int, int>>nextBuffer;
        //寻找第一个1
        int i = 0, j = 0;
        int result = 0;
        for (auto& row : grid) {
            j = 0;
            for (auto& item : row) {
                if (item) {
                    item = -1;
                    buffer.push({ i,j });
                    currentBuffer.push_back({ i,j });
                    goto __end;
                }
                ++j;
            }
            ++i;
        }
    __end:

        while (!buffer.empty()) {
            auto pos = buffer.front();
            buffer.pop();
            //左侧
            i = pos.first;
            j = pos.second - 1;
            if (j >= 0) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    buffer.push({ i,j });
                    currentBuffer.push_back({ i,j });
                }
            }
            //上侧
            i = pos.first - 1;
            j = pos.second;
            if (i >= 0) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    buffer.push({ i,j });
                    currentBuffer.push_back({ i,j });
                }
            }
            //右侧
            i = pos.first;
            j = pos.second + 1;
            if (j < grid[0].size()) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    buffer.push({ i,j });
                    currentBuffer.push_back({ i,j });
                }
            }
            //下侧
            i = pos.first + 1;
            j = pos.second;
            if (i < grid.size()) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    buffer.push({ i,j });
                    currentBuffer.push_back({ i,j });
                }
            }
        }
        //此时currentBuffer中存放的就是找到的岛的所有坐标
        //开始广度优先遍历 寻找另外一座岛

        list<pair<int, int>>* p = &currentBuffer;
        list<pair<int, int>>* q = &nextBuffer;
        while (true) {
            for (auto& pos : *p) {
                //左侧
                i = pos.first;
                j = pos.second - 1;
                if (j >= 0) {
                    if (grid[i][j] == 1) {
                        return result;
                    }
                    else if (grid[i][j] == 0) {
                        grid[i][j] = -2;
                        q->push_back({ i,j });
                    }
                }
                //上侧
                i = pos.first - 1;
                j = pos.second;
                if (i >= 0) {
                    if (grid[i][j] == 1) {
                        return result;
                    }
                    else if (grid[i][j] == 0) {
                        grid[i][j] = -2;
                        q->push_back({ i,j });
                    }
                }
                //右侧
                i = pos.first;
                j = pos.second + 1;
                if (j < grid[0].size()) {
                    if (grid[i][j] == 1) {
                        return result;
                    }
                    else if (grid[i][j] == 0) {
                        grid[i][j] = -2;
                        q->push_back({ i,j });
                    }
                }
                //下侧
                i = pos.first + 1;
                j = pos.second;
                if (i < grid.size()) {
                    if (grid[i][j] == 1) {
                        return result;
                    }
                    else if (grid[i][j] == 0) {
                        grid[i][j] = -2;
                        q->push_back({ i,j });
                    }
                }
            }
            //清除p buffer,交换pg
            p->clear();
            auto temp = p;
            p = q;
            q = temp;
            ++result;
        }
        return 0;
    }
};
