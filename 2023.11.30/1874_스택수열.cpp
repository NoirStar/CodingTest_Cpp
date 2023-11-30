#include <bits/stdc++.h>

using namespace std;

int main() {
	int nCount;
	cin >> nCount;
	vector<int> vCount(nCount);
	stack<int> sRet;
	vector<char> vRetPrint;
	
	for (int i = 0; i < nCount; i++) {
		cin >> vCount[i];
	}

	int nIdx = 1;
	for (const auto& c : vCount) {
		bool bFind = false;

		while (true) {
			if (nIdx < c) {
				sRet.push(nIdx);
				vRetPrint.push_back('+');
				nIdx++;
			}
			else if (nIdx == c) {
				sRet.push(nIdx);
				vRetPrint.push_back('+');
				nIdx++;
				sRet.pop();
				vRetPrint.push_back('-');
				bFind = true;
				break;
			}
			else {
				if (sRet.size() == 0) break;
				if (sRet.top() == c) {
					sRet.pop();
					vRetPrint.push_back('-');
					bFind = true;
					break;
				}
				sRet.pop();
				vRetPrint.push_back('-');
			}
		};
		if (bFind == false) {
			cout << "NO";
			return 0;
		}
	}

	for (const auto& c : vRetPrint) {
		cout << c << '\n';
	}

	return 0;
}