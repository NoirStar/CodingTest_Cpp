#include <bits/stdc++.h>

using namespace std;

// n ���̵��� �� , m ����
long long n, m, highJ = 0, lowJ = 1, midJ;
long long minJ = numeric_limits<long long>::max();

long long v[300001];

// ���� Ž���� �̿�. �־��� ���� �ȿ��� ������ �����ϴ� ���� �ظ� ���ϴ� �����ϱ� 
// ����Ž���� ������ �� ����

// �л��鿡�� � �� ��ŭ(maxPerStudent) �����ָ� �� ������ �� �ִ��� �˻�
bool IsDistribution(long long maxPerStudent) {
	int reqStudent = 0;
	for (long long i = 0; i < m; i++) {
		// �׻� ���� ���� �������� ���޴� �ֵ��� �־�ȴ�.
		reqStudent += v[i] / maxPerStudent;

		// �ϳ��� ���� �����������Ƿ�
		if (v[i] % maxPerStudent) reqStudent++;
	}
	return n >= reqStudent;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> n >> m;
	for (long long i = 0; i < m; i++) {
		cin >> v[i];
		// ����Ž�� ���������� ����
		highJ = max(highJ, v[i]);
	}

	while (lowJ <= highJ) {
		midJ = (lowJ + highJ) / 2;
		if (IsDistribution(midJ)) {
			// �� ������ �������� �ּҰ�
			minJ = min(minJ, midJ);
			highJ = midJ - 1;
		}
		else {
			lowJ = midJ + 1;
		}
	}
	
	cout << minJ;

	return 0;
}