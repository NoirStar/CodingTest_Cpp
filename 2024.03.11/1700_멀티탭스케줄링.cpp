#include <bits/stdc++.h>

using namespace std;

// �޸� ����¡ ���� �˰���
// Optimal Page Replacement Algorithm
// ���� �ý��ۿ����� ��ƴ�. �̷��� �����ϴ°Ŵϱ� �ٵ� �̹����� �̷��� �� �־�������.
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int n, k, nCount=0;

	cin >> k >> n;

	vector<int> v;
	vector<int> vArr(101,0);
	vector<int> vVisited(101, 0);
	for (int i = 0; i < n; i++) {
		cin >> vArr[i];
	}

	// 1. ���� 2 3 �� ���ְ�, 1 2 �� ���´ٸ� 1 2 �� ���°� �̴´�
	// ���������� ��Ƽ�� �˰���. ����� �̷��� �����Ǵ� �������� �����Ѵ�.
	// �ٽ��� ������ ���� �������. �׷� �����ִ°��� ���� �� �̷��� �����°� �����ϸ��

	for (int i = 0; i < n; i++) {
		// ���� �ʾҴ� ���̸�, 
		if (!vVisited[vArr[i]]) {
			// �ܼ�Ʈ�� �� á���� ���°� ������
			if (v.size() == k) {
				int lastIdx = 0, pos = 0;

				// �ܼ�Ʈ�� �����ִ°� ��ȸ
				for (int a : v) {
					// ���� �� �̷��� �����Ǵ°� ã�´�.
					int pick = 987654321;
					for (int j = i + 1; j < n; j++) {
						// �����ִ� ������ǰ �� ���� �� �̷��� �����°��� ã�´�.
						if (a == vArr[j]) {
							pick = j;
							break;
						}
					}
					if (lastIdx < pick) {
						lastIdx = pick;
						// �����ִ°� ��ü�ϱ����� ��ǥ
						pos = a;
					}
				}
				vVisited[pos] = 0;
				nCount++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(vArr[i]);
			vVisited[vArr[i]] = 1;
		}
	}

	cout << nCount;

	return 0;
}

