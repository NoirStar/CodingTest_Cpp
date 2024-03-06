#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;

	int n, d, c;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> c;
		v.push_back({d, c});
	}

	// 오름차순으로 정렬
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		// min heap에 컵라면 저장
		pq.push(v[i].second);
		if (pq.size() > v[i].first) {
			pq.pop();
		}
	}

	int nSum = 0;
	
	while (pq.size()) {
		nSum += pq.top();
		pq.pop();
	}
	cout << nSum;

	return 0;
}