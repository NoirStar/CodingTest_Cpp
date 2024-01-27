#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	int a = 0, b = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> n;
			if (i == 0) a += n;
			else b += n;
		}
	}

	a >= b ? cout << a : cout << b;
	return 0;
}