#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}

	// a ��ġ�� ���� ������ ���� ����
	sort(v.begin(), v.end());

	vector<int> lis;

	// b�� ���� lis ����
	for (auto& x : v) {
		auto it = lower_bound(lis.begin(), lis.end(), x.second);
		
		if (it == lis.end()) {
			lis.push_back(x.second);
		}
		else {
			*it = x.second;
		}
	}

	cout << n-lis.size();
	return 0;
}