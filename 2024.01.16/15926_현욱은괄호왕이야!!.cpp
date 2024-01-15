#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	stack<int> sAns;
	vector<int> vAns(200001, 0);
	string s;
	cin >> s;

	// (())) => 11110 와 같은 배열로 저장한다. 정답은 1 오답은 0

	for (int i = 0; i < n; i++) {
		// ( 왔을때 push 해서 카운팅한다.
		if (s[i] == '(') sAns.push(i);
		// ) 가 왔고 사이즈가 있으면, pop을 한다. (짝이 맞는 괄호를 제거)
		else if (sAns.size()) {
			vAns[i] = 1;
			vAns[sAns.top()] = 1;
			sAns.pop();
		}
	}

	int nCount = 0, nMax = 0;
	for (int i = 0; i < n; i++) {
		if (vAns[i]) {
			nCount++;
			nMax = max(nMax, nCount);
		}
		else {
			nCount = 0;
		}
	}

	cout << nMax;

	return 0;
}