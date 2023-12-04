#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nCount;
	cin >> nCount;

	if (nCount == 0) {
		cout << 0;
		return 0;
	}

	vector<int> vCount(nCount);
	for (int i = 0; i < nCount; i++) {
		cin >> vCount[i];
	}
	sort(vCount.begin(), vCount.end());

	int nException = round(nCount * 0.15);

	int nAvg = 0;
	for (int i = nException; i < nCount - nException; i++) {
		nAvg += vCount[i];
	}
	nAvg = round(nAvg / (nCount - nException * 2.0));
	cout << nAvg;

	return 0;
}