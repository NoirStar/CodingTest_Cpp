#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	priority_queue<float,vector<float>, greater<float>> pqRet;
	for (int i = 0; i < n; i++) {
		float tmp;
		cin >> tmp;
		pqRet.push(tmp);
	}

	for (int i = 0; i < 7; i++) {
		cout.setf(ios::showpoint);
		cout << fixed;
		cout.precision(3);
		cout << pqRet.top() << '\n';
		pqRet.pop();
	}

	return 0;
}

