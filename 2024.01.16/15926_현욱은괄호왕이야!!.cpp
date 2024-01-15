#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	stack<int> sAns;
	vector<int> vAns(200001, 0);
	string s;
	cin >> s;

	// (())) => 11110 �� ���� �迭�� �����Ѵ�. ������ 1 ������ 0

	for (int i = 0; i < n; i++) {
		// ( ������ push �ؼ� ī�����Ѵ�.
		if (s[i] == '(') sAns.push(i);
		// ) �� �԰� ����� ������, pop�� �Ѵ�. (¦�� �´� ��ȣ�� ����)
		else if (sAns.size()) {
			vAns[i] = 1;
			vAns[sAns.top()] = 1;
			sAns.pop();
		}
	}

	int nCount = 0, nMax = 0;
	for (int i = 0; i < n; i++) {
		if (vAns[i]) {
			nCount++;
			nMax = max(nMax, nCount);
		}
		else {
			nCount = 0;
		}
	}

	cout << nMax;

	return 0;
}