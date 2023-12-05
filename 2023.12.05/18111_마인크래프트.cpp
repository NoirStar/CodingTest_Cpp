#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nRow, nCol, nInven;

	cin >> nRow >> nCol >> nInven;

	vector<vector<int>> vBlock(nRow, vector<int>(nCol, 0));

	int nMax = 0, nMin = 0;
	for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			cin >> vBlock[i][j];
			if (i == 0 && j == 0) {
				nMax = vBlock[i][j];
				nMin = vBlock[i][j];
			}
			else {
				nMax = max(nMax, vBlock[i][j]);
				nMin = min(nMin, vBlock[i][j]);
			}
		}
	}
	
	vector<pair<int, int>> vRet;

	for (int h = nMin; h <= nMax; h++) {
		int nPlus = 0, nMinus = 0;
		int nInvenTemp = nInven;

		for (int i = 0; i < nRow; i++) {
			for (int j = 0; j < nCol; j++) {
				// 뺐을때 마이너스면, 만들어야할 h보다 높으니까 *2
				// 뺐을때 플러스는 만들어야할 h 보다 낮으니까 그냥 인벤에서 빼면됨
				// 일단 인벤토리 고려안하고 다 쓴다음에 인벤토리가 마이너스면 break
				if (h > vBlock[i][j]) {
					nInvenTemp -= (h - vBlock[i][j]);
					nPlus += (h - vBlock[i][j]);
				}
				else if (h < vBlock[i][j]) {
					nInvenTemp += (vBlock[i][j] - h);
					nMinus += (vBlock[i][j] - h);
				}
			}
		}
		if (nInvenTemp >= 0) {
			vRet.push_back(make_pair(nPlus + nMinus * 2, h));
		}	
	}

	sort(vRet.begin(), vRet.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
		if (p1.first == p2.first) {
			return p1.second > p2.second;
		}
		return p1.first < p2.first;
	});

	cout << vRet[0].first << ' ' << vRet[0].second;

	return 0;
}