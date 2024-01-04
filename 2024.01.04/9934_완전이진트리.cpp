#include <bits/stdc++.h>

using namespace std;
// InOrder 레벨화

int h;
vector<int> vNode;
vector<vector<int>> vRet;

void Re(int s, int e, int level) {
	// 재귀 기저사례 정의
	if (s > e) return;
	if (s == e) {
		vRet[level].push_back(vNode[s]);
		return;
	}
	int nMid = (s + e) / 2;

	vRet[level].push_back(vNode[nMid]);

	//1 7  4 1~3  5~7
	Re(s, nMid-1, level + 1);
	Re(nMid+1, e, level + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> h;

	
	int end = pow(2, h) - 1;

	vRet.assign(h, vector<int>());
	vNode.assign(end, 0);

	for (int i = 0; i < end; i++) {
		cin >> vNode[i];
	}

	Re(0, end-1, 0);
	
	for (const auto& v : vRet) {
		for (const auto& e : v) {
			cout << e << ' ';
		}
		cout << '\n';
	}

	return 0;
}