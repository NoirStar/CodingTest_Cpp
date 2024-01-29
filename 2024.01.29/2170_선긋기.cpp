#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, from, to, l, r;
	
	cin >> n;
	vector<pair<int, int>> vLine(n);

	// ��ġ�� ��� �����ؼ� �������� + ���ִ� ���
	// 2������ �ƴ϶� 1���������� �����ϸ��

	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		vLine[i] = { from, to };
	}

	sort(vLine.begin(), vLine.end());
	l = vLine[0].first;
	r = vLine[0].second;

	int nRet = 0;
	for (int i = 1; i < n; i++) {
		// ���������� ���� ���. ũ�� ������ ���������� ũ�� ��ġ�� ����
		if (r < vLine[i].first) {
			nRet += (r - l);
			// ���ο� ������ ����
			l = vLine[i].first;
			r = vLine[i].second;
		}
		// ������ �ִ� ���
		else if(vLine[i].first <= r && vLine[i].second >= r) {
			r = vLine[i].second; // ū������ ����
		} 
	}
	nRet += r - l;
	cout << nRet;

	return 0;
}

