#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n+1, 1);
	vector<int> vPrime;
	v[1] = 0; // 1�� �Ҽ����ƴ�

	for (int i = 2; i <= sqrt(n); ++i) {
		if (v[i] == 0) continue;
		for (int j = i * i; j <= n; j += i) {
			v[j] = 0; // i�� ������ i�� ������� �Ҽ��� �ƴ�
		}
	}

	for (int i = 2; i < n + 1; i++) {
		if (v[i]) vPrime.push_back(i);
	}

	// n ������ �Ҽ����� �ٱ��߰� ���� �������� �̿��ؼ� ���ӵ� ���ڵ���
	int nSum = 0;
	int e = 0, nCount = 0;
	for (int s = 0; s < vPrime.size(); s++) {
		// end �� �ɶ����� ����
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