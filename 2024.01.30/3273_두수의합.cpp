#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, x, l, r, nRet = 0;
	cin >> n;
	vector<int> vNum(n);

	for (int i = 0; i < n; i++) {
		cin >> vNum[i];
	}
	cin >> x;

	sort(vNum.begin(), vNum.end());

	// 시작과 끝점을 할 수 도있고, 시작점을 두개 잡을 수도있음
	l = 0, r = n - 1;

	while (l < r) {
		if (vNum[l] + vNum[r] == x) {
			r--;
			nRet++;
		}
		else if (vNum[l] + vNum[r] > x) r--;
		else if (vNum[l] + vNum[r] < x) l++;
	}
	cout << nRet;

	return 0;
}