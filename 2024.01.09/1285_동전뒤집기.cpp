#include <bits/stdc++.h>

using namespace std;
int n, nRet = 987654321;
vector<int> vCoin;
// �ุ ������ ���� �����ش� �������ִ�.
// T-1 H-0

void go(int here) {
	
	// �������� �Դٸ�, ���� �ѹ� üũ�غ���.
	if (here == n + 1) {
		// �� üũ
		int nSum = 0;
		// i ��  100 010 001  ��Ʈ����ũ �Ųٷ� 1 2 4
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
			// �޸� ī��Ʈ
			int nCount = 0;
			// ��üũ
			for (int j = 1; j <= n; j++) {
				if (vCoin[j] & i) nCount++;
			}
			// ��������, �ȵ����°� �� �޸��� �ּҰ�
			nSum += min(nCount, n - nCount);
		}
		// ���� ����Ǽ��� �޸��� �� �ּҰ� ��
		nRet = min(nRet, nSum);
		return;
	}

	// ���� �ϳ��� �̵��ϸ鼭 (������+1)  �����°��, �ȵ����°�� �ΰ����� ����
	// �ȵ����� ���
	go(here + 1);
	// �����°��
	vCoin[here] = ~vCoin[here];
	go(here + 1);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> n;
	vCoin.assign(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int value = 1;
		// HHT �� ��Ʈ����ŷ�� �Ųٷ� ����   124 �ڸ���, T�� 1  => 4
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'T') vCoin[i] |= value;
			value *= 2;
		}
	}

	go(1);
	cout << nRet;

	return 0;
}