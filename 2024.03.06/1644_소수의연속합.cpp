#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n+1, 1);
	vector<int> vPrime;
	v[1] = 0; // 1은 소수가아님

	for (int i = 2; i <= sqrt(n); ++i) {
		if (v[i] == 0) continue;
		for (int j = i * i; j <= n; j += i) {
			v[j] = 0; // i를 제외한 i의 배수들은 소수가 아님
		}
	}

	for (int i = 2; i < n + 1; i++) {
		if (v[i]) vPrime.push_back(i);
	}

	// n 이하의 소수들은 다구했고 이제 투포인터 이용해서 연속된 숫자덧셈
	int nSum = 0;
	int e = 0, nCount = 0;
	for (int s = 0; s < vPrime.size(); s++) {
		// end 를 될때까지 증가
		while (nSum < n && e < vPrime.size()) {
			nSum += vPrime[e];
			e++;
		}
		if (nSum == n) nCount++;
		nSum -= vPrime[s];
	}

	cout << nCount;

	return 0;
}