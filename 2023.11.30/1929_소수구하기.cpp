#include <bits/stdc++.h>

using namespace std;

int main() {
	int nN, nM;
	cin >> nN >> nM;
	// �����佺�׳׽��� ü
	
	vector<int> vPrime(nM + 1, 1);
	vPrime[1] = 0; // 1�� �Ҽ��� �ƴ�

	for (int i = 2; i <= sqrt(nM); ++i) {
		if (vPrime[i] != 1) continue;
		for (int j = i * i; j <= nM; j += i) {
			vPrime[j] = 0; // i�� ������ i�� ������� �Ҽ��� �ƴ�
		}
	}

	// ���
	for (int i = nN; i <= nM; i++) {
		if (vPrime[i] == 1) {
			cout << i << '\n';
		}
	}

	return 0;
}