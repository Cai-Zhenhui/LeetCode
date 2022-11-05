#include "common.h"

#include "1106.hpp"

int main() {
	

	{
		Solution s;
		vector<string> tcs = {
			"!(&(f,t))",
			"&(&(&(!(&(f)),&(t),|(f,f,t)),|(t),|(f,f,t)),!(&(|(f,f,t),&(&(f),&(!(t),&(f),|(f)),&(!(&(f)),&(t),|(f,f,t))),&(t))),&(!(&(&(!(&(f)),&(t),|(f,f,t)),|(t),|(f,f,t))),!(&(&(&(t,t,f),|(f,f,t),|(f)),!(&(t)),!(&(|(f,f,t),&(&(f),&(!(t),&(f),|(f)),&(!(&(f)),&(t),|(f,f,t))),&(t))))),!(&(f))))",
			"!(&(&(!(&(f)),&(t),|(f,f,t)),&(t),&(t,t,f)))",
			 "!(f)",
			 "|(f,t)",
			 "&(t,f)",
			 "|(&(t,f,t),!(t))"
		};
		for (auto& tc : tcs) {
			cout<<s.parseBoolExpr(tc)<<endl;
		}
	}
	
	return 0;
}