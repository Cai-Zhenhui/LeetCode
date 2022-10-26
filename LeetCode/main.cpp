#include "common.h"

#include "862.hpp"

int main() {
	

	{
		Solution s;
		vector<int> v={2,-1,2};
		s.shortestSubarray(v,3);
	}
	{
		Solution s;
		vector<int> v = { 2,-1,2 ,3,-2,9,5 };
		s.shortestSubarray(v,7);
	}
	{
		Solution s;
		vector<int> v = { 56,-21,56,35,-9 };
		s.shortestSubarray(v, 61);
	}
	return 0;
}