#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	const int n = 4;
	string a[n] = { "���", "����", "��", "��" };

	// n���� ������ ����? �� �ƴ϶� ���� 0000 ���� 1111 ���� ���ڴٴ� �ǹ�.
	for (int i = 0; i < (1 << n); i++) {
		string ret = "";
		for (int j = 0; j < n; j++) {
			// ���ư��� i�� and ������ ���ؼ� ����� ���� ����Ѵ�.
			// ���� i�� 1100 �̶��   1 << j �� ���� �Ѻ�Ʈ �����ؼ� �����ִ��� Ȯ���Ѵ�.
			if (i & (1 << j)) {
				ret += a[j] + " ";
			}
		}
		cout << ret << '\n';
	}

	return 0;
}