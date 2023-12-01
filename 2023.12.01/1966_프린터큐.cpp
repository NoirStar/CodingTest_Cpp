#include <bits/stdc++.h>

using namespace std;

int main() {
	int nPrint, nPrimary, nOrder ,nPrintCount;
	cin >> nPrint;
	vector<int> vRet;
	
	for (int i = 0; i < nPrint; i++) {
		priority_queue <int> pqPrint;
		queue<pair<int, int>> qPrint;
		
		cin >> nPrintCount >> nOrder;
		for (int j = 0; j < nPrintCount; j++) {
			cin >> nPrimary;
			qPrint.push(make_pair(nPrimary, j));
			pqPrint.push(nPrimary);
		}

		int nCount = 0;
		while (!qPrint.empty()) {
			auto aTemp = qPrint.front();
			qPrint.pop();

			if (pqPrint.top() == aTemp.first) {
				pqPrint.pop();
				nCount++;
				if (aTemp.second == nOrder) {
					vRet.push_back(nCount);
					break;
				}
			}
			else {
				qPrint.push(aTemp);
			}
		}
	}

	for (const auto& r : vRet) {
		cout << r << '\n';
	}

	return 0;
}