#include <bits/stdc++.h>

using namespace std;


long long s, e, cnt[100001], arr[100001], ret;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	while (e < n) {
		// cnt �ߺ�üũ�� �ϴ� �迭�� 0�϶� �� �ߺ��� �ƴҶ�
		if (!cnt[arr[e]]) {
			// üũ
			cnt[arr[e]]++;
			// ���� �ε���
			e++;
		}
		else {
			// üũ�� �ߴµ�, �������� �ߺ��̴� �̷��� e-s �Ѱ� �ᱹ ����Ǽ�
			ret += (e - s);
			// 1 2 3 1 �̸� s �� ������ �������Ѽ� 1������ �ߺ��� ���ٰ��̱� ������
			cnt[arr[s]]--;
			s++;
		}
	}
	// e�� ������ ������
	// 1 2 3 1 2 �ε�, s�� 3�̰� e�� 2 �ϱ� 3 1 2 
	// 3 1 2�� ����� ���� ��������   3 1 2  31 12 312   3*4/2
	ret += (long long)(e - s) * (e - s + 1) / 2; // ���������� ��

	cout << ret;


	return 0;
}