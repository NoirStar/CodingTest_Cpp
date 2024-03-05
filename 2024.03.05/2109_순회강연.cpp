#include<bits/stdc++.h>

using namespace std;

int main() {
	int n,day,pay;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		cin >> pay >> day;
		v.push_back({ day, pay });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		// pay의 값이 최소힙에 저장됨
		pq.push(v[i].second);

		// d 일이 아니라 d일안에 와주면 된다는 뜻임.
		// 어쨌든 모든 일수를 채워야하니까, 일수에 넘어간거중 최소를 뺀다.
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