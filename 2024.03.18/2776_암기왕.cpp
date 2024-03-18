#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, n, m, tmp;

	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<int> v1, v2;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			v1.push_back(tmp);
		}

		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			v2.push_back(tmp);
		}

		sort(v1.begin(), v1.end());
		
		for (auto n : v2) {
			// n이 등장하는 처음의 반복자를 리턴
			auto it = lower_bound(v1.begin(), v1.end(), n);
			if (it != v1.end()) {
				if (*it == n) cout << 1 << '\n';
				else cout << 0 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}