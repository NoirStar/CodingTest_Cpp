#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, l;
	vector<pair<int, int>> v;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end());

	int nCnt = 0, end = 0;
	
	for (auto& p : v) {

		// ���� �������� ���� ������ �������̸� ���ƾ��ϹǷ�
		if (end < p.first) {
			end = p.first;
		}

		// �����̸� �������� ���� ���� ���
		while (end < p.second) {
			end += l;
			nCnt++;
		}
	}
	cout << nCnt;
	
	return 0;
}