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
		// pay�� ���� �ּ����� �����
		pq.push(v[i].second);

		// d ���� �ƴ϶� d�Ͼȿ� ���ָ� �ȴٴ� ����.
		// ��·�� ��� �ϼ��� ä�����ϴϱ�, �ϼ��� �Ѿ���� �ּҸ� ����.
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