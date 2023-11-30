#include <bits/stdc++.h>

using namespace std;

int main() {
	int nN, nM;
	cin >> nN >> nM;
	// 에라토스테네스의 체
	
	vector<int> vPrime(nM + 1, 1);
	vPrime[1] = 0; // 1은 소수가 아님

	for (int i = 2; i <= sqrt(nM); ++i) {
		if (vPrime[i] != 1) continue;
		for (int j = i * i; j <= nM; j += i) {
			vPrime[j] = 0; // i를 제외한 i의 배수들은 소수가 아님
		}
	}

	// 출력
	for (int i = nN; i <= nM; i++) {
		if (vPrime[i] == 1) {
			cout << i << '\n';
		}
	}

	return 0;
}