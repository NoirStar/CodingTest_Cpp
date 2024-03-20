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
		// i���� j�� ��� Ž���ϸ鼭, i�� ���������ҷ� �ϴ� LIS (����������ϴ� �κм���)
		for (int j = 0; j < i; ++j) {
			// ���Ұ� ũ��, ���̰� �� ��� �� �� �ִٸ� �߰��ؾ���
			if (v[j] < v[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				prev[i] = j;
				// �߰��� �ε����� �����Ѵ�. ���߿� ���� �̱����ؼ�

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