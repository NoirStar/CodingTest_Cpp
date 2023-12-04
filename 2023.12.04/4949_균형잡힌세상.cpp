#include <bits/stdc++.h>

using namespace std;

int main() {
	string strInput;
	vector<string> vRet;
	for (;;) {
		getline(cin, strInput);
		if (strInput == ".") break;
		
		stack<char> sComp;
		bool bBalance = true;
		for (const auto& c : strInput) {
			if (c == '(' || c == '[') {
				sComp.push(c);
			}
			else if(c == ')') {
				if (sComp.empty() || sComp.top() != '(') {
					bBalance = false;
					break;
				}
				sComp.pop();
			}
			else if (c == ']') {
				if (sComp.empty() || sComp.top() != '[') {
					bBalance = false;
					break;
				}
				sComp.pop();
			}
		}
		if (!sComp.empty()) bBalance = false;
		bBalance ? vRet.push_back("yes") : vRet.push_back("no");
	}	

	for (const auto& str : vRet) cout << str << '\n';


	return 0;
}