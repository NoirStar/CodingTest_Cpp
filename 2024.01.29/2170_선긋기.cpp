#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, from, to, l, r;
	
	cin >> n;
	vector<pair<int, int>> vLine(n);

	// 겹치면 계속 갱신해서 마지막에 + 해주는 방식
	// 2차원이 아니라 1차원적으로 생각하면됨

	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		vLine[i] = { from, to };
	}

	sort(vLine.begin(), vLine.end());
	l = vLine[0].first;
	r = vLine[0].second;

	int nRet = 0;
	for (int i = 1; i < n; i++) {
		// 겹쳐져있지 않은 경우. 크기 순으로 정렬했으니 크면 겹치지 않음
		if (r < vLine[i].first) {
			nRet += (r - l);
			// 새로운 값으로 갱신
			l = vLine[i].first;
			r = vLine[i].second;
		}
		// 겹쳐져 있는 경우
		else if(vLine[i].first <= r && vLine[i].second >= r) {
			r = vLine[i].second; // 큰값으로 갱신
		} 
	}
	nRet += r - l;
	cout << nRet;

	return 0;
}

