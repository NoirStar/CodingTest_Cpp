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

	// a 위치에 따라 전깃줄 쌍을 정렬
	sort(v.begin(), v.end());

	vector<int> lis;

	// b에 대한 lis 생성
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