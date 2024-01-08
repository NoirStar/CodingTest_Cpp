#include <bits/stdc++.h>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	
	int n;
	cin >> n;
	vector<int> vMin(4);
	vector<vector<int>> vFood(n, vector<int>(5,0));
	map<int, vector<vector<int>>> mRet;

	for (int i = 0; i < 4; i++) {
		cin >> vMin[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> vFood[i][j];
		}
	}
	int nMin = 987654321;
	vector<int> vSelect;
	// 0000 에서 1111까지
	for (int i = 0; i < (1 << n); i++) {
		// 한 비트씩 접근
		vector<int> vSum(5);
		vSelect.clear();
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				for (int k = 0; k < 5; k++) {
					vSum[k] += vFood[j][k];
				}
				vSelect.push_back(j + 1);
			}
		}
		
		bool bMin = true;
		for (int j = 0; j < 4; j++) {
			if (vSum[j] < vMin[j]) {
				bMin = false;
				break;
			}
		}

		// sum 값이 최소보다 작을때, 넣는다.
		if (bMin && (nMin >= vSum[4])) {
			nMin = vSum[4];
			mRet[nMin].push_back(vSelect);
		}
	}

	if (nMin != 987654321) {
		sort(mRet[nMin].begin(), mRet[nMin].end());
		cout << nMin << '\n';
		for (const auto& s : mRet[nMin][0]) {
			cout << s << ' ';
		}
	}
	else {
		cout << -1;
	}

	return 0;
}