#include "common.h"

#include "901.hpp"

int main() {
	{
		StockSpanner s;
		cout << s.next(100) << endl;
		cout << s.next(80) << endl;
		cout << s.next(60) << endl;
		cout << s.next(70) << endl;
		cout << s.next(60) << endl;
		cout << s.next(75) << endl;
		cout << s.next(85) << endl;
	}
	{
		StockSpanner s;
		cout << s.next(29) << endl;
		cout << s.next(91) << endl;
		cout << s.next(62) << endl;
		cout << s.next(76) << endl;
		cout << s.next(51) << endl;
	}
	return 0;
}