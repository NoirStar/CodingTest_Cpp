#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nStair;

	cin >> nStair;

	vector<int> vStair(nStair+1);

	for (int i = 1; i <= nStair; i++) {
		cin >> vStair[i];
	}

	vector<int> vDp(nStair + 1);
	vDp[1] = vStair[1];
	vDp[2] = vStair[1] + vStair[2];
	vDp[3] = vStair[3] + max(vStair[1], vStair[2]);


	for (int i = 4; i <= nStair; i++)
	{
		vDp[i] = vStair[i] + max(vStair[i - 1] + vDp[i - 3], vDp[i - 2]);
	}

	cout << vDp[nStair];

	return 0;
}