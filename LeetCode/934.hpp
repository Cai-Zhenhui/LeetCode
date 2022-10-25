#ifdef _MY_LOCAL_
#include "common.h"
#endif
/*
934. ��̵���
https://leetcode.cn/problems/shortest-bridge/
*/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>>buffer;
        list<pair<int, int>>currentBuffer;
        list<pair<int, int>>nextBuffer;
        //Ѱ�ҵ�һ��1
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
            //���
            i = pos.first;
            j = pos.second - 1;
            if (j >= 0) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    buffer.push({ i,j });
                    currentBuffer.push_back({ i,j });
                }
            }
            //�ϲ�
            i = pos.first - 1;
            j = pos.second;
            if (i >= 0) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    buffer.push({ i,j });
                    currentBuffer.push_back({ i,j });
                }
            }
            //�Ҳ�
            i = pos.first;
            j = pos.second + 1;
            if (j < grid[0].size()) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    buffer.push({ i,j });
                    currentBuffer.push_back({ i,j });
                }
            }
            //�²�
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
        //��ʱcurrentBuffer�д�ŵľ����ҵ��ĵ�����������
        //��ʼ������ȱ��� Ѱ������һ����

        list<pair<int, int>>* p = &currentBuffer;
        list<pair<int, int>>* q = &nextBuffer;
        while (true) {
            for (auto& pos : *p) {
                //���
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
                //�ϲ�
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
                //�Ҳ�
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
                //�²�
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
            //���p buffer,����pg
            p->clear();
            auto temp = p;
            p = q;
            q = temp;
            ++result;
        }
        return 0;
    }
};
