#include <bits/stdc++.h>

using namespace std;

int n, nMin = 987654321;
vector<int> vPeople;
vector<int> vConnect;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	// �������� �α��� ����
	vPeople.assign(n+1, 0);
	vConnect.assign(n+1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> vPeople[i];
	}

	// ���������� ��Ʈ���ϸ���
	for (int i = 1; i <= n; i++) {
		int con;
		cin >> con;
		for (int j = 1; j <= con; j++) {
			int c;
			cin >> c;
			vConnect[i] |= (1 << (c-1));
		}
	}

	// �� ���ű��� �����µ�, 1���̻� �־���ϰ�  ������ ���鳢�� ������־���Ѵ�.

	// n=4 ��� 0001 ~ 1110 ���� ����. ���ʿ� ���Ƽ� �ִ°� �Ұ����ϹǷ�. ���� 1�̻�
	for (int i = 1; i < (1 << n) - 1; i++) {
		int a, b;
		a = i;
		b = ~i;

		int nPeopleA = 0, nPeopleB = 0;
		bool bGood = true;
		for (int j = 0; j < n; j++) {
			// �Ѻ�Ʈ�� �����ؼ� �������� üũ �� ��带 �˻�������, �ٸ� ��Ʈ�� �ִٸ� 
			if (a & (1 << j)) {
				// Ž���� ��Ʈ�� ���������� �ٸ� ���������� ����Ǿ��ִٸ�
				if ((a & vConnect[j + 1]) == 0 && a != (1 << j)) {
					bGood = false;
					break;
				}
				// �α��� ���
				nPeopleA += vPeople[j+1];
			}
			else {
				if ((b & vConnect[j+1]) == 0 && b != (1 << j)) {
					bGood = false;
					break;
				}
				nPeopleB += vPeople[j+1];
			}
		}
		if(bGood)
			nMin = min(nMin, abs(nPeopleA - nPeopleB));
	}

	if (nMin == 987654321)
		cout << -1;
	else 
		cout << nMin;

	return 0;
}
