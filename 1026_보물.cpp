#include <bits/stdc++.h>

using namespace std;

int main() {
	int nArray;
	cin >> nArray;

	vector<pair<int, int>> vArrayA, vArrayB;

	for (int i = 0; i < nArray; i++) {
		int nTemp;
		cin >> nTemp;
		vArrayA.push_back(make_pair(i, nTemp));
	}

	for (int i = 0; i < nArray; i++) {
		int nTemp;
		cin >> nTemp;
		vArrayB.push_back(make_pair(i, nTemp));
	}

	sort(vArrayA.begin(), vArrayA.end(),
		[&](const pair<int, int>& n1, const pair<int, int>& n2) {
		int nBeforeSum = 0, nAfterSum = 0;
		for (int i = 0; i < nArray; i++) {
			if (i == n1.first) {
				nAfterSum += (n2.second * vArrayB[i].second);
			} else if (i == n2.first) {
				nAfterSum += (n1.second * vArrayB[i].second);
			} else {
				nAfterSum += (vArrayA[i].second * vArrayB[i].second);
			}
			nBeforeSum += (vArrayA[i].second * vArrayB[i].second);
		}
		if (nBeforeSum > nAfterSum) {
			return true;
		}
		else {
			return false;
		}
	});

	for (auto a : vArrayA) {
		cout << a.second << ' ';
	}
	cout << endl;

	int nSum = 0;
	for (int i = 0; i < nArray; i++) {
		nSum += (vArrayA[i].second * vArrayB[i].second);
	}
	cout << nSum;

	return 0;
}

/*


예제 입력 1
5
1 1 1 6 0
2 7 8 3 1
예제 출력 1
18

*/