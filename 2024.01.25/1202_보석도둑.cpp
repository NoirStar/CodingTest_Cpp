#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n,k;
	cin >> n >> k;
	// n 보석의 정보 개수, k 가방에 담을수 있는 최대 무게. 최대 1개만담을수있음

	vector<pair<ll, ll>> vJu(n);
	vector<ll> vBag(k);
	
	for (int i = 0; i < n; i++) {
		cin >> vJu[i].first >> vJu[i].second;
	}

	for (int i = 0; i < k; i++) {
		cin >> vBag[i];
	}
	
	// 보석, 가방 무게를 작은것부터 정렬
	sort(vJu.begin(), vJu.end());
	sort(vBag.begin(), vBag.end());
	priority_queue<ll> pq;

	// 가방에 들어갈 수있는 무게가 적은거부터
	// 가방무게보다 적으면서 가장 비싼거? 하면될듯
	// 효율적이란걸 생각하라.
	// 무게를 적게 담을 수 있는 가방에 넣을 수 있는 보석을 다넣어버리기
	// 우선순위큐를 이용하면, 가방에 들어간 최대 

	int j = 0;
	ll llRet = 0;
	// 가방 수만큼
	for (int i = 0; i < k; i++) {
		// 가방에 넣을 수있는 보석일때
		while (j < n && vJu[j].first <= vBag[i]) {
			pq.push(vJu[j++].second);
		}
		// 다 넣었을때 pq기 때문에 최상위는 최대값
		if (pq.size()) {
			llRet += pq.top();
			pq.pop();
		}
	}
	cout << llRet;

	return 0;
}