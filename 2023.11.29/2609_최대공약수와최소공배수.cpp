#include <bits/stdc++.h>

using namespace std;

// ��Ŭ���� ȣ����
int GetGcd(int a, int b) {
	if (a == 0) return b;
	return GetGcd(b % a, a);
}

int main() {
	int nA, nB, nGcd;
	cin >> nA >> nB;

	nGcd = GetGcd(nA, nB);
	
	cout << nGcd << '\n' << (nA * nB) / nGcd;
	return 0;
}

