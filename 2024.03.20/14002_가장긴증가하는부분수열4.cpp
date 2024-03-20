#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n), dp(n, 1), prev(n, -1);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int maxLen = 1, lastIdx = 0;
	for (int i = 1; i < n; ++i) {
		// i까지 j가 계속 탐색하면서, i를 마지막원소로 하는 LIS (가장긴증가하는 부분수열)
		for (int j = 0; j < i; ++j) {
			// 원소가 크고, 길이가 더 길어 질 수 있다면 추가해야지
			if (v[j] < v[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				prev[i] = j;
				// 추가된 인덱스를 저장한다. 나중에 값을 뽑기위해서

				if (dp[i] > maxLen) {
					maxLen = dp[i];
					lastIdx = i;
				}
			}
		}
	}

	vector<int> lis;
	for (int i = lastIdx; i != -1; i = prev[i]) {
		lis.push_back(v[i]);
	}

	reverse(lis.begin(), lis.end());

	cout << maxLen << '\n';

	for (auto l : lis) {
		cout << l << ' ';
	}

	return 0;
}