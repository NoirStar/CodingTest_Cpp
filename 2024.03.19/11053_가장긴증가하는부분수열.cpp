#include <bits/stdc++.h>

using namespace std;

int LIS(const vector<int>& seq) {
	vector<int> lis;

	for (int x : seq) {
		// x �̻��� ��ġ�� ã�´�. �̺� Ž������ 
		auto it = lower_bound(lis.begin(), lis.end(), x);
		
		// ��ã�Ҵٴ°� x �� ��ũ�ٴ°��� �׷� �ǵڿ� �־��ش�.
		if (it == lis.end()) {
			lis.push_back(x);
		}
		// ã������ x�� �� �����ϱ� �� ū �ֶ� ��ȯ����
		else {
			// ������� 3 10 20 �̰� x �� 15���  20����ġ�� ã�� ��ȯ�Ѵ�.
			*it = x;
		}
	}
	return lis.size(); // �ִ� ���� �κ� ������ ũ��
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cout << LIS(v);

	return 0;
}