#include <bits/stdc++.h>

using namespace std;

int main() {
	int nTest;
	string strPattern, strInput;
	cin >> nTest;
	cin >> strPattern;

	// 누적합으로 풀수있는 방법?
	int nStarIdx = strPattern.find('*');
	string strPre = strPattern.substr(0, nStarIdx);
	string strSuf = strPattern.substr(nStarIdx + 1);

	for (int i = 0; i < nTest; i++) {
		cin >> strInput;
	
		if (strPre.size() + strSuf.size() > strInput.size()) {
			cout << "NE" << '\n';
		}
		else {
			if(strPre == strInput.substr(0, nStarIdx) && 
				strSuf == strInput.substr(strInput.size() - strSuf.size())) {
				cout << "DA" << '\n';
			}
			else {
				cout << "NE" << '\n';
			}
		}
	}
	return 0;
}