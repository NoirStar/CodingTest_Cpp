#include <bits/stdc++.h>

using namespace std;

int n, nMin = 987654321;
vector<int> vPeople;
vector<int> vConnect;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	// 각구역의 인구수 벡터
	vPeople.assign(n+1, 0);
	vConnect.assign(n+1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> vPeople[i];
	}

	// 연결정보를 비트로하면어떨까
	for (int i = 1; i <= n; i++) {
		int con;
		cin >> con;
		for (int j = 1; j <= con; j++) {
			int c;
			cin >> c;
			vConnect[i] |= (1 << (c-1));
		}
	}

	// 두 선거구로 나누는데, 1명이상 있어야하고  나눠진 구들끼리 연결되있어야한다.

	// n=4 라면 0001 ~ 1110 까지 돈다. 한쪽에 몰아서 주는건 불가능하므로. 구역 1이상
	for (int i = 1; i < (1 << n) - 1; i++) {
		int a, b;
		a = i;
		b = ~i;

		int nPeopleA = 0, nPeopleB = 0;
		bool bGood = true;
		for (int j = 0; j < n; j++) {
			// 한비트씩 접근해서 연결정보 체크 각 노드를 검사했을때, 다른 비트만 있다면 
			if (a & (1 << j)) {
				// 탐지된 비트의 연결정보가 다른 구역끼리만 연결되어있다면
				if ((a & vConnect[j + 1]) == 0 && a != (1 << j)) {
					bGood = false;
					break;
				}
				// 인구수 계산
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
