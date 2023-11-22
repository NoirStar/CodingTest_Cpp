#include <bits/stdc++.h>

using namespace std;

bool IsPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int nInt, nErase;
	cin >> nInt >> nErase;

	map<int, bool> mChe;
	for (int i = 2; i <= nInt; i++) {
		mChe[i] = false;
	}

	int nCount = 0;
	for (int i = 2; i <= nInt; i++) {
		if (mChe[i] == false) {
			if (IsPrime(mChe[i])) {
				mChe[i] = true;
				nCount++;
				if (nCount == nErase) {
					cout << i;
					return 0;
				}
				for (int j = 2 * i; j <= nInt; j+=i) {
					if (mChe[j] == false) {
						mChe[j] = true;
						nCount++;
					}
					if (nCount == nErase) {
						cout << j;
						return 0;
					}
				}
			}
		}
	}

	return 0;
}