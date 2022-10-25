#include "common.h"

#include "934.hpp"

int main() {
	{
		Solution s;
		vector<vector<int>> g = {
			{0,1,0,0,0,0,0},
			{1,1,1,1,0,0,1},
			{1,0,0,1,0,1,1},
			{1,1,1,1,0,0,0},
			{0,1,1,0,0,0,0},
			{0,1,0,0,0,0,0},
			{0,1,0,0,0,0,0},
		};
		s.shortestBridge(g);
        for (auto& row : g) {
            for (auto& item : row) {
				cout << item << " ";
            }
			cout << endl;
        }
	}
	return 0;
}