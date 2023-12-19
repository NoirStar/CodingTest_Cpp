#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nNum;
	cin >> nNum;
	
	// 2x3 =  ||| =| |= ¤±| |¤±   

	vector<int> vDp(1001);
	vDp[1] = 1;
	vDp[2] = 3;

	for (int i = 3; i <= 1000; i++) {
		vDp[i] = (vDp[i - 1] + 2*vDp[i - 2]) % 10007;
	}

	cout << vDp[nNum];

	return 0;
}