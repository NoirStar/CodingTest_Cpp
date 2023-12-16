#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nTest;

	cin >> nTest;

	vector<int> vZero(41);
	vector<int> vOne(41);

	vZero[0] = 1;
	vOne[0] = 0;
	vOne[1] = 1;

	for (int n = 2; n <= 40; n++)
	{
		vZero[n] = vZero[n - 1] + vZero[n - 2];
		vOne[n] = vOne[n - 1] + vOne[n - 2];
	}

	for (int i = 0; i < nTest; i++) {
		int n;
		cin >> n;
		cout << vZero[n] << ' ' << vOne[n] << '\n';
	}


	return 0;
}