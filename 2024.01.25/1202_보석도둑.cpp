#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,k;
	cin >> n >> k;
	// n ������ ���� ����, k ���濡 ������ �ִ� �ִ� ����. �ִ� 1��������������

	vector<pair<ll, ll>> vJu(n);
	vector<ll> vBag(k);
	
	for (int i = 0; i < n; i++) {
		cin >> vJu[i].first >> vJu[i].second;
	}

	for (int i = 0; i < k; i++) {
		cin >> vBag[i];
	}
	
	// ����, ���� ���Ը� �����ͺ��� ����
	sort(vJu.begin(), vJu.end());
	sort(vBag.begin(), vBag.end());
	priority_queue<ll> pq;

	// ���濡 �� ���ִ� ���԰� �����ź���
	// ���湫�Ժ��� �����鼭 ���� ��Ѱ�? �ϸ�ɵ�
	// ȿ�����̶��� �����϶�.
	// ���Ը� ���� ���� �� �ִ� ���濡 ���� �� �ִ� ������ �ٳ־������
	// �켱����ť�� �̿��ϸ�, ���濡 �� �ִ� 

	int j = 0;
	ll llRet = 0;
	// ���� ����ŭ
	for (int i = 0; i < k; i++) {
		// ���濡 ���� ���ִ� �����϶�
		while (j < n && vJu[j].first <= vBag[i]) {
			pq.push(vJu[j++].second);
		}
		// �� �־����� pq�� ������ �ֻ����� �ִ밪
		if (pq.size()) {
			llRet += pq.top();
			pq.pop();
		}
	}
	cout << llRet;

	return 0;
}