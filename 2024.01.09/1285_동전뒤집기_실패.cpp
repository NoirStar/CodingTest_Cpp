#include <bits/stdc++.h>

using namespace std;

// H(앞면)-1  T(뒷면)-0
vector<int> vCoin;
int n;

void ReverseRow(int idx) {
	vCoin[idx] = ~vCoin[idx];
}

void ReverseCol(int idx) {
	for (int i = 0; i < n; i++) {
		vCoin[i] ^= (1 << idx);
	}
}

// 앞면이 최소인곳을 뒤집어야함. 그래야 뒷면이 최소가됨
int CalcRow(int idx) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (vCoin[idx] & (1 << i)) {
			temp++;
		}
	}
	return temp;
}
int CalcCol(int idx) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (vCoin[i] & (1 << idx)) {
			temp++;
		}
	}
	return temp;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	vCoin.assign(n,0);

	for (int i = 0; i < n; i++) {
		int bit = (1 << n) -1;
		for (int j = n-1; j >= 0; j--) {
			char c;
			cin >> c;
			if (c == 'T') {
				bit ^= (1 << j);
			}
		}
		vCoin[i] = bit;
	}

	// 한 행, 한 열 씩 뒤집는 작업을 수행한다.
	// 앞면이 최소인곳을 뒤집는다.
	int nRetMin = 987654321;
	int nCount = 0;
	while (true) {
		
		pair<int, int> pFrontMin = { 987654321, 0 };

		for (int i = 0; i < n * 2; i++) {
			int temp;
			if (i < n) {
				temp = CalcRow(i);
			}
			else {
				temp = CalcCol(i - n);
			}

			if (pFrontMin.first >= temp) {
				pFrontMin.first = temp;
				pFrontMin.second = i;
			}
		}

		if (pFrontMin.second < n) {
			ReverseRow(n);
		}
		else {
			ReverseCol(pFrontMin.second-n);
		}

		// 뒷면의 최소값
		int nMin = 0;
		for (int i = 0; i < n; i++) {
			int front = CalcCol(i);
			nMin += (n-front);
		}
		nRetMin = min(nRetMin, nMin);
		
		nCount++;
		if (nCount == 1000) break;
	}

	cout << nRetMin;

	return 0;
}