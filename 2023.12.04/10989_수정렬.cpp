#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int nNum;
	cin >> nNum;

	map<short, int> mNum;
	for (int i = 0; i < nNum; i++) {
		int nTemp;
		cin >> nTemp;
		mNum[nTemp]++;
	}

	for (const auto& n : mNum) {
		for (int i = 0; i < n.second; i++) {
			cout << n.first << '\n';
		}
	}

	return 0;
}