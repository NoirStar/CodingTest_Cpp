#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, a, b;
	cin >> n;

	vector<pair<int, int>> vCow(n);
	for (int i = 0; i < n; i++) {
		// 도착시간, 검문시간
		cin >> a >> b;
		vCow[i] = { a, b };
	}	
	
	sort(vCow.begin(), vCow.end());

	int nTime = vCow[0].first;
	for (int i = 0; i < n; i++) {
		if (nTime < vCow[i].first) {
			nTime = vCow[i].first + vCow[i].second;
		}
		else {
			nTime += vCow[i].second;
		}
	}
	cout << nTime;

	return 0;
}