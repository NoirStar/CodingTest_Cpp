#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long a, b;
	int c, nRet = -1;

	cin >> a >> b;
	
	queue<pair<long long, int>> q;
	q.push({a, 1});

	while (!q.empty()) {
		long long na = q.front().first;
		c = q.front().second;
		q.pop();

		if (na == b) {
			nRet = c;
			break;
		}

		if (b >= na * 2) {
			q.push({ na * 2, c + 1 });
		}
		if (b >= na *10 +1) {
			q.push({ na * 10 + 1, c + 1 });
		}
	}

	cout << nRet;

	return 0;
}