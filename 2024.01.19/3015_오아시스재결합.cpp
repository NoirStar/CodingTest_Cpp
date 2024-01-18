#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	// ¦����� �����̴� ����ϱ�
	// 3 2 1 5 | 3 8    ��ó�� ���̶� ¦�� �Ǵ� ���̵��� 5 ���� �����. �� ���Ĵ� ������ �ʿ�X
	// ���⼭ ���̵� �� ���� ū�� ������! � ����
	// ū 5�� �տ� ���� 3 2 1 �̶� ���ϸ� ��. �ֳ��ϸ� ū���� �ڿ� �����¼��� �� �ʿ� X����
	stack<pair<ll, ll>> s;
	ll nTemp, nRet = 0;
	for (int i = 0; i < n; i++) {
		cin >> nTemp;
		int nCount = 1;

		// ������ �� ���� ���ų� ������ ¦���Ⱑ��
		while (s.size() && s.top().first <= nTemp) {
			nRet += s.top().second; // count�� ����(��������)
			
			// ���� ���
			if (s.top().first == nTemp) {
				nCount = s.top().second + 1;
			}
			else {
				nCount = 1;
			}
			s.pop();
		}
		if (s.size()) nRet++;
		s.push({nTemp,nCount});
	}
	cout << nRet;
	
	return 0;
}