#include <bits/stdc++.h>

using namespace std;
int n, nRet = 987654321;
vector<int> vCoin;
// 행만 뒤집고 열은 최적해는 정해져있다.
// T-1 H-0

void go(int here) {
	
	// 끝점까지 왔다면, 열을 한번 체크해본다.
	if (here == n + 1) {
		// 열 체크
		int nSum = 0;
		// i 는  100 010 001  비트마스크 거꾸로 1 2 4
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
			// 뒷면 카운트
			int nCount = 0;
			// 열체크
			for (int j = 1; j <= n; j++) {
				if (vCoin[j] & i) nCount++;
			}
			// 뒤집은거, 안뒤집는거 중 뒷면의 최소값
			nSum += min(nCount, n - nCount);
		}
		// 현재 경우의수의 뒷면의 값 최소값 비교
		nRet = min(nRet, nSum);
		return;
	}

	// 행을 하나씩 이동하면서 (가로줄+1)  뒤집는경우, 안뒤집는경우 두가지로 구분
	// 안뒤집는 경우
	go(here + 1);
	// 뒤집는경우
	vCoin[here] = ~vCoin[here];
	go(here + 1);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> n;
	vCoin.assign(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int value = 1;
		// HHT 면 비트마스킹을 거꾸로 생각   124 자리면, T만 1  => 4
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'T') vCoin[i] |= value;
			value *= 2;
		}
	}

	go(1);
	cout << nRet;

	return 0;
}