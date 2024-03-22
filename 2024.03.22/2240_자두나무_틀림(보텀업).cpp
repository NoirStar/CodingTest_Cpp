#include <bits/stdc++.h>
using namespace std;

int T, W;

int dp[1001][31][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// �ڵ� ����������, �����ϼ��ִ� ��

	cin >> T >> W;

	vector<int> vZa(T+1);

	for (int i = 0; i < T; i++) {
		cin >> vZa[i];
	}


	// t �ð� w Ƚ�� p 1,2 ����
	// ������ �ִ°��
	// 1) �ڵΰ� �������� ��ġ  dp[t][w][p] = dp[t-1][w][p] + 1
	// 2) �ڵΰ� �ȶ���������ġ dp[t][w][p] = dp[t-1][w][p]

	// ��ġ�� ������ ���
	// 1) �ڵΰ� �������� ��ġ dp[t][w][p] = dp[t-1][w-1][3-p] + 1 (3-p �������� 1->2 2->1����)
	// 2) �ڵΰ� �ȶ������� ��ġ dp[t][w][p] = dp[t-1][w-1][3-p]
	
	// �ʱ� ���� ����
	for (int i = 0; i <= W; ++i) {
		dp[0][i][1] = 0; // ���� ��ġ�� 1�� ���� �Ʒ�
		dp[0][i][2] = -1; // �����δ� ������ �� ���� ���·� �ʱ�ȭ
	}


	for (int t = 1; t <= T; t++) {
		for (int w = 0; w <= W; w++) {
			// ������ �ִ� ���
			dp[t][w][1] = max(dp[t][w][1], dp[t - 1][w][1] + (vZa[t] == 1 ? 1 : 0));
			dp[t][w][2] = max(dp[t][w][2], dp[t - 1][w][2] + (vZa[t] == 2 ? 1 : 0));

			// �����̴� ���
			if (w > 0) {
				dp[t][w][1] = max(dp[t][w][1], dp[t - 1][w - 1][2] + (vZa[t] == 1 ? 1 : 0));
				dp[t][w][2] = max(dp[t][w][2], dp[t - 1][w - 1][1] + (vZa[t] == 2 ? 1 : 0));
			}
		}
	}
	
	int nRet = 0;
	for (int w = 0; w <= W; ++w) {
		nRet = max(nRet, max(dp[T][w][1], dp[T][w][2]));
	}

	cout << nRet;


	return 0;
}